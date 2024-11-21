(getter-setter-funcs)=

# Variable getter and setter functions

These functions are used to access and modify the variables
that a model exposes through its BMI
(see {ref}`get-input-var-names` and {ref}`get-output-var-names`).

A *getter* is a function called to get a variable from a model's *state*.
A model's state variables typically change with each time step,
so getters are called to get current values.

A *setter* is a function called to change/overwrite a variable in
a model's state. A setter may impose restrictions on how a
state variable can be changed or check the new data for validity.

(get-value)=

## *get_value*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```{map-bmi-function} get_value
:language: sidl
```
:::

:::{tab-item} Python
:sync: python
```{map-bmi-function} get_value
:language: python
```
:::
:::{tab-item} C
:sync: c
```{map-bmi-function} get_value
:language: c
```
:::
:::{tab-item} C++
:sync: c++
```{map-bmi-function} get_value
:language: c++
```
:::
::::

The `get_value` function takes a variable name and copies values into a
provided array parameter.
The type and size of the array parameter depend on the variable,
and can be determined through
{ref}`get-var-type`, {ref}`get-var-nbytes`, etc.
Recall that arrays are always flattened in BMI,
even if the model uses dimensional variables.

**Implementation notes**

- The *dest* argument must be defined and allocated before calling
  `get_value`. Whatever values it contains are overwritten in the call
  to `get_value`.
- In Python, the array parameter is a {term}`numpy` array.
- In Java, only [primitive types] (e.g., `int`, `double`), not
  [wrapper classes] (e.g., `Integer`, `Double`), are supported.
- In C++ and Java, `get_value` is a void function.
- Depending on how a model is written, a variable may not be
  accessible until after the call to {ref}`initialize`. Likewise, the
  variable may not be accessible after calling {ref}`finalize`.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-value-ptr)=

## *get_value_ptr*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```{map-bmi-function} get_value_ptr
:language: sidl
```
:::

:::{tab-item} Python
:sync: python
```{map-bmi-function} get_value_ptr
:language: python
```
:::
:::{tab-item} C
:sync: c
```{map-bmi-function} get_value_ptr
:language: c
```
:::
:::{tab-item} C++
:sync: c++
```{map-bmi-function} get_value_ptr
:language: c++
```
:::
::::

The `get_value_ptr` function takes a variable name and returns a reference
to a variable.
Unlike the array parameter returned from {ref}`get-value`,
the reference always points to the current values of the variable,
even if the model's state has changed.

**Implementation notes**

- The reference points to a flattened array.
- In C++ and Java, the *dest_ptr* argument is omitted, and the reference is
  returned through the function.
- In Java, this function can only be used with one-dimensional arrays.
- In Python, a {term}`numpy` array is returned.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-value-at-indices)=

## *get_value_at_indices*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```{map-bmi-function} get_value_at_indices
:language: sidl
```
:::

:::{tab-item} Python
:sync: python
```{map-bmi-function} get_value_at_indices
:language: python
```
:::
:::{tab-item} C
:sync: c
```{map-bmi-function} get_value_at_indices
:language: c
```
:::
:::{tab-item} C++
:sync: c++
```{map-bmi-function} get_value_at_indices
:language: c++
```
:::
::::

Use the `get_value_at_indices` function to get a copy of a variable's values
at the locations specified by the one-dimensional array indices
in the *inds* argument.
The values are returned through the *dest* argument.

**Implementation notes**

All the notes from {ref}`get-value` apply.
Additionally,

- Both *dest* and *inds* are flattened arrays.
- The *inds* argument is always of type integer.

(set-value)=

## *set_value*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```{map-bmi-function} set_value
:language: sidl
```
:::

:::{tab-item} Python
:sync: python
```{map-bmi-function} set_value
:language: python
```
:::
:::{tab-item} C
:sync: c
```{map-bmi-function} set_value
:language: c
```
:::
:::{tab-item} C++
:sync: c++
```{map-bmi-function} set_value
:language: c++
```
:::
::::

The `set_value` function takes a variable name and an array of values,
*src*,
and copies those values into the model's internal array of values,
overwriting the current contents.
The type and size of *src* must match the model's internal array,
and can be determined through
{ref}`get-var-type`, {ref}`get-var-nbytes`, etc.
Recall that arrays are always flattened in BMI,
even if the model uses dimensional variables.

**Implementation notes**

- In Python, *src* is a {term}`numpy` array.
- In Java, only [primitive types] (e.g., `int`, `double`), not
  [wrapper classes] (e.g., `Integer`, `Double`), are supported.
- In C++ and Java, `set_value` is a void function.
- Depending on how a model is written, a variable may not be
  accessible until after the call to {ref}`initialize`. Likewise, the
  variable may not be accessible after calling {ref}`finalize`.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(set-value-at-indices)=

## *set_value_at_indices*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```{map-bmi-function} set_value_at_indices
:language: sidl
```
:::

:::{tab-item} Python
:sync: python
```{map-bmi-function} set_value_at_indices
:language: python
```
:::
:::{tab-item} C
:sync: c
```{map-bmi-function} set_value_at_indices
:language: c
```
:::
:::{tab-item} C++
:sync: c++
```{map-bmi-function} set_value_at_indices
:language: c++
```
:::
::::

Use the `set_value_at_indices` function to set a variable's values
at the locations specified by the one-dimensional array indices
in the *inds* argument.

**Implementation notes**

All the notes from {ref}`set-value` apply.
Additionally,

- Both *src* and *inds* are flattened arrays.
- The *inds* argument is always of type integer.

:::{include} links.md
:::
