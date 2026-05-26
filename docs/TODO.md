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

## Math

- Fix integration visual stretching
- Add scaling for integration and differentiation

## Measurements

- Add measurements (V_pp, V_rms, V_avg, V_min, V_max, freq, period)

## Other

- **Protocol Decoding / Bus Analysis**: Real-time decoding of serial protocols (I2C, SPI, UART, CAN, LIN, I2S) displayed time-aligned with physical traces.
- **Advanced Triggering Modes**:
  - Pulse Width / Glitch trigger (pulses narrower/wider than a threshold)
  - Runt trigger (pulses crossing one threshold but failing to cross the second)
  - Rise/Fall time triggers
  - Serial pattern match triggering
- **Digital Phosphor / Intensity Grading**: Visual persistence mapping where frequently hit pixels are brighter or color-coded, revealing jitter and rare glitches.
- **X-Y Mode (Lissajous Curves)**: Plotting Channel 1 against Channel 2 to show phase differences and component signatures.
- **Digital Filtering**: Selectable low-pass, high-pass, and band-pass filters per channel with adjustable cutoffs to clean up noisy inputs.
- **Mask / Limit Testing**: Define tolerance bands around a template waveform and trigger actions (stop, save screenshot) on violations.
- **Bode Plotting / FRA (Frequency Response Analysis)**: Sweeping a built-in generator frequency to plot gain and phase response over frequency.

