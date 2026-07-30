# Variables
BUILD_DIR = build
TARGET = Scoped
CMAKE_FLAGS = -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

.PHONY: all build setup rebuild clean run

# Default target
all: setup
	cmake --build $(BUILD_DIR)

# Alias for make build
build: all

# Configure CMake if build directory does not exist
setup:
	@if [ ! -d "$(BUILD_DIR)" ]; then \
		mkdir -p $(BUILD_DIR); \
		cmake -S . -B $(BUILD_DIR) $(CMAKE_FLAGS); \
		ln -sf $(BUILD_DIR)/compile_commands.json .; \
	fi

# Force a complete rebuild
rebuild: clean all

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR)
	rm -f compile_commands.json

run: all
	./$(BUILD_DIR)/$(TARGET)
