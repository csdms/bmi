---
title: "The Basic Model Interface 2.0: A standard interface for coupling numerical models and data in the geosciences"
tags:
  - C
  - C++
  - Fortran
  - Python
  - modeling
  - interface
authors:
  - name: Eric Hutton
    orcid: 0000-0002-5864-6459
    affiliation: 1
  - name: Mark Piper
    orcid: 0000-0001-6418-277X
    affiliation: 1
  - name: Greg Tucker
    orcid: 0000-0003-0364-5800
    affiliation: 1, 2
affiliations:
  - name: Community Surface Dynamics Modeling System, University of Colorado Boulder
    index: 1
  - name: Cooperative Institute for Research in Environmental Sciences, University of Colorado Boulder
    index: 2
date: 10 January 2020
bibliography: paper.bib

---

# Summary

Component modeling,
in which a new model is created by coupling the inputs and outputs
of existing numerical models,
is a research technique gaining adoption in Earth-surface process research.
For example,
`@ratliff:2018`
show that a river model transporting sediment
can feed a delta model, which distributes the sediment,
while `@hoch:2019` show that coupling hydrologic and hydrodynamic models
may sharpen inundation estimate in flood modeling.

In software engineering,
an interface is a named set of functions
with prescribed arguments and return values.
The *Basic Model Interface* (BMI)
provides a standard set of functions
for querying, modifying, and running a model or tool.
Equipping a model with a BMI
allows the model to be coupled with other models that expose a BMI.
The BMI concept was introduced by `@peckham:2013`
as a foundational technology for the proposed
[Community Surface Dynamics Modeling System](https://csdms.colorado.edu)
(CSDMS)
model coupling framework.
The current work represents an update to the original BMI,
with new functions for describing variables
and for working with structured and unstructured grids.
Full documentation for the current version of the BMI
is available at https://bmi.readthedocs.io.

The functions that comprise the BMI are designed
to be straightforward to implement in any programming language,
using only simple data types from standard language libraries.
To generalize across languages,
the BMI is expressed in the Scientific Interface Definition Language
`[@epperly:2012]`.
BMI specifications for four languages---C, C++, Fortran, and Python---have
been derived from the SIDL specification.
For each language,
links to the GitHub repositories supplying the specification
and an example implementation are listed in Table 1 below.

**Table 1:**
Repositories containing BMI language specifications and examples.
Prefix the CSDMS GitHub organization (https://github.com/csdms) to the
repository name to obtain the full repository URL.

| Language | Specification | Example implementation |
| -------- | ------------- | ---------------------- |
| C        | [bmi-c]       | [bmi-example-c]        |
| C++      | [bmi-cxx]     | [bmi-example-cxx]      |
| Fortran  | [bmi-fortran] | [bmi-example-fortran]  |
| Python   | [bmi-python]  | [bmi-example-python]   |

[bmi-c]: https://github.com/csdms/bmi-c
[bmi-cxx]: https://github.com/csdms/bmi-cxx
[bmi-fortran]: https://github.com/csdms/bmi-fortran
[bmi-python]: https://github.com/csdms/bmi-python
[bmi-example-c]: https://github.com/csdms/bmi-example-c
[bmi-example-cxx]: https://github.com/csdms/bmi-example-cxx
[bmi-example-fortran]: https://github.com/csdms/bmi-example-fortran
[bmi-example-python]: https://github.com/csdms/bmi-example-python

Detailed instructions for building the language specification and example
are given within each repository.

While CSDMS currently supports the four languages listed in Table 1,
a BMI can be created for any language.
BMI is a community-driven standard;
contributions that follow the contributor code of conduct are welcomed,
and are acknowledged in the repository and the documentation.

# Acknowledgements

This work is supported by the National Science Foundation
under Grant No. 1831623, *Community Facility Support: The
Community Surface Dynamics Modeling System (CSDMS)*.

# References
