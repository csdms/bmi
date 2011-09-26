#! /usr/bin/env python

class BMI (object):
    def initialize (self, file):
        pass
    def update (self):
        pass
    def finalize (self):
        pass
    def run_model (self):
        pass

    def get_var_type (self, var):
        pass
    def get_var_units (self, var):
        pass
    def get_var_rank (self, var):
        pass
    def get_var_name (self, var):
        pass

    def get_value (self, long_var_name):
        pass
    def set_value (self, long_var_name, src):
        pass

    def get_component_name (self):
        pass
    def get_input_var_names (self):
        pass
    def get_output_var_names (self):
        pass

    def get_grid_dimen (self, long_var_name):
        pass
    def get_grid_res (self, long_var_name):
        pass
    def get_grid_corner (self, long_var_name):
        pass

    def is_raster_grid (self, long_var_name):
        pass


