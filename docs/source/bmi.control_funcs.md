(control-funcs)=

# Model control functions

These BMI functions are critical to plug-and-play modeling because
they allow a calling component to bypass a model's own time loop.
They also provide the caller with fine-grained control over the
model -- a calling application is able to, for instance, update a
model one time step at a time, change its state, and then continue
updating.

(initialize)=

## *initialize*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```java
int initialize(in string config_file);
```
:::

:::{tab-item} Python
:sync: python
```python
def initialize(self, config_file: str) -> None:
```
:::
::::

The `initialize` function accepts a string argument that gives the
path to its {term}`configuration file`.
This function should perform all tasks that are to take place before
entering the model's time loop.  Models should be refactored, if
necessary, to read their inputs (which could include filenames for
other input files) from a configuration file.
BMI does not impose any constraint on how configuration files are
formatted.

**Implementation notes**

- Models should be refactored, if necessary, to use a configuration
  file.
- While no constraints are placed on how configuration files are
  formatted, [YAML](https://yaml.org) is preferred.
- In C and Fortran, the *config_file* argument is passed as
  a character array, whereas in C++, Java, and Python, it's passed as
  a string -- a basic type in these languages.
- In C and Fortran, an integer status code indicating success (zero) or failure (nonzero)
  is returned. In C++, Java, and Python, an exception is raised on failure.

(update)=

## *update*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```java
int update();
```
:::

:::{tab-item} Python
:sync: python
```python
def update(self) -> None:
```
:::
::::

The `update` function advances the model by a single time step. This
is the model's own internal time step (as returned by the BMI
{ref}`get-time-step` function), not the time step
of a controlling application.
This function should perform all tasks that take place during one
pass through the model's time loop.  It does not contain the time
loop. This typically involves incrementing all of the model's state
variables.  If the model's state variables don't change in time,
then they can be computed by the {ref}`initialize` function and this
function can just return without doing anything.

**Implementation notes**

- In C and Fortran, an integer status code indicating success (zero) or failure (nonzero)
  is returned. In C++, Java, and Python, an exception is raised on failure.

(update-until)=

## *update_until*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```java
int update_until(in double time);
```
:::

:::{tab-item} Python
:sync: python
```python
def update_until(self, time: float) -> None:
```
:::
::::

The `update_until` function updates the model to a particular time,
as provided by its *time* argument.
If the model permits,
the *time* argument can be a non-integral multiple of time steps,
and even negative.
Once called, the value returned
by the BMI {ref}`get-current-time` function must return the provided time
to reflect that the model was updated to the requested time.

**Implementation notes**

- Time is always a double-precision value.
- In C and Fortran, an integer status code indicating success (zero) or failure (nonzero)
  is returned. In C++, Java, and Python, an exception is raised on failure.

(finalize)=

## *finalize*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```java
int finalize();
```
:::

:::{tab-item} Python
:sync: python
```python
def finalize(self) -> None:
```
:::
::::

The `finalize` function should perform all tasks that take place
after exiting the model's time loop.  This typically includes
deallocating memory, closing files and printing reports.

**Implementation notes**

- In C and Fortran, an integer status code indicating success (zero) or failure (nonzero)
  is returned. In C++, Java, and Python, an exception is raised on failure.
