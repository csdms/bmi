Model Control Functions
=======================

These BMI functions are critical to plug-and-play modeling because
they allow a calling component to bypass a model's own time loop.
They also provide the caller with *fine-grained control* over the
model - a calling application is able to, for instance, update a
model one time step at a time, change its state, and then continue
updating.

Initialization
--------------

.. code-block:: java

    /* SIDL */
    void initialize(in string config_file);

.. code-block:: c

    /* C */
    int initialize(const char * config_file, void** handle);

.. code-block:: c++

    /* C++ */
    void Initialize (const char *config_file);

.. code-block:: fortran

   ! Fortran (>=2003)
   integer function initialize(this, config_file)
     class (*), intent(out) :: this
     character (len=*), intent(in) :: config_file


The `initialize` function accepts a string argument that gives the
name (and path) of its "main input file", or *configuration file*.
This function should perform all tasks that are to take place before
entering the model's time loop.  Models should be refactored, if
necessary, to read their inputs (which could include filenames for
other input files) from a configuration file (a text file).
CSDMS does not impose any constraint on how configuration files are
formatted, but a "template" of your model's config file (with
placeholder values) is needed when the BMI model is imported into 
a framework such as the CSDMS PyMT. This is considered part of the
model's BMI metadata.


Time stepping
-------------

.. code-block:: java

    /* SIDL */
    void update();
    void update_until(in double then);

.. code-block:: c

    /* C */
    int update(void *handle);
    int update_until(void *handle, double then);

.. code-block:: c++

    /* C++ */
    void Update(void);
    void UpdateUntil(double then);

.. code-block:: fortran

   ! Fortran (>=2003)
   integer function update(this)
     class (*), intent(inout) :: this
   integer function update_until(this, then)
     class (*), intent(inout) :: this
     double precision, intent(in) :: then


The `update` function advances the model by a single timestep. This
is the model's own internal timestep (as returned by the BMI
`get_time_step` function) - not the timestep of a controlling application.
This function should perform all tasks that take place during one
pass through the model's time loop.  It does not contain the time
loop. This typically includes incrementing all of the model's state
variables.  If the model's state variables don't change in time,
then they can be computed by the `initialize` function and this
function can just return without doing anything.

The `update_until` function updates the model to a particular time,
as provided by its *time* argument. Once called, the value returned
by the BMI `get_current_time` function must return the provided time
to reflect that the model was updated to the requested time.

.. note:: `update_until` is part of the BMI++

Finalization
------------

.. code-block:: java

    /* SIDL */
    void finalize();

.. code-block:: c

    /* C */
    int finalize(void *handle);

.. code-block:: c++

    /* C++ */
    void Finalize(void);

.. code-block:: fortran

   ! Fortran (>=2003)
   integer function finalize(this)
     class (*), intent(inout) :: this

The `finalize` function should perform all tasks that take place
after exiting the model's time loop.  This typically includes
deallocating memory, closing files and printing reports.
