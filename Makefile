# Variables
BUILD_DIR = build
TARGET = Scoped
CMAKE_FLAGS = -DCMAKE_EXPORT_COMPILE_COMMANDS=ON

# Default target to run the build
all: $(BUILD_DIR)
	cmake --build $(BUILD_DIR)

# Target to create the directory and configure CMake
setup:
	mkdir -p $(BUILD_DIR)
	cmake -S . -B $(BUILD_DIR) $(CMAKE_FLAGS)
	ln -sf $(BUILD_DIR)/compile_commands.json .

# Force a complete rebuild
rebuild: clean setup all

# Clean up build artifacts
clean:
	rm -rf $(BUILD_DIR)
	rm -f compile_commands.json

run:
	./$(BUILD_DIR)/$(TARGET)

.PHONY: all setup rebuild clean
