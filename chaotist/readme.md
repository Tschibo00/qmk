# tschibo00/chaotist

## Hardware
- RPi2040 Pico
- Custom ergoish layout to use all those beautiful keycaps that are lying around uselessly when you have only ortho 40s
- supports two options for the upper edge keys plus two options for bottom row

## Flashing
Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

qmk flash -kb tschibo00/chaotist -km default

## Todos
- [ ] correct keyboard matrix in info.json

## have a look

more or less up-to-date layout:

![keyboard layout](misc/layout.png)
