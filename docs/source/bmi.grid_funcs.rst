.. _get_grid:

Model Grids
===========

Different models often use different computational grids.  An
application that calls a BMI needs a complete and standardized
description of a model's grid in order to automatically accommodate
differences between model grids (via regridding) when coupled
models share data.  Currently, BMI supports four different grid types.
Depending on the grid type, the model will implement a different
set of grid functions. By calling a model's :ref:`get_var_grid`
function, an application is able to determine which methods will
be implemented for a particular grid.


Grid Type
---------

.. code-block:: java

  string get_grid_type(in int id)

The type of grid as a string. Valid return values are:

* ``uniform_rectilinear``
* ``rectilinear``
* ``structured_quadrilateral``
* ``unstructured``


.. _get_grid_rank:

Grid rank
---------

.. code-block:: java

    int get_grid_rank(in int id)

The number of dimension in the grid is its *rank*. A grid's rank
determines the length of many of the following grid functions.
For instance, :ref:`get_grid_shape` will return an array that is
of length *rank*. In a similar way, a grid's rank determines which
of ``get_grid_x``, ``get_grid_y``, etc. are implemented.

``get_grid_rank`` returns the rank of a particular grid. ``0``
for scalar, ``1`` for 1D, etc.

Grid size
---------

.. code-block:: java

    int get_grid_size(in int id)

``get_grid_size`` returns the size of a grid as the number of
elements. This is used for, among other things, to give the
length of arrays returned by ``get_grid_x`` and ``get_grid_y``
for :ref:`unstructured <unstructured_mesh>` and
:ref:`structured quad grids <structured_quad>`.


Structured grids of quadrilaterals
----------------------------------

.. _get_grid_shape:

Grid shape
^^^^^^^^^^

.. code-block:: java

    int get_grid_shape(in int id, out array<int, 1> shape)

A structured grid of quadrilaterals is one formed by a stacked
next one-another such that every vertex is surrounded by four
quadrilaterals. A special case of such a grid is
:ref:`uniform_rectilinear` where rectangles are stacked next
to one another row-by-row.

For all quadrilateral grids, the ``get_grid_shape`` function
is necessary to provide the number of rows and columns (for
a 2D grid). Note that this function (as well as the other
grid functions) returns information about each dimension
ordered with "ij" indexing (as opposed to "xy"). For example,
the ``get_grid_shape`` function for the uniform rectilinear
grid shown below would return the array ``[4, 5]``. If there
were a third dimension, the length of the *z-dimension*
would be listed first.

.. note::

  Note that the grid shape is the number of *nodes* in the
  coordinate directions and not the number of cells or
  elements.  It is possible for grid values to be
  associated with the nodes or with the cells.


.. _uniform_rectilinear:

Uniform rectilinear
^^^^^^^^^^^^^^^^^^^

.. code-block:: java

    int get_grid_origin(in int id, out array<int, 1> origin)
    int get_grid_spacing(in int id, out array<int, 1> spacing)

.. image:: images/mesh_uniform_rectilinear.png
   :scale: 20 %

A uniform rectilinear (or Cartesian grid) is a special case of
a grid of quadrilaterals such that the elements have equal width
in each dimension. That is, for a 2D grid, elements have a
constant width of ``dx`` in the *x-direction` and ``dy`` in the
*y-direction`. The case of ``dx == dy`` is oftentimes called
as *raster grid*.

To completely define points of a uniform rectilinear grid,
one needs only three pieces of information. Namely, the
number of elements in each dimension (:ref:`get_grid_shape`),
the width of each element (in each dimension) and the location
of the corner of the grid.

``get_grid_spacing`` provides the width of each element in
the number of dimension as returned by :ref:`get_grid_rank`.
The spacing is *ij-indexing* order. That is spacing in rows
followed by spacing in columns.

``get_grid_origin`` provides the location of the lower-left
corner of the grid (also in *ij-indexing* order).


Rectilinear
^^^^^^^^^^^

.. code-block:: java

    int get_grid_rank(in int id)
    int get_grid_size(in int id)
    int get_grid_shape(in int id, out array<int, 1> shape)
    int get_grid_x(in int id, out array<int, 1> x)
    int get_grid_y(in int id, out array<int, 1> y)
    int get_grid_z(in int id, out array<int, 1> z)

.. image:: images/mesh_rectilinear.png
   :scale: 20 %

A rectilinear grid is simply a uniform rectilinear grid whose spacing
in a single dimension varies (as shown in the above image). In this
case, an array of coordinates for each row and column (for 2D) is
required.

``get_grid_y`` provides an array (whose length is the number of
*rows*) that gives the y-coordinate for each row.

``get_grid_x`` provides an array (whose length is the number of
*columns*) that gives the y-coordinate for each column.


.. _structured_quad:

Structured quadrilaterals
^^^^^^^^^^^^^^^^^^^^^^^^^

.. code-block:: java

    int get_grid_rank(in int id)
    int get_grid_size(in int id)
    int get_grid_shape(in int id, out array<int, 1> shape)
    int get_grid_x(in int id, out array<int, 1> x)
    int get_grid_y(in int id, out array<int, 1> y)
    int get_grid_z(in int id, out array<int, 1> z)

.. image:: images/mesh_structured_quad.png
   :scale: 20 %

The most general structured quadrilateral grid is one whose
rows (and columns) do not share a common coordinate. In this
case, coordinates are required for each grid element. For this
more general case, ``get_grid_x`` and ``get_grid_y`` are
repurposed to provide this information.

``get_grid_y`` returns an array (whose length is the number
of total nodes) of x-coordinates.

``get_grid_x`` returns an array (whose length is the number
of total nodes) of y-coordinates.

.. _unstructured_mesh:

Unstructured
------------

.. code-block:: java

    int get_grid_rank(in int id)

    int get_grid_x(in int id, out array<int, 1> x)
    int get_grid_y(in int id, out array<int, 1> y)
    int get_grid_z(in int id, out array<int, 1> z)

    int get_grid_node_count(in int grid)
    int get_grid_edge_count(in int grid)
    int get_grid_face_count(in int grid)

    int get_grid_edge_nodes(in int grid, out array<int, 1> edge_nodes)
    int get_grid_face_edges(in int grid, out array<int, 1> face_edges)
    int get_grid_face_nodes(in int grid, out array<int, 1> face_nodes)
    int get_grid_nodes_per_face(in int grid, out array<int, 1> nodes_per_face)

This is the most general grid type and can be used for any type of grid.
However, most grids that consist of 4-sided polygons can be represented
using one of the other grid types.  This grid type must be used if
the grid consists of any elements or *cells* that do not have four sides.
This includes any grid of triangles (e.g.
`Delaunay triangles <http://en.wikipedia.org/wiki/Delaunay_triangulation>`_
and a
`Voronoi tesselation <http://en.wikipedia.org/wiki/Voronoi_tessellation>`_.

Note that a grid of
`equilateral triangles <http://en.wikipedia.org/wiki/Triangle_tiling>`_,
while is most certainly *structured*, would need to be represented
as an unstructured grid.  The same is true for a grid of
`hexagons <http://en.wikipedia.org/wiki/Hexagonal_tiling>`_.
