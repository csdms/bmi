---
title: "The Basic Model Interface 2.0: A standard interface for coupling numerical models in the geosciences"
tags:
  - C
  - C++
  - Fortran
  - Python
  - geosciences
  - modeling
  - interface
authors:
  - name: Eric W.H. Hutton
    orcid: 0000-0002-5864-6459
    affiliation: 1
  - name: Mark D. Piper
    orcid: 0000-0001-6418-277X
    affiliation: 1
  - name: Gregory E. Tucker
    orcid: 0000-0003-0364-5800
    affiliation: 1, 2, 3
affiliations:
  - name: Community Surface Dynamics Modeling System, University of Colorado Boulder, USA
    index: 1
  - name: Cooperative Institute for Research in Environmental Sciences (CIRES), University of Colorado Boulder, USA
    index: 2
  - name: Department of Geological Sciences, University of Colorado Boulder, USA
    index: 3
date: 10 January 2020
bibliography: paper.bib

---

# Summary

Component modeling is a research technique
in which new models are constructed by coupling the inputs and outputs
of simpler existing models. 
Component modeling traces its roots
to component-based software engineering,
where a software system is constructed from a number
of independent, reusable software components,
each encapsulating a unit of functionality
and exposing inputs and outputs through an interface.
A tangible analogy is a bicycle.
A bicycle is a system of reusable, replaceable components.
Tires are one of the components.
You can easily swap in a studded tire for icy winter streets,
then swap it out again in the summer.

While there is a longer history of component modeling
in fields such as climate modeling,
with, for example, the Earth System Modeling Framework [@collins:2005],
component modeling is relatively new
to the earth surface processes community.
Some recent examples include
@ratliff:2018, who show that a river model transporting sediment
can feed a delta model that distributes the sediment,
and @hoch:2019, who show that coupling hydrologic and hydrodynamic models
may sharpen inundation estimates in flood modeling.

In component-based software engineering,
components communicate through interfaces:
named sets of functions with prescribed arguments and return values.
The bicycle analogy above benefits from a standard interface
for tire diameter and width.
Likewise,
component modeling can benefit from an interface
for describing the inputs, outputs, and behaviors of a model.
The *Basic Model Interface* (BMI)
provides a standard set of functions
for querying, modifying, and running a model.
Equipping a model with a BMI
allows the model to be coupled with other models that expose a BMI.
The BMI concept was introduced by @peckham:2013
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
[@epperly:2012].
BMI specifications for four languages---C, C++, Fortran, and Python---have
been derived from the SIDL specification.
For each language,
links to the GitHub repositories supplying the specification
and an example implementation are listed in Table 1 below.
Detailed instructions for building the language specification and example
are given within each repository.

\  

**Table 1:**
Repositories containing BMI language specifications and examples.
Prefix the CSDMS GitHub organization (https://github.com/csdms/) to the
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

While CSDMS currently supports the four languages listed in Table 1,
a BMI can be created for any language.
BMI is a community-driven standard;
contributions that follow the contributor code of conduct
listed in the main BMI repository are welcomed,
and are acknowledged in the repository and the documentation.

# Acknowledgements

This work is supported by the National Science Foundation
under Grant No. 1831623, *Community Facility Support: The
Community Surface Dynamics Modeling System (CSDMS)*.

# References
