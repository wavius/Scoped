# Project TODOs

## UI

- Maybe move colors to traces. Right now its in the processor for Frequency domain and in the channel for Time domain.
- Add reset settings button for each tab
- Add a proper scale to signal and fft plots; this requires choosing an ADC so its on hold

## FFT

- Add vertical scale and offset

## Hardware

- Add support for multiple concurrent hardware channels
- Change FPGA USB to stream multiple channels and edit `OscilloscopeUI::drawHardwareStatus`

## Trigger

- Edge trigger level hardcoded for 8 bit ADC

## Math

- Fix integrate and differentiate

## Measurements

- Add measurements (V_pp, V_rms, V_avg, V_min, V_max, freq, period)
