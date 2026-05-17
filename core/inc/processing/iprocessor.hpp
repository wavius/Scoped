#pragma once

#include <common/trace.hpp>
#include <string>
#include <vector>

namespace Scoped {

class IChannel;

class IProcessorControl {
public:
  // Lifecycle
  virtual ~IProcessorControl() = default;

  // Accessors
  virtual std::string getName() const = 0;
  virtual bool isEnabled() const = 0;
  virtual float getVerticalScale() const = 0;
  virtual float getVerticalOffset() const = 0;
  virtual size_t getHorizontalScale() const { return 0; }
  virtual size_t getHorizontalOffset() const { return 0; }

  // Setters
  virtual void setEnabled(bool enabled) = 0;
  virtual void setVerticalScale(float scale) = 0;
  virtual void setVerticalOffset(float offset) = 0;
  virtual void setHorizontalScale(size_t /*scale*/) {}
  virtual void setHorizontalOffset(size_t /*offset*/) {}
};

// Base for processors operating across multiple channels.
class IVirtualProcessor : public IProcessorControl {
public:
  // Lifecycle
  virtual ~IVirtualProcessor() = default;

  // Pipeline
  virtual void process(const std::vector<IChannel *> &sources,
                       std::vector<Trace> &traces) = 0;
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
