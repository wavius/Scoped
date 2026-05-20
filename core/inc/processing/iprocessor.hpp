#pragma once

#include <array>
#include <common/trace.hpp>
#include <string>
#include <vector>

namespace Scoped {

class IChannel;

// RGBA color: each component in [0.0, 1.0]
using Color = std::array<float, 4>;

enum class ProcessorType {
  FFT,
  Math,
  Unknown,
};

class IProcessorControl {
public:
  // Lifecycle
  virtual ~IProcessorControl() = default;

  // Accessors
  virtual std::string getName() const = 0;
  virtual ProcessorType getType() const = 0;
  virtual bool isEnabled() const = 0;
  virtual float getVerticalScale() const = 0;
  virtual float getVerticalOffset() const = 0;
  virtual size_t getHorizontalScale() const { return 0; }
  virtual size_t getHorizontalOffset() const { return 0; }
  virtual Color getColor() const { return {1.0f, 1.0f, 1.0f, 1.0f}; }

  // Setters
  virtual void setEnabled(bool enabled) = 0;
  virtual void setVerticalScale(float scale) = 0;
  virtual void setVerticalOffset(float offset) = 0;
  virtual void setHorizontalScale(size_t /*scale*/) {}
  virtual void setHorizontalOffset(size_t /*offset*/) {}
  virtual void setColor(const Color & /*color*/) {}
};

// Base for processors operating across multiple channels.
class IVirtualProcessor : public IProcessorControl {
public:
  // Lifecycle
  virtual ~IVirtualProcessor() = default;

  // Pipeline
  virtual void process(const std::vector<IChannel *> &sources,
                       std::vector<Trace> &traces,
                       size_t trigger_in_frame) = 0;
};

// Base class for signal processing stages.
template <typename HardwareT> class IProcessor : public IProcessorControl {
public:
  // Lifecycle
  virtual ~IProcessor() = default;

  // Pipeline
  // Applies the processing operation and generates/mutates traces.
  virtual void process(const std::vector<HardwareT> &raw_frame,
                       std::vector<Trace> &traces) = 0;
};

} // namespace Scoped
