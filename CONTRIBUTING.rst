.. highlight:: shell

============
Contributing
============

Contributions are welcomed and greatly appreciated!
BMI is a community-driven open source project, so every little bit helps.
`Credit`_ will always be given.

This document describes how to contribute to the BMI project.
It covers the main `BMI repository`_,
as well as the language specifications and examples
for supported languages
listed in `Table 1`_ of the `BMI documentation`_.

--------------
Making changes
--------------

The following sections describe the process through which changes to the BMI
specification, language bindings, language examples, and support tools are made.

Pull requests
~~~~~~~~~~~~~

If you'd like to propose a change to the BMI or any of its language
bindings, examples, or tools, you must submit a pull request (PR) to the
corresponding GitHub repository. If you have questions regarding a potential
change, or if you're unsure whether your proposed changes or additions are
acceptable, we recommend you first submit your question as a GitHub issue in the
corresponding repository, which can later be turned into a PR.

When a PR is opened against the BMI or any of its language bindings, examples,
or tools, it will be tagged either as a *Request for Comment* (RFC) or for
resolution through *lazy consensus*. The RFC process is intended for major
changes to the BMI, whereas lazy consensus applies to minor changes such as
typos or documentation updates.

Request for Comment (RFC)
~~~~~~~~~~~~~~~~~~~~~~~~~

Once a PR has been tagged as an RFC, a review process begins.
It proceeds in three steps:

1. discussion
2. summary
3. resolution

Discussion
..........

Reviewers (the other developers and interested community members) will write
comments on your PR to help you improve its implementation, documentation, and
style. Every single developer working on the project has their code reviewed,
and we've come to see it as friendly conversation from which we all learn and
the overall code quality benefits. Therefore, please don't let the review
discourage you from contributing: its only aim is to improve the quality of
project, not to criticize (we are, after all, very grateful for the time you're
donating!).

The author of the PR should try to build consensus and integrate feedback. An
RFC with broad support will be more likely to be quickly accepted than one
without comments. If you feel that your PR has been forgotten,
please feel free to reach out directly to the project team.

We expect that most PRs will not be accepted without some modification. You can
make changes by pushing commits directly to the PR branch and leaving comments
that explain the modifications.

Summary
.......

Once all parties have weighed in and there has been adequate discussion, the PR
moves to a summary period. A team member will move for the discussion
phase to end and for the summary period to begin, which will end with a
recommendation for the RPC (merge, close, or, postpone). Team members making
this motion should use their best judgment that adequate discussion has taken
place and that the consequences of the proposed change have been adequately
addressed.

The summary period will typically last about a week, allowing
stakeholders to have a chance to lodge any final objections before the team
reaches a final decision.

The intent is for this summary period to be fairly quiet, with most of the
discussion taking place during the discussion phase. There will likely be times,
however, where stakeholders might raise serious enough concerns that the PR
moves back into the discussion phase.

Resolution
..........

The RFC process concludes with the PR being merged, closed, or postponed.

There must be a *consensus* from project developers and interested community
members for a PR to be merged. Consensus has a particular meaning when used
with open source projects; see the `BMI governance document`_ for a definition
of consensus in this context.

If consensus isn't achieved, the PR will be postponed (the team feels the PR can
wait until some future time) or closed.

Lazy Consensus
~~~~~~~~~~~~~~

`Lazy consensus`_, as defined by the Apache Software Foundation, is a
decision-making policy which assumes general consent if no responses are posted
within a defined period.

For the BMI project, a PR tagged for resolution through lazy consensus can be
merged if no comments are posted within one week.

-------------------
Reporting a problem
-------------------

Report bugs or other problems by creating a GitHub issue at
https://github.com/csdms/bmi/issues.

In the issue, be sure to explain the problem and include additional details to
help maintainers reproduce the problem. Here are some suggestions that will make
it easier to track down the source of the problem:

* Use a clear and descriptive title for the issue that identifies the problem.
* Describe, and if possible provide a minimal example that demonstrates, the
  exact steps that reproduce the problem.
* Describe the behavior you are seeing after these steps.
* Describe the behavior you expect to see after these steps.

------------------
Providing feedback
------------------

The best way to send feedback is to file an issue at
https://github.com/csdms/bmi/issues.

If you are proposing a feature:

* Explain in detail how it would work.
* Keep the scope as narrow as possible, to make it easier to implement.
* Remember that this is a volunteer-driven project, and that contributions
  are welcome.


.. Links

.. _Credit: https://bmi.readthedocs.io/en/latest/credits.html
.. _BMI repository: https://github.com/csdms/bmi
.. _Table 1: https://bmi.readthedocs.io/en/latest/#id43
.. _BMI documentation: https://bmi.readthedocs.io
.. _BMI governance document: https://bmi.readthedocs.io/en/latest/governance.html
.. _Lazy consensus: https://community.apache.org/committers/lazyConsensus.html
