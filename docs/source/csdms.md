(pymt)=

# BMI-based tools: *babelizer* and *pymt*

A model that provides the BMI functions can be converted
to a plug-and-play component
that runs in the CSDMS [Python Modeling Toolkit] (*pymt*).
This conversion process can be done
automatically with the CSDMS [Babelizer], which generates
a Python package from models written in
C, C++, Fortran, and Python.
Some additional metadata is required,
describing such things as:

- the model author(s), license, description, web page, etc.
- how the model is built and how it can be linked
- template input files
- description of input parameters (description, units, ranges, etc.)

Within *pymt*, a component automatically gains many
new capabilities. This includes the ability to be coupled to
other models even if their programming language, variable
names, variable units, time-stepping scheme or
computational grid is different.  It also gains:

- the ability to write output variables to standardized NetCDF
  files,
- unit conversion tools,
- time interpolation,
- all the data analysis and visualization tools available in Python,
- the ability to run in a Jupyter Notebook

If you have a model with a BMI,
and would like to componentize it and add it to *pymt*,
please contact us through the [CSDMS Help Desk].
We'd be happy (and excited) to help!

% Links:

[babelizer]: https://babelizer.readthedocs.io
[csdms help desk]: https://github.com/csdms/help-desk
[python modeling toolkit]: https://pymt.readthedocs.io
