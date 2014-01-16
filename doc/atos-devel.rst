======================
ATOS Development Rules
======================

Python coding rules
-------------------

Follow coding style rules described in PEP8:
       http://www.python.org/dev/peps/pep-0008

Code coverage
-------------

Do not submit code not covered by "make check"

The following pragmas can be used in python comments to document and ignore
non-covered code:
- *pragma fatal*: used for fatal errors
- *pragma unreachable*: used for non-executable code
- *pragma uncovered*: used for code still not covered by tests
- *pragma branch_uncovered*: used for branches partially covered
- *pragma branch_always*: used for branch always taken

Release
-------

Internal checks before release:
- Run qualification tests
- Run example tests from tutorial
- Run interactive tests
- Update Codex documentation

