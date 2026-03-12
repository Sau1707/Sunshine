# Sunshine

This repository is reduced to the parts needed to build and run the automated tests.

It keeps:

- the source code exercised by the tests
- the test suite
- the project documentation
- one GitHub Actions workflow that configures, builds, and runs the tests

It drops the upstream release, packaging, and distribution surface.

## Build

```bash
cmake -S . -B build -DBUILD_TESTS=ON
cmake --build build -j2
ctest --test-dir build/tests --output-on-failure
```

## Docs

- [Getting Started](docs/getting_started.md)
- [Configuration](docs/configuration.md)
- [Command Line](docs/api.md)
- [Building](docs/building.md)
- [Troubleshooting](docs/troubleshooting.md)
