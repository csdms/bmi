#!/usr/bin/env python

from __future__ import print_function

import sys
import numpy as np

from poisson import BmiPoisson


def main():
    model = BmiPoisson()

    model.initialize()

    print('%s' % model.get_component_name ())

    for i in xrange(10):
        print('Time %d' % i)
        np.savetxt(sys.stdout, model.get_value('land_surface__elevation'),
                   fmt='%.3f')
        model.update()

    print('Time %d' % i)
    np.savetxt(sys.stdout, model.get_value('land_surface__elevation'),
               fmt='%.3f')

    model.finalize()


if __name__ == '__main__':
    main()
