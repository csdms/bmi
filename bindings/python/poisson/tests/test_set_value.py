#!/usr/bin/env python
from nose.tools import assert_is, assert_is_not
from numpy.testing import assert_array_almost_equal
import numpy as np

from poisson import BmiPoisson


def test_set_value():
    model = BmiPoisson()
    model.initialize()

    z0 = model.get_value_ptr('land_surface__elevation')
    z1 = np.zeros_like(z0) - 1

    model.set_value('land_surface__elevation', z1)

    new_z = model.get_value_ptr('land_surface__elevation')

    assert_is(new_z, z0)
    assert_is_not(new_z, z1)
    assert_array_almost_equal(new_z, z1)
