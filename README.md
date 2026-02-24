![[License: MIT][license-link]][license-badge]
![[DOI][doi-link]][doi-badge]
![[Documentation][rtd-link]][rtd-badge]
![[JOSS Article][joss-link]][joss-badge]

[doi-badge]: https://zenodo.org/badge/DOI/10.5281/zenodo.3955010.svg
[doi-link]: https://doi.org/10.5281/zenodo.3955009
[license-badge]: https://img.shields.io/badge/License-MIT-yellow.svg
[license-link]: https://opensource.org/licenses/MIT
[rtd-badge]: https://readthedocs.org/projects/bmi/badge/?version=stable
[rtd-link]: https://bmi.readthedocs.io/en/stable
[joss-badge]: https://joss.theoj.org/papers/10.21105/joss.02317/status.svg
[joss-link]: https://doi.org/10.21105/joss.02317

# The Basic Model Interface


---

The Basic Model Interface (BMI) is a standardized set of functions
that allows coupling of models to models and models to data.

---


The *Basic Model Interface* (BMI),
developed by the [Community Surface Dynamics Modeling System] (CSDMS),
is a standardized set of control and query functions that,
when added to a software element such as a model or a dataset,
makes that software easier to couple with other software that also exposes a BMI.

A BMI makes a model self-describing and fully controllable
by a modeling framework or application.
By design, the BMI functions are straightforward to implement in
any language, using basic data types from standard language libraries.
Also by design, the BMI functions are noninvasive.
This means that a model's BMI does not make calls to other
components or tools and is not modified to use any
framework-specific data structures. A BMI, therefore, introduces no
dependencies into a model, so the model can still be used
in a stand-alone manner.

The BMI is expressed
in the [Scientific Interface Definition Language] (SIDL).
From [bmi.sidl](./bmi.sidl),
CSDMS has derived BMI specifications
for five languages--C, C++, Fortran, Java,
and Python.
For each language,
links to the specification and an example implementation
are listed in the table below.

| Language | Specification | Example implementation |
| -------- | ------------- | ---------------------- |
| C        | [bmi-c]       | [bmi-example-c]        |
| C++      | [bmi-cxx]     | [bmi-example-cxx]      |
| Fortran  | [bmi-fortran] | [bmi-example-fortran]  |
| Java     | [bmi-java]    | [bmi-example-java]     |
| Python   | [bmi-python]  | [bmi-example-python]   |
| R        | [bmi-r]       | [bmi-example-r]        |

Detailed instructions for building the specifications and examples
are given at each link above.
Alternatively, the specifications can be installed through conda
(C, C++, Fortran, Python) or Maven (Java).
See the links above for details.

While CSDMS currently supports the languages listed above,
a BMI specification can be written for any language.
BMI is a community-driven standard;
[contributions](CONTRIBUTING.rst)
that follow the [contributor code of conduct](./CODE-OF-CONDUCT.rst)
are welcomed,
and are [acknowledged](./AUTHORS.rst).

The table below lists community-contributed
language specifications and examples
for Javascript and Julia.

| Language   | Specification | Example implementation |
| ---------- | ------------- | ---------------------- |
| Javascript | [bmi-js]      | [bmi-example-js]       |
| Julia      | [bmi-julia]   | [bmi-example-julia]    |

The default branch of this repository
reflects the current state of development for the BMI.
When implementing a BMI,
please use the [latest release] listed in the right sidebar;
currently this is [Basic Model Interface 2.0].
For more information on implementing a BMI,
see the [documentation].

BMI is open source software released under the [MIT License](./LICENSE.md).
BMI is an element of the [CSDMS Workbench],
an integrated system of software tools, technologies, and standards
for building and coupling models.

*The Community Surface Dynamics Modeling System
is supported by the National Science Foundation.*

<!-- Links -->

[basic model interface 2.0]: https://github.com/csdms/bmi/releases/tag/v2.0
[bmi-c]: https://github.com/csdms/bmi-c
[bmi-cxx]: https://github.com/csdms/bmi-cxx
[bmi-example-c]: https://github.com/csdms/bmi-example-c
[bmi-example-cxx]: https://github.com/csdms/bmi-example-cxx
[bmi-example-fortran]: https://github.com/csdms/bmi-example-fortran
[bmi-example-java]: https://github.com/csdms/bmi-example-java
[bmi-example-js]: https://github.com/uihilab/bmi-example-js
[bmi-example-julia]: https://github.com/csdms/bmi-example-julia
[bmi-example-python]: https://github.com/csdms/bmi-example-python
[bmi-example-r]: https://github.com/csdms/bmi-example-r
[bmi-fortran]: https://github.com/csdms/bmi-fortran
[bmi-java]: https://github.com/csdms/bmi-java
[bmi-js]: https://github.com/uihilab/bmi-js
[bmi-julia]: https://github.com/Deltares/BasicModelInterface.jl
[bmi-python]: https://github.com/csdms/bmi-python
[bmi-r]: https://github.com/csdms/bmi-r
[community surface dynamics modeling system]: https://csdms.colorado.edu
[csdms workbench]: https://csdms.colorado.edu/wiki/Workbench
[documentation]: https://bmi.readthedocs.io
[latest release]: https://github.com/csdms/bmi/releases
[scientific interface definition language]: https://doi.org/10.1177/1094342011414036
