The *Basic Model Interface* (BMI) is a library specification
created by the `Community Surface Dynamics Modeling System`_ (CSDMS)
to facilitate the conversion of a model or dataset
into a reusable, plug-and-play component.
Recall that, in this context, an interface is a named set of functions
with prescribed arguments and return values.
The BMI functions make a model self-describing and fully controllable
by a modeling framework or application.
By design, the BMI functions are straightforward to implement in
any language, using only simple data types from standard language libraries.
Also by design, the BMI functions are noninvasive.
This means that a model's BMI does not make calls to other
components or tools and is not modified to use any
framework-specific data structures. A BMI, therefore, introduces no
dependencies into a model, so the model can still be used
in a stand-alone manner.

While a BMI can be written for any language,
CSDMS currently supports four languages:
C, C++, Fortran, and Python.
The specification for each language is given in Table 1,
along with a corresponding example
in which the BMI is implemented.

.. _specs_and_examples:

.. table:: **Table 1:** BMI language specifications.
   :align: center
   :widths: 20, 25, 25, 30

   ========  =============  ==============  ======================
   Language  Specification  Repository      Example
   ========  =============  ==============  ======================
   C         `bmi.h`_       `bmi-c`_        `bmi-example-c`_
   C++       `bmi.hxx`_     `bmi-cxx`_      `bmi-example-cxx`_
   Fortran   `bmi.f90`_     `bmi-fortran`_  `bmi-example-fortran`_ 
   Python    `bmi.py`_      `bmi-python`_   `bmi-example-python`_
   ========  =============  ==============  ======================

A complete description of the functions that make up the BMI is given next.


.. _basic_model_interface:

The Basic Model Interface
=========================

The functions that comprise the Basic Model Interface
can be grouped into categories:

* :ref:`control_funcs`
* :ref:`info_funcs`
* :ref:`var_funcs`
* :ref:`time_funcs`
* :ref:`getter_setter_funcs`
* :ref:`grid_funcs`

Table 2 lists the individual BMI functions
along with a brief description.
Following the table is a detailed description of each function,
including the function prototype in SIDL,
grouped by functional category.

Be sure to check out the collected wisdom of our :ref:`best practices
document <implementation>` for tips on implementing a BMI.

.. table:: **Table 2:** Summary of BMI functions.
   :align: center
   :widths: 30, 70

   ==============================  =========================================
   Function                        Description 
   ==============================  =========================================
   :ref:`initialize`               Perform startup tasks for the model.
   :ref:`update`                   Advance model state by one time step.
   :ref:`update_until`             Advance model state until the given time.
   :ref:`finalize`                 Perform tear-down tasks for the model.
   :ref:`get_component_name`       Name of the model.
   :ref:`get_input_item_count`     Count of a model's input variables.
   :ref:`get_output_item_count`    Count of a model's output variables.
   :ref:`get_input_var_names`      List of a model's input variables.
   :ref:`get_output_var_names`     List of a model's output variables.
   :ref:`get_var_grid`             Get the grid identifier for a variable.
   :ref:`get_var_type`             Get the data type of a variable.
   :ref:`get_var_units`            Get the units of a variable.
   :ref:`get_var_itemsize`         Get the size (in bytes) of one element of a variable.
   :ref:`get_var_nbytes`           Get the total size (in bytes) of a variable.
   :ref:`get_var_location`         Get the grid element type of a variable.
   :ref:`get_current_time`         Current time of the model.
   :ref:`get_start_time`           Start time of the model.
   :ref:`get_end_time`             End time of the model.
   :ref:`get_time_units`           Time units used in the model.
   :ref:`get_time_step`            Time step used in the model.
   :ref:`get_value`                Get a copy of values of a given variable.
   :ref:`get_value_ptr`            Get a reference to the values of a given variable.
   :ref:`get_value_at_indices`     Get variable values at specific locations.
   :ref:`set_value`                Set the values of a given variable.
   :ref:`set_value_at_indices`     Set the values of a variable at specific locations.
   :ref:`get_grid_rank`            Get the number of dimensions of a computational grid.
   :ref:`get_grid_size`            Get the total number of elements of a computational grid.
   :ref:`get_grid_type`            Get the grid type as a string.
   :ref:`get_grid_shape`           Get the dimensions of a computational grid.
   :ref:`get_grid_spacing`         Get the spacing between grid nodes.
   :ref:`get_grid_origin`          Get the origin of a grid.
   :ref:`get_grid_x`               Get the locations of a grid's nodes in dimension 1.
   :ref:`get_grid_y`               Get the locations of a grid's nodes in dimension 2.
   :ref:`get_grid_z`               Get the locations of a grid's nodes in dimension 3.
   :ref:`get_grid_node_count`      Get the number of nodes in the grid.
   :ref:`get_grid_edge_count`      Get the number of edges in the grid.
   :ref:`get_grid_face_count`      Get the number of faces in the grid.
   :ref:`get_grid_edge_nodes`      Get the edge-node connectivity.
   :ref:`get_grid_face_edges`      Get the face-edge connectivity.
   :ref:`get_grid_face_nodes`      Get the face-node connectivity.
   :ref:`get_grid_nodes_per_face`  Get the number of nodes for each face.
   ==============================  =========================================

.. include:: bmi.control_funcs.rst
.. include:: bmi.info_funcs.rst
.. include:: bmi.var_funcs.rst
.. include:: bmi.time_funcs.rst
.. include:: bmi.getter_setter.rst
.. include:: bmi.grid_funcs.rst


..
   Links

.. _Community Surface Dynamics Modeling System: https://csdms.colorado.edu
.. _bmi.h: https://github.com/csdms/bmi-c/blob/master/bmi.h
.. _bmi.hxx: https://github.com/csdms/bmi-cxx/blob/master/bmi.hxx
.. _bmi.f90: https://github.com/csdms/bmi-fortran/blob/master/bmi.f90
.. _bmi.py: https://github.com/csdms/bmi-python/blob/master/bmipy/bmi.py
.. _bmi-c: https://github.com/csdms/bmi-c
.. _bmi-cxx: https://github.com/csdms/bmi-cxx
.. _bmi-fortran: https://github.com/csdms/bmi-fortran
.. _bmi-python: https://github.com/csdms/bmi-python
.. _bmi-example-c: https://github.com/csdms/bmi-example-c
.. _bmi-example-cxx: https://github.com/csdms/bmi-example-cxx
.. _bmi-example-fortran: https://github.com/csdms/bmi-example-fortran
.. _bmi-example-python: https://github.com/csdms/bmi-example-python
.. _UDUNITS: http://www.unidata.ucar.edu/software/udunits/
.. _The Units Database: https://www.unidata.ucar.edu/software/udunits/udunits-current/doc/udunits/udunits2.html#Database
.. _time unit conventions: https://www.unidata.ucar.edu/software/udunits/udunits-current/udunits/udunits2-accepted.xml
