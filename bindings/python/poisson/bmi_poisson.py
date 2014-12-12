#! /usr/bin/env python
import numpy as np
from scipy import ndimage

from bmi import Bmi, BmiGridType
from .poisson import Poisson


class BmiPoisson(Bmi):
    _name = '2D Poisson Solver'
    _input_var_names = ['land_surface__elevation']
    _output_var_names = ['land_surface__elevation']
    _var_units = {'land_surface__elevation': 'meter'}

    def __init__(self):
        self._model = None
        self._values = {}

    def initialize(self, filename=None):
        if filename is not None:
            self._model = Poisson.from_file(filename)
        else:
            self._model = Poisson()
        self._values = {
            'land_surface__elevation': self._model.z,
        }

    def update(self):
        self._model.advance_in_time()

    def update_frac(self, time_frac):
        self._model._dt, save_dt = time_frac * dt, dt
        self.update()
        self._model._dt = save_dt

    def update_until(self, then):
        n_steps = (then - self.get_current_time()) / self.get_time_step()

        for _ in xrange(int(n_steps)):
            self._update()
        self.update_frac(n_steps - int(n_steps))

    def finalize(self):
        self._model = None

    def get_var_type (self, var_name):
        return str(self.get_value_ptr(var_name).dtype)

    def get_var_units(self, var_name):
        return self._var_units[var_name]

    def get_var_rank(self, var_name):
        return self.get_value_ptr(var_name).ndim

    def get_var_size(self, var_name):
        return self.get_value_ptr(var_name).size

    def get_var_nbytes(self, var_name):
        return self.get_value_ptr(var_name).nbytes

    def get_value_ptr(self, var_name):
        return self._values[var_name]

    def get_value(self, var_name):
        return self.get_value_ptr(var_name).copy()

    def get_value_at_indices(self, var_name, indices):
        return self.get_value_ptr(var_name)[indices]

    def set_value(self, var_name, src):
        val = self.get_value_ptr(var_name)
        val[:] = src

    def set_value_at_indices(self, var_name, indices, src):
        val = self.get_value_ptr(var_name)
        val[indices] = src

    def get_component_name(self):
        return self._name

    def get_input_var_names(self):
        return self._input_var_names

    def get_output_var_names(self):
        return self._output_var_names

    def get_grid_shape (self, var_name):
        return self.get_value_ptr(var_name).shape

    def get_grid_spacing(self, var_name):
        return self._model._spacing

    def get_grid_origin (self, var_name):
        return self._model._origin

    def get_grid_type(self, var_name):
        if self._values.has_key (var_name):
            return BmiGridType.UNIFORM
        else:
            return BmiGridType.UNKNOWN

    def get_start_time (self):
        return 0.

    def get_end_time (self):
        return np.finfo ('d').max

    def get_current_time (self):
        return self.time
