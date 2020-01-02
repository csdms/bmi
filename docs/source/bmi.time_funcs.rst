.. _time_funcs:

Time functions
--------------

These simple diagnostic functions provide information on model time.
Model time is always expressed as a floating point value.

.. _get_current_time:

*get_current_time*
..................

.. code-block:: java

   /* SIDL */
   int get_current_time(out double time);

The current model time.

**Implementation notes**

* In C++ and Python, the argument is omitted and the time is returned
  from the function.

.. _get_start_time:

*get_start_time*
................

.. code-block:: java

   /* SIDL */
   int get_start_time(out double time);

The start time of the  model.

**Implementation notes**

* The start time in BMI is typically defined to be 0.0.
* In C++ and Python, the argument is omitted and the time is returned
  from the function.


.. _get_end_time:

*get_end_time*
................

.. code-block:: java

   /* SIDL */
   int get_end_time(out double time);

The end time of the  model.

**Implementation notes**

* If the model doesn't define an end time, a large number (e.g.,
  1.0e6) is typically chosen.
* In C++ and Python, the argument is omitted and the time is returned
  from the function.


.. _get_time_units:

*get_time_units*
................

.. code-block:: java

   /* SIDL */
   int get_time_units(out string units);

Get the units of time as reported by the model's BMI (through
:ref:`get_current_time`, :ref:`get_end_time`, etc.).
It's recommended to use `time unit conventions`_ from Unidata's
`UDUNITS`_ package; e.g., `s`, `min`, `h`, `d`.

**Implementation notes**

* Avoid using `years` as a unit, if possible, since a year is
  difficult to define precisely.
* In C++ and Python, the argument is omitted and the units are returned
  from the function.


.. _get_time_step:

*get_time_step*
...............

.. code-block:: java

   /* SIDL */
   int get_time_step(out double time_step);

Get the time step used in the model.
The time step is always expressed as a floating point value.

**Implementation notes**

* A time step is typically a positive value. However, if the model
  permits it, a negative value can be used (running the model
  backward).
* In C++ and Python, the argument is omitted and the time step is returned
  from the function.
