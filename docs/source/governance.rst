The Basic Model Interface (BMI): governance and decision-making
===============================================================

The purpose of this document is to formalize the governance process used for the
Basic Model Interface (BMI) in both ordinary and extraordinary situations, and
to clarify how decisions are made and how the various elements of our community
interact, including the relationship between open source collaborative
development and work that may be funded by for-profit or non-profit entities.

Summary
-------

The Basic Model Interface (BMI) is a community-owned and community-run project.
To the maximum extent possible, decisions about project direction are made by
community consensus (but note that "consensus" here has a somewhat technical
meaning that might not match everyone's expectations--see below). Some members
of the community additionally contribute by serving on the Steering Council (see
below), where they are responsible for facilitating the establishment of
community consensus, for stewarding project resources, and--in extreme
cases--for making project decisions if the normal community-based process breaks
down.

The Project
-----------

BMI is an open source software project (hereafter, the Project) affiliated with
the NSF-funded `Community Surface Dynamics Modeling System`_ (CSDMS). The goal
of the Project is to develop an open source software interface standard for
querying and controlling models. The Project also includes tools, documentation,
and examples to support and promote this standard. The software developed by the
Project is released under the MIT open source license, developed openly, and
hosted on public GitHub repositories under the csdms and other GitHub
organization. Proposed changes to the Project must follow the `CONTRIBUTING`_
document in the Project's main GitHub repository.

The Project is developed by a team of distributed developers, called
Contributors. Contributors are individuals who have contributed code,
documentation, designs, or other work to the Project. Anyone can be a
Contributor. Contributors can be affiliated with any legal entity or none.
Contributors participate in the project by submitting, reviewing, and discussing
GitHub pull requests and issues and participating in open and public Project
discussions on GitHub and other channels. The foundation of Project
participation is openness and transparency.

The Project Community consists of all Contributors and Users of the Project.
Contributors work on behalf of and are responsible to the larger Project
Community. We strive to keep the barrier between Contributors and Users as low
as possible.

Governance
----------

This section describes the governance and leadership model of the Project. The
foundations of Project governance are:

* Openness & Transparency
* Active Contribution
* Institutional Neutrality

Consensus-based decision making by the community
................................................

Normally, decisions on the Project will be made by consensus of all interested
Contributors. The primary goal of this approach is to ensure that the people who
are most affected by and involved in any given change can contribute their
knowledge in the confidence that their voices will be heard, because thoughtful
review from a broad community is the best mechanism we know of for creating
high-quality software.

The mechanism we use to accomplish this goal may be unfamiliar for those who are
not experienced with the cultural norms around free/open-source software
development. We provide a summary here, and highly recommend that all
Contributors additionally read the chapter `Social and Political
Infrastructure`_ of Karl Fogel's *Producing Open Source Software*, and in
particular the section on `Consensus-based Democracy`_, for a more detailed
discussion.

In this context, consensus does not require:

* that we wait to solicit everyone's opinion on every change,
* that we ever hold a vote on anything, or
* that everyone is happy or agrees with every decision.

For us, what consensus means is that we entrust everyone with the right to veto
any change if they feel it necessary. While this may sound like a recipe for
obstruction, this is not what happens. Instead, we find that most people take
this responsibility seriously, and only invoke their veto when they judge that a
serious problem is being ignored, and that their veto is necessary to protect
the Project. In practice, it turns out that vetoes are almost never
formally invoked because their mere possibility ensures that Contributors are
motivated from the start to find solutions that everyone can live with, thus
accomplishing our goal of ensuring that all interested perspectives are taken
into account.

How do we know when consensus has been achieved? In principle, this is
difficult, since consensus is defined by the absence of vetoes, which requires
us to somehow prove a negative. In practice, we use a combination of our best
judgment (e.g., a simple and uncontroversial bug fix posted on GitHub and
reviewed by a core developer is probably fine) and best efforts (e.g.,
substantive changes must not only follow the Project's CONTRIBUTING document,
but also be posted to the Project's designated communication channel in order to
give the broader community a chance to catch any problems and suggest
improvements; we assume that anyone who cares enough about BMI to invoke their
veto right should be on the Project's communication channel). If no one comments
on the Project's communication channel after several days, then it's probably
fine.

If one does need to invoke a formal veto, then it should consist of:

* an unambiguous statement that a veto is being invoked,
* an explanation of why it is being invoked, and
* a description of what conditions (if any) would convince the vetoer to
  withdraw their veto.

If all proposals for resolving some issue are vetoed, then the status quo wins
by default.

In the worst case, if a Contributor is genuinely misusing their veto in an
obstructive fashion to the detriment of the Project, then they can be ejected
from the Project by consensus of the Steering Council--see below.

Steering Council
................

The Project has a Steering Council (a.k.a. the BMI Council) that consists of
Project Contributors and Users. The overall role of the Council is to ensure,
with input from the Community, the long-term well-being of the Project, both
technically and as a community.

During everyday Project activities, Council Members participate in discussions,
code reviews, and other Project activities as peers with all other Contributors
and the Community. In these everyday activities, Council Members do not have any
special power or privilege through their membership on the Council. However, it
is expected that because of the quality and quantity of their contributions and
their expert knowledge of the Project that Council Members will provide useful
guidance, both technical and in terms of Project direction, to potentially less
experienced Contributors.

The Steering Council plays a special role in certain situations. In particular,
the Council may, if necessary:

* Make decisions about the overall scope, vision, and direction of the Project.
* Make decisions about strategic collaborations with other organizations or
  individuals.
* Make decisions about specific technical issues, features, bugs, and pull
  requests. They are the primary mechanism of guiding the code review process and
  merging pull requests.
* Update policy documents such as this one.
* Make decisions when regular community discussion doesn’t produce consensus on
  an issue in a reasonable time frame.

However, the Council's primary responsibility is to facilitate the ordinary
community-based decision making procedure described above. If the Council ever
has to step in and formally override the community for the health of the
Project, then they will do so, but they will consider reaching this point to
indicate a failure in their leadership.

Council decision making
.......................

If it becomes necessary for the Steering Council to produce a formal decision,
then they will use a form of the `Apache Foundation voting process`_. This is a
formalized version of consensus, in which +1 votes indicate agreement, -1 votes
are vetoes (and must be accompanied with a rationale, as above), and fractional
votes (e.g. -0.5, +0.5) can be used if one wishes to express an opinion without
registering a full veto. These numeric votes can also be used informally to get
a general sense of the Community's feelings on some issue. A formal vote only
occurs if explicitly declared, and if this does occur then the vote should be
held open for long enough to give all interested Council Members a chance to
respond--at least one week.

In practice, we anticipate that for most Council decisions (e.g., voting in new
members) a more informal process will suffice.

Council membership
..................

A list of current Steering Council Members is maintained at the page `Steering
Council`_.

To become eligible to join the Steering Council, an individual must be a Project
Contributor who has produced substantial contributions or a Project User that
has applied BMI in a substantial way. Candidate Council Members are nominated by
existing Council Members. The Candidate must confirm they are interested and
willing to serve in this capacity. The Candidate becomes a Member following
consensus of the existing Council. The Council will be initially formed from a
set of existing Project Contributors and Users who, as of early 2022, have been
currently active in Project development or application.

When considering potential Members, the Council will look at candidates with a
comprehensive view, including but not limited to code, code review,
applications, infrastructure work, communication channel participation,
community help/building, education and outreach, design work, etc. We are
deliberately not setting arbitrary quantitative metrics (like "100 commits in
this repo") to avoid encouraging behavior that plays to the metrics rather than
the Project's overall well-being. We want to encourage a diverse array of
backgrounds, viewpoints, and talents, which is why we explicitly do not define
code as the sole metric on which Council membership will be evaluated.

If a Council Member becomes inactive in the Project for a period of one year,
they will be considered for removal from the Council. Before removal, the
inactive Member will be approached to see if they plan on returning to active
participation. If not, they will be removed after a Council vote. If they plan
on returning to active participation, they will be given a grace period of one
year. If they do not return to active participation within that time period they
will be removed by vote of the Council without further grace period. All former
Council Members can be considered for membership again at any time in the
future, like any other Project Contributor or User. Retired Council members will
be listed on the project website, acknowledging the period during which they
were active in the Council.

The Council reserves the right to eject current Members if they are deemed to be
actively harmful to the Project's well-being, and if attempts at communication
and conflict resolution have failed. This requires the consensus of the
remaining Members.

Conflict of interest
....................

It is expected that Council Members will be employed at a range of universities,
government agencies, companies, and non-profit organizations. Because of this,
it is possible that Members will have conflict of interests. Such conflict of
interests include, but are not limited to:

* Financial interests, such as investments, employment or contracting work,
  outside of the Project that may influence their work on the Project.
* Access to proprietary information of their employer that could potentially leak
  into their work with the Project.

All members of the Council shall disclose to the rest of the Council any
conflict of interest they may have. Members with a conflict of interest in a
particular issue may participate in Council discussions on that issue, but must
recuse themselves from voting on the issue.

Private communications of the Council
.....................................

To the maximum extent possible, Council discussions and activities will be
public and done in collaboration and discussion with the Project Contributors
and Community. The Council will have a private communication channel that will
be used sparingly and only when a specific matter requires privacy. When private
communications and decisions are needed, the Council will do its best to
summarize those to the Community after eliding personal/private/sensitive
information that should not be posted to the public internet.

Subcommittees
.............

The Council can create subcommittees that provide leadership and guidance for
specific aspects of the Project. Like the Council as a whole, subcommittees
should conduct their business in an open and public manner unless privacy is
specifically called for. Private subcommittee communications should happen on
the communication channel of the Council unless specifically called for.

Institutional Partners and Funding
----------------------------------

The Steering Council is the primary leadership for the Project. No outside
institution, individual, or legal entity has the ability to own, control, usurp
or influence the Project other than by participating in the Project as
Contributors and Council Members. However, because institutions can be an
important funding mechanism for the project, it is important to formally
acknowledge institutional participation in the Project. These are Institutional
Partners.

An Institutional Contributor is any individual Project Contributor who
contributes to the project as part of their official duties as an Institutional
Partner. Likewise, an Institutional Council Member is any Project Steering
Council Member who contributes to the Project as part of their official duties
as an Institutional Partner.

With these definitions, an Institutional Partner is any recognized legal entity
in the United States or elsewhere that employs at least one Institutional
Contributor or Institutional Council Member. Institutional Partners can be
for-profit or non-profit entities.

Institutions become eligible to become an Institutional Partner by employing
individuals who actively contribute to the Project as part of their official
duties. To state this another way, the only way for a Partner to influence the
project is by actively contributing to the open development of the Project, in
equal terms to any other Contributor or Council Member. Merely using Project
software in an institutional context does not allow an entity to become an
Institutional Partner. Financial gifts do not enable an entity to become an
Institutional Partner. Once an institution becomes eligible for Institutional
Partnership, the Steering Council must nominate and approve the Partnership.

If at some point an existing Institutional Partner stops having any contributing
employees, then a one-year grace period commences. If at the end of this one
year period they continue not to have any contributing employees, then their
Institutional Partnership will lapse, and resuming it will require going through
the normal process for new Partnerships.

An Institutional Partner is free to pursue funding for their work on the Project
through any legal means. This could involve a non-profit organization raising
money from private foundations and donors or a for-profit company building
proprietary products and services that leverage Project software and services.
Funding acquired by Institutional Partners to work on the Project is called
Institutional Funding. However, no funding obtained by an Institutional Partner
can override the Steering Council. If a Partner has funding to do Project work
and the Council decides to not pursue that work, the Partner is free to pursue
it on their own. However in this situation, that part of the Partner's work will
not be under the Project umbrella and cannot use the Project trademarks in a way
that suggests a formal relationship.

Institutional Partner benefits are:

* Acknowledgment on Project websites, in talks, and on promotional material.
* Ability to acknowledge their own funding sources on Project websites, in
  talks, and on promotional material.
* Ability to influence the Project through the participation of their Council
  Member.

A list of current Institutional Partners is maintained at the page
`Institutional Partners`_.

Document history
----------------

https://github.com/csdms/bmi/commits/master/docs/source/governance.rst

Acknowledgments
---------------

Substantial portions of this document were adapted from the `NumPy governance
document`_.

License
-------

To the extent possible under law, the authors have waived all copyright and
related or neighboring rights to the BMI project governance and decision-making
document, as per the `CC-0 public domain dedication / license`_.



.. Links

.. _Community Surface Dynamics Modeling System: https://csdms.colorado.edu
.. _CONTRIBUTING: https://github.com/csdms/bmi/blob/master/CONTRIBUTING.rst
.. _Chapter 4: Social and Political Infrastructure
.. _Social and Political Infrastructure: https://producingoss.com/en/producingoss.html#social-infrastructure
.. _Consensus-based Democracy: https://producingoss.com/en/producingoss.html#consensus-democracy
.. _Apache Foundation voting process: https://www.apache.org/foundation/voting.html
.. _Steering Council: ./council.html
.. _Institutional Partners: ./partners.html
.. _NumPy governance document: https://numpy.org/doc/stable/dev/governance/index.html
.. _CC-0 public domain dedication / license: https://creativecommons.org/publicdomain/zero/1.0/
