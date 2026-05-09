# Project TODOs

## UI / UX

- [ ] Fix hardcoded trigger source in `OscilloscopeUI::drawTriggerLine` (currently defaults to channel 0).
- [ ] Add a "Source" selector in the Trigger UI to switch between channels.
- [ ] Implement a selector for the timebase reference channel.

## Signal Processing

- [ ] Refactor `calculateFFT` to use an **Iterative Cooley-Tukey** algorithm (avoid recursive allocations).
- [ ] Add **Logarithmic Scaling (dB)** for the FFT magnitude display.
- [ ] Add support for multiple FFT traces (one per channel).
- [ ] Add ability to switch between different FFT algorithms (e.g. Recursive vs Iterative).

## Hardware

- [ ] Add support for multiple concurrent hardware channels.
- [ ] Change FPGA USB to stream multiple channels and edit `OscilloscopeUI::drawHardwareStatus`.
