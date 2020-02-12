# CLIP STUDIO PAINT Macro pad for namecard2x4

this keymap is macro pad for CLIP STUDIO PAINT.
if keyboard settings is us keyboard, The key which does not work normally exists. change shortcut or change keymap.

## setting
change `keymap.c`'s `mode_mac` to `false`, enter win mode after keyboard startup.
change a mode temporarily from KEYBOARD layer.

## Keymap

### BASE layer

|||||
|---|---|---|---|
| pen | eraser | dropper | brush size increase(hold to transition CANVAS layer) |
| brush | fill | quick access(hold to transition KEYBOARD layer) | brush size reduce(hold to transition OTHER layer) |

> if use quick access, assign to `Shift + Q` for `File>Shortcut>Window>Quick Access` or `File>Shortcut>Popup Palette>Quick Access`

### CANVAS layer

|||||
|---|---|---|---|
| zoom in | zoom off | levoversion | - |
| zoom out | entire display | dextroversion | move tool |

### OTHER layer

|||||
|---|---|---|---|
| UnDo | Copy | Cut | Save |
| ReDo | Paste | Delete | - |

### KEYBOARD layer

|||||
|---|---|---|---|
| Win mode | - | - | - |
| Mac mode | - | - | - |
