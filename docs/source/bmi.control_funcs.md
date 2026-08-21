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
int initialize(in string config_file, in array<string, 1> requested_extensions, out array<string, 1> supported_extensions);
```
:::

:::{tab-item} Python
:sync: python
```python
def initialize(self, config_file: str, requested_extensions: Collection[str]) -> Collection[str]:
```
:::

:::{tab-item} c
:sync: c
```c
int initialize(void *self, char *config_file, char const **requested_extensions, char const **supported_extensions);
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

It also takes an array of strings `requested_extensions` describing
the extensions that the caller would like to use if the the model
supports it. The model should determine which extensions it can
support, given its code and potentially the contents of the
configuration file. The supported extensions should be listed in
elements of the output array `supported_extensions`.

Use of extensions is completely optional within the scope of the core
BMI specification. Individual callers or models may require particular
extensions to provide their functionality. In the case where such an
extension is missing from the requested or supported extensions arrays
in or after the `initialize` call (respectively), the model or caller
should fail accordingly.

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
- In C, the length of `supported_extensions` is upper-bounded by
  `requested_extensions`, and so should be allocated
  accordingly. Models should copy pointers from `requested_extensions`
  to `supported_extensions` as appropriate. This allows the caller to
  retain ownership.

**Extensions Rationale**

- The set of extensions that a caller can support should
  be known in advance, since they will have their own semantics beyond
  those of this BMI specification. Thus, it does not make sense in
  this setting for models to advertise any extension that the caller
  does not support.
- The set of extensions that a model supports may be
  determined by the particular configuration with which it's
  initialized. Thus, this cannot be queried before the `initialize()`
  function.
- Extensions may require additional initialization steps. Thus, they
  are requested in the `initialize()` function to indicate which ones
  will be used if available. If they require added information or
  setup behavior from the caller, as described in their own
  specification, the caller is responsible for conforming to that
  specification.
- If a caller requests a particular extension and a model indicates
  support for it, the model may ultimately *require* that the caller
  use the extension as it is specified. This implies, for instance,
  that an extension requiring additional setup before the model enters
  its time loop (e.g. setting values of calibration parameters or an
  MPI communicator) may mean that the model will fail if that setup is
  not done before other BMI functions are called.


(get-extension)=

## *get_extension*


::::{tab-set}
:sync-group: lang

:::{tab-item} SIDL
:sync: sidl
```java
int get_extension(in string extension_name, out pointer extension_object);
```
:::

:::{tab-item} Python
:sync: python
```python
def get_extension(self, extension_name: str) -> object:
```
:::

:::{tab-item} c
:sync: c
```c
int get_extension(void *self, char const *name, void **extension_object);
```
:::

:::{tab-item} c++
:sync: c++
```c++
void* get_extension(std::string name);
```
:::
::::




For extensions specified to provide additional functions, these should
be accessed by the caller obtaining an associated extension object
with those functions as members.

**Implementation Notes**

- For staticly typed languages, including C, C++, and Fortran, the
  output `extension_object` will be represented as an anonymous
  (type-erased) pointer - `void *` or `type(c_ptr)`. The caller is
  responsible for knowing the type of the pointed-to object, and
  casting the pointer appropriately.
- In dynamically typed languages like Python, the return value will be
  an object reference. The caller is expected to know what methods are
  valid to call on the referenced object. If type checking is desired,
  it may be implemented by wrapping the `get_extension` call in a
  function with a suitable type hint on its return value.
- In C and C++, the `extension_object` instance is owned by the model
  object, and should be suitably handled by a call to `finalize(self)`
  or `model->Finalize()`, respectively.
- Depending on the model implementation language, the pointed-to
  object need not be wholly distinct or disjoint in memory from the
  model itself (i.e. `self` or `this`):

```python
def get_extension(self, extension_name: str):
    if extension_name not in enabled_extensions:
        raise UnimplementedException
    return self
```

```c++
class MyModel : public bmi::Bmi, public ExtensionA, public ExtensionB
{
  // ...
  void* get_extension(std::string name) override {
    // Casts below offset `this` to reference the corresponding vtable
    if (name == "ExtensionA") { return static_cast<ExtensionA*>(this); }
    if (name == "ExtensionB") { return static_cast<ExtensionB*>(this); }
    throw std::runtime_error("Unimplemented extension requested");
  }

  void ExtensionA_Method1(int param1, void* param2) override;
  void ExtensionA_Method2(int param1, void* param2) override;

  void ExtensionB_Method1(int param1, void* param2) override;
  void ExtensionB_Method2(int param1, void* param2) override;
};
```

```c
int MyModel_ExtensionA_Method1(struct Bmi *self, int param1, void* param2);
int MyModel_ExtensionA_Method2(struct Bmi *self, int param1, void* param2);

struct MyModel
{
  // ...

  struct ExtensionA extension_a = {
    .method1 = &MyModel_ExtensionA_Method1;
    .method2 = &MyModel_ExtensionA_Method2;
  };
};

// ...
int MyModel_get_extension(struct Bmi *self, const char *extension_name, void** extension_object) {
  struct MyModel *my_model = self->data;

  if (strcmp(extension_name, "ExtensionA") == 0) {
    *extension_object = &my_model->extension_a;
    return BMI_SUCCESS;
  }

  return BMI_FAILURE;
}
```

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

:::{tab-item} c
:sync: c
```c
int update(void *self);
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
:::{tab-item} c
:sync: c
```c
int update_until(void *self, double then);
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

:::{tab-item} c
:sync: c
```c
int finalize(void *self);
```
:::
::::

The `finalize` function should perform all tasks that take place
after exiting the model's time loop.  This typically includes
deallocating memory, closing files and printing reports.

**Implementation notes**

- In C and Fortran, an integer status code indicating success (zero) or failure (nonzero)
  is returned. In C++, Java, and Python, an exception is raised on failure.
