# Configuration

Sunshine now exposes a smaller configuration surface aimed at remote desktop access instead of game streaming.

## Main Areas

### General

General settings cover:

- credentials
- logging
- state and certificate paths

### Input

Input configuration is limited to:

- keyboard enable/disable
- mouse enable/disable
- scancode behavior
- scrolling behavior
- pen/touch behavior where supported

Controller and gamepad configuration is no longer part of the supported product surface.

### Audio / Video

The audio/video section controls:

- capture backend selection
- encoder selection
- bitrate
- frame pacing
- audio sink selection
- display device selection and mode handling

### Network

Network settings still control:

- bind behavior
- ports
- encryption policy
- stream timeouts

### Advanced

Advanced settings remain available for platform-specific overrides, but the default direction is:

- desktop capture first
- fewer optional subsystems enabled by default
- no app catalog or launcher flow

## Default Session Model

Sunshine always provides a single built-in desktop session. The product no longer presents an app library as the main
streaming model.
