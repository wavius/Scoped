# Build configuration
BUILD_DIR  ?= build
BUILD_TYPE ?= Release
TARGET     := Scoped
JOBS       ?= $(shell nproc 2>/dev/null || echo 4)
CMAKE_FLAGS := -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=$(BUILD_TYPE)

.PHONY: all build setup rebuild clean run release debug help

# Default target: build project
all: setup
	@cmake --build $(BUILD_DIR) -j$(JOBS)

# Alias for make all
build: all

# Configure CMake if build directory does not exist
setup: $(BUILD_DIR)/Makefile

$(BUILD_DIR)/Makefile:
	@mkdir -p $(BUILD_DIR)
	@cmake -S . -B $(BUILD_DIR) $(CMAKE_FLAGS)
	@ln -sf $(BUILD_DIR)/compile_commands.json .

# Build explicitly in Release mode
release:
	@rm -rf $(BUILD_DIR)
	@$(MAKE) BUILD_TYPE=Release all

# Build explicitly in Debug mode
debug:
	@rm -rf $(BUILD_DIR)
	@$(MAKE) BUILD_TYPE=Debug all

# Force a complete rebuild
rebuild: clean all

# Clean build directory and generated artifacts
clean:
	@rm -rf $(BUILD_DIR)
	@rm -f compile_commands.json

# Build and execute the target application
run: all
	@./$(BUILD_DIR)/$(TARGET)

# Show help output for available targets
help:
	@echo "Available targets:"
	@echo "  all     - Build project (default)"
	@echo "  build   - Alias for all"
	@echo "  run     - Build and run $(TARGET)"
	@echo "  release - Re-configure and build in Release mode"
	@echo "  debug   - Re-configure and build in Debug mode"
	@echo "  rebuild - Clean and rebuild project"
	@echo "  clean   - Remove build directory and compile_commands.json"
	@echo "  help    - Show this help message"

