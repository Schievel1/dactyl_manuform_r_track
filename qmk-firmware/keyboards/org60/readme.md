# QMK Firmware for 大橘子外设 (Large Orange Peripheral)'s 60% Org60 PCB

![Top View of a pair of XD60 Keyboards (same layout as Org60)](https://i.imgur.com/3Jq2743.jpg)


## Quantum MK Firmware
For the full Quantum feature list, see [the parent readme.md](/readme.md).

## Additional Notes

### GH60 Variant
The Org60 seems to be a variant of the XD60 (which is essentially a GH60 rev. C, with support for a right-hand arrow cluster), which has USB-C and built-in RGB underlighting.

Compatibility with GH60 expansion boards is unknown.

### Support
Board also supports in-switch LEDs (two-pin, single colour), as well as WS2182 LED strips for underglow lighting.

Default keymap included, matching configuration on sale page.

### Backlight Issues
Taken from [r/mk](https://www.reddit.com/r/MechanicalKeyboards/comments/6xsd5c/modification_discovered_the_org60_pcb_has_a/)

MOSFET that drives the in switch LEDs is not connected to a PWM pin. (It is connected to pin F5). Fix mentioned in reddit post re-routes to pin B5. You will have to change the pin to B5 in `config.h`

## Build
To build the default keymap, simply run `make org60:default`.