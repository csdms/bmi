(grid-funcs)=

# Model grid functions

The functions in this section describe {ref}`model grids <model-grids>`.
In the BMI,
every {term}`exchange item` is defined on a grid,
and is referenced by a {term}`grid identifier`
returned from the {ref}`get-var-grid` function.
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
(See {ref}`model-grids` and {ref}`best-practices`.)

(get-grid-type)=

## *get_grid_type*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_type(in int grid, out string type);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_type(self, grid: int) -> str:
```

Given a {term}`grid identifier`, get the type of that grid as a string.
Valid grid types are:

- `scalar`
- `points`
- `vector`
- `unstructured`
- `structured_quadrilateral`
- `rectilinear`
- `uniform_rectilinear`

A detailed description of the grid types supported in BMI
is given in the {ref}`model-grids` section.

**Implementation notes**

- In C++, Java, and Python, the *type* argument is omitted and the grid
  type name is returned from the function as a string.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-grid-rank)=

## *get_grid_rank*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_rank(in int grid, out int rank);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_rank(self, grid: int) -> int:
```

Given a {term}`grid identifier`, get the {term}`rank` (the number of
dimensions) of that grid as an integer.

A grid's rank determines the length of the return value
of many of the following grid functions.
For instance, {ref}`get-grid-shape` returns an array of length *rank*.
Similarly, a grid's rank determines which
of {ref}`get-grid-x`, {ref}`get-grid-y`, etc. are implemented.

**Implementation notes**

- This function is needed for every {ref}`grid type <model-grids>`.
- In C++, Java, and Python, the *rank* argument is omitted and the grid
  rank is returned from the function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-grid-size)=

## *get_grid_size*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_size(in int grid, out int size);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_size(self, grid: int) -> int:
```

Given a {term}`grid identifier`,
get the total number of elements (or {term}`nodes <node>`)
of that grid as an integer.

The grid size is used for, among other things, the
length of arrays returned by {ref}`get-grid-x` and {ref}`get-grid-y`
for {ref}`unstructured <unstructured-grids>` and
{ref}`structured quad <structured-quad>` grids.

**Implementation notes**

- This function is needed for every {ref}`grid type <model-grids>`.
- In C++, Java, and Python, the *size* argument is omitted and the grid
  size is returned from the function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-grid-shape)=

## *get_grid_shape*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_shape(in int grid, in array<int, 1> shape);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_shape(self, grid: int, shape: NDArray[np.int_]) -> NDArray[np.int_]:
```

Get the dimensions of the model grid.

Note that this function (as well as the other grid functions)
returns information ordered with "ij" indexing (as opposed to "xy").
For example,
consider a two-dimensional rectilinear grid
with four columns (`nx = 4`)
and three rows (`ny = 3`).
The {ref}`get-grid-shape` function would return a shape
of `[ny, nx]`, or `[3,4]`.
If there were a third dimension, the length of the *z*-dimension, `nz`,
would be listed first.

Also note that the grid shape is the number of {term}`nodes <node>`
in the coordinate directions and not the number of cells or elements.
It is possible for grid values to be associated with the nodes or with
the cells.

**Implementation notes**

- This function is used for describing all {ref}`structured grids
  <structured-grids>`.
- In Python, the *shape* argument is a {term}`numpy <NumPy>` array.
- In C++ and Java, this is a void function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-grid-spacing)=

## *get_grid_spacing*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_spacing(in int grid, in array<double, 1> spacing);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_spacing(
             self, grid: int, spacing: NDArray[np.float64]
         ) -> NDArray[np.float64]:
