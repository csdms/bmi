Time functions
==============

.. code-block:: java

  double get_time_step()
  string get_time_units()
  double get_start_time()
  double get_current_time()
  double get_end_time()

Time units
----------

.. _get_time_units:

.. code-block:: java

  string get_time_units()

Return the units of time as reported by the model's BMI (through
`get_current_time`_, `get_end_time`_, etc.).

Time step
---------

.. _get_time_step:

.. code-block:: java

  double get_time_step()

Time
----

.. _get_current_time:
.. _get_start_time:
.. _get_end_time:

.. code-block:: java

  double get_start_time()
  double get_current_time()
  double get_end_time()
