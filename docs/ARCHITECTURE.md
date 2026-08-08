# Scoped Architecture

## Data Pipeline

<br>
<div align="left">
  <img src="img/flowchart1.png" height="600">
  <img src="img/flowchart2.png"" height="600">
</div>
<br>

The pipeline is split into structural layers:

- **Oscilloscope (Hub)** coordinates hardware, global triggers, and implements a **Two-Pass Update Engine** (updating hardware channels first, then virtual channels).
- **IChannel / Channel** abstracts data sources. `HardwareChannel` handles buffer acquisition. `VirtualChannel` evaluates cross-channel logic. Both output `Trace` objects.
- **Processors** act as generators, taking frames and mutating or creating new trace representations (e.g., adding an FFT Trace or filtered traces).
- **UI** iterates over generated traces and routes them to the correct plotting subsystem based on their `Domain` metadata.

## Objects

### Oscilloscope

The central core abstraction. Owns the hardware connections (`USBDevice` / `UARTDevice`), the global trigger engine (`ITrigger`), and an array of abstract `IChannel` objects. Provides multi-channel synchronization by evaluating a trigger on a source channel and capturing a time-aligned frame across all channels simultaneously using a Two-Pass execution model.

### CircularBuffer\<T\>

Lock-free ring buffer for raw sample acquisition.

### ITrigger

Abstract base for type-agnostic trigger strategies. Operates on normalized float samples from an `IChannel` to avoid coupling with specific hardware bit-depths.

- Exposes `getUIParameters()` and `getTriggerLevels()` so the UI can dynamically generate controls (sliders, combos) and draw trigger lines.
- **EdgeTrigger** — Fires when a sample crosses a threshold with hysteresis. Supports rising/falling edge selection.

### IProcessor\<HardwareT\> & IVirtualProcessor

- **IProcessor** applies isolated signal processing on a raw frame within a hardware channel. Implementations include `FilterProcessor`, `FFTProcessor`, and `MeasurementProcessor`.
- **IVirtualProcessor** takes data from multiple channel traces and produces new traces. For example, `MathProcessor` handles operations like CH1 + CH2.

### Trace

A single output artifact representing a plottable line or matrix. Contains metadata such as `Domain::Time` or `Domain::Frequency` along with localized scaling parameters. Extensible for Decoders and Measurements.

### IChannel, Channel\<HardwareT\> & VirtualChannel

- **IChannel**: Type-agnostic interface exposing normalized samples and output traces.
- **Channel\<HardwareT\>**: A concrete hardware pipeline owning a buffer and processor chain.
- **VirtualChannel**: A channel without a buffer that queries traces from other source channels and applies `IVirtualProcessor`s.

### IntensityMap

2D hit-count grid for digital phosphor display. Accepts time-domain normalized data and rasterizes using Bresenham lines.

### Hardware Interface

Provides data acquisition from the FPGA backend.
- **USBDevice**: CDC bulk-transfer interface running a background thread for high-speed streaming.
- **UARTDevice**: Slower serial interface for stable data capture at lower sampling rates.

## File Map

The codebase is organized into four main modules within the `core` directory:

### `common/`
Core data structures and base interfaces.
| File | Role |
|---|---|
| `oscilloscope.hpp` | Central hub, Two-Pass updater & triggers |
| `channel.hpp` | IChannel, Channel\<T\>, VirtualChannel |
| `trace.hpp` | Trace object + Domain metadata |
| `circularbuffer.hpp` | Ring buffer (header-only template) |
| `constants.hpp` | Global configuration constants |

### `hardware/`
Physical communication layers.
| File | Role |
|---|---|
| `usb.hpp/.cpp` | High-speed USB CDC acquisition |
| `uart.hpp/.cpp` | Serial UART acquisition |

### `processing/`
Signal processing nodes.
| File | Role |
|---|---|
| `iprocessor.hpp` | Base templates for IProcessor and IVirtualProcessor |
| `trigger.hpp` | ITrigger + EdgeTrigger |
| `filter_processor.hpp` | IIR/FIR filter implementation |
| `fft_processor.hpp` | Real-time Fast Fourier Transform |
| `math_processor.hpp` | Cross-channel math operations |
| `measurement_processor.hpp` | Waveform statistics (Vpp, Vrms, Freq) |
| `window.hpp` | Window functions for FFT |

### `ui/`
User Interface and rendering.
| File | Role |
|---|---|
| `ui.hpp/.cpp` | Main UI layout, rendering loops |
| `ui_*.cpp` | Submodules for Channels, FFT, Math, Filters |
| `intensitymap.hpp/.cpp` | Phosphor display rasterizer |
| `ui_helpers.hpp` | ImGui helper utilities |
| `colors.hpp` | Centralized color themes |

### Root
| File | Role |
|---|---|
| `main.cpp` | SDL lifecycle + main loop initialization |
