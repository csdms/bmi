.. _var_funcs:

Variable information functions
------------------------------

These BMI functions provide information
about a particular input or output variable.
They must accommodate any variable returned from the
:ref:`get_input_var_names` or :ref:`get_output_var_names` functions --
the variable name is used as an argument in each function. 
Based on the information returned,
type or unit conversions can be applied when necessary.


.. _get_var_grid:

*get_var_grid*
..............

.. code-block:: java

   int get_var_grid(in string name, out int grid);

Each input and output variable is defined on a grid.
(Available grid types are listed in the :ref:`grid_funcs` section.)
The `get_var_grid` function provides the identifier (an integer) for this grid.
The identifier can be passed to the BMI
:ref:`grid information <grid_funcs>` functions
to get the details of a particular grid;
e.g., *x*- and *y*-coordinates, size, type, etc.
A model can have one or more grids.

**Implementation notes**

* Grid identifiers start at 0.
* In C++ and Python, the *grid* argument is omitted and the grid
  identifier is returned from the function.


.. _get_var_type:

*get_var_type*
..............

.. code-block:: java

   int get_var_type(in string name, out string type);

The `get_var_type` function provides the data type of the
variable as it's stored in memory by the model.
The data type is returned as a string following the :term:`numpy` convention
used by the `dtype`_ attribute; e.g., `int32`, `float`, etc.

**Implementation notes**

* In C++ and Python, the *type* argument is omitted and the variable
  type name is returned from the function.


.. _get_var_units:

*get_var_units*
...............

.. code-block:: java

   int get_var_units(in string name, out string units);

Get the units of the given variable.
Standard unit names, in lower case, should be used, such as `meters`
or `seconds`.
Standard abbreviations, such as `m` for meters, are
also supported. For variables with compound units, each unit name
is separated by a single space, with exponents other than 1 placed
immediately after the name, as in `m s-1` for velocity, `W m-2` for
an energy flux, or `km2` for an area.
The abbreviations used in the BMI are derived from
Unidata's `UDUNITS`_ package.
See, for example, `The Units Database`_ for a
full description of valid unit names and a list of supported units.

**Implementation notes**

* In C++ and Python, the *units* argument is omitted and the variable
  units name is returned from the function.


.. _get_var_itemsize:

*get_var_itemsize*
..................

.. code-block:: java

    int get_var_itemsize(in string name, out int size);

The `get_var_itemsize` function provides the size, in bytes,
of a single element of the variable.
For example, if data for a variable are stored as 64-bit integers,
`get_var_itemsize` would return 8.

**Implementation notes**

* In C++ and Python, the *size* argument is omitted and the item size
  is returned from the function.


.. _get_var_nbytes:

*get_var_nbytes*
................

.. code-block:: java

    int get_var_nbytes(in string name, out int nbytes);


The `get_var_nbytes` function provides the total amount of memory used to store
a variable; i.e., the number of items multiplied by the size of each item.

**Implementation notes**

* In C++ and Python, the *nbytes* argument is omitted and the total
  amount of memory used by the variable is returned from the function.


.. _get_var_location:

*get_var_location*
..................

.. code-block:: java

    int get_var_location(in string name, out string location);

The `get_var_location` function,
given a variable name, returns a string that indicates on what grid
element the variable is defined. Valid return values are:

* `"node"`
* `"edge"`
* `"face"`

**Implementation notes**

* In C++ and Python, the *location* argument is omitted and the location
  is returned from the function.


.. Links

.. _dtype: https://docs.scipy.org/doc/numpy/reference/arrays.dtypes.html
