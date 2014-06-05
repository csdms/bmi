#!/usr/bin/env python

from __future__ import print_function

from bmi import MyBMI

def run ():
    bmi = MyBMI ()

    print ('Initializing... ', end='')
    bmi.initialize (None)
    print ('Done.')

    print ('%s' % bmi.get_component_name ())

    for i in range (10):
        print ('Running time step: %d... ' % i, end='')
        bmi.update ()
        print ('Done.')

    print ('Finalizing... ', end='')
    bmi.finalize ()
    print ('Done.')

if __name__ == '__main__':
    run ()

