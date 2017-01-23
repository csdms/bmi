.. bmi documentation master file, created by
   sphinx-quickstart on Tue Jan  3 13:30:36 2017.
   You can adapt this file completely to your liking, but it should at least
   contain the root `toctree` directive.

The Basic Model Interface
=========================

The Basic Model Interface (BMI) is a library specification to
simplify the coupling of models.

Motivation
----------

.. image:: images/bmi_logo.png
   :scale: 10 %
   :align: right
   :alt: The Basic Model Interface

Development of scientific modeling software increasingly requires
the coupling of multiple, independently developed models.
Component-based software engineering enables the integration of
plug-and-play components, but significant additional challenges
must be addressed in any specific domain in order to produce a
usable development and simulation environment that also encourages
contributions and adoption by entire communities. In this paper we
describe the challenges in creating a coupling environment for
Earth-surface process modeling and the innovative approach that
we have developed to address them within the Community Surface
Dynamics Modeling System.


User Guide
----------

.. toctree::
   :maxdepth: 2

   bmi.spec
   csdms

References
==========

.. [CSDMS] The Community Surface Dynamics Modeling System

   https://csdms.colorado.edu

.. [BmiDocs] BMI documentation

   https://github.com/csdms/bmi

.. [BmiGitHub] BMI description and bindings

   https://github.com/csdms/bmi

.. [Peckham2013] `Computers & Geosciences article <http://www.sciencedirect.com/science/article/pii/S0098300412001252>`_ that describes BMI

  Scott D. Peckham, Eric W.H. Hutton, Boyana Norris, *A component-based
  approach to integrated modeling in the geosciences: The design of
  CSDMS*, Computers & Geosciences, Volume 53, April 2013, Pages 3-12,
  ISSN 0098-3004, http://dx.doi.org/10.1016/j.cageo.2012.04.002.


Indices and tables
==================

* :ref:`genindex`
* :ref:`modindex`
* :ref:`search`

