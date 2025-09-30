# Makefile for building Charybdis QMK firmware

.PHONY: all left right clean flash-left flash-right

# Default target
all: left right

# Build left half
left:
	qmk compile -kb charybdis/left -km default

# Build right half  
right:
	qmk compile -kb charybdis/right -km default

# Clean build artifacts
clean:
	qmk clean

# Flash left half (requires keyboard in bootloader mode)
flash-left:
	qmk flash -kb charybdis/left -km default

# Flash right half (requires keyboard in bootloader mode)
flash-right:
	qmk flash -kb charybdis/right -km default

# Show help
help:
	@echo "Available targets:"
	@echo "  all        - Build both keyboard halves"
	@echo "  left       - Build left half only"
	@echo "  right      - Build right half only"
	@echo "  clean      - Clean build artifacts"
	@echo "  flash-left - Flash left half firmware"
	@echo "  flash-right- Flash right half firmware"
	@echo "  help       - Show this help message"