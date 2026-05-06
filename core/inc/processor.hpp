#pragma once

#include <cstdint>
#include "trace.hpp"
#include <vector>

namespace Scoped {

/// Base class for signal processing stages.
///
/// Processors transform a triggered frame in-place and are chained
/// between the trigger output and the display engine.
template <typename HardwareT>
class IProcessor {
public:
  // ---------------------------------------------------------------------------
  // Lifecycle
  // ---------------------------------------------------------------------------

  virtual ~IProcessor() = default;

  // ---------------------------------------------------------------------------
  // Pipeline
  // ---------------------------------------------------------------------------

  /// Applies the processing operation and generates/mutates traces.
  virtual void process(const std::vector<HardwareT> &raw_frame, std::vector<Trace> &traces) = 0;
};

} // namespace Scoped
