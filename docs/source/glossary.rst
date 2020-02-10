Glossary
========

A glossary of terms used with BMI.


.. glossary::

   $

      The default shell prompt.

   Anaconda

      A Python distribution that includes libraries for scientific
      computing and a package manager. See
      https://www.anaconda.com/distribution for more information.

   Basic Model Interface (BMI)

      A set a functions that are used to interact with and control a
      model. See https://bmi.readthedocs.io for more information.

   Community Surface Dynamics Modeling System (CSDMS)

      CSDMS is an NSF-funded program that seeks to transform the
      science and practice of earth-surface dynamics modeling. For
      more information, visit https://csdms.colorado.edu.

   class

      A program that acts as a template for creating
      :term:`objects<object>`.

   conda

      The package manager for :term:`Anaconda`. Also an informal name
      for an Anaconda installation.

   conda-forge

      A collection of community-built packages distributed by
      :term:`Anaconda`. See https://conda-forge.org.

   conda environment

      A :term:`conda` sub-installation that isolates a group of
      packages from the main conda installation.

   configuration file

      A file that contains information, including initial values of
      parameters, for setting up a :term:`model`.

   coupling

      See :term:`model coupling`.

   data

      Information held by an :term:`object`.

   edge

      A line or curve bounded by two :term:`nodes <node>`.

   exchange item

      A variable that a model with a BMI produces or consumes.
      Exchange items are public, not internal variables in the
      model. Exchange items should use :term:`Standard Names`.

   face

      A plane or surface enclosed by a set of :term:`edges <edge>`. In
      a 2D horizontal application one may consider the word "polygon",
      but in the hierarchy of elements the term "face" is most common.
      See also :term:`node`.

   grid

      A representation of a larger spatial domain by smaller discrete
      cells. See :ref:`model_grids` and :ref:`references`, as well as
      terms :term:`node`, :term:`edge`, and :term:`face`.

   grid identifier

      A unique object that labels (identifies) a model grid. Grid
      identifiers are integers, starting at zero. Often abbreviated
      "grid id". They're obtained through the :ref:`get_var_grid`
      function.

   grid node

      See :term:`node`.

   import

      The process of bringing code from a Python :term:`module` into
      another module or into an interactive Python session.

   instance

      See :term:`object`.

   method

      Programs that act upon the :term:`data` of an :term:`object`.

   model

      A computer program that attempts to describe a physical process
      with mathematical relationships that evolve over time and are
      solved numerically. For more information, see, for example,
      https://en.wikipedia.org/wiki/Numerical_modeling_(geology).

   model configuration file

      A file, usually in a text-based format, that lists the tunable
      parameters of a model and supplies their initial values.

   model coupling

      Models are *coupled* when they exchange inputs and outputs,
      often at the resolution of individual time steps. *One-way
      coupling* occurs when the outputs from one model are used as
      inputs to another model. *Two-way coupling* is when outputs from
      one model are used as inputs for another model, which in turn
      supplies its outputs to the first model as inputs, producing a
      feedback.

   module

      A file (with the ``.py`` extension) that contains Python code.

   node

      A point that has a coordinate pair or triplet: the most basic
      element of a grid. Variable values are typically calculated at
      nodes. See also :term:`face` and :term:`edge`.

   NumPy

      A Python library that provides arrays. Outputs from *pymt* are
      NumPy arrays. See also http://www.numpy.org.

   object

      A variable that is a concrete example of a
      :term:`class`. Objects have :term:`data` and
      :term:`methods<method>` that act upon those data.

   rank

      The number of dimensions of a model grid. A scalar has rank 0, a
      vector has rank 1, a rectilinear grid has rank 2, etc.

   refactor

      The act of modifying the internals of a program without changing
      the external behaviors of the program. Refactoring is often done
      to clean up code and improve its performance.

   Standard Names

      A semantic mediation technology developed at CSDMS for precisely
      matching variable names between models. For more information,
      see https://csdms.colorado.edu/wiki/CSDMS_Standard_Names.

   unit test

      A program that isolates and runs a section (a unit) of source
      code to ensure that it produces an expected result.
