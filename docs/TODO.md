# Project TODOs

## UI

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

- Implement FFT differentiate
- Once ADC sample rate is known, reimplement integration with `dt = 1/sample_rate` for physically accurate V·s output (requires `IChannel::getSampleRate()`)

## Measurements

- Add measurements (V_pp, V_rms, V_avg, V_min, V_max, freq, period)
