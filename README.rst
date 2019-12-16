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

To simplify the transformation of an existing model
into a reusable, plug-and-play component,
the `Community Surface Dynamics Modeling System`_ (CSDMS)
has developed an interface -- the *Basic Model Interface (BMI)* -- that
a developer can implement for a model.
Recall that in this context an *interface* is a named set of functions
with prescribed names, argument types, and return types.
The BMI functions make a model *self-describing* and fully *controllable*
by a modeling framework or application.
By design, the BMI functions are straightforward to implement in
any language, using only simple data types from standard language libraries.
Also by design, the BMI functions are *noninvasive*.
This means that a model's BMI does not make calls to other
components or tools and is not modified to use any
framework-specific data structures. A BMI, therefore, introduces no
dependencies into a model, meaning the model can still be used
in a *stand-alone* manner.

The BMI is expressed in the file `bmi.sidl <./bmi.sidl>`_
using the `Scientific Interface Definition Language`_ (SIDL).
BMIs for four languages -- C, C++, Fortran (77, 90/95, 03, 08),
and Python -- are derived from this SIDL file.
Links to the bindings and a working example
for each language are listed in the table below.

.. table:: BMI language bindings and examples
   :align: center
   :widths: 10, 10, 10

   ========  ==============  ======================
   Language  Binding         Example
   ========  ==============  ======================
   C         `bmi-c`_        `bmi-example-c`_
   C++       `bmi-cxx`_      `bmi-example-cxx`_
   Fortran   `bmi-fortran`_  `bmi-example-fortran`_
   Python    `bmi-python`_   `bmi-example-python`_
   ========  ==============  ======================


Detailed instructions for building the bindings and examples
are given at each link above.
The bindings can be installed through `conda`.

.. code-block:: bash

   $ conda install -c conda-forge bmi-c
   $ conda install -c conda-forge bmi-cxx
   $ conda install -c conda-forge bmi-fortran
   $ conda install -c conda-forge bmipy

While CSDMS currently supports the four languages
listed in the table above,
a BMI can be described for any language,
and contributions are welcomed.

Please note that this project is released with a
`Contributor Code of Conduct <./CODE-OF-CONDUCT.rst>`_.
By participating in this project you agree to abide by its terms.

The Community Surface Dynamics Modeling System
is supported by the National Science Foundation.


.. Links

.. _Community Surface Dynamics Modeling System: https://csdms.colorado.edu
.. _Scientific Interface Definition Language: http://dx.doi.org/10.1177/1094342011414036
.. _bmi-c: https://github.com/csdms/bmi-c
.. _bmi-cxx: https://github.com/csdms/bmi-cxx
.. _bmi-fortran: https://github.com/csdms/bmi-fortran
.. _bmi-python: https://github.com/csdms/bmi-python
.. _bmi-example-c: https://github.com/csdms/bmi-example-c
.. _bmi-example-cxx: https://github.com/csdms/bmi-example-cxx
.. _bmi-example-fortran: https://github.com/csdms/bmi-example-fortran
.. _bmi-example-python: https://github.com/csdms/bmi-example-python
