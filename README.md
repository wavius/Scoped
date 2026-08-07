# Scoped

Scoped is a C++ software oscilloscope with an FPGA frontend.

![Preview](docs/img/preview_2ch.png)

## Features

Scoped is designed with a modern, modular user interface featuring fully dockable tabs.

- **Display:**
  - Hardware-accelerated digital phosphor rendering.
  - Controls for vertical/horizontal scale and offset for each trace.

- **Trigger:**
  - Rising and falling edge triggering.
  - Source and level selection.

- **FFT:**
  - Real-time Fast Fourier Transform powered by `pocketfft`.
  - **Window functions:** Rectangular, Hanning, Hamming, Blackman-Harris, Flat Top.
  - Linear or Decibel (dB) scale.

- **Math:**
  - Addition, Subtraction, Multiplication, Inversion, Integration, Differentiation.

- **Filters:**
  - Cascaded dual-biquad filter architecture.
  - **Responses:** Lowpass, Highpass, Bandpass, Bandstop.
  - **Topologies:** Butterworth, Bessel, Chebyshev.
  - Frequency response graph.

- **Measurements:**
  - Vpp, Vrms, Vavg, Vmin, Vmax, Frequency, and Period.

- **Hardware Integration:**
  - Connection to FPGA frontend over USB or UART.

## Building from Source

CMake (>= 3.15) and C++20 compiler.

### Dependencies

- SDL2 (`libsdl2-dev`)
- OpenGL (`libgl1-mesa-dev`)
- libusb-1.0 (`libusb-1.0-0-dev`)
- pkg-config

### Compilation

```bash
make setup
make all
make run
```

## Next Steps

The software side is mostly complete and fully functional with simulated inputs. The FPGA-based hardware frontend needs to be designed and built.

Future software features are described in docs/TODO.md.

## Hardware Specs

### ADC

AD9226
- 65M samplers per second (max)
- 12-bit resolution

<br>
<div align="left">
  <img src="docs/img/boards/ad9226.png" alt="AD9226" width="600px">
</div>
<br>

### FPGA

Lattice ECP5
- Muse LAB iCESugar-Pro v1.3

<br>
<div align="left">
  <img src="docs/img/boards/icesugar_pro.jpg" alt="iCESugar-Pro v1.3" width="600px">
</div>
<br>

### USB PHY

USB3300

<br>
<div align="left">
  <img src="docs/img/boards/usb3300.jpg" alt="iCESugar-Pro v1.3" width="600px">
</div>
<br>
