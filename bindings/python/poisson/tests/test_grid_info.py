#!/usr/bin/env python
from nose.tools import assert_equal, assert_list_equal
import numpy as np

from poisson import BmiPoisson


def test_grid_var_names():
    model = BmiPoisson()
    model.initialize()

    names = model.get_input_var_names()
    assert_list_equal(names, ['land_surface__elevation'])

    names = model.get_output_var_names()
    assert_list_equal(names, ['land_surface__elevation'])


def test_grid_var_units():
    model = BmiPoisson()
    model.initialize()
    assert_equal(model.get_var_units('land_surface__elevation'), 'meter')


def test_grid_var_rank():
    model = BmiPoisson()
    model.initialize()
    assert_equal(model.get_var_rank('land_surface__elevation'), 2)


def test_grid_var_shape():
    model = BmiPoisson()
    model.initialize()
    assert_equal(model.get_grid_shape('land_surface__elevation'), (10, 20))


def test_grid_var_spacing():
    model = BmiPoisson()
    model.initialize()
    assert_equal(model.get_grid_spacing('land_surface__elevation'), (1., 1.))


def test_grid_var_origin():
    model = BmiPoisson()
    model.initialize()
    assert_equal(model.get_grid_origin('land_surface__elevation'), (0., 0.))


def test_grid_var_type():
    model = BmiPoisson()
    model.initialize()
    assert_equal(model.get_var_type('land_surface__elevation'), 'float64')
