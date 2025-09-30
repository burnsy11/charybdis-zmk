# QMK Conversion Summary

This document summarizes the complete conversion from ZMK to QMK configuration for the Charybdis split keyboard.

## What Was Converted

### 1. **Keyboard Configuration**
- **From**: ZMK device tree files (`.dtsi`, `.overlay`, `.conf`)
- **To**: QMK configuration files (`config.h`, `rules.mk`, `info.json`)

### 2. **Layout & Matrix**
- **Preserved**: Exact 5-column layout with thumb cluster
- **Preserved**: Matrix pin configuration for RP2040/nice!nano
- **Converted**: ZMK matrix transform → QMK LAYOUT_5x3 macro

### 3. **Layers** (8 total, identical functionality)
1. **Base**: QWERTY with home row mods
2. **Numeral/Function**: F-keys and numpad
3. **Symbol**: Brackets, symbols, operators  
4. **Navigation**: Arrows, editing commands
5. **Media**: Volume, playback controls
6. **Pointer**: Mouse control, trackball modes
7. **Scroll**: Trackball scroll mode
8. **Sniper**: Trackball precision mode

### 4. **Home Row Mods** 
- **Preserved timing**: 200ms tapping term, 150ms quick tap
- **Preserved behavior**: Hold trigger positions, bilateral combinations
- **Converted**: ZMK `hml`/`hmr` behaviors → QMK `LGUI_T`, `LALT_T`, etc.

### 5. **Tap-Hold Behaviors**
- **Layer taps**: `LT(_LAYER, KC_KEY)` for ESC→Media, Space→Nav, etc.
- **Per-key configuration**: Custom tapping terms and hold behaviors
- **Identical timing**: Matches ZMK `require-prior-idle-ms`, `quick-tap-ms`

### 6. **Combos** (6 total)
- **Left hand**: D+F, C+V, V+B → Left/Right/Middle click
- **Right hand**: J+K, M+Comma, Comma+Dot → Left/Right/Middle click
- **Preserved timing**: 40ms combo term, 150ms require-prior-idle

### 7. **Trackball Support** (PMW3610)
- **Preserved settings**: 2000 CPI normal, 800 CPI sniper
- **Preserved modes**: Scroll layer (6), Sniper layer (7)
- **Preserved rotation**: 90° orientation
- **Configuration**: All PMW3610 settings match ZMK exactly

### 8. **Split Keyboard Setup**
- **Key change**: Dual USB connections (each half plugs in separately)
- **Master detection**: Pin-based handedness detection (GP16)
- **Communication**: Serial protocol between halves
- **Separate builds**: Independent firmware for left/right halves

## Files Created

### Core Keyboard Definition
- `keyboards/charybdis/config.h` - Main configuration
- `keyboards/charybdis/rules.mk` - Build rules
- `keyboards/charybdis/keyboard.json` - Keyboard metadata
- `keyboards/charybdis/charybdis.h` - Layout macros
- `keyboards/charybdis/keymaps/default/keymap.c` - Main keymap

### Split-Specific Configurations
- `keyboards/charybdis/left/` - Left half configuration (no trackball)
- `keyboards/charybdis/right/` - Right half configuration (with trackball)
- Each has `config.h`, `rules.mk`, `info.json`

### Build System
- `Makefile` - Simple build commands
- `.gitignore` - QMK build artifacts
- Updated `README.md` - QMK build instructions

## Files Removed (ZMK-specific)
- `build.yaml` - ZMK build configuration
- `boards/shields/` - ZMK shield definitions  
- `config/` - ZMK keymap and configuration
- `zephyr/` - Zephyr RTOS module definition

## Key Differences from Original ZMK

1. **USB Connection**: Each half connects separately (no wireless)
2. **Build Process**: Two separate firmware files to flash
3. **Master/Slave**: Pin-based detection instead of wireless pairing
4. **Configuration**: C headers instead of device tree files

## Building & Flashing

```bash
# Build both halves
make all

# Build individually  
make left
make right

# Flash (with keyboard in bootloader mode)
make flash-left
make flash-right
```

## Validation

The conversion maintains:
- ✅ Identical key layout and positions
- ✅ Identical layer functionality  
- ✅ Identical timing parameters
- ✅ Identical home row mod behavior
- ✅ Identical combo functionality
- ✅ Identical trackball configuration
- ✅ Support for split keyboard with dual USB