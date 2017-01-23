Variable Getter and Setter Functions
====================================

.. code-block:: java

    void get_value(in string name, array<> buffer)
    void set_value(in string name, array<> value)


A *getter* is a function that your model provides that other
entities can call in order to get a variable from your model's
*state* (often as a reference).  Often a model's state variables
are changing with each time step, so getters are called to get
current values.

A *setter* is a function that your model provides that other
entities can call in order to change/overwrite a variable in
your model's state. A setter may impose restrictions on how a
state variable can be changed or check the new data for validity. 

``get_value`` takes a variable name and copies values into a
provided buffer.

``set_value`` takes a variable name and an array of values an
copies those values into its internal array of values.
