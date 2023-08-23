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

   /* SIDL */
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
* In C++, Java, and Python, the *grid* argument is omitted and the grid
  identifier is returned from the function.
* In C and Fortran, an integer status code indicating success (zero) or
  failure (nonzero) is returned.

[:ref:`var_funcs` | :ref:`basic_model_interface`]


.. _get_var_type:

*get_var_type*
..............

.. code-block:: java

   /* SIDL */
   int get_var_type(in string name, out string type);

The `get_var_type` function provides the data type of the
variable as it's stored in memory by the model.
The data type is returned as a string.
Use of native language type names is encouraged;
e.g., in C, use `int`, `float`, and `double`,
while in Fortran, use `integer`, `real`, and `double precision`.

**Implementation notes**

* In C++, Java, and Python, the *type* argument is omitted and the variable
  type name is returned from the function as a string.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.
* In Java, only `primitive types`_ (e.g., ``int``, ``double``), not
  `wrapper classes`_ (e.g., ``Integer``, ``Double``), are supported.

[:ref:`var_funcs` | :ref:`basic_model_interface`]


.. _get_var_units:

*get_var_units*
...............

.. code-block:: java

   /* SIDL */
   int get_var_units(in string name, out string units);

Get the units of the given variable.
Standard unit names, in lower case, should be used,
such as ``"meters"`` or ``"seconds"``.
Standard abbreviations, such as ``"m"`` for meters, are
also supported. For variables with compound units, each unit name
is separated by a single space, with exponents other than 1 placed
immediately after the name, as in ``"m s-1"`` for velocity,
``"W m-2"`` for an energy flux, or ``"km2"`` for an area.
The abbreviations used in the BMI are derived from
Unidata's `UDUNITS`_ package.
See, for example, `The Units Database`_ for a
full description of valid unit names and a list of supported units.

**Implementation notes**

* Dimensionless quantities should use ``""`` or ``"1"`` as the unit.
* Variables without units should use ``"none"``.
* In C++, Java, and Python, the *units* argument is omitted and the variable
  units name is returned from the function as a string.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`var_funcs` | :ref:`basic_model_interface`]


.. _get_var_itemsize:

*get_var_itemsize*
..................

.. code-block:: java

   /* SIDL */
   int get_var_itemsize(in string name, out int size);

The `get_var_itemsize` function provides the size, in bytes,
of a single element of the variable.
For example, if data for a variable are stored as 64-bit integers,
`get_var_itemsize` would return 8.

**Implementation notes**

* In C++, Java, and Python, the *size* argument is omitted and the item size
  is returned from the function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`var_funcs` | :ref:`basic_model_interface`]


.. _get_var_nbytes:

*get_var_nbytes*
................

.. code-block:: java

   /* SIDL */
   int get_var_nbytes(in string name, out int nbytes);

The `get_var_nbytes` function provides the total amount of memory used to store
a variable; i.e., the number of items multiplied by the size of each item.

**Implementation notes**

* In C++, Java, and Python, the *nbytes* argument is omitted and the total
  amount of memory used by the variable is returned from the function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`var_funcs` | :ref:`basic_model_interface`]


.. _get_var_location:

*get_var_location*
..................

.. code-block:: java

   /* SIDL */
   int get_var_location(in string name, out string location);

The `get_var_location` function,
given a variable name, returns a string that indicates on what grid
element the variable is defined. Valid return values are:

* ``node``
* ``edge``
* ``face``

**Implementation notes**

* In C++, Java, and Python, the *location* argument is omitted and the location
  is returned from the function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.
* If the given variable is a scalar (i.e., defined on a :ref:`scalar
  grid <unstructured_grids>`), the location from this function is ignored.

[:ref:`var_funcs` | :ref:`basic_model_interface`]


.. Links

.. _dtype: https://docs.scipy.org/doc/numpy/reference/arrays.dtypes.html
