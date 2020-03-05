Cowm is a dynamic tiling window manager for X and a fork of [dwm](https://dwm.suckless.org/), is designed to be easy to use, EWMH compliant and themable like [LeftWM](https://github.com/leftwm/leftwm).

The changes from dwm have been made around the idea of easy and quick personalization. The goal is to create a version of dwm entirely customizable via X resources and that can be easily used with tools like [polybar](https://github.com/polybar/polybar). There are plenty of window managers out there that meet these requirements, but we really like dwm and wanted to work from there.

The [dwm patches](https://dwm.suckless.org/patches/) cannot be directly applied, but are quite easy to implement by hand.

## Getting started
The installation process is identical to dwm's. Clone the repo, navigate to the directory and install using `make`.
```bash
git clone https://github.com/lfoscari/cowm
cd cowm
sudo make install
```
After compilig for the first time a `config.h` file is createid, this is the applied configuration file. If anything breaks, just delete `config.h` and recompile.

## Theming
Thanks to the magic of X resources in cowm is possible to change some values while running, more options are coming soon. The values currently updatable via `~/.Xresources` are:
```
! COWM
cowm.norm_fg: #FFFFFF
cowm.norm_bg: #000000
cowm.norm_border: #000000

cowm.sel_fg: #000000
cowm.sel_bg: #FFFFFF
cowm.sel_border: #000000
```

#### Default keys
- `Mod + (1-9)` switch to a tag
- `Mod + Shift + (1-9)` move the focused window to tag
- `Mod + (↑↓)` focus the different windows in the current workspace
- `Mod + Shift + (↑↓)` change stack window size
- `Mod + Shift + (←→)` change master horizontal size
- `Mod + Enter` open a terminal
- `Mod + q` close the current window
- `Mod + Shift + r` reload the Xresources
- `Mod + Shift + q` exit cowm

## To implement
- [ ] Switch tags with arrows
- [x] Pick Xresources (with soft-reload)
- [ ] Up & down bash script
- [ ] Included bar (like spectrwm)

## To fix
- [ ] Transparency brigthens the color
- [ ] Xresources overwrite the current values, there is no default value option after making at least one change
- [ ] `Mod + Shift + Enter` doesn't move window to/from stack

## dwm patches
- [Alpha](https://dwm.suckless.org/patches/alpha/)
- [Alternative tags decoration](https://dwm.suckless.org/patches/alttagsdecoration/)
- [Autostart](https://dwm.suckless.org/patches/autostart/) (theming)
- [Bar padding](https://dwm.suckless.org/patches/barpadding/)
- [Cfacts](https://dwm.suckless.org/patches/cfacts/)
- [EWMH tags](https://dwm.suckless.org/patches/ewmhtags/)
- [Tile gap](https://dwm.suckless.org/patches/tilegap/)

Created by:
- [Luigi Foscari](https://github.com/lfoscari)
- [Michele Ferrante](https://github.com/il-mich)
