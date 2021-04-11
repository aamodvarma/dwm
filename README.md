dwm - dynamic window manager
============================
dwm is an extremely fast, small, and dynamic window manager for X.

# Installation
------------

Enter the following command to build and install dwm (if
necessary as root):

```sh
sudo make clean install
```

# Running dwm
-----------
Add the following line to your .xinitrc to start dwm using startx:

```sh
exec dwm
```

Add the following line to your .xinitrc to start dwm using startx and also automatically restart dwm after killing it while keeping all the process open.

```sh
while :; do
        ssh-agent dwm
done
```

# Configuration
-------------
The configuration of dwm is done by creating a custom config.h
and (re)compiling the source code.
