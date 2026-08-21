(metadata-funcs)=

# Model and BMI metadata functions

These functions supply metadata about a model and its BMI.

(get-bmi-version)=

## *get_bmi_version*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```java
int get_bmi_version(out string version);
```
:::

:::{tab-item} Python
:sync: python
```python
def get_bmi_version(self) -> str:
```
:::
:::{tab-item} c
:sync: c
```c
int get_bmi_version(void *self, char *version);
```
:::
::::

:::{versionadded} 2.1
:::

This function supplies the version of BMI implemented as a string.

**Implementation notes**

- The version must be >=2.1.
- In C and Fortran, the *version* argument is a a character array, and an integer
  status code indicating success (zero) or failure (nonzero) is returned.
- In C++, Java, and Python, this argument is omitted, and a string -- a basic type
  in these languages -- is returned from the function.

(get-component-name)=

## *get_component_name*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```java
int get_component_name(out string name);
```
:::

:::{tab-item} Python
:sync: python
```python
def get_component_name(self) -> str:
```
:::
:::{tab-item} c
:sync: c
```c
int get_component_name(void *self, char *name);
```
:::
::::

This function supplies the name of the model component as a string.
There are no restrictions on the name,
but it should be unique to prevent conflicts with other components.

**Implementation notes**

- In C and Fortran, the *name* argument is a a character array, and an integer
  status code indicating success (zero) or failure (nonzero) is returned.
- In C++, Java, and Python, this argument is omitted, and a string -- a basic type
  in these languages -- is returned from the function.
