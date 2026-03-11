# Building

Sunshine uses CMake and now defaults to a lean desktop-streaming configuration.

## Recommended Toolchain

- CMake 3.25 or newer
- GCC 13+, Clang 17+, or Apple Clang 15+

## Core Dependencies

Package names vary by platform, but the reduced build expects:

- OpenSSL
- Opus
- platform capture/input dependencies

On Linux, a practical minimal build typically needs:

- `cmake`
- `pkg-config`
- `libopus`
- `libnuma`
- `libevdev`
- `libva`
- `libx11`

## Configure

```bash
cmake -S . -B build -DBUILD_TESTS=OFF -DBUILD_DOCS=OFF
```

The default Linux options are already trimmed:

- `SUNSHINE_ENABLE_TRAY=OFF`
- `SUNSHINE_ENABLE_CUDA=OFF`
- `SUNSHINE_ENABLE_DRM=OFF`
- `SUNSHINE_ENABLE_WAYLAND=OFF`
- `SUNSHINE_ENABLE_PORTAL=OFF`
- `SUNSHINE_ENABLE_X11=ON`
- `SUNSHINE_ENABLE_VAAPI=ON`

## Build

```bash
cmake --build build -j2
```

## Optional Overrides

If your target host needs them, explicitly re-enable optional backends during configure.
