.. _implementation_comments:

Comments on implementing a BMI
==============================

.. todo::

   The following is intended to be a compilation of BMI best practices.
   It's just a sketch rn.

BMI is a simple concept,
but when implementing a BMI,
the devil is often in the details.
Here are some tips to help when writing a BMI for a model.

* All functions in the BMI must be implemented. Stub, at least. Return
  BMI_FAILURE or raise NotImplemted exception.
* The BMI method listed are the minimum required. You can have
  additional methods that help. E.g., `update_frac` is common.
* Implementation details are up to the model developer. All that the
  BMI specifies are the names of the functions their arguments and
  return values.
* Use constructs that are natural for the language. We don’t want to
  scare away developers.
* Flattened arrays. Avoid row/column-major indexing issues. 
* Re-factor into IRF.
* Don’t use global variables.
* It’s OK to have a config file be a binary format file like HDF5 or
  netCDF, but it’s preferred to use a text based config file like YAML.
* Boundary conditions can be handled with standard names.
