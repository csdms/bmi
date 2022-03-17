.. _grid_funcs:

Model grid functions
--------------------

The functions in this section describe :ref:`model grids <model_grids>`. 
In the BMI,
every :term:`exchange item` is defined on a grid,
and is referenced by a :term:`grid identifier`
returned from the :ref:`get_var_grid` function.
This identifier is a required input to the functions listed below.

A model can have multiple grids.
For example,
consider modeling the diffusion of temperature over a flat plate.
One grid could be a uniform rectilinear grid on which
temperature is defined.
A second grid could be a scalar,
on which a constant thermal diffusivity is defined.

Not all grid functions are used by each type of grid.
However, all BMI grid functions must be implemented.
(See :ref:`model_grids` and :ref:`best_practices`.)


.. _get_grid_type:

*get_grid_type*
...............

.. code-block:: java

   /* SIDL */
   int get_grid_type(in int grid, out string type);

Given a :term:`grid identifier`, get the type of that grid as a string.
Valid grid types are:

* ``scalar``
* ``points``
* ``vector``
* ``unstructured``
* ``structured_quadrilateral``
* ``rectilinear``
* ``uniform_rectilinear``

A detailed description of the grid types supported in BMI
is given in the :ref:`model_grids` section.

**Implementation notes**

* In C++, Java, and Python, the *type* argument is omitted and the grid
  type name is returned from the function as a string.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_rank:

*get_grid_rank*
...............

.. code-block:: java

   /* SIDL */
   int get_grid_rank(in int grid, out int rank);

Given a :term:`grid identifier`, get the :term:`rank` (the number of
dimensions) of that grid as an integer.

A grid's rank determines the length of the return value
of several grid functions.
For example,
both :ref:`get_grid_shape` and :ref:`get_grid_coordinate_names`
return an array of length *rank*.

**Implementation notes**

* This function is needed for every :ref:`grid type <model_grids>`.
* In C++, Java, and Python, the *rank* argument is omitted and the grid
  rank is returned from the function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_size:

*get_grid_size*
...............

.. code-block:: java

   /* SIDL */
   int get_grid_size(in int grid, out int size);

Given a :term:`grid identifier`,
get the total number of elements (or :term:`nodes <node>`)
of that grid as an integer.

The grid size is used for, among other things, the
length of arrays returned by :ref:`get_grid_coordinate`
for :ref:`unstructured <unstructured_grids>` and
:ref:`structured quad <structured_quad>` grids.

**Implementation notes**

* This function is needed for every :ref:`grid type <model_grids>`.
* In C++, Java, and Python, the *size* argument is omitted and the grid
  size is returned from the function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_shape:

*get_grid_shape*
................

.. code-block:: java

   /* SIDL */
   int get_grid_shape(in int grid, in array<int, 1> shape);

Get the dimensions of the model grid.

Note that this function (as well as the other grid functions)
returns information ordered with "ij" indexing (as opposed to "xy").
For example,
consider a two-dimensional rectilinear grid
with four columns (``nx = 4``)
and three rows (``ny = 3``).
The :ref:`get_grid_shape` function would return a shape
of ``[ny, nx]``, or ``[3,4]``.
If there were a third dimension, the length of the *z*-dimension, ``nz``,
would be listed first.

Also note that the grid shape is the number of :term:`nodes <node>`
in the coordinate directions and not the number of cells or elements.
It is possible for grid values to be associated with the nodes or with
the cells.

**Implementation notes**

* This function is used for describing all :ref:`structured grids
  <structured_grids>`.
* In Python, the *shape* argument is a :term:`numpy <NumPy>` array.
* In C++ and Java, this is a void function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_spacing:

*get_grid_spacing*
..................

.. code-block:: java

   /* SIDL */
   int get_grid_spacing(in int grid, in array<double, 1> spacing);

Get the distance between the :term:`nodes <node>` of the model grid.

The :ref:`get_grid_spacing` function provides the width of each cell in
the number of dimensions as returned by :ref:`get_grid_rank`.
As with :ref:`get_grid_shape`,
the spacing is given in "ij" indexing* order;
e.g., for a two-dimensional grid,
the spacing between rows is followed by spacing between columns, ``[dy, dx]``.

**Implementation notes**

* This function is used for describing :ref:`uniform rectilinear
  <uniform_rectilinear>` grids.
* In Python, the *spacing* argument is a :term:`numpy <NumPy>` array.
* In C++ and Java, this is a void function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_origin:

*get_grid_origin*
.................

.. code-block:: java

   /* SIDL */
   int get_grid_origin(in int grid, in array<double, 1> origin);

Get the coordinates of the lower-left corner of the model grid.

The *origin* parameter is a one-dimensional array of the size
returned by :ref:`get_grid_rank`.
As with :ref:`get_grid_shape`,
the origin is given in "ij" indexing* order;
e.g., for a two-dimensional grid,
the origin is given in the column dimension, followed by the row dimension,
``[y0, x0]``.

