# Mini42 Miryoku Keymap

A Miryoku-style keymap for the Controller Works mini42 keyboard, implementing all 11 layers with tap dance layer switching and Mac clipboard shortcuts.

## Features

- **11 Layers**: BASE, EXTRA, TAP, BUTTON, NAV, MOUSE, MEDIA, NUM, NUMPAD, SYM, FUN
- **Tap Dance**: Double-tap required for layer switching and bootloader access
- **Mac Clipboard Shortcuts**: Undo, Cut, Copy, Paste, Redo using LGUI modifiers
- **Mod-Tap Keys**: Dual-function keys with 250ms tapping term

## Prerequisites

1. Install [QMK Toolbox](https://github.com/qmk/qmk_toolbox) (for flashing on macOS)
2. Or install QMK CLI:
   ```bash
   python3 -m pip install --user qmk
   qmk setup
   ```

## Building the Firmware

### Using QMK CLI

```bash
qmk compile -kb controllerworks/mini42 -km jvinding_mini42_miryoku
```

The compiled firmware will be located at:
```
qmk_firmware/.build/controllerworks_mini42_jvinding_mini42_miryoku.uf2
```

### Using Make (legacy)

```bash
make controllerworks/mini42:jvinding_mini42_miryoku
```

## Flashing the Firmware

### Method 1: Using QMK Toolbox (Recommended for macOS)

1. Open QMK Toolbox
2. Put your keyboard into bootloader mode:
   - **Physical reset**: Press the RST button twice rapidly
   - **Or** use the key mapped to `QK_BOOT` (double-tap the TD_BOOT key on any layer)
3. In QMK Toolbox:
   - Select the `.uf2` file from the build output
   - Click "Flash" or press the flash button
   - Wait for the "File written successfully" message

### Method 2: Using QMK CLI

```bash
qmk flash -kb controllerworks/mini42 -km jvinding_mini42_miryoku
```

**Note**: 
- The bootloader is automatically detected from the keyboard configuration (RP2040)
- Make sure your keyboard is in bootloader mode before running this command:
  - Double-tap the RST button on the PCB
  - Or hold the BOOTSEL button while plugging in the USB cable

### Method 3: Manual UF2 Flash

1. Put keyboard into bootloader mode (double-tap RST button)
2. The keyboard should appear as a USB drive
3. Copy the `.uf2` file to the USB drive
4. The keyboard will automatically flash and reboot

## Layer Overview

- **BASE**: Colemak layout with mod-tap keys on home row
- **EXTRA**: QWERTY variant layout
- **TAP**: Mod-tap adjustments overlay
- **BUTTON**: Mouse and clipboard shortcuts
- **NAV**: Navigation keys (arrows, page up/down, etc.)
- **MOUSE**: Mouse movement and buttons
- **MEDIA**: Media controls (volume, play/pause)
- **NUM**: Numbers and basic symbols
- **NUMPAD**: Full numpad layout
- **SYM**: Symbols and special characters
- **FUN**: Function keys (F1-F12)

## Key Layout

- **Outer columns** (columns 0 and 5) are disabled (`KC_NO`)
- **10 working keys per row** (columns 1-4 on each half)
- **3 thumb keys per half**

## Customization

Edit `keymap.c` to modify:
- Layer key assignments
- Tap dance configurations
- Clipboard shortcuts
- Mod-tap key mappings

Edit `config.h` to adjust:
- Tapping term
- Hold behavior settings
- Split keyboard options

## Troubleshooting

### Build Errors

- Ensure you're in the QMK firmware root directory
- Run `qmk setup` to update QMK
- Try `qmk compile -c` to clean build cache

### ARM Toolchain Issues (stdint.h missing)

If you encounter errors like `fatal error: stdint.h: No such file or directory`, your ARM toolchain is missing newlib (the embedded C library). This is common with Homebrew's `arm-none-eabi-gcc` version 15.x.

**Solution 1: Install Complete ARM GCC Embedded Toolchain (Recommended)**
```bash
brew install --cask gcc-arm-embedded
```

**Solution 2: Use Older Toolchain Version**
```bash
brew uninstall arm-none-eabi-gcc
brew install arm-none-eabi-gcc@8
```

**Solution 3: Install ARM Toolchain via xPack**
```bash
npm install -g xpm
xpm install --global @xpack-dev-tools/arm-none-eabi-gcc
```

After installing a complete toolchain, verify it works:
```bash
qmk doctor
```

All toolchain checks should pass.

### Flash Errors

- Make sure keyboard is in bootloader mode
- Try a different USB cable/port
- On macOS, you may need to grant permissions to QMK Toolbox in System Preferences > Security & Privacy

### Keymap Issues

- Verify the keymap compiles without errors
- Check that all layers are properly defined
- Ensure tap dance indices match the tap_dance_actions array

## References

- [QMK Documentation](https://docs.qmk.fm/)
- [Mini42 Keyboard](https://controller.works/products/mini42-low-profile-ergonomic-keyboard)
- [Miryoku Layout](https://github.com/manna-harbour/miryoku)

