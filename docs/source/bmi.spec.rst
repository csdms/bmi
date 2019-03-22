The *Basic Model Interface (BMI)* is a simple interface
created by the `Community Surface Dynamics Modeling System`_ (CSDMS)
to facilitate the conversion of a numerical model into a reusable,
plug-and-play component.
A model exposing a BMI can be integrated into
the `CSDMS Python Modeling Toolkit`_ (*pymt*)
and used within Python.

Recall that, in this context,
an *interface* is a named set of functions with prescribed
function names, argument types and return types.  The BMI functions
make a model *self-describing* and fully *controllable* by a
modeling framework or application.

By design, the BMI functions are straightforward to implement in
any language and use only simple, universal, data types. While the
:ref:`cmf`
supports C, C++, Fortran, Java,
and Python, a BMI can be written for any language.  CSDMS
provides `example`_ BMI bindings in each of the above languages.

Also by design, the BMI functions are *noninvasive*.  This means
that a BMI-compliant model does not make any calls to other
components or tools and is not modified to use any
framework-specific data structures. BMI therefore introduces no
dependencies into a model and the model can still be used
in a *stand-alone* manner.

BMI Specification
=================

Detailed descriptions of the BMI functions
are grouped by functional category below.

.. toctree::
   :maxdepth: 1

   bmi.control_funcs
   bmi.info_funcs
   bmi.time_funcs
   bmi.var_funcs
   bmi.getter_setter
   bmi.grid_funcs

..
   Links

.. _Community Surface Dynamics Modeling System: https://csdms.colorado.edu
.. _CSDMS Python Modeling Toolkit: https://pymt.readthedocs.io
.. _example: https://github.com/csdms/bmi/tree/master/bindings
