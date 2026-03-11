# Troubleshooting

This build is tuned for remote desktop streaming. Most issues now fall into one of these areas:

- host desktop session availability
- capture backend selection
- encoder availability
- audio capture
- input permissions

## Sunshine Starts But Streaming Fails

Check:

- the host is logged into a real desktop session
- the selected capture backend exists on the host
- a working encoder is available
- the client can reach the configured ports

## Black Screen

Try:

- using a different capture backend
- selecting a different encoder
- verifying the host display is active and not sleeping

## No Audio

Check the configured host audio sink and verify the OS is producing audio on that device.

## Keyboard or Mouse Input Does Not Work

This refactor keeps keyboard and mouse input only. If input fails:

- confirm the Sunshine process has permission to use virtual input devices
- verify `/dev/uinput` access on Linux
- confirm the host desktop session accepts injected input

## Pairing Problems

If Moonlight cannot pair:

- verify Sunshine is running
- confirm the client can reach the host
- check logs for certificate or credential setup problems
- retry from the pairing page in the web UI

## Not Supported

These are no longer supported troubleshooting targets for the main product flow:

- launching individual games or applications
- featured apps
- cover art downloads
- controller or gamepad emulation
- ViGEmBus setup through the web UI
