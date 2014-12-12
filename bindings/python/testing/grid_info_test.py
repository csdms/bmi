#!/usr/bin/env python

from __future__ import print_function

import sys
import numpy as np

from poisson import BmiPoisson


def print_var_info(model, var):
    print('Variable name: %s' % var)
    print('Type: %s' % model.get_var_type(var))
    print('Units: %s' % model.get_var_units(var))
    print('Rank: %s' % model.get_var_rank(var))
    print('Dimension: %s' % 'x'.join(
        [str(x) for x in model.get_grid_shape(var)]))
    print('Resolution: %s' % 'x'.join(
        [str(x) for x in model.get_grid_spacing(var)]))
    print('Corner: (%s)' % ','.join(
        [str(x) for x in model.get_grid_origin(var)]))


def main():
    model = BmiPoisson()

    model.initialize()

    print('%s' % model.get_component_name())

    vars = model.get_input_var_names()
    vars.sort()
    for var in vars:
        print_var_info(model, var)
        print('')

    vars = model.get_output_var_names()
    vars.sort()
    for var in vars:
        print_var_info(model, var)
        print('')

    model.finalize()


if __name__ == '__main__':
    main()
