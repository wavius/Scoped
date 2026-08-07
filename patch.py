import re

with open("core/inc/common/channel.hpp", "r") as f:
    content = f.read()

# Fix extractAndProcessFrame
content = re.sub(
r"    size_t half_vis = m_horizontal_scale / 2;.*?base_trace\.data\[i\] = Constants::ADC_VMIN \+ \(static_cast<float>\(m_raw_frame\[time_start \+ i\]\) / Constants::ADC_LEVELS\) \* v_range;\n    }",
r"    base_trace.data = m_float_frame;",
content, flags=re.DOTALL)

# Fix reprocessLastFrame
content = re.sub(
r"    size_t half_vis = m_horizontal_scale / 2;.*?base_trace\.data\[i\] = Constants::ADC_VMIN \+ \(static_cast<float>\(m_raw_frame\[time_start \+ i\]\) / Constants::ADC_LEVELS\) \* v_range;\n    }\n\n    m_traces\.push_back\(std::move\(base_trace\)\);\n\n    m_float_frame\.resize\(actual_width\);\n    for \(size_t i = 0; i < actual_width; \+\+i\) \{\n      m_float_frame\[i\] = Constants::ADC_VMIN \+ \(static_cast<float>\(m_raw_frame\[i\]\) / Constants::ADC_LEVELS\) \* v_range;\n    }",
r"""    m_float_frame.resize(actual_width);
    float v_range = Constants::ADC_VMAX - Constants::ADC_VMIN;
    for (size_t i = 0; i < actual_width; ++i) {
      m_float_frame[i] = Constants::ADC_VMIN + (static_cast<float>(m_raw_frame[i]) / Constants::ADC_LEVELS) * v_range;
    }
    
    base_trace.data = m_float_frame;
    m_traces.push_back(std::move(base_trace));""",
content, flags=re.DOTALL)

with open("core/inc/common/channel.hpp", "w") as f:
    f.write(content)
