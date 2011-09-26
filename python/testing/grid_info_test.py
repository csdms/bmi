#!/usr/bin/env python

from __future__ import print_function

import sys
import numpy as np

from bmi import MyBMI

def print_var_info (bmi, var):
    print ('Variable name: %s' % var)
    print ('Type: %s' % bmi.get_var_type (var))
    print ('Units: %s' % bmi.get_var_units (var))
    print ('Rank: %s' % bmi.get_var_rank (var))
    print ('Dimension: %s' % 'x'.join ([str(x) for x in bmi.get_grid_dimen (var)]))
    print ('Resolution: %s' % 'x'.join ([str(x) for x in bmi.get_grid_res (var)]))
    print ('Corner: (%s)' % ','.join ([str(x) for x in bmi.get_grid_corner (var)]))
    if bmi.is_raster_grid (var):
        print ('Grid type: %s' % 'Uniform')
    else:
        print ('Grid type: %s' % 'Non-uniform')


def run ():
    bmi = MyBMI ()

    bmi.initialize (None)

    print ('%s' % bmi.get_component_name ())

    vars = bmi.get_input_var_names ()
    vars.sort ()
    for var in vars:
        print_var_info (bmi, var)
        print ('')

    vars = bmi.get_output_var_names ()
    vars.sort ()
    for var in vars:
        print_var_info (bmi, var)
        print ('')

    bmi.finalize ()

if __name__ == '__main__':
    run ()

