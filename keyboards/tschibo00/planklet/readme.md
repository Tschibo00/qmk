# tschibo00/planklet

## Flashing
Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

qmk flash -kb planklet -km default

## Todos
- [ ] use correct space/underscore solution of bm40
- [ ] solve mod tap with MC_DEL for del/backsp and ' "
- [ ] find better solution for RGB light to store settings for both layers
- [ ] add win left/right