(basic-model-interface)=

# The Basic Model Interface

The functions that comprise the Basic Model Interface
can be grouped into categories:

```{toctree}
:maxdepth: 1

Metadata <bmi.metadata_funcs>
Control <bmi.control_funcs>
Info <bmi.info_funcs>
Variables <bmi.var_funcs>
Time <bmi.time_funcs>
Getters and setters <bmi.getter_setter>
Grid <bmi.grid_funcs>
```

Table 3 lists the individual BMI functions
along with a brief description.
Following the table is a detailed description of each function,
including the function prototype in {term}`SIDL`,
grouped by functional category.

:::{table} **Table 3:** Summary of BMI functions.
:align: left
:widths: 30, 70

| Function                       | Description                                               |
| ------------------------------ | --------------------------------------------------------- |
| {ref}`get-bmi-version`         | Version of the BMI implemented.                           |
| {ref}`initialize`              | Perform startup tasks for the model.                      |
| {ref}`update`                  | Advance model state by one time step.                     |
| {ref}`update-until`            | Advance model state until the given time.                 |
| {ref}`finalize`                | Perform tear-down tasks for the model.                    |
| {ref}`get-component-name`      | Name of the model.                                        |
| {ref}`get-varset-item-count`   | Count of a model's variables in a set.                    |
| {ref}`get-varset-members`      | List of a model's variables in a set.                     |
| {ref}`get-var-grid`            | Get the grid identifier for a variable.                   |
| {ref}`get-var-type`            | Get the data type of a variable.                          |
| {ref}`get-var-units`           | Get the units of a variable.                              |
| {ref}`get-var-itemsize`        | Get the size (in bytes) of one element of a variable.     |
| {ref}`get-var-nbytes`          | Get the total size (in bytes) of a variable.              |
| {ref}`get-var-location`        | Get the grid element type of a variable.                  |
| {ref}`get-current-time`        | Current time of the model.                                |
| {ref}`get-start-time`          | Start time of the model.                                  |
| {ref}`get-end-time`            | End time of the model.                                    |
| {ref}`get-time-units`          | Time units used in the model.                             |
| {ref}`get-time-step`           | Time step used in the model.                              |
| {ref}`get-value`               | Get a copy of values of a given variable.                 |
| {ref}`get-value-ptr`           | Get a reference to the values of a given variable.        |
| {ref}`get-value-at-indices`    | Get variable values at specific locations.                |
| {ref}`set-value`               | Set the values of a given variable.                       |
| {ref}`set-value-at-indices`    | Set the values of a variable at specific locations.       |
| {ref}`get-grid-rank`           | Get the number of dimensions of a computational grid.     |
| {ref}`get-grid-size`           | Get the total number of elements of a computational grid. |
| {ref}`get-grid-type`           | Get the grid type as a string.                            |
| {ref}`get-grid-shape`          | Get the dimensions of a computational grid.               |
| {ref}`get-grid-spacing`        | Get the spacing between grid nodes.                       |
| {ref}`get-grid-origin`         | Get the origin of a grid.                                 |
| {ref}`get-grid-x`              | Get the locations of a grid's nodes in dimension 1.       |
| {ref}`get-grid-y`              | Get the locations of a grid's nodes in dimension 2.       |
| {ref}`get-grid-z`              | Get the locations of a grid's nodes in dimension 3.       |
| {ref}`get-grid-node-count`     | Get the number of nodes in the grid.                      |
| {ref}`get-grid-edge-count`     | Get the number of edges in the grid.                      |
| {ref}`get-grid-face-count`     | Get the number of faces in the grid.                      |
| {ref}`get-grid-edge-nodes`     | Get the edge-node connectivity.                           |
| {ref}`get-grid-face-edges`     | Get the face-edge connectivity.                           |
| {ref}`get-grid-face-nodes`     | Get the face-node connectivity.                           |
| {ref}`get-grid-nodes-per-face` | Get the number of nodes for each face.                    |
:::
