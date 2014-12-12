#!/usr/bin/env python
from __future__ import print_function

from poisson import BmiPoisson


def main():
    model = BmiPoisson()

    print('Initializing... ', end='')
    model.initialize()
    print('Done.')

    print('%s' % model.get_component_name())

    for i in xrange(10):
        print('Running time step: %d... ' % i, end='')
        model.update()
        print('Done.')

    print('Finalizing... ', end='')
    model.finalize()
    print('Done.')


if __name__ == '__main__':
    main()
