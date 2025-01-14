# tschibo00/hacktrick

This was a special project to bring Selectric I keycaps back to life in a MX keyboard.
It required conversion of the keycaps and rotated MX switches (i.e. "sideways").
The keyboard is gasket mounted with a special sound guidance feature to have a more bassy sound.

## hardware
- RPi2040 Zero
- Specifically designed for converted Selectric keycaps

## BOM
- PCB
- Plate
- RPi2040 Zero
- 34 diodes, e.g. 1N4148
- 33 Kailh hot-swap sockets
- 33 key switches of your liking (need simple stem, not box style or round)
- 33 key caps (I use converted Selectric I keycaps)
- Encoder, e.g. Bourns EC11 (I'm using dentless with 24ppr and push)
- 4 heat inserts M2.5 5.7x4.6mm
- 2 screws M2.5x20 (back)
- 2 screws M2.5x16 (front)
- 6 rubber pads 9.5mm diameter
- USB port extension (I used this for looks: https://www.aliexpress.us/item/3256804440339698.html)
- 5x3mm self-adhesive sealing tape for the gasket mount
- bottom case printed
- top case printed
- paint to your likings :)
- optional: 2x220 resistor + 2x LEDs
- optional: dampening (I use cork between PCB+plate and in case bottom)

## Rough build instructions
- Cut out the middle section of the PCB if not already cut out
  - BE AWARE you're cutting fiberglass. PLEASE take appropriate precautions to not risk your health!!!
- Drill a hole in the plate in the middle of the cut out section to accomodate for the encoder (if not yet drilled)
  - BE AWARE you're cutting fiberglass. PLEASE take appropriate precautions to not risk your health!!!
- solder the diodes on top
- solder the hot-swap sockets on bottom
- solder the RPi
- solder short cables (best ribbon) to the encoder. Solder cables to the headers or PCB directly
- carefully put the heat inserts into the case top
- mount USB extension cable and fix it inside the case
- add the sealing tape to the gaskets from all sides
- mount switches and plate
- push encoder through plate hole and tighten screw
- insert PCB sandwich into case top (this has the gasket mount)
- attach USB extension
- carefully close the case (upside down is easier)
- put in and gently tighten the screws
