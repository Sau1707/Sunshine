# Sunshine

Sunshine is a self-hosted remote desktop streaming server for Moonlight-compatible clients.

This refactored repository is intentionally focused on remote work instead of gaming. The server exposes a single
built-in desktop session and starts streaming the active desktop immediately when a client connects.

## What This Project Does

Sunshine keeps the core pieces needed for a practical remote desktop host:

- desktop capture
- video encoding
- host audio capture
- Moonlight-compatible pairing and streaming
- keyboard and mouse input forwarding
- terminal-driven configuration and administration

## What This Project No Longer Does

The desktop-only refactor removes the gaming-oriented product surface:

- no application launcher
- no app scanning or featured apps flow
- no controller or gamepad support
- no ViGEm workflow
- no profiles or per-game tuning model
- no browser-based configuration surface

## Default Behavior

Clients see one entry: `Desktop`.

Selecting that entry starts a remote desktop session. Sunshine does not launch a game or host application first.
By default, Sunshine also applies the incoming client resolution to the active desktop for the session.

## Terminal Administration

Administrative setup is done from the terminal:

- `sunshine --creds <username> <password>`
- `sunshine --set key=value [key=value ...]`
- `sunshine -0` to enter Moonlight pairing PINs on stdin

## Build

The repository now defaults to a reduced Linux feature set suitable for desktop streaming:

```bash
cmake -S . -B build -DBUILD_TESTS=OFF -DBUILD_DOCS=OFF
cmake --build build -j2
```

## Documentation

- [Getting Started](docs/getting_started.md)
- [Configuration](docs/configuration.md)
- [Command Line](docs/api.md)
- [Building](docs/building.md)
- [Troubleshooting](docs/troubleshooting.md)
