.. _metadata_funcs:

Model and BMI metadata functions
--------------------------------

These functions supply metadata about a model and its BMI.

.. _get_bmi_version:

*get_bmi_version*
.................

.. code-block:: java

  /* SIDL */
  int get_bmi_version(out string version);

.. versionadded:: 2.1

This function supplies the version of BMI implemented as a string.

**Implementation notes**

* The version must be >=2.1.
* In C and Fortran, the *version* argument is a a character array, and an integer
  status code indicating success (zero) or failure (nonzero) is returned.
* In C++, Java, and Python, this argument is omitted, and a string -- a basic type
  in these languages -- is returned from the function.
* *Parallel*: **TODO**: determine how to flag that a component is MPI aware? Using a BMI extension?

[:ref:`metadata_funcs` | :ref:`basic_model_interface`]
