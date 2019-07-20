
Debian
====================
This directory contains files used to package zarhexcashd/zarhexcash-qt
for Debian-based Linux systems. If you compile zarhexcashd/zarhexcash-qt yourself, there are some useful files here.

## zarhexcash: URI support ##


zarhexcash-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install zarhexcash-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your zarhexcashqt binary to `/usr/bin`
and the `../../share/pixmaps/zarhexcash128.png` to `/usr/share/pixmaps`

zarhexcash-qt.protocol (KDE)

