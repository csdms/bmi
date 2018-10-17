Model Information Functions
===========================

These BMI functions provide lists of names for the variables that
a model uses (`get_input_var_names`) and provides
(`get_output_var_names`).

Input and output variable names
-------------------------------

.. code-block:: java

  /* SIDL */
  array<string> get_input_var_names();
  array<string> get_output_var_names();

.. code-block:: c

  /* C */
  int get_input_var_name_count(void *handle, int *count);
  int get_output_var_name_count(void *handle, int *count);
  int get_input_var_names(void *handle, char **names);
  int get_output_var_names(void *handle, char **names);

.. code-block:: c++

  /* C++ */
  int GetInputVarNameCount(void);
  int GetOutputVarNameCount(void);
  void GetInputVarNames(char * const * const names);
  void GetOutputVarNames(char * const * const names);

.. code-block:: fortran

   ! Fortran (>=2003)
   function get_input_var_name_count(self, count) result (bmi_status)
   function get_output_var_name_count(self, count) result (bmi_status)
     class (*), intent(in) :: self
     integer, intent(out) :: count
     integer :: bmi_status

   function get_input_var_names(self, names) result (bmi_status)
   function get_output_var_names(self, names) result (bmi_status)
     class (*), intent(in) :: self
     character (len=*), pointer, intent(out) :: names(:)
     integer :: bmi_status


`get_input_var_names` returns a string array of the model's
*input variable* names as, preferably, CSDMS Standard Names.
Likewise `get_output_var_names` returns a string array of the
model's *output variable* names as CSDMS Standard Names.


Component name
--------------

.. code-block:: java

  /* SIDL */
  string get_component_name()

.. code-block:: c

  /* C */
  int get_component_name(void *handle, char * name);

.. code-block:: c++

  /* C++ */
  void GetComponentName(char * const name);

.. code-block:: fortran

   ! Fortran (>=2003)
   function get_component_name(self, name) result (bmi_status)
     class (*), intent(in) :: self
     character (len=*), pointer, intent(out) :: name
     integer :: bmi_status


Return the name of the model as a string. We don't impose any
restrictions on the model name but it should be unique name
so as not to clash with other components.

Model attributes
----------------

.. code-block:: java

  string get_attribute(in string att_name)

.. note:: `get_attribute` is part of BMI++

`get_attribute` returns an attribute value as a string. These
attributes do not change from one model instance to another).
Examples of possible attributes are:

* model_name
* version (e.g. 2.0.1)
* author_name
* grid_type
* time_step_type
* step_method (e.g. explicit, implicit, semi_implicit, iterative)

For the *grid_type* attribute (see ''Grid Information Functions''
below), examples of allowed return values are:

* uniform_grid
* rectilinear_grid
* structured_grid
* unstructured_grid
* none

For the "time_step_type" attribute, examples of allowed return values
are:

* fixed (Timestep size is fixed for all time and is used by all grid cells.)
* adaptive (Timestep varies in time, but is used by all grid cells.)
* des (Timestep size varies in both space and time.  See below.)
* none (State variables do not vary in time.)

Note that DES ([http://en.wikipedia.org/wiki/Discrete_event_simulation
Discrete Event Simulation]) models allow each grid cell to have its
own, adaptive time step.

The "grid_type" attribute can be used by a framework to automatically
perform spatial regridding when coupled models use different grids as
well as to determine which grid control functions are implemented for
the model.

The "time_step_type" attribute and BMI functions like 
`get_time_step` below are used by a framework to automatically
accommodate time step differences between coupled models.

For time-stepping models ("time_step_type" other than "none"), the
"step_method" attribute is used to distinguish between "explicit"
and "implicit" numerical solution schemes.  Some "models" - like
root finders and "successive over relaxation" (SOR) solvers -
involve iterations as opposed to "time steps".  They would return
a "time_step_type" attribute of "none" and a "step_method" attribute
of "iterative".   Note that their `update` function still gives the
caller fine-grained control.

