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

   <a href='https://doi.org/10.5281/zenodo.3955009'>
     <img src='https://zenodo.org/badge/DOI/10.5281/zenodo.3955010.svg' alt='DOI'></a>
   <a href="https://doi.org/10.21105/joss.02317">
     <img src="https://joss.theoj.org/papers/10.21105/joss.02317/status.svg" alt="JOSS article"></a>
   <a href='https://bmi.readthedocs.io/en/latest/?badge=latest'>
     <img src='https://readthedocs.org/projects/bmi/badge/?version=latest' alt='Documentation Status'></a>
   <a href="https://opensource.org/licenses/MIT">
     <img alt="License: MIT" src="https://img.shields.io/badge/License-MIT-yellow.svg"></a>

   </p>

   <p align="center">

   The Basic Model Interface (BMI) is a standardized set of functions
   that allows coupling of models to models and models to data.

   </p>

The *Basic Model Interface* (BMI) is a library specification
created by the `Community Surface Dynamics Modeling System`_ (CSDMS)
to facilitate the conversion of a model or dataset
into a reusable, plug-and-play component.
Recall that in this context an interface is a named set of functions
with prescribed arguments and return values.
The BMI functions make a model self-describing and fully controllable
by a modeling framework or application.
By design, the BMI functions are straightforward to implement in
any language, using only basic data types from standard language libraries.
Also by design, the BMI functions are noninvasive.
This means that a model's BMI does not make calls to other
components or tools and is not modified to use any
framework-specific data structures. A BMI, therefore, introduces no
dependencies into a model, so the model can still be used
in a stand-alone manner.

The BMI is expressed
in the `Scientific Interface Definition Language`_ (SIDL)
in the file `bmi.sidl <./bmi.sidl>`_.
BMI specifications for five languages -- C, C++, Fortran, Java,
and Python -- are derived from this SIDL file.
For each language,
links to the specification and an example implementation
are listed in the table below.

.. table::
   :align: center
   :widths: 10, 10, 15

   ========  ==============  ======================
   Language  Specification   Example implementation
   ========  ==============  ======================
   C         `bmi-c`_        `bmi-example-c`_
   C++       `bmi-cxx`_      `bmi-example-cxx`_
   Fortran   `bmi-fortran`_  `bmi-example-fortran`_
   Java      `bmi-java`_     `bmi-example-java`_
   Python    `bmi-python`_   `bmi-example-python`_
   ========  ==============  ======================

Detailed instructions for building the specifications and examples
are given at each link above.

While CSDMS currently supports the languages listed above,
a BMI can be written for any language.
BMI is a community-driven standard;
`contributions <CONTRIBUTING.rst>`_
that follow the `contributor code of conduct <./CODE-OF-CONDUCT.rst>`_
are welcomed,
and are `acknowledged <./AUTHORS.rst>`_.
BMI is open source software released under the `MIT License <./LICENSE>`_.
BMI is an element of the `CSDMS Workbench`_,
an integrated system of software tools, technologies, and standards
for building and coupling models.

*The Community Surface Dynamics Modeling System
is supported by the National Science Foundation.*


.. Links

.. _Community Surface Dynamics Modeling System: https://csdms.colorado.edu
.. _Scientific Interface Definition Language: http://dx.doi.org/10.1177/1094342011414036
.. _bmi-c: https://github.com/csdms/bmi-c
.. _bmi-cxx: https://github.com/csdms/bmi-cxx
.. _bmi-fortran: https://github.com/csdms/bmi-fortran
.. _bmi-java: https://github.com/csdms/bmi-java
.. _bmi-python: https://github.com/csdms/bmi-python
.. _bmi-example-c: https://github.com/csdms/bmi-example-c
.. _bmi-example-cxx: https://github.com/csdms/bmi-example-cxx
.. _bmi-example-fortran: https://github.com/csdms/bmi-example-fortran
.. _bmi-example-java: https://github.com/csdms/bmi-example-java
.. _bmi-example-python: https://github.com/csdms/bmi-example-python
.. _CSDMS Workbench: https://csdms.colorado.edu/wiki/Workbench
