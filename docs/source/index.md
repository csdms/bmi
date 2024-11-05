# The Basic Model Interface

When you climb in the driver's seat of an unfamiliar car,
you are nonetheless presented with a familiar sight.
Whatever the make or model may be,
we take it for granted that the vehicle will provide
a steering wheel, brake pedal, and speedometer,
alongside the various other controls and readouts
that are common to essentially all cars and trucks on the planet.
Although we don't usually think of it this way,
drivers across the globe benefit from a standard interface:
a set of control mechanisms and information displays
that have essentially the same design regardless of whether the vehicle
is a tiny electric two-seater or a giant stretch limousine.
This standard interface makes the job of operating a vehicle much easier
than it would be if each one presented a radically different interface.
Imagine a world where switching from a sports car to a pickup truck
required months of study and practice!
Similarly, railroads benefit from a standard for coupling rail cars together.
The result: trains can be assembled from combinations of all sorts
of different rail cars, built by different companies,
in different places, and with different purposes.

We believe that numerical models,
and the sub-components that make up those models,
should offer a similar kind of standardization.
To this end,
the [Community Surface Dynamics Modeling System] (CSDMS)
has developed the *Basic Model Interface* (BMI):
a set of standard control and query functions that,
when added to a model code,
make that model both easier to learn
and easier to couple with other software elements.

While a BMI can be written for any language,
CSDMS currently supports five languages:
C, C++, Fortran, Java, and Python.
The specification for each language is given in Table 1,
along with a corresponding example
in which the BMI is implemented.

(specs-and-examples)=

```{eval-rst}
.. table:: **Table 1:** BMI languages.
   :align: center
   :widths: 20, 25, 25, 30

   ========  =============  ==============  ======================
   Language  Specification  Repository      Example
   ========  =============  ==============  ======================
   C         `bmi.h`_       `bmi-c`_        `bmi-example-c`_
   C++       `bmi.hxx`_     `bmi-cxx`_      `bmi-example-cxx`_
   Fortran   `bmi.f90`_     `bmi-fortran`_  `bmi-example-fortran`_
   Java      `bmi.java`_    `bmi-java`_     `bmi-example-java`_
   Python    `bmi.py`_      `bmi-python`_   `bmi-example-python`_
   ========  =============  ==============  ======================
```

BMI is a community standard.
Table 2 lists community-contributed language specifications and examples
for two languages, Javascript and Julia.

```{eval-rst}
.. table:: **Table 2:** Community-contributed BMI languages.
   :align: center
   :widths: 20, 25, 25, 30

   ==========  =============  ============  =====================
   Language    Specification  Repository    Example
   ==========  =============  ============  =====================
   Javascript  `bmi.js`_      `bmi-js`_     `bmi-example-js`_
   Julia       `bmi.jl`_      `bmi-julia`_  `bmi-example-julia`_
   ==========  =============  ============  =====================
```

Along with the examples,
two documents may be particularly helpful when writing a BMI:

- {ref}`Getting Started Guide <getting_started>` --- a place to start
  if you haven't written a BMI before
- {ref}`BMI Best Practices <best_practices>` --- our collected wisdom on
  implementing a BMI

A complete description of the functions that make up the BMI is given next.

```{toctree}
:caption: Getting Started
:hidden: true
:maxdepth: 2

How to <bmi.getting_started>
bmi.best_practices
```

```{toctree}
:caption: Reference
:hidden: true
:maxdepth: 2

BMI Spec <bmi.spec>
model_grids
BMI-based tools <csdms>
glossary
references
```

BMI is an element of the [CSDMS Workbench],
an integrated system of software tools, technologies, and standards
for building and coupling models.

% Help
% ----
%
% Adding a BMI to a model can be a daunting task.
% If you'd like assistance,
% CSDMS can help.
% Depending on your need, we can provide advice or consulting services.
% Feel free to contact us through the `CSDMS Help Desk`_.

```{toctree}
:caption: Contrubuting
:hidden: true
:maxdepth: 1

contributing
Code of Conduct <conduct>
```

```{toctree}
:caption: About
:hidden: true
:maxdepth: 1

citation
credits
Governance <governance>
council
partners
```

```{toctree}
:caption: Project Links
:hidden: true
:maxdepth: 1

Help <https://github.com/csdms/help-desk>
GitHub <https://github.com/csdms/bmi>
Docs <https://bmi.readthedocs.io>
```

% Links:

[bmi-c]: https://github.com/csdms/bmi-c
[bmi-cxx]: https://github.com/csdms/bmi-cxx
[bmi-example-c]: https://github.com/csdms/bmi-example-c
[bmi-example-cxx]: https://github.com/csdms/bmi-example-cxx
[bmi-example-fortran]: https://github.com/csdms/bmi-example-fortran
[bmi-example-java]: https://github.com/csdms/bmi-example-java
[bmi-example-js]: https://github.com/uihilab/bmi-example-js
[bmi-example-julia]: https://github.com/csdms/bmi-example-julia
[bmi-example-python]: https://github.com/csdms/bmi-example-python
[bmi-fortran]: https://github.com/csdms/bmi-fortran
[bmi-java]: https://github.com/csdms/bmi-java
[bmi-js]: https://github.com/uihilab/bmi-js
[bmi-julia]: https://github.com/Deltares/BasicModelInterface.jl
[bmi-python]: https://github.com/csdms/bmi-python
[bmi.f90]: https://github.com/csdms/bmi-fortran/blob/master/bmi.f90
[bmi.h]: https://github.com/csdms/bmi-c/blob/master/bmi.h
[bmi.hxx]: https://github.com/csdms/bmi-cxx/blob/master/bmi.hxx
[bmi.java]: https://github.com/csdms/bmi-java/blob/master/src/main/java/edu/colorado/csdms/bmi/BMI.java
[bmi.jl]: https://github.com/Deltares/BasicModelInterface.jl/blob/master/src/BasicModelInterface.jl
[bmi.js]: https://github.com/uihilab/BMI-JS/blob/main/bmijs/bmi.js
[bmi.py]: https://github.com/csdms/bmi-python/blob/master/src/bmipy/bmi.py
[community surface dynamics modeling system]: https://csdms.colorado.edu
[csdms help desk]: https://github.com/csdms/help-desk
[csdms workbench]: https://csdms.colorado.edu/wiki/Workbench
