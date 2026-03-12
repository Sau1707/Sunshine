# Building

The repository now builds the test target only.

## Recommended Toolchain

- CMake 3.20 or newer
- Ninja or Make
- GCC 13+ or Clang 17+

## Linux Dependencies

Package names vary by distro, but the test build expects these development packages:

- Boost
- OpenSSL
- Opus
- PulseAudio
- libevdev
- libdrm
- libva
- libX11
- libXfixes
- libxcb-dri3
- libcap
- Wayland headers

## Configure

```bash
cmake -S . -B build -DBUILD_TESTS=ON
```

## Build

```bash
cmake --build build -j2
```

## Run Tests

```bash
ctest --test-dir build/tests --output-on-failure
```
