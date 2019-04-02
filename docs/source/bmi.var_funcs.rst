Variable Information Functions
==============================

These BMI functions are called a framework to obtain information
about a particular input or output variable.  They must
accommodate any variable that is returned by the BMI functions
`get_input_var_names` or `get_output_var_names`. Based on this
information, a framework can apply type or unit conversion when
necessary.


.. _get_var_grid:

Variables grids
---------------

.. code-block:: java

    int get_var_grid(in string name)
    string get_var_location(in string name)

Each variable is associated with a grid on which the variable is defined.
A single model can have one or more grids. `get_var_grid` returns an
id (as an `int`) to its grid. That id is then passed to the BMI
:ref:`get_grid` functions to get information about a particular grid
(x and y coordinates, size, etc.). The `get_var_location` function,
given a variable name, returns a string that indicates on what grid
element the variable is defined. Valid return values are `"node"`,
`"edge"`, and `"face"`.

Variable units
--------------

.. code-block:: java

  string get_var_units(in string name)

Standard unit names, in lower case, should be used, such as `meters`
or `seconds`. Standard abbreviations, like `m` for meters, are
also supported. For variables with compound units, each unit name
is separated by a single space, with exponents other than 1 placed
immediately after the name, as in `m s-1` for velocity, `W m-2` for
an energy flux, or `km2` for an area. Please see
`udunits <http://www.unidata.ucar.edu/software/udunits/>`_ for a
full description of valid unit names and a list of supported units.

Variable data type
------------------

.. code-block:: java

  string get_var_type(in string name)
  int get_var_itemsize(in string name)
  int get_var_nbytes(in string name)

These functions provide information about the size of the data as
it's stored in memory. `get_var_type` returns the data type of the
variable as it's stored by the model. The data type is returned as
a string following the `numpy` convention used by the `dtype`
attribute (`int32`, `float`, etc.).

`get_var_itemsize` returns the size, in bytes, of each item of the
variable. For example if data for a variable are stored as 64-bit
integers, `get_var_itemsize` would return 8.

`get_var_nbytes` return the total amount of memory used to store
the entire array of data for a variable. That is, the number
of items multiplied by the size of each item.