**Implementation notes**

* This function is used for describing :ref:`uniform rectilinear
  <uniform_rectilinear>` grids.
* In Python, the *origin* argument is a :term:`numpy <NumPy>` array.
* In C++ and Java, this is a void function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_coordinate_names:

*get_grid_coordinate_names*
...........................

.. code-block:: java

   /* SIDL */
   int get_grid_coordinate_names(in int grid, out array<string, 1> names);

Given a :term:`grid identifier`,
get an array of the coordinate names defined for the grid;
e.g., ``["x", "y", "z"]``,
or ``["x1", "x2", "x3"]``,
or ``["lon", "lat", "hgt"]``, etc.
The length of the array is given by :ref:`get_grid_rank`.

**Implementation notes**

* This function is used for describing all :ref:`grid types <model_grids>`.
* In C and Fortran, the names are passed back as an array of character pointers
  (because the coordinate names could have differing lengths), and an integer
  status code indicating success (zero) or failure (nonzero) is returned.
* In C++, the argument is omitted and the names are returned from the function
  in a vector, a standard container in the language.
* In Java, the argument is omitted and the names are returned from the function
  in a string array, a standard container in the language.
* In Python, the argument is omitted and the names are returned from the
  function in a tuple, a standard container in the language.
* Some grids may not have coordinates (e.g., grids of type ``scalar`` or
  ``none``).
* This function was introduced in BMI 2.1.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_coordinate_units:

*get_grid_coordinate_units*
...........................

.. code-block:: java

   /* SIDL */
   int get_grid_coordinate_units(in int grid, in string name, out string units);

Given a :term:`grid identifier`
and a coordinate name returned from :ref:`get_grid_coordinate_names`,
get the units of the coordinate.

Standard unit names in lower case,
such as ``"meters"`` or ``"millibars"``,
should be used.
Standard abbreviations,
such as ``"m"`` or ``"mb"``, are also supported.
The abbreviations used in the BMI are derived from
Unidata's `UDUNITS`_ package.
See, for example, `The Units Database`_ for a
full description of valid unit names and a list of supported units.

**Implementation notes**

* This function is used for describing all :ref:`grid types <model_grids>`.
* Dimensionless quantities (such as sigma coordinates)
  should use ``""`` or ``"1"`` as the unit.
* Grids without units should use ``"none"``.
* In C++, Java, and Python, the *units* argument is omitted and the grid
  units name is returned from the function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.
* This function was introduced in BMI 2.1.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_coordinate:

*get_grid_coordinate*
.....................

.. code-block:: java

   /* SIDL */
   int get_grid_coordinate(in int grid, in string name, in array<double, 1> coordinates);

Given a :term:`grid identifier`
and a coordinate name returned from :ref:`get_grid_coordinate_names`,
get the locations of the grid :term:`nodes <node>` in a single
coordinate direction.

The length of the one-dimensional array of coordinates depends on the grid type
and the coordinate.
(It will be a value from either :ref:`get_grid_shape` or :ref:`get_grid_size`.)
See :ref:`model_grids` for more information.

**Implementation notes**

* This function is used for describing :ref:`rectilinear <rectilinear>`,
  :ref:`structured quadrilateral <structured_quad>`,
  and all :ref:`unstructured <unstructured_grids>` grids.
* In Python, the *coordinates* argument is a :term:`numpy <NumPy>` array.
* In C++ and Java, this is a void function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.
* This function was introduced in BMI 2.1. It replaces the deprecated
  *get_grid_x*, *get_grid_y*, and *get_grid_z* functions.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_node_count:

*get_grid_node_count*
.....................

.. code-block:: java

   /* SIDL */
   int get_grid_node_count(in int grid, out int count);

Get the number of :term:`nodes <node>` in the grid.

**Implementation notes**

* This function is used for describing :ref:`unstructured
  <unstructured_grids>` grids.
* In C++, Java, and Python, the *count* argument is omitted and the node
  count is returned from the function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_edge_count:

*get_grid_edge_count*
.....................

.. code-block:: java

   /* SIDL */
   int get_grid_edge_count(in int grid, out int count);

Get the number of :term:`edges <edge>` in the grid.

**Implementation notes**

* This function is used for describing :ref:`unstructured
  <unstructured_grids>` grids.
* In C++, Java, and Python, the *count* argument is omitted and the edge
  count is returned from the function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_face_count:

*get_grid_face_count*
.....................

.. code-block:: java

   /* SIDL */
   int get_grid_face_count(in int grid, out int count);

Get the number of :term:`faces <face>` in the grid.

**Implementation notes**

* This function is used for describing :ref:`unstructured
  <unstructured_grids>` grids.
* In C++, Java, and Python, the *count* argument is omitted and the face
  count is returned from the function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_edge_nodes:

