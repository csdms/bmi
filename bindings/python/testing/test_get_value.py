#!/usr/bin/env python
from nose import assert_true
import numpy as np

from poisson import BmiPoisson


def test_get_initial_value():
    model = BmiPoisson()
    model.initialize()

    z0 = model.get_value('land_surface__elevation')
    assert_true(np.all(z0 < 1. & z0 >= 0.))

    for _ in xrange(10):
        model.update()

    z = model.get_value('land_surface__elevation')
    assert_true(z0 is z)
