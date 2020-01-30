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
(See :ref:`model_grids` and :ref:`implementation`.)


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

* In C++ and Python, the *type* argument is omitted and the grid
  type name is returned from the function.

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
of many of the following grid functions.
For instance, :ref:`get_grid_shape` returns an array of length *rank*.
Similarly, a grid's rank determines which
of :ref:`get_grid_x`, :ref:`get_grid_y`, etc. are implemented.

**Implementation notes**

* This function is needed for every :ref:`grid type <model_grids>`.
* In C++ and Python, the *rank* argument is omitted and the grid
  rank is returned from the function.

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
length of arrays returned by :ref:`get_grid_x` and :ref:`get_grid_y`
for :ref:`unstructured <unstructured_grids>` and
:ref:`structured quad <structured_quad>` grids.

**Implementation notes**

* This function is needed for every :ref:`grid type <model_grids>`.
* In C++ and Python, the *size* argument is omitted and the grid
  size is returned from the function.

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
* In C++, this is a void function.

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
* In C++, this is a void function.

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
* In C++, this is a void function.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_x:

*get_grid_x*
............

.. code-block:: java

   /* SIDL */
   int get_grid_x(in int grid, in array<double, 1> x);

Get the locations of the grid :term:`nodes <node>` in the first
coordinate direction.

The length of the resulting one-dimensional array depends on the grid type.
(It will have either :ref:`get_grid_rank` or :ref:`get_grid_size` elements.)
See :ref:`model_grids` for more information.

**Implementation notes**

* This function is used for describing :ref:`rectilinear <rectilinear>`,
  :ref:`structured quadrilateral <structured_quad>`,
  and all :ref:`unstructured <unstructured_grids>` grids.
* In Python, the *x* argument is a :term:`numpy <NumPy>` array.
* In C++, this is a void function.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_y:

*get_grid_y*
............

.. code-block:: java

   /* SIDL */
   int get_grid_y(in int grid, in array<double, 1> y);

Get the locations of the grid :term:`nodes <node>` in the second
coordinate direction.

The length of the resulting one-dimensional array depends on the grid type.
(It will have either :ref:`get_grid_rank` or :ref:`get_grid_size` elements.)
See :ref:`model_grids` for more information.

**Implementation notes**

* This function is used for describing :ref:`rectilinear <rectilinear>`,
  :ref:`structured quadrilateral <structured_quad>`,
  and all :ref:`unstructured <unstructured_grids>` grids.
* In Python, the *y* argument is a :term:`numpy <NumPy>` array.
* In C++, this is a void function.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_z:

*get_grid_z*
............

.. code-block:: java

   /* SIDL */
   int get_grid_z(in int grid, in array<double, 1> z);

Get the locations of the grid :term:`nodes <node>` in the third
coordinate direction.

The length of the resulting one-dimensional array depends on the grid type.
(It will have either :ref:`get_grid_rank` or :ref:`get_grid_size` elements.)
See :ref:`model_grids` for more information.

**Implementation notes**

* This function is used for describing :ref:`rectilinear <rectilinear>`,
  :ref:`structured quadrilateral <structured_quad>`,
  and all :ref:`unstructured <unstructured_grids>` grids.
* In Python, the *z* argument is a :term:`numpy <NumPy>` array.
* In C++, this is a void function.

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
* In C++ and Python, the *count* argument is omitted and the node
  count is returned from the function.

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
* In C++ and Python, the *count* argument is omitted and the edge
  count is returned from the function.

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
* In C++ and Python, the *count* argument is omitted and the face
  count is returned from the function.

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
* In C++, this is a void function.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_face_edges:

*get_grid_face_edges*
.....................

.. code-block:: java

   /* SIDL */
   int get_grid_face_edges(in int grid, in array<int, 1> face_edges);

Get the face-edge connectivity.

**Implementation notes**

* This function is used for describing :ref:`unstructured
  <unstructured_grids>` grids.
* In Python, the *face_edges* argument is a :term:`numpy <NumPy>` array.
* In C++, this is a void function.

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

**Implementation notes**

* This function is used for describing :ref:`unstructured
  <unstructured_grids>` grids.
* In Python, the *face_nodes* argument is a :term:`numpy <NumPy>` array.
* In C++, this is a void function.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]


.. _get_grid_nodes_per_face:

*get_grid_nodes_per_face*
.........................

.. code-block:: java

   /* SIDL */
   int get_grid_nodes_per_face(in int grid, in array<int, 1> nodes_per_face);

Get the number of nodes for each face.

The number of edges per face is equal to the number of nodes per face.

**Implementation notes**

* This function is used for describing :ref:`unstructured
  <unstructured_grids>` grids.
* In Python, the *nodes_per_face* argument is a :term:`numpy <NumPy>` array.
* In C++, this is a void function.

[:ref:`grid_funcs` | :ref:`basic_model_interface`]
