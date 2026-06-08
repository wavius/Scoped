# Scoped

Scoped is a computer-based digital oscilloscope software built in C++.

![Preview](img/Scoped_preview.png)

## Features

Digital phosphor display, modular UI with dockable tabs. 

- **Trigger Engine:** Rising and falling edge triggering. Other types to be implemented.
- **FFT Processing:** Real-time FFT using `pocketfft`.
- **Math Operations:** Addition, subtraction, multiplication, inversion, integration, and FFT-based differentiation.
- **Digital Filters:** Lowpass, Highpass, Bandpass, and Bandstop filter responses. Butterworth, Bessel, Chebyshev filter types.
- **Measurements:** Vpp, Vrms, Vavg, Vmin, Vmax, Frequency, and Period.
- **Hardware:** Connect to FPGA frontend over USB.

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

The software side is mostly complete and fully functional with simulated inputs. The FPGA-based hardware frontend needs to be designed built.

Future software features are described in docs/TODO.md.

## Hardware Specs

- ADC: TBD
- FPGA: Muse LAB iCESugar-Pro v1.3 
