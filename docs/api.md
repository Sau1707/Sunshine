# API

Sunshine exposes a small administrative API for the web UI and automation.

## Authentication

Use the admin username and password configured in the web UI. Browser-based state-changing requests also require the
CSRF token flow used by the web UI.

## Active Endpoints

### Session and Pairing

- `GET /api/csrf-token`
- `POST /api/pin`
- `POST /api/apps/close`

`/api/apps/close` remains as a compatibility-oriented stop-session endpoint even though app management itself has been
removed from the product surface.

### Clients

- `GET /api/clients/list`
- `POST /api/clients/unpair`
- `POST /api/clients/unpair-all`

### Configuration

- `GET /api/config`
- `POST /api/config`
- `POST /api/password`

### Diagnostics and Host Control

- `GET /api/logs`
- `POST /api/reset-display-device-persistence`
- `POST /api/restart`

## Removed API Surface

The desktop-only refactor removed the active routing surface for:

- app catalog management
- cover upload and retrieval
- featured app flows
- ViGEmBus installation and status endpoints
