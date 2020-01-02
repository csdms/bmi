.. _getter_setter_funcs:

Variable getter and setter functions
------------------------------------

These functions are used to access and modify the variables
that a model exposes through its BMI
(see :ref:`get_input_var_names` and :ref:`get_output_var_names`).

A *getter* is a function called to get a variable from your model's *state*.
A model's state variables typically change with each time step,
so getters are called to get current values.

A *setter* is a function called to change/overwrite a variable in
your model's state. A setter may impose restrictions on how a
state variable can be changed or check the new data for validity. 


.. _get_value:

*get_value*
...........

.. code-block:: java

   /* SIDL */
   int get_value(in string name, in array<> dest);

The `get_value` function takes a variable name and copies values into a
provided buffer.
The type and size of the buffer depend on the variable,
and can be determined through
:ref:`get_var_type`, :ref:`get_var_nbytes`, etc.
Recall that arrays are always flattened in BMI,
even if the model uses dimensional variables.

**Implementation notes**

* The *dest* argument must be defined and allocated before calling
  `get_value`. Whatever values it contains are overwritten in the call
  to `get_value`.
* In Python, the buffer is a :term:`numpy` array.
* In C++, `get_value` is a void function.
* Depending on how a model is written, a variable may not be
  accessible until after the call to :ref:`initialize`. Likewise, the
  variable may not be accessible after calling :ref:`finalize`.

.. _get_value_ptr:

*get_value_ptr*
...............

.. code-block:: java

   /* SIDL */
   int get_value_ptr(in string name, out array<> dest_ptr);

The `get_value_ptr` function takes a variable name and returns a reference
to a variable.
Unlike the buffer returned from :ref:`get_value`,
the reference always points to the current values of the variable,
even if the model's state has changed.

**Implementation notes**

* The reference points to a flattened array.
* In C++, the *dest_ptr* argument is omitted, and the reference is
  returned through the function.
* In Python, a :term:`numpy` array is returned.


.. _get_value_at_indices:

*get_value_at_indices*
......................

.. code-block:: java

   /* SIDL */
   int get_value_at_indices(in string name, in array<> dest, in array<int, 1> inds);

Use the `get_value_at_indices` function to get a copy of a variable's values
at the locations specified by the one-dimensional array indices
in the *inds* argument.
The values are returned through the *dest* argument.

**Implementation notes**

All the notes from :ref:`get_value` apply.
Additionally,

* Both *dest* and *inds* are flattened arrays.
* The *inds* argument is always of type integer.


.. _set_value:

*set_value*
...........

.. code-block:: java

   /* SIDL */
   int set_value(in string name, in array<> src);

The `set_value` function takes a variable name and an array of values,
*src*,
and copies those values into the model's internal array of values,
overwriting the current contents.
The type and size of *src* must match the model's internal array,
and can be determined through
:ref:`get_var_type`, :ref:`get_var_nbytes`, etc.
Recall that arrays are always flattened in BMI,
even if the model uses dimensional variables.

**Implementation notes**

* In Python, *src* is a :term:`numpy` array.
* In C++, `set_value` is a void function.
* Depending on how a model is written, a variable may not be
  accessible until after the call to :ref:`initialize`. Likewise, the
  variable may not be accessible after calling :ref:`finalize`.


.. _set_value_at_indices:

*set_value_at_indices*
......................

.. code-block:: java

   /* SIDL */
   int set_value_at_indices(in string name, in array<int, 1> inds, in array<> src);

Use the `set_value_at_indices` function to set a variable's values
at the locations specified by the one-dimensional array indices
in the *inds* argument.

**Implementation notes**

All the notes from :ref:`set_value` apply.
Additionally,

* Both *src* and *inds* are flattened arrays.
* The *inds* argument is always of type integer.
