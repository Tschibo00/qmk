# tschibo00/chaotist

## WARNING
This project is a personal project, i just built one prototype. It's not considered complete, nor tested or error-free.

I won't develop this much, just releasing it as-is for anybody knowledgable picking up and maybe building upon it.

It is NOT ready to take the files and produce a working keyboard!

## hardware
- RPi2040 Pico
- The current keymaps is designed as either QWERTZ or Colemak DH layout used with US International to have äöüß€ available for combos.
    - however only Colemak is actively developed
- To build the case with the given 3d file, the following additional material is required:
    - M2.5 x 10mm screws and bolts
    - if you want to add the weights, break out the inserts, add 15x2mm metal stripes (e.g. steel) and apply with double-sided tape

## Flashing
Enter the bootloader in 3 ways:

* **Bootmagic reset**: Hold down the key at (0,0) in the matrix (usually the top left key or Escape) and plug in the keyboard
* **Physical reset button**: Briefly press the button on the back of the PCB - some may have pads you must short instead
* **Keycode in layout**: Press the key mapped to `QK_BOOT` if it is available

qmk flash -kb tschibo00/chaotist -km default
qmk flash -kb tschibo00/chaotist -km qwertyFullBottom
qmk flash -kb tschibo00/chaotist -km colemakDhFullBottom

## have a look
![beauty shot](misc/beautyshot.jpg)

## Configurations

```
Regular layout
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│0/0  │0/1  │0/2  │0/3  │0/4  │0/5  │0/6  │0/7  │0/8  │0/9  │0/10 │0/11 │
│     │     │     │1u   │     │     │     │     │1u   │     │     │     │
│     │     │1.25u├─────┤1.5u │     │     │1.5u ├─────┤1.25u│     │     │
│     │1.75u├─────┤1/3  ├─────┤1.75u│1.75u├─────┤1/8  ├─────┤1.75u│     │
│     ├─────┤1/2  │1u   │1/4  ├─────┼─────┤1/7  │1u   │1/9  ├─────┤     │
│     │1/1  │1u   ├─────┤1u   │1/5  │1/6  │1u   ├─────┤1u   │1/10 │     │
│2.75u│1u   ├─────┤2/3  ├─────┤1u   │1u   ├─────┤2/8  ├─────┤1u   │2.75u│
├─────┴─────┤2/2  │     │2/4  ├─────┼─────┤2/7  │     │2/9  ├─────┴─────┤
│2/0        │     │     │     │2/5  │2/6  │     │     │     │2/11       │
│2u         │1.5u │1.75u│1.25u│1u   │1u   │1.25u│1.75u│1.5u │2u         │
├────────┬──┴──┬──┴─────┴─────┴─────┴─────┴─────┴─────┴──┬──┴──┬────────┤
│3/0     │3/2  │3/3                                   3/8│3/9  │3/11    │
│1.5u    │1u   │7u                                       │1u   │1.5u    │
└────────┴─────┴─────────────────────────────────────────┴─────┴────────┘
keymap (. are not used points in matrix)
xxxxxxxxxxxx
.xxxxxxxxxx.
x.xxxxxxxx.x
x.xx....xx.x
Alternative layout if more keys are required
┌─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┬─────┐
│0/0  │0/1  │0/2  │0/3  │0/4  │0/5  │0/6  │0/7  │0/8  │0/9  │0/10 │0/11 │
│     │     │     │     │     │     │     │     │     │     │     │     │
│1.5u │     │1.25u├─────┤1.5u │     │     │1.5u ├─────┤1.25u│     │1.5u │
├─────┤1.75u├─────┤1/3  ├─────┤1.75u│1.75u├─────┤1/8  ├─────┤1.75u├─────┤
│1/0  ├─────┤1/2  │1u   │1/4  ├─────┼─────┤1/7  │1u   │1/9  ├─────┤1/11 │
│     │1/1  │1u   ├─────┤1u   │1/5  │1/6  │1u   ├─────┤1u   │1/10 │     │
│1.25u│1u   ├─────┤2/3  ├─────┤1u   │1u   ├─────┤2/8  ├─────┤1u   │1.25u│
├─────┴─────┤2/2  │     │2/4  ├─────┼─────┤2/7  │     │2/9  ├─────┴─────┤
│2/0        │     │     │     │2/5  │2/6  │     │     │     │2/11       │
│2u         │1.5u │1.75u│1.25u│1u   │1u   │1.25u│1.75u│1.5u │2u         │
├────────┬──┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴─────┴──┬──┴──┬──┴──┬────────┤
│3/0     │3/2  │3/3  │3/4        │3/5  │3/7        │3/8  │3/9  │3/11    │
│1.5u    │1u   │1u   │2u         │1u   │2u         │1u   │1u   │1.5u    │
└────────┴─────┴─────┴───────────┴─────┴───────────┴─────┴─────┴────────┘
keymap (. are not used points in matrix)
xxxxxxxxxxxx
xxxxxxxxxxxx
x.xxxxxxxx.x
x.xxxx.xxx.x
```

# Todos
- [x] correct keyboard matrix in info.json
- [x] use correct del line macro
- [x] add macros from other code
- [x] add colemak dh
- [x] make better use of function layer
- [x] think about utilizing move layer better
- [x] move escape somewhere else to avoid accidental presses
- [x] add case file with build instructions
- [x] move more critical commands like boot to a special layer thats not triggered accidentally
- [-] try to use space/underscore again
- [x] add audio layer
- [x] add repeat on delete
- [x] add missing symbols like percent, angled brackets
- [x] use magic key as leader key and hold for shift
- [x] switch ; and : in base layer (or think of a better way to use the key :D)
- [ ] make layer switch permanent, when combined with leader key. switch back to base layer on next leader key press

