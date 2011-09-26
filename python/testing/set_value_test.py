#!/usr/bin/env python

from __future__ import print_function

import sys
import numpy as np

from bmi import MyBMI

np_type = {'double': np.float64, 'int':np.int64}

def print_var_values (bmi, var_name):
    s = ', '.join ([str (x) for x in bmi.get_value (var_name)])
    print ('%s' % s)

def run ():
    bmi = MyBMI ()

    bmi.initialize (None)

    print ('%s' % bmi.get_component_name ())

    dimen = bmi.get_grid_dimen ('height_above_sea_floor')
    type = bmi.get_var_type ('height_above_sea_floor')
    new_vals = np.ones (dimen, dtype=np_type[type])*-1

    print ('0: ', end='')
    print_var_values (bmi, 'height_above_sea_floor')

    bmi.set_value ('height_above_sea_floor', new_vals)

    print ('1: ', end='')
    print_var_values (bmi, 'height_above_sea_floor')

    # Another way to set values. This is faster but a bit more confusing.
    z = bmi.get_value ('height_above_sea_floor')
    z *= -1
    print ('2: ', end='')
    print_var_values (bmi, 'height_above_sea_floor')

    # Why confusing? Because you might think the following would work
    # the same as the previous example, but it doesn't
    z = bmi.get_value ('height_above_sea_floor')*-1
    print ('3: ', end='')
    print_var_values (bmi, 'height_above_sea_floor')

    bmi.finalize ()

if __name__ == '__main__':
    run ()