```

Get the distance between the {term}`nodes <node>` of the model grid.

The {ref}`get-grid-spacing` function provides the width of each cell in
the number of dimensions as returned by {ref}`get-grid-rank`.
As with {ref}`get-grid-shape`,
the spacing is given in "ij" indexing\* order;
e.g., for a two-dimensional grid,
the spacing between rows is followed by spacing between columns, `[dy, dx]`.

**Implementation notes**

- This function is used for describing {ref}`uniform rectilinear
  <uniform-rectilinear>` grids.
- In Python, the *spacing* argument is a {term}`numpy <NumPy>` array.
- In C++ and Java, this is a void function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-grid-origin)=

## *get_grid_origin*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_origin(in int grid, in array<double, 1> origin);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_origin(
             self, grid: int, origin: NDArray[np.float64]
         ) -> NDArray[np.float64]:
```

Get the coordinates of the lower-left corner of the model grid.

The *origin* parameter is a one-dimensional array of the size
returned by {ref}`get-grid-rank`.
As with {ref}`get-grid-shape`,
the origin is given in "ij" indexing\* order;
e.g., for a two-dimensional grid,
the origin is given in the column dimension, followed by the row dimension,
`[y0, x0]`.

**Implementation notes**

- This function is used for describing {ref}`uniform rectilinear
  <uniform-rectilinear>` grids.
- In Python, the *origin* argument is a {term}`numpy <NumPy>` array.
- In C++ and Java, this is a void function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-grid-x)=

## *get_grid_x*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_x(in int grid, in array<double, 1> x);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_x(self, grid: int, x: NDArray[np.float64]) -> NDArray[np.float64]:
```

Get the locations of the grid {term}`nodes <node>` in the first
coordinate direction.

The length of the resulting one-dimensional array depends on the grid type.
(It will use a value from either {ref}`get-grid-shape` or {ref}`get-grid-size`.)
See {ref}`model-grids` for more information.

**Implementation notes**

- This function is used for describing {ref}`rectilinear <rectilinear>`,
  {ref}`structured quadrilateral <structured-quad>`,
  and all {ref}`unstructured <unstructured-grids>` grids.
- In Python, the *x* argument is a {term}`numpy <NumPy>` array.
- In C++ and Java, this is a void function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-grid-y)=

## *get_grid_y*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_y(in int grid, in array<double, 1> y);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_y(self, grid: int, y: NDArray[np.float64]) -> NDArray[np.float64]:
```

Get the locations of the grid {term}`nodes <node>` in the second
coordinate direction.

The length of the resulting one-dimensional array depends on the grid type.
(It will use a value from either {ref}`get-grid-shape` or {ref}`get-grid-size`.)
See {ref}`model-grids` for more information.

**Implementation notes**

- This function is used for describing {ref}`rectilinear <rectilinear>`,
  {ref}`structured quadrilateral <structured-quad>`,
  and all {ref}`unstructured <unstructured-grids>` grids.
- In Python, the *y* argument is a {term}`numpy <NumPy>` array.
- In C++ and Java, this is a void function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-grid-z)=

## *get_grid_z*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_z(in int grid, in array<double, 1> z);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_z(self, grid: int, z: NDArray[np.float64]) -> NDArray[np.float64]:
```

Get the locations of the grid {term}`nodes <node>` in the third
coordinate direction.

The length of the resulting one-dimensional array depends on the grid type.
(It will use a value from either {ref}`get-grid-shape` or {ref}`get-grid-size`.)
See {ref}`model-grids` for more information.

**Implementation notes**

- This function is used for describing {ref}`rectilinear <rectilinear>`,
  {ref}`structured quadrilateral <structured-quad>`,
  and all {ref}`unstructured <unstructured-grids>` grids.
- In Python, the *z* argument is a {term}`numpy <NumPy>` array.
- In C++ and Java, this is a void function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-grid-node-count)=

## *get_grid_node_count*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_node_count(in int grid, out int count);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_node_count(self, grid: int) -> int:
```

Get the number of {term}`nodes <node>` in the grid.

**Implementation notes**

- This function is used for describing {ref}`unstructured
  <unstructured-grids>` grids.
