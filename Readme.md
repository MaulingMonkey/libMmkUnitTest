# libMmkUnitTest

MaulingMonKey's Unit Testing API.  No, the world didn't really need another unit testing library either.  Yes, I wrote one anyways.

Project Goals:
- Cross Platform - E.g. I shouldn't have to customize anything to get a sane Android unit testing story.  Not quite there yet.
- No Config - aiming to have "perfect" NuGet integration, with .libs, sane defaults, and source compilation fallback.

License: [Apache 2.0](LICENSE.txt)

# TODO

- The rest of this README
- Creation of Android .apk s for unit test .so s from a template without requiring a wrapper project.
- Move more junk to .cpp files
- Customize src builds to output non-conflicting .obj files
- Regression/comparison testing (separate project?)
- Fuzz testing (separate project?)
- Chaos monkey failure testing (separate project?)

# Development

## Terminology
| Category | A grouping of unit tests (via MMK_UNIT_TEST_CATEGORY) |
| Test     | An individual MMK_UNIT_TEST test / entry point        |
| Check    | An individual ASSERT_X or REQUIRE_X macro invokation. |
