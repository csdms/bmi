(time-funcs)=

# Time functions

These simple diagnostic functions provide information on model time.
Model time is always expressed as a floating point value.

(get-current-time)=

## *get_current_time*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```{map-bmi-function} get_current_time
:language: sidl
```
:::
:::{tab-item} Python
:sync: python
```{map-bmi-function} get_current_time
:language: python
```
:::
:::{tab-item} c
:sync: c
```{map-bmi-function} get_current_time
:language: c
```
:::
:::{tab-item} c++
:sync: c++
```{map-bmi-function} get_current_time
:language: c++
```
:::
::::

The current model time.

**Implementation notes**

- In C++, Java, and Python, the argument is omitted and the time is returned
  from the function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-start-time)=

## *get_start_time*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```{map-bmi-function} get_start_time
:language: sidl
```
:::
:::{tab-item} Python
:sync: python
```{map-bmi-function} get_start_time
:language: python
```
:::
:::{tab-item} c
:sync: c
```{map-bmi-function} get_start_time
:language: c
```
:::
:::{tab-item} c++
:sync: c++
```{map-bmi-function} get_start_time
:language: c++
```
:::
::::

The start time of the  model.

**Implementation notes**

- The start time in BMI is typically defined to be 0.0.
- In C++, Java, and Python, the argument is omitted and the time is returned
  from the function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-end-time)=

## *get_end_time*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```{map-bmi-function} get_end_time
:language: sidl
```
:::
:::{tab-item} Python
:sync: python
```{map-bmi-function} get_end_time
:language: python
```
:::
:::{tab-item} c
:sync: c
```{map-bmi-function} get_end_time
:language: c
```
:::
:::{tab-item} c++
:sync: c++
```{map-bmi-function} get_end_time
:language: c++
```
:::
::::

The end time of the  model.

**Implementation notes**

- If the model doesn't define an end time, a large number (e.g., the
  largest floating point number supported on a platform) is typically
  chosen.
- In C++, Java, and Python, the argument is omitted and the time is returned
  from the function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-time-units)=

## *get_time_units*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```{map-bmi-function} get_time_units
:language: sidl
```
:::

:::{tab-item} Python
:sync: python
```{map-bmi-function} get_time_units
:language: python
```
:::
:::{tab-item} c
:sync: c
```{map-bmi-function} get_time_units
:language: c
```
:::
:::{tab-item} c++
:sync: c++
```{map-bmi-function} get_time_units
:language: c++
```
:::
::::

Get the units of time as reported by the model's BMI (through
{ref}`get-current-time`, {ref}`get-end-time`, etc.).
It's recommended to use [time unit conventions] from Unidata's
[UDUNITS] package; e.g., `"s"`, `"min"`, `"h"`, `"d"`.

**Implementation notes**

- Avoid using `"years"` as a unit, if possible, since a year is
  difficult to define precisely. UDUNITS defines a year as 365.2422
  days or 31556926 seconds.
- Dimensionless quantities should use `""` or `"1"` as the unit.
- Models that don't vary with time, or don't have time units should
  use `"none"`.
- In C++, Java, and Python, the argument is omitted and the units are returned
  from the function as a string.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

(get-time-step)=

## *get_time_step*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```{map-bmi-function} get_time_step
:language: sidl
```
:::
:::{tab-item} Python
:sync: python
```{map-bmi-function} get_time_step
:language: python
```
:::
:::{tab-item} c
:sync: c
```{map-bmi-function} get_time_step
:language: c
```
:::
:::{tab-item} c++
:sync: c++
```{map-bmi-function} get_time_step
:language: c++
```
:::
::::

Get the time step used in the model.
The time step is always expressed as a floating point value.

**Implementation notes**

- A time step is typically a positive value. However, if the model
  permits it, a negative value can be used (running the model
  backward).
- In C++, Java, and Python, the argument is omitted and the time step is returned
  from the function.
- In C and Fortran, an integer status code indicating success (zero) or failure
  (nonzero) is returned.

:::{include} links.md
:::
