#!/usr/bin/env python
from __future__ import print_function

import sys
import numpy as np

from poisson import BmiPoisson


def print_var_names(model):
    print('Input var names: ', end='')
    names = model.get_input_var_names()
    names.sort()
    print('%s' % ', '.join(names))

    print('Output var names: ', end='')
    names = model.get_output_var_names()
    names.sort()
    print('%s' % ', '.join(names))


def main():
    model = BmiPoisson()

    model.initialize()

    print('%s' % model.get_component_name())

    print_var_names(model)

    model.finalize()


if __name__ == '__main__':
    main()
