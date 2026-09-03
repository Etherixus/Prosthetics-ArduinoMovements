# Prosthetics-ArduinoMovements

Arduino/C++ control code for an EMG-driven prosthetic hand, built with the
**Neurotechnology Exploration Team (NXT)** at Rochester Institute of Technology.

The hand uses MyoWare EMG sensors on the forearm to read muscle activation and
drives one hobby servo per finger through a five-servo assembly. This repository
collects the firmware, the per-subsystem bench tests written while bringing it
up, and the calibration work that was still in progress.

## Layout

```
Finger_Servo.ino    Main hand controller (5 servos, switch-triggered open/close)
sketches/           Standalone bench tests, one Arduino sketch folder each
experiments/        Work-in-progress code that does not currently compile
```

## Main controller — `Finger_Servo.ino`

Defines a `Servo` per digit (thumb, index, bird, ring, pinky) on pins 1–5, with
individual `*_MAX` / `*_MIN` travel limits per finger, since the fingers do not
share a range — the ring finger tops out at 110° where the pinky reaches 175°.
`openHand()` and `closeHand()` sweep the set, gated on a switch at pin 12.

## `sketches/` — bench tests

| Sketch | What it does |
| --- | --- |
| `MyoWare_Test` | Minimal EMG read: `analogRead(A4)` streamed to serial at ~100 Hz for inspecting raw sensor output |
| `Multiple_Fingers_Myoware_Detection` | Same idea on a second input, used while working toward per-finger channel separation |
| `servo_test` | Interactive continuous-servo tuning over serial — `s/f/F/r/R` to drive, `+/-` to trim the stop value live. This is how the neutral point per servo was found |
| `FingerTest` | Single-servo sanity check, sweeps one finger between 30° and 160° |
| `Fabric_Test_code` | Conductive-fabric pressure sensor: takes 10 `analogRead` samples over ~20 ms and averages them, then maps the result onto a 6-LED bar |
| `touch_test` | Analog fabric-contact threshold test (triggers between 229–255) |
| `sketch_sep18a` | Digital version of the same, `INPUT_PULLUP` with edge detection on D2 |

## `experiments/` — does not compile

Kept because the approach is worth preserving, not because it runs.

| Sketch | Status |
| --- | --- |
| `Emg_Callibration` | Guided per-muscle calibration: prompts for a fist, then an open hand, recording the EMG bounds for hand/thumb/index to derive thresholds. Unfinished — calls `analog.Read()` rather than `analogRead()`, calls `map()` with no arguments, and never includes `Servo.h` |
| `7_Servos_Outputs` | Power-supply test to confirm one rail could drive seven servos at once. Setup is complete; `loop()` ends on a bare `s7.write()` with no argument |
| `Finger_Servo` | Later bench iteration of the main controller — thumb moved to pin 7, main loop commented out to isolate a single servo. Contains a typo (`#define BIRD_PIN 3z`) |

## Hardware

- Arduino (5 V, servo-capable)
- MyoWare muscle sensors on analog inputs
- 5× hobby servos, one per digit
- Conductive-fabric contact sensors (fingertip feedback, exploratory)
- External supply for the servo rail — see `experiments/7_Servos_Outputs`

## Status

The mechanical actuation and per-finger servo control work. Raw EMG acquisition
works. The path between them — calibration, thresholding, and mapping muscle
activation onto finger positions — is the part that was still open when this
code was last touched.

## Provenance

Originally at `Neurotechnology-Exploration-Team/Prosthetics-ArduinoMovements`,
which is no longer reachable. The first two commits here preserve the original
2022 history and authorship; the sketch collection was added later from local
working copies.
