# Project TODOs

## UI

- Add a proper scale to signal and fft plots; this requires choosing an ADC so its on hold

## Hardware

- Add support for multiple concurrent hardware channels
- Change FPGA USB to stream multiple channels and edit `OscilloscopeUI::drawHardwareStatus`

## Filter

- Fix beginning of filter array
- Add higher order filters

## Measurements

- Measurement visualizers and cursors

## FFT

- "None" window option

## Trigger

- Pulse Width
- Runt trigger
- Rise/Fall time triggers
- Serial pattern match triggering
- Delay/holdoff

## Other

- **Digital Phosphor / Intensity Grading**: Visual persistence mapping where frequently hit pixels are brighter or color-coded, revealing jitter and rare glitches.
- **X-Y Mode (Lissajous Curves)**: Plotting Channel 1 against Channel 2 to show phase differences and component signatures.