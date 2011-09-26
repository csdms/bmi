#!/usr/bin/env python

from __future__ import print_function

import sys
import numpy as np

from bmi import MyBMI

def print_var_values (bmi, var_name):
    s = ', '.join ([str (x) for x in bmi.get_value (var_name)])
    print ('%s' % s)

def run ():
    bmi = MyBMI ()

    bmi.initialize (None)

    print ('%s' % bmi.get_component_name ())

    for i in range (10):
        print ('Time %d: ' % i, end='')
        print_var_values (bmi, 'height_above_sea_floor')
        bmi.update ()

    print ('Time %d: ' % i, end='')
    print_var_values (bmi, 'height_above_sea_floor')

    bmi.finalize ()

if __name__ == '__main__':
    run ()

