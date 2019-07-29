.. role:: raw-html-m2r(raw)
   :format: html


.. raw:: html

   <p align="center">
      <a href='https://bmi.readthedocs.org/'>
         <img src='https://github.com/csdms/bmi/raw/master/docs/source/_static/bmi-logo-header-text.png'/>
      </a>
   </p>

.. raw:: html

   <h2 align="center">The Basic Model Interface</h2>



.. raw:: html

   <p align="center">

   <a href='https://bmi.readthedocs.io/en/latest/?badge=latest'>
     <img src='https://readthedocs.org/projects/bmi/badge/?version=latest' alt='Documentation Status'></a>
   <a href="https://opensource.org/licenses/MIT">
     <img alt="License: MIT" src="https://img.shields.io/badge/License-MIT-yellow.svg"></a>

   </p>

   <p align="center">

   The Basic Model Interface (BMI) is a library specification to
   simplify the coupling of models.

   </p>

In order to simplify conversion of an existing model to a reusable,
plug-and-play model component, the
`Community Surface Dynamics Modeling System <https://csdms.colorado.edu>`_
(CSDMS) has developed a simple
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

The most current development version is always available from our git repository:
http://github.com/csdms/bmi.

Please note that this project is released with a
`Contributor Code of Conduct <./CODE-OF-CONDUCT.rst>`_.
By participating in this project you agree to abide by its terms.
