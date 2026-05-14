# Project TODOs

## UI / UX

- Fix hardcoded trigger source in `OscilloscopeUI::drawTriggerLine` (currently defaults to channel 0).
- Add a "Source" selector in the Trigger UI to switch between channels.
- Add a proper scale to signal and fft plots
- Add channel enable

## FFT

- Add vertical scale and offset

## Hardware

- Add support for multiple concurrent hardware channels.
- Change FPGA USB to stream multiple channels and edit `OscilloscopeUI::drawHardwareStatus`.

## Trigger

- Edge trigger level hardcoded for 8 bit ADC
