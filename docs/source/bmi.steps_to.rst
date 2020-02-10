.. _steps_to_bmi:

How to get started
==================

If you want to add a Basic Model Interface (BMI) to your own model,
here are some tips on getting started.

1. Take a look at the list of BMI
:ref:`control functions and their descriptions <basic_model_interface>`
to get an idea of what these functions are meant to do
and how they provide a standard set of controls for your model.

2. On the theory that it's often easier to start with an example and
modify it, we recommend starting with a copy of
the :ref:`BMI example code<specs_and_examples>`---look for the version
written in the language of your model---to use as a template.
Each link points to a GitHub repository that includes an
example model called "heat", and a corresponding BMI in a file called
"bmi_heat" (so, for example, the Python version is "bmi_heat.py",
the C version is "bmi_heat.c" and "bmi_heat.h", etc.).
You can grab copies by cloning the repository to your local machine
and doing a file copy from there,
or by selecting, copying, and pasting the code directly
into your favorite editor.

3. Modify each of the BMI functions in the template file so that it works
on your model, rather than on the original "heat" example. Depending
on how your model code is structured, you may need to do some
:term:`refactoring <refactor>`.
For example, if your model's initialization and main
processing are lumped together in the same body of code, you will need
to divide them into separate functions. Our experience is that codes
that are already modular usually need little or no modification,
whereas codes that are more monolithic tend to require a lot more
refactoring (but that is probably worthwhile anyway for the sake of
the quality and sustainability of the code!). Each case is a bit
different. We encourage you to contact us with questions by posting an
issue on the `CSDMS Help Desk`_.

4. Test it out. Try writing a program or script that initializes your
model with a simple test case using the :ref:`initialize` function,
runs it with the :ref:`update` or :ref:`update_until` functions,
and exchanges data using :ref:`get_value` and :ref:`set_value`.
Run a test to verify that you get the same output from your BMI'd model
that you got from it prior to BMI'ing.
(Note: we recommend writing a :term:`unit test` for each of your
BMI functions; to learn more about unit tests,
check out our `webinar`_).

5. *(Optional but cool)* With a few additional steps, you can make your
model operate as a :ref:`pymt <pymt>` component,
so you can drive it directly from a Python shell,
and write Python scripts to couple it with other models.
(Learn more about *pymt* :ref:`here <pymt>`, and through its `documentation`_.)
The CSDMS Integration Facility team can provide help and guidance on this
process: just contact us through the `CSDMS Help Desk`_.


.. Links:

.. _CSDMS Help Desk: https://github.com/csdms/help-desk
.. _webinar: https://csdms.colorado.edu/wiki/Presenters-0478
.. _documentation: https://pymt.readthedocs.io
