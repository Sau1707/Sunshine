# Getting Started

Sunshine is now a desktop-first remote streaming server.

## Setup Flow

1. Install or build Sunshine on the host.
2. Start Sunshine.
3. Set admin credentials from the terminal.
4. Pair a Moonlight-compatible client.
5. Launch the single `Desktop` session.

## What Clients See

Clients do not browse host applications anymore. Sunshine exposes one built-in desktop session and streams the active
desktop when that entry is selected.

## First Run

On first run, Sunshine creates host TLS material if it does not already exist. Set admin credentials from the terminal:

```bash
sunshine --creds <username> <password>
```

## Recommended Host Setup

- Keep the host logged in to a graphical desktop session.
- Prefer wired networking when possible.
- Use hardware encoding if your GPU supports it.
- Expect keyboard and mouse input only.

## Pairing

Moonlight pairing remains the intended client workflow:

1. add the Sunshine host in Moonlight
2. run Sunshine with `-0` and enter the PIN shown by Moonlight in the terminal
3. connect to the `Desktop` session

## Session Model

When a session starts, Sunshine:

- captures the current desktop
- applies the client-requested desktop resolution by default
- encodes video
- captures host audio
- forwards keyboard and mouse input
- streams over the Moonlight-compatible transport
