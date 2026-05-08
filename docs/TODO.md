# Project TODOs

## UI / UX

- [ ] Fix hardcoded trigger source in `OscilloscopeUI::drawTriggerLine` (currently defaults to channel 0).
- [ ] Fix hardcoded FFT source in `OscilloscopeUI::drawFFTControl` (currently defaults to channel 0).
- [ ] Add a "Source" selector in the Trigger UI to switch between channels.
- [ ] Implement a selector for the timebase reference channel.

## Signal Processing

- [ ] Finish FFT magnitude calculation and populate trace data in `FFTProcessor::process`.
- [ ] Implement windowing functions (Hanning/Hamming) for FFT to reduce leakage.
- [ ] Add support for multiple FFT traces (one per channel).

## Hardware

- [ ] Add support for multiple concurrent hardware channels.
- [ ] Change FPGA USB to stream multiple channels and edit `OscilloscopeUI::drawHardwareStatus`.