- In C++, Java, and Python, the *count* argument is omitted and the node
  count is returned from the function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-grid-edge-count)=

## *get_grid_edge_count*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_edge_count(in int grid, out int count);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_edge_count(self, grid: int) -> int:
```

Get the number of {term}`edges <edge>` in the grid.

**Implementation notes**

- This function is used for describing {ref}`unstructured
  <unstructured-grids>` grids.
- In C++, Java, and Python, the *count* argument is omitted and the edge
  count is returned from the function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-grid-face-count)=

## *get_grid_face_count*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_face_count(in int grid, out int count);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_face_count(self, grid: int) -> int:
```

Get the number of {term}`faces <face>` in the grid.

**Implementation notes**

- This function is used for describing {ref}`unstructured
  <unstructured-grids>` grids.
- In C++, Java, and Python, the *count* argument is omitted and the face
  count is returned from the function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-grid-edge-nodes)=

## *get_grid_edge_nodes*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_edge_nodes(in int grid, in array<int, 1> edge_nodes);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_edge_nodes(
             self, grid: int, edge_nodes: NDArray[np.int_]
         ) -> NDArray[np.int_]:
```

Get the edge-node connectivity.

For each edge, connectivity is given as node at edge tail, followed by
node at edge head. The total length of the array is
2 * {ref}`get-grid-edge-count`.

**Implementation notes**

- This function is used for describing {ref}`unstructured
  <unstructured-grids>` grids.
- In Python, the *edge_nodes* argument is a {term}`numpy <NumPy>` array.
- In C++ and Java, this is a void function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-grid-face-edges)=

## *get_grid_face_edges*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_face_edges(in int grid, in array<int, 1> face_edges);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_face_edges(
             self, grid: int, face_edges: NDArray[np.int_]
         ) -> NDArray[np.int_]:
```

Get the face-edge connectivity.

The length of the array returned is the sum of the values of
{ref}`get-grid-nodes-per-face`.

**Implementation notes**

- This function is used for describing {ref}`unstructured
  <unstructured-grids>` grids.
- In Python, the *face_edges* argument is a {term}`numpy <NumPy>` array.
- In C++ and Java, this is a void function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-grid-face-nodes)=

### *get_grid_face_nodes*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_face_nodes(in int grid, in array<int, 1> face_nodes);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_face_nodes(
             self, grid: int, face_nodes: NDArray[np.int_]
         ) -> NDArray[np.int_]:
```

Get the face-node connectivity.

For each face, the nodes (listed in a counter-clockwise direction)
that form the boundary of the face.
For a grid of quadrilaterals,
the total length of the array is 4 * {ref}`get-grid-face-count`.
More generally,
the length of the array is the sum of the values of
{ref}`get-grid-nodes-per-face`.

**Implementation notes**

- This function is used for describing {ref}`unstructured
  <unstructured-grids>` grids.
- In Python, the *face_nodes* argument is a {term}`numpy <NumPy>` array.
- In C++ and Java, this is a void function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-grid-nodes-per-face)=

## *get_grid_nodes_per_face*

```{eval-rst}
.. tab-set::
   :sync-group: lang

   .. tab-item:: SIDL
      :sync: sidl

      .. code-block:: java

         int get_grid_nodes_per_face(in int grid, in array<int, 1> nodes_per_face);

   .. tab-item:: Python
      :sync: python

      .. code-block:: python

         def get_grid_nodes_per_face(
             self, grid: int, nodes_per_face: NDArray[np.int_]
         ) -> NDArray[np.int_]:
```

Get the number of nodes for each face.

The returned array has a length of {ref}`get-grid-face-count`.
The number of edges per face is equal to the number of nodes per face.

**Implementation notes**

- This function is used for describing {ref}`unstructured
  <unstructured-grids>` grids.
- In Python, the *nodes_per_face* argument is a {term}`numpy <NumPy>` array.
- In C++ and Java, this is a void function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.
