(info-funcs)=

# Model information functions

These functions supply the model name
and the model's {term}`exchange items <exchange item>` --
the variables that the model can use from
and provide to other models that have a BMI.

(get-varset-member-count)=

## *get_varset_member_count*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl

```java
int get_varset_member_count(in string set_name, out int count);
```
:::
:::{tab-item} Python
:sync: python
```python
def get_varset_member_count(self, set_name: str) -> int:
```
:::
:::{tab-item} c
:sync: c
```c
int get_varset_member_count(void *self, const char *name, int *count);
```
:::
::::

Gets the number of exchange items in a particular set exposed by the model.

**Implementation notes**

- In C++, Java, and Python, the *count* argument is omitted and the count
  is returned from the function.
- In C and Fortran, an integer status code indicating success (BMI_SUCCESS) or
  failure (BMI_FAILURE) is returned.

(get-varset-members)=

## *get_varset_members*

::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl

```java
int get_varset_members(in string set_name, out array<string, 1> names);
```
:::
:::{tab-item} Python
:sync: python
```python
def get_varset_members(self, set_name: str) -> tuple[str, ...]:
```
:::
:::{tab-item} c
:sync: c
```c
int get_varset_members(void *self, const char *name, char const* const* members);
```
:::
::::

Gets an array of names for the variables the model publishes in the requested set.
The length of the array is given by {ref}`get-varset-member-count`.
The names are preferably in the form of CSDMS {term}`Standard Names`.
Standard Names enable a modeling framework to determine whether a
variable in one model is equivalent to, or compatible with,
a corresponding variable in another model.
This allows the framework to automatically connect components.
Standard Names do not have to be used within the model.

Available variable sets are defined by this specification, extensions,
or private conventions between the caller and model.

**Implementation notes**

- In C and Fortran, the names are passed back as an array of character
  pointers (because the variable names could have differing lengths), and an
  integer status code indicating success (zero) or failure (nonzero) is returned.
- In C++, the argument is omitted and the names are returned from the
  function in a vector, a standard container in the language.
- In Java, the argument is omitted and the names are returned from the
  function in a string array, a standard container in the language.
- In Python, the argument is omitted and the names are returned from the
  function in a tuple, a standard container in the language.
- A model might have no input variables.

:::{include} links.md
:::
