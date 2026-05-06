# Scoped Architecture

## Data Pipeline

```text
USB Hardware ──► Oscilloscope ──► HardwareChannel (Buffer) ──► Raw Frame ──► IProcessor[] ──► Trace[] 
                 (Hub/Trigger)                                                                     │
                                                                                                   ▼
                                      VirtualChannel (Math/Logic) ◄── IVirtualProcessor ◄── Trace[]
                                                                                                   │
                                                                                                   ▼
                                                       Trace[] ──► UI Router ──► IntensityMap (Time Domain)
                                                                             └──► ImPlot Line (Frequency Domain)
```

The pipeline is split into structural layers:
- **Oscilloscope (Hub)** coordinates hardware, global triggers, and implements a **Two-Pass Update Engine** (updating hardware channels first, then virtual channels).
- **IChannel / Channel** abstracts data sources. `HardwareChannel` handles buffer acquisition. `VirtualChannel` evaluates cross-channel logic. Both output `Trace` objects.
- **Processors** act as generators, taking frames and mutating or creating new trace representations (e.g., adding an FFT Trace).
- **UI** iterates over generated traces and routes them to the correct plotting subsystem based on their `Domain` metadata.

## Objects

### Oscilloscope
The central core abstraction. Owns the hardware connection (`USBDevice`), the global trigger engine (`ITrigger`), and an array of abstract `IChannel` objects. Provides multi-channel synchronization by evaluating a trigger on a source channel and capturing a time-aligned frame across all channels simultaneously using a Two-Pass execution model.

### CircularBuffer\<T\>
Lock-free ring buffer for raw sample acquisition.

### ITrigger
Abstract base for type-agnostic trigger strategies. Operates on normalized float samples from an `IChannel` to avoid coupling with specific hardware bit-depths.
- Exposes `getUIParameters()` and `getTriggerLevels()` so the UI can dynamically generate controls (sliders, combos) and draw trigger lines.
- **EdgeTrigger** — Fires when a sample crosses a threshold with hysteresis. Supports rising/falling edge selection.

### IProcessor\<HardwareT\> & IVirtualProcessor
- **IProcessor** applies isolated signal processing on a raw frame within a hardware channel.
- **IVirtualProcessor** takes data from multiple channel traces and produces new traces (e.g., Math CH1 + CH2).

### Trace
A single output artifact representing a plottable line or matrix. Contains metadata such as `Domain::Time` or `Domain::Frequency` along with localized scaling parameters. Extensible for Decoders and Measurements.

### IChannel, Channel\<HardwareT\> & VirtualChannel
- **IChannel**: Type-agnostic interface exposing normalized samples and output traces.
- **Channel\<HardwareT\>**: A concrete hardware pipeline owning a buffer and processor chain.
- **VirtualChannel**: A channel without a buffer that queries traces from other source channels and applies `IVirtualProcessor`s.

### IntensityMap
2D hit-count grid for digital phosphor display. Accepts time-domain normalized data and rasterizes using Bresenham lines.

### USBDevice
CDC bulk-transfer interface for the iCESugar-Pro FPGA. Runs a background thread that streams raw bytes into the active hardware channel.

## File Map

| File | Role |
|---|---|
| `oscilloscope.hpp` | Central hub, Two-Pass updater & triggers |
| `circularbuffer.hpp` | Ring buffer (header-only template) |
| `trigger.hpp` | ITrigger + EdgeTrigger |
| `trace.hpp` | Trace object + Domain metadata |
| `processor.hpp` | IProcessor interface (header-only template) |
| `channel.hpp` | IChannel, Channel\<T\>, VirtualChannel |
| `intensitymap.hpp/.cpp` | Phosphor display rasterizer |
| `usb.hpp/.cpp` | Hardware acquisition |
| `ui.hpp/.cpp` | ImGui/ImPlot rendering + display ownership |
| `main.cpp` | SDL lifecycle + main loop |