*get_grid_edge_nodes*
.....................

.. code-block:: java

   /* SIDL */
   int get_grid_edge_nodes(in int grid, in array<int, 1> edge_nodes);

Get the edge-node connectivity.

For each edge, connectivity is given as node at edge tail, followed by
node at edge head. The total length of the array is 
2 * :ref:`get_grid_edge_count`.

**Implementation notes**

* This function is used for describing :ref:`unstructured
  <unstructured_grids>` grids.
* In Python, the *edge_nodes* argument is a :term:`numpy <NumPy>` array.
* In C++ and Java, this is a void function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_face_edges:

*get_grid_face_edges*
.....................

.. code-block:: java

   /* SIDL */
   int get_grid_face_edges(in int grid, in array<int, 1> face_edges);

Get the face-edge connectivity.

The length of the array returned is the sum of the values of
:ref:`get_grid_nodes_per_face`.

**Implementation notes**

* This function is used for describing :ref:`unstructured
  <unstructured_grids>` grids.
* In Python, the *face_edges* argument is a :term:`numpy <NumPy>` array.
* In C++ and Java, this is a void function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_face_nodes:

*get_grid_face_nodes*
.....................

.. code-block:: java

   /* SIDL */
   int get_grid_face_nodes(in int grid, in array<int, 1> face_nodes);

Get the face-node connectivity.

For each face, the nodes (listed in a counter-clockwise direction)
that form the boundary of the face.
For a grid of quadrilaterals, 
the total length of the array is 4 * :ref:`get_grid_face_count`.
More generally,
the length of the array is the sum of the values of
:ref:`get_grid_nodes_per_face`.

**Implementation notes**

* This function is used for describing :ref:`unstructured
  <unstructured_grids>` grids.
* In Python, the *face_nodes* argument is a :term:`numpy <NumPy>` array.
* In C++ and Java, this is a void function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_nodes_per_face:

*get_grid_nodes_per_face*
.........................

.. code-block:: java

   /* SIDL */
   int get_grid_nodes_per_face(in int grid, in array<int, 1> nodes_per_face);

Get the number of nodes for each face.

The returned array has a length of :ref:`get_grid_face_count`.
The number of edges per face is equal to the number of nodes per face.

**Implementation notes**

* This function is used for describing :ref:`unstructured
  <unstructured_grids>` grids.
* In Python, the *nodes_per_face* argument is a :term:`numpy <NumPy>` array.
* In C++ and Java, this is a void function.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_crs:

*get_grid_crs*
...............

.. code-block:: java

   /* SIDL */
   int get_grid_crs(in int grid, out string crs);

Given a :term:`grid identifier`,
get `coordinate reference system`_ (CRS) information for the grid as a string.

Note that the BMI doesn't specify which standard to use
for the output of this function---that's left to the implementation.
We can, however, make recommendations;
e.g., OGC `Well-Known Text`_ (WKT), `PROJ`_, or `EPSG`_.

A small example:
if you have data in a projected CRS,
say, UTM zone 13 North with the WGS84 datum,
you could use `spatialreference.org`_ to find information about this projection
(`EPSG:32613 <https://www.spatialreference.org/ref/epsg/wgs-84-utm-zone-13n/>`_)
and return it from :ref:`get_grid_crs`
as (for example) a PROJ string:

.. code-block::

  +proj=utm +zone=13 +ellps=WGS84 +datum=WGS84 +units=m +no_defs 

or as WKT:

.. code-block::

 PROJCS["WGS 84 / UTM zone 13N",
    GEOGCS["WGS 84",
        DATUM["WGS_1984",
            SPHEROID["WGS 84",6378137,298.257223563,
                AUTHORITY["EPSG","7030"]],
            AUTHORITY["EPSG","6326"]],
        PRIMEM["Greenwich",0,
            AUTHORITY["EPSG","8901"]],
        UNIT["degree",0.01745329251994328,
            AUTHORITY["EPSG","9122"]],
        AUTHORITY["EPSG","4326"]],
    UNIT["metre",1,
        AUTHORITY["EPSG","9001"]],
    PROJECTION["Transverse_Mercator"],
    PARAMETER["latitude_of_origin",0],
    PARAMETER["central_meridian",-105],
    PARAMETER["scale_factor",0.9996],
    PARAMETER["false_easting",500000],
    PARAMETER["false_northing",0],
    AUTHORITY["EPSG","32613"],
    AXIS["Easting",EAST],
    AXIS["Northing",NORTH]]

as you prefer.

**Implementation notes**

* In C++, Java, and Python, the *crs* argument is omitted and the CRS
  is returned from the function as a string.
* In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.
* A return string of ``""`` or ``"none"`` (but not the UDUNITS ``"1"``, which
  could be taken as an `EPSG code`_) indicates no projection information.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]
