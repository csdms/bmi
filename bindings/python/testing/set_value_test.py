#!/usr/bin/env python
from __future__ import print_function

import sys
import numpy as np

from poisson import BmiPoisson


def print_var_values(model, var_name):
    from sys import stdout

    x = model.get_value(var_name)
    np.savetxt(sys.stdout, x, fmt='%.3f')


def main():
    model = BmiPoisson()

    model.initialize()

    print('%s' % model.get_component_name())

    dimen = model.get_grid_shape('land_surface__elevation')
    type = model.get_var_type('land_surface__elevation')
    new_vals = np.ones(dimen, dtype=type) * -1

    print('0: ', end='')
    print_var_values(model, 'land_surface__elevation')

    model.set_value('land_surface__elevation', new_vals)

    print('1: ', end='')
    print_var_values(model, 'land_surface__elevation')

    # Another way to set values. This is faster but a bit more confusing.
    z = model.get_value('land_surface__elevation')
    z *= -1
    print('2: ', end='')
    print_var_values(model, 'land_surface__elevation')

    # Why confusing? Because you might think the following would work
    # the same as the previous example, but it doesn't
    z = model.get_value('land_surface__elevation') * -1
    print('3: ', end='')
    print_var_values(model, 'land_surface__elevation')

    model.finalize()


if __name__ == '__main__':
    main()
