(extensions)=

# BMI Extensions

An extension of BMI is identified by a unique name string. It could
encompass one or several of the following:

- Added functions exposed through extension objects that models export
  via `get-extension-object`
- Variable sets that callers can expect models to publish
- Shared conventions of calling sequences or protocols around the use
  of existing functions in core BMI or other extensions

Models implementing BMI are not required to support these extensions,
nor any others.


## Added Functions

Added functions in an extension must be expressed as members of an
{term}`extension object`. Models expose these extension objects via
`get-extension-object`. The name string should match the name of the
extension itself. If an extension needs to expose multiple distinct
objects, the name used for each should be an elaboration of the
extension's name.

The extension must specify the type signature of each extension object
it defines, with all of its members. For interoperability, develoeprs
are encouraged to use types and calling conventions that follow the
practices of core BMI. However, this standard also anticipates that
extensions may be used to explicitly obtain functionality that is
specific to a programming language or platform.

## Published Variable Sets

Extensions may define a variable set or sets that models and callers
can use to enrich their interactions. If a single name, it should
match that of the extension. Multiple names should each be an
elaboration of the extension's name. Extensions are free to define the
semantics of these sets as they please.

## Shared Conventions and Protocols

Extensions may describe added constraints or enrished semantics for
how models and callers will interact using existing function in core
BMI or extensions they otherwise depend on.

## Relationship of Standardized Extensions to developers and the BMI specification process

The extensions described here have been designed and adopted by the
BMI council. They are standardized to support a common, interoperable
ecosystem of models and callers. We encourage development of other
extensions, and recommend that they follow the practices of extensions
described here. The BMI council only intends to standardize key
extensions that it expects will be broadly applicable. Extensions that
build on BMI for niche use cases are encouraged, and do not require
the BMI council's endorsement.

Nevertheless, the council appreciates being told of substantial
extensions, to better understand BMI usage and inform subsequent
development. The council can potentially provide design guidance and
share related experience.  Presentations about extensions can act as
an informal peer-reviewed venue.
