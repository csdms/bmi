Time functions
--------------

.. code-block:: java

  double get_time_step()
  string get_time_units()
  double get_start_time()
  double get_current_time()
  double get_end_time()

..
   Use "String" instead of "string" so that your syntax highlighter catches it?

.. _get_time_units:

*get_time_units*
................

.. code-block:: java

  string get_time_units()

..
   Use "String" instead of "string" so that your syntax highlighter catches it?

Return the units of time as reported by the model's BMI (through
`get_current_time`_, `get_end_time`_, etc.).
CSDMS recommends using time unit conventions from Unidata's
`UDUNITS`_ package.

..
   Is there anything simple to add about the time units? If you go to that page, it takes a lot of clicks/time to get to acceptable time units. Can you easily list the common ones?

.. _get_time_step:

*get_time_step*
...............

.. code-block:: java

  double get_time_step()


.. _get_current_time:

*get_current_time*
..................

.. code-block:: java

  double get_current_time()


.. _get_start_time:

*get_start_time*
................

.. code-block:: java

  double get_start_time()


.. _get_end_time:

*get_end_time*
................

.. code-block:: java

  double get_end_time()
