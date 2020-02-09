### cowm
A fork of dwm designed to be easier to use, EWMH compliant and themable like [LeftWM](https://github.com/leftwm/leftwm).

As of now the whole wm is just a dwm clone with many patches installed, you can try it with the command
```bash
patch -p1 < cowm.diff
```

#### README to-do
- [ ] Description
- [ ] Why use cowm
- [ ] Installation guide
- [ ] Configuration and theming
- [ ] Features

#### Default keys
- `Mod + (1-9)` switch to a tag
- `Mod + Shift + (1-9)` move the focused window to tag
- `Mod + (↑↓)` focus the different windows in the current workspace
- `Mod + Shift + (↑↓)` change stack window size
- `Mod + Shift + (←→)` change master horizontal size
- `Mod + Enter` open a terminal
- `Mod + Shift + Q` exit cowm
- `Mod + Q` close the current window
- `Mod + Shift + R` reload the Xresources

## To implement
- [ ] Switch tags with arrows
- [ ] Pick Xresources (with soft-reload)
- [ ] Up & down bash script
- [ ] Included bar (like spectrwm)

## To fix
- [ ] Transparency brigthens the color

## dwm patches
- [Alpha](https://dwm.suckless.org/patches/alpha/)
- [Alternative tags decoration](https://dwm.suckless.org/patches/alttagsdecoration/)
- [Autostart](https://dwm.suckless.org/patches/autostart/) (theming)
- [Bar padding](https://dwm.suckless.org/patches/barpadding/)
- [Centered window name](https://dwm.suckless.org/patches/centeredwindowname/)
- [Cfacts](https://dwm.suckless.org/patches/cfacts/)
- [EWMH tags](https://dwm.suckless.org/patches/ewmhtags/)
- [Tile gap](https://dwm.suckless.org/patches/tilegap/)

Created by:
- [Luigi Foscari](https://github.com/lfoscari)
- [Michele Ferrante](https://github.com/il-mich)
