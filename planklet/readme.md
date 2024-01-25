# tschibo00/planklet
Ortho 3x13 layout with 2u in the middle column.
Added one backlight/sidelight WS2812 and a 5-digit 7-segment display from and old HP calculator for funsies.

## Flashing
Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

qmk flash -kb tschibo00/planklet -km default

## Todos
- [x] use correct space/underscore solution of bm40
- [x] solve mod tap with esc, MC_DEL for del/backsp and ' "
- [ ] find better solution for RGB light to store settings for both layers
- [x] add win left/right
- [x] fix buggy/flaky display update
- [ ] add more animation effects in game mode

~~- [ ] set pwm of all segments in init~~
