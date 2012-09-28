#! /usr/bin/env python

class BmiGridType (object):
    UNKNOWN = 0
    UNIFORM = 1
    RECTILINEAR = 2
    STRUCTURED = 3
    UNSTRUCTURED = 4

class BMI (object):
    def initialize (self, file):
        pass
    def update (self):
        pass
    def update_until (self, time):
        pass
    def finalize (self):
        pass
    def run_model (self):
        pass

    def get_var_type (self, long_var_name):
        pass
    def get_var_units (self, long_var_name):
        pass
    def get_var_rank (self, long_var_name):
        pass

    def get_value (self, long_var_name):
        pass
    def get_value_at_indices (self, long_var_name, inds):
        pass
    def set_value (self, long_var_name, src):
        pass
    def set_value_at_indices (self, long_var_name, inds, src):
        pass

    def get_component_name (self):
        pass
    def get_input_var_names (self):
        pass
    def get_output_var_names (self):
        pass

    def get_start_time (self):
        pass
    def get_end_time (self):
        pass
    def get_current_time (self):
        pass

class BmiRaster (BMI):
    def get_grid_shape (self, long_var_name):
        pass
    def get_grid_spacing (self, long_var_name):
        pass
    def get_grid_origin (self, long_var_name):
        pass

class BmiRectilinear (BMI):
    def get_grid_shape (self, long_var_name):
        pass
    def get_grid_x (self, long_var_name):
        pass
    def get_grid_y (self, long_var_name):
        pass
    def get_grid_z (self, long_var_name):
        pass

class BmiStructured (BMI):
    def get_grid_shape (self, long_var_name):
        pass
    def get_grid_x (self, long_var_name):
        pass
    def get_grid_y (self, long_var_name):
        pass
    def get_grid_z (self, long_var_name):
        pass

class BmiUnstructured (BMI):
    def get_grid_x (self, long_var_name):
        pass
    def get_grid_y (self, long_var_name):
        pass
    def get_grid_z (self, long_var_name):
        pass
    def get_grid_connectivity (self, long_var_name):
        pass
    def get_grid_offset (self, long_var_name):
        pass

