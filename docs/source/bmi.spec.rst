The *Basic Model Interface* (BMI) is a library specification
created by the `Community Surface Dynamics Modeling System`_ (CSDMS)
to facilitate the conversion of a model or dataset
into a reusable, plug-and-play component.
Recall that, in this context, an interface is a named set of functions
with prescribed arguments and return values.
The BMI functions make a model self-describing and fully controllable
by a modeling framework or application.
By design, the BMI functions are straightforward to implement in
any language, using only simple data types from standard language libraries.
Also by design, the BMI functions are noninvasive.
This means that a model's BMI does not make calls to other
components or tools and is not modified to use any
framework-specific data structures. A BMI, therefore, introduces no
dependencies into a model, so the model can still be used
in a stand-alone manner.

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
