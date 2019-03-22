.. _cmf:

The CSDMS Modeling Framework
============================

Any model that provides the BMI functions can be easily converted
to a CSDMS plug-and-play component within the CSDMS Modeling
Framework (CMF).  This conversion/wrapping process can be done
automatically using the CSDMS Babelizer tool, which generates
bindings for all of the CSDMS supported languages, so that the
model becomes a plug-in for within the CSDMS framework.

Any model that provides the BMI functions should also be
straightforward to ingest as a component into other component-based
modeling frameworks.  For example, all model coupling frameworks
use Model Control Functions very similar to those of the BMI,
so providing them helps get a model ready for *plug-and-play* into
any framework.

Within the CMF, a component automatically gains many
new capabilities. This includes the ability to be coupled to
other models even if their (1) programming language, (2) variable
names, (3) variable units, (4) time-stepping scheme or (5)
computational grid is different.  It also gains:

* the ability to write output variables to standardized NetCDF
  files,
* a graphical user interface (GUI),
* unit conversion tools,
* time interpolation


CSDMS Standard Names
====================

Note that the *name* parameter in many of the BMI functions
refers to a standardized variable name from the
`CSDMS_Standard_Names <http://csdms.colorado.edu/wiki/CSDMS_Standard_Names>`_.
These names are not *required* by the BMI to be CSDMS Standard Names,
however, the use of standardized names makes it possible for a
framework (or a human) to more easily match components' input and
output variables.

.. note:

  Note you **do not** change the variable names that you currently
  use within your model.  The standard names are too long to be
  used within your model code.  Instead, you find a matching CSDMS
  Standard Name for each variable in your model and then write your
  BMI functions to accept the standard names and map them to your
  model's internal names.


Model Metadata
==============

For a model to be incorporated into the CSDMS framework, some additional
metadata is required. This metadata describes such things as:

*  The model author(s), license, description, web page, etc.
*  How the model is built and how it can be linked
*  Template input files
*  Description of input parameters (description, units, ranges, etc.)
