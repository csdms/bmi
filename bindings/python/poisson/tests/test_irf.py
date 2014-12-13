#!/usr/bin/env python
from numpy.testing import assert_almost_equal, assert_array_less
import numpy as np

from poisson import BmiPoisson


def test_grid_initialize():
    model = BmiPoisson()
    model.initialize()

    assert_almost_equal(model.get_current_time(), 0.)
    assert_array_less(model.get_value('land_surface__elevation'), 1.)
    assert_array_less(0., model.get_value('land_surface__elevation'))


def test_update():
    model = BmiPoisson()
    model.initialize()

    for time in xrange(10):
        model.update()
        assert_almost_equal(model.get_current_time(), time + 1.)


def test_update_until():
    model = BmiPoisson()
    model.initialize()

    model.update_until(10.1)
    assert_almost_equal(model.get_current_time(), 10.1)


def test_finalize():
    model = BmiPoisson()
    model.initialize()
    model.update()
    model.finalize()
