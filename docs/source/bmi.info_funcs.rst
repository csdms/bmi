.. _info_funcs:

Model information functions
---------------------------

These functions supply the model name
and the model's :term:`exchange items <exchange item>` -- 
the variables that the model can use from
and provide to other models that have a BMI.

.. _get_component_name:

*get_component_name*
....................

.. code-block:: java

  /* SIDL */
  int get_component_name(out string name);

This function supplies the name of the model component as a string.
There are no restrictions on the name,
but it should be unique to prevent conflicts with other components.

**Implementation notes**

* In C and Fortran, the *name* argument is a a character array, and an integer
  status code indicating success (zero) or failure (nonzero) is returned.
* In C++ and Python, this argument is omitted, and a string -- a basic type
  in these languages -- is returned from the function.

[:ref:`info_funcs` | :ref:`basic_model_interface`]


.. _get_input_item_count:

*get_input_item_count*
......................

.. code-block:: java

  /* SIDL */
  int get_input_item_count(out int count);

The number of variables the model can use from other models
implementing a BMI.
Also the number of variables that can be set with :ref:`set_value`.

**Implementation notes**

* In C++ and Python, the argument is omitted and the count is returned
  from the function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`info_funcs` | :ref:`basic_model_interface`]


.. _get_output_item_count:

*get_output_item_count*
.......................

.. code-block:: java

  /* SIDL */
  int get_output_item_count(out int count);

The number of variables the model can provide other models
implementing a BMI.
Also the number of variables that can be retrieved with :ref:`get_value`.

**Implementation notes**

* In C++ and Python, the argument is omitted and the count is
  returned from the function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`info_funcs` | :ref:`basic_model_interface`]


.. _get_input_var_names:

*get_input_var_names*
.....................

.. code-block:: java

  /* SIDL */
  int get_input_var_names(out array<string, 1> names);

Gets an array of names for the variables the model can use from other
models implementing a BMI.
The length of the array is given by :ref:`get_input_item_count`.
The names are preferably in the form of CSDMS :term:`Standard Names`.
Standard Names enable a modeling framework to determine whether an
input variable in one model is equivalent to, or compatible with,
an output variable in another model.
This allows the framework to automatically connect components.
Standard Names do not have to be used within the model.

**Implementation notes**

* In C and Fortran, the names are passed back as an array of character
  pointers (because the variable names could have differing lengths), and an
  integer status code indicating success (zero) or failure (nonzero) is returned.
* In C++, the argument is omitted and the names are returned from the
  function in a vector, a standard container in the language.
* In Python, the argument is omitted and the names are returned from the
  function in a tuple, a standard container in the language.
* A model might have no input variables.

[:ref:`info_funcs` | :ref:`basic_model_interface`]


.. _get_output_var_names:

*get_output_var_names*
......................

.. code-block:: java

  /* SIDL */
  int get_output_var_names(out array<string, 1> names);

Gets an array of names for the variables the model can provide to other
models implementing a BMI.
The length of the array is given by :ref:`get_output_item_count`.
The names are preferably in the form of CSDMS :term:`Standard Names`.
Standard Names enable a modeling framework to determine whether an
input variable in one model is equivalent to, or compatible with,
an output variable in another model.
This allows the framework to automatically connect components.
Standard Names do not have to be used within the model.

**Implementation notes**

* In C and Fortran, the names are passed back as an array of character
  pointers (because the variable names could have differing lengths), and an
  integer status code indicating success (zero) or failure (nonzero) is returned.
* In C++, the argument is omitted and the names are returned from the
  function in a vector, a standard container in the language.
* In Python, the argument is omitted and the names are returned from the
  function in a tuple, a standard container in the language.
* A model may have no output variables.

[:ref:`info_funcs` | :ref:`basic_model_interface`]
