#! /usr/bin/env python

import numpy as np

from BMI import BMI

class MyBMI (BMI):
    var_type = {'grid_longitude': 'double',
                 'height_above_sea_floor': 'double'}
    var_units = {'grid_longitude': 'arc_degrdd',
                 'height_above_sea_floor': 'meter'}
    var_rank = {'grid_longitude': 1, 'height_above_sea_floor': 1}
    name = 'Example Python Model'
    input_var_names = ["height_above_sea_floor"]
    output_var_names = ['grid_longitude', 'height_above_sea_floor']

    def __init__ (self):
        self.dt = 0
        self.t = 0

        self.x = np.array ([])
        self.z = np.array ([])

        self.value = {}

    def initialize (self, file):
        if file is not None:
            f = open (file, 'r')
            vals = f.readline ().split (',')
            (self.dt, len) = (float (vals[0]), int (vals[1]))
        else:
            self.dt = 1.
            len = 10
        self.x = np.arange (len)
        self.z = np.zeros (len)
        self.value['grid_longitude'] = self.x
        self.value['height_above_sea_floor'] = self.z

    def update (self):
        self.x += self.dt
        self.z += self.x*self.dt

    def finalize (self):
        self.dt = 0
        self.t = 0

        self.x = np.array ([])
        self.z = np.array ([])

    def get_var_type (self, long_var_name):
        return self.var_type[long_var_name]
    def get_var_units (self, long_var_name):
        return self.var_units[long_var_name]
    def get_var_rank (self, long_var_name):
        return self.var_rank[long_var_name]

    def get_value (self, long_var_name):
        return self.value[long_var_name]
    def value_at_indices (self, long_var_name, indices):
        return self.get_value (long_var_name)[indeces]
    def set_value (self, long_var_name, src):
        val = self.get_value (long_var_name)
        val[:] = src
    def set_value_at_indices (self, long_var_name, indices, src):
        val = self.get_value (long_var_name)
        val[indices] = src

    def get_component_name (self):
        return self.name
    def get_input_var_names (self):
        return self.input_var_names
    def get_output_var_names (self):
        return self.output_var_names

    def get_grid_dimen (self, long_var_name):
        return self.get_value (long_var_name).shape
    def get_grid_res (self, long_var_name):
        return [1.]
    def get_grid_corner (self, long_var_name):
        return [0.]


    def is_raster_grid (self, long_var_name):
        return True

