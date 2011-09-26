#!/usr/bin/env python

from __future__ import print_function

import sys
import numpy as np

from bmi import MyBMI

def print_var_names (bmi):
    print ('Input var names: ', end='')
    names = bmi.get_input_var_names ()
    names.sort ()
    print ('%s' % ', '.join (names))

    print ('Output var names: ', end='')
    names = bmi.get_output_var_names ()
    names.sort ()
    print ('%s' % ', '.join (names))

def run ():
    bmi = MyBMI ()

    bmi.initialize (None)

    print ('%s' % bmi.get_component_name ())

    print_var_names (bmi)

    bmi.finalize ()

if __name__ == '__main__':
    run ()

