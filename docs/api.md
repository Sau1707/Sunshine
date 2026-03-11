# Command Line

Sunshine administration is terminal-driven.

## Supported Commands

- `sunshine --creds <username> <password>`
- `sunshine --set key=value [key=value ...]`
- `sunshine --help`
- `sunshine --version`
- `sunshine -0`

## Notes

- `--creds` writes persistent admin credentials to the configured credentials file.
- `--set` persists configuration overrides directly into the config file.
- `-0` reads the Moonlight pairing PIN from stdin.
- Relative and absolute config file paths are still supported as the positional file argument.
