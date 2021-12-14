.. _best_practices:

BMI best practices
==================

BMI is a simple concept---it's just a set of functions
with rules for the function names, arguments, and returns.
However, when implementing a BMI, the devil is often in the details.
In no particular order,
here are some tips to help when writing a BMI for a model.

* All functions in the BMI must be implemented. For example, even if a
  model operates on a :ref:`uniform rectilinear <uniform_rectilinear>`
  grid, a :ref:`get_grid_x` function has to be written. This function
  can be empty and simply return the ``BMI_FAILURE`` status code or
  raise a ``NotImplemented`` exception, depending on the language.

* The :ref:`BMI functions <basic_model_interface>` listed in the
  documentation are the minimum required. Optional functions that act
  as helpers can be added to a model's BMI. For example, an
  `update_frac` function that updates a model's state by a fractional
  time step is a common addition to a BMI.

* Implementation details are left up to the model developer. All that
  the BMI specifies are the names of the functions, their arguments,
  and their return values.

* :term:`Standard Names` are not required for naming a model's
  :term:`exchange items <exchange item>`. However, the use of
  standardized names makes it easier for a framework (or a human) to
  match input and output variables between models.

* Don't change the variable names for exchange items 
  you currently use within your model
  to :term:`Standard Names`. Instead, find a
  `matching`_ Standard Name for each variable and then
  write your BMI functions to accept the Standard Names and map them
  to your model's internal names.

* Constructs and features that are natural for the language should be
  used when implementing a BMI. BMI strives to be developer-friendly.

* BMI functions always use flattened, one-dimensional arrays. This
  avoids any issues stemming from row/column-major indexing when
  coupling models written in different languages. It's the developer's
  responsibility to ensure that array information is
  flattened/redimensionalized in the correct order.

* Recall that models can have mulitple grids. This can be particularly
  useful for defining :term:`exchange items <exchange item>` that
  don't vary over the model domain; e.g., a diffusivity -- just define
  the variable on a separate :ref:`scalar grid <unstructured_grids>`.

* Avoid using global variables, if possible. This isn't strictly a BMI
  requirement, but if a model only uses local variables, its BMI will
  be self-contained. This may allow multiple instances of the model to
  be run simultaneously, possibly permitting the model to be coupled
  with itself.

* Boundary conditions, including boundary conditions that change with
  the model state, can be represented with :term:`exchange items
  <exchange item>`.

* :term:`Configuration files <configuration file>` are typically text
  (e.g., `YAML`_ is preferred by CSDMS), but this isn't a strict
  requirement; binary data models such as `HDF5`_ and `netCDF`_ also
  work well for storing configuration data.

* Before fitting a model with a BMI, the model code may have to be
  :term:`refactored <refactor>` into modular *initialize-run-finalize*
  (IRF) steps in order to interact with the BMI functions. This is often
  the most difficult part of adding a BMI, but the modularization
  tends to improve the quality of the code.

* Avoid allocating memory within a BMI function. Memory allocation is
  typically the responsibility of the model. This helps keep the BMI
  middleware layer thin.

* Be sure to check out the examples: `C`_, `C++`_, `Fortran`_, `Java`_, `Python`_.
  Although they wrap a very simple model, they give useful insights into how a
  BMI can be implemented in each language.

* Return codes (C and Fortran) and exceptions (C++, Java, and Python) can help with
  debugging a BMI, and can provide useful information to a user.

.. Links:

.. _YAML: https://yaml.org/
.. _HDF5: https://www.hdfgroup.org/solutions/hdf5/
.. _netCDF: https://www.unidata.ucar.edu/software/netcdf/
.. _C: https://github.com/csdms/bmi-example-c
.. _C++: https://github.com/csdms/bmi-example-cxx
.. _Fortran: https://github.com/csdms/bmi-example-fortran
.. _Java: https://github.com/csdms/bmi-example-java
.. _Python: https://github.com/csdms/bmi-example-python
.. _matching: https://github.com/csdms/standard_names_registry
