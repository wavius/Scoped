#include <displayframe.hpp>

namespace Scoped {

DisplayFrame::DisplayFrame(size_t size) : m_samples(size, 0) {}

const uint8_t *DisplayFrame::getSamples() const { return m_samples.data(); }

size_t DisplayFrame::getSize() const { return m_samples.size(); }

void DisplayFrame::copyFrom(const std::vector<uint8_t> &data) {
  m_samples = data;
}

} // namespace Scoped
