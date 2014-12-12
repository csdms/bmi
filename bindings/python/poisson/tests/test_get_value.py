#!/usr/bin/env python
from nose.tools import assert_true, assert_is, assert_is_not
from numpy.testing import assert_array_less, assert_array_almost_equal
import numpy as np

from poisson import BmiPoisson


def test_get_initial_value():
    model = BmiPoisson()
    model.initialize()

    z0 = model.get_value_ptr('land_surface__elevation')
    assert_array_less(z0, 1.)
    assert_array_less(0., z0)


def test_get_value_copy():
    model = BmiPoisson()
    model.initialize()

    z0 = model.get_value('land_surface__elevation')
    z1 = model.get_value('land_surface__elevation')

    assert_is_not(z0, z1)
    assert_array_almost_equal(z0, z1)


def test_get_value_reference():
    model = BmiPoisson()
    model.initialize()

    z0 = model.get_value_ptr('land_surface__elevation')
    z1 = model.get_value('land_surface__elevation')

    assert_is_not(z0, z1)
    assert_array_almost_equal(z0, z1)

    for _ in xrange(10):
        model.update()

    assert_is(z0, model.get_value_ptr('land_surface__elevation'))
