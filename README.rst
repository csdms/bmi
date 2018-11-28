.. image:: https://readthedocs.org/projects/bmi-spec/badge/?version=latest
        :target: https://bmi-spec.readthedocs.io/en/latest/?badge=latest
        :alt: Documentation Status

The Basic Model Interface
=========================

Documentation: https://bmi-spec.readthedocs.io

License: MIT

Summary: The Basic Model Interface (BMI) is a library specification to
simplify the coupling of models.

.. image:: docs/source/images/bmi_logo_small.png
   :scale: 10 %
   :align: right
   :alt: The Basic Model Interface


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

Scott D. Peckham, Eric W.H. Hutton, Boyana Norris, A component-based approach to integrated modeling in the geosciences: The design of CSDMS, Computers & Geosciences, Volume 53, April 2013, Pages 3-12, ISSN 0098-3004, http://dx.doi.org/10.1016/j.cageo.2012.04.002.

Full article:

http://www.sciencedirect.com/science/article/pii/S0098300412001252

The most current development version is always available from our git repository:

http://github.com/csdms/bmi
