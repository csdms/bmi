#! /usr/bin/env python

"""
>>> import numpy as np
>>> np.set_printoptions (precision=2, linewidth=150, suppress=True)

>>> c = Model ()
>>> c.initialize ()

>>> c.get_input_var_names ()
['surface_elevation']
>>> c.get_output_var_names ()
['surface_elevation']

>>> var_name = 'surface_elevation'

>>> c.get_grid_type (var_name) == BmiGridType.UNIFORM
True

>>> c.get_grid_shape (var_name)
(20, 10)
>>> c.get_grid_spacing (var_name)
(1.0, 1.0)
>>> c.get_grid_origin (var_name)
(0.0, 0.0)

>>> c.get_start_time ()
0.0
>>> c.get_current_time ()
0.0
>>> print '%.2g' % c.get_end_time ()
1.8e+308

>>> c.update ()
>>> c.get_current_time ()
1.0

>>> z = c.get_value (var_name)
>>> z[:-3,:].sum ()
0.0
>>> np.all (z[-2:-1,:].sum () > 0)
True

>>> c.update_until (3.)
>>> c.get_current_time ()
3.0

>>> z[:-5,:].sum ()
0.0
>>> np.all (z[-4:-1,:].sum () > 0)
True

"""

import numpy as np

from BMI import BMI, BmiGridType
from scipy import ndimage

class Model (BMI):
    _var_units = {'surface_elevation': 'meter'}
    _name = 'Example Python Model'
    _input_var_names = ['surface_elevation']
    _output_var_names = ['surface_elevation']

    def __init__ (self):
        self._dt = 0
        self._shape = (0, 0)
        self._spacing = (0., 0.)
        self._origin = (0., 0.)
        self._t = 0.

        self._z = None
        self._temp_z = None

        self._value = {}

    @staticmethod
    def _set_bc (z):
        z[:,0] = 0.
        z[:,-1] = 0.
        z[0,:] = 0.

        top_x = z.shape[1] - 1
        z[-1,:] = .25*top_x**2 - (np.arange (top_x+1) - .5*top_x)**2

    def initialize (self, file=None):
        if file is not None:
            f = open (file, 'r')
            vals = f.readline ().split (',')
            self._dt, ny, nx = (float (vals[0]), int (vals[1]), int (vals[2]))
            self._shape = (ny, nx)
        else:
            self._dt = 1.
            self._shape = (20, 10)

        self._spacing = (1., 1.)
        self._origin = (0., 0.)

        self._z = np.zeros (self._shape)
        self._set_bc (self._z)
        self._temp_z = self._z.copy ()

        self._value['surface_elevation'] = self._z

        dx, dy = self._spacing
        self._stencil = np.array ([[0., dx**2, 0.], [dy**2, 0., dy**2], [0., dx**2, 0.]]) / (2. * (dx**2 + dy**2)) * self._dt

    def update (self):
        ndimage.convolve (self._z, self._stencil, output=self._temp_z)
        self._set_bc (self._temp_z)
        self._z[:] = self._temp_z

        self._t += self._dt

    def update_until (self, t):
        (dt, n_steps) = np.modf (t - self.get_current_time ())
        for i in xrange (int (n_steps)):
            self.update ()

        if dt > 0:
            self._stencil *= dt / self._dt
            self.update ()
            self._stencil *= self._dt / dt

    def finalize (self):
        self._dt = 0
        self._t = 0

        self._z = np.array ([])
        self._temp_z = np.array ([])

    def get_var_type (self, long_var_name):
        return str (self.get_value (long_var_name).dtype)
    def get_var_units (self, long_var_name):
        return self.var_units[long_var_name]
    def get_var_rank (self, long_var_name):
        return self.get_value (long_var_name).ndim

    def get_value (self, long_var_name):
        return self._value[long_var_name]
    def get_value_at_indices (self, long_var_name, indices):
        return self.get_value (long_var_name)[indices]
    def set_value (self, long_var_name, src):
        val = self.get_value (long_var_name)
        val[:] = src
    def set_value_at_indices (self, long_var_name, indices, src):
        val = self.get_value (long_var_name)
        val[indices] = src

    def get_component_name (self):
        return self._name
    def get_input_var_names (self):
        return self._input_var_names
    def get_output_var_names (self):
        return self._output_var_names

    def get_grid_shape (self, long_var_name):
        return self.get_value (long_var_name).shape
    def get_grid_spacing (self, long_var_name):
        return self._spacing
    def get_grid_origin (self, long_var_name):
        return self._origin

    def get_grid_type (self, long_var_name):
        if self._value.has_key (long_var_name):
            return BmiGridType.UNIFORM
        else:
            return BmiGridType.UNKNOWN

    def get_start_time (self):
        return 0.
    def get_end_time (self):
        return np.finfo ('d').max
    def get_current_time (self):
        return self._t

def main ():
    import doctest
    doctest.testmod ()

if __name__ == '__main__':
    main ()
