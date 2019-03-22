In order to simplify conversion of an existing model to a reusable,
plug-and-play model component, CSDMS has developed a simple
interface called the *Basic Model Interface* or *BMI* that model
developers are asked to implement.  Recall that in this
context an *interface* is a named set of functions with prescribed
function names, argument types and return types.  The BMI functions
make the model *self-describing* and fully *controllable* by a
modeling framework or application.

By design, the BMI functions are straightforward to implement in
any language and use only simple (universal) data types. While the
CSDMS model coupling framework supports C, C++, Fortran, Java,
and Python, a BMI can described for any language.  CSDMS
provides example bindings for BMI in each of the above languages.

Also by design, the BMI functions are *noninvasive*.  This means
that a BMI-compliant model does not make any calls to other
components or tools and is not modified to use any
framework-specific data structures. BMI therefore introduces no
dependencies into a model and the model can still be used
in a *stand-alone* manner.

.. toctree::
   :maxdepth: 1

   bmi.control_funcs
   bmi.info_funcs
   bmi.time_funcs
   bmi.var_funcs
   bmi.getter_setter
   bmi.grid_funcs
