#!/bin/sh

cat <<EOF | xmenu
[]= Tiled Layout	0
><> Floating Layout	1
[M] Monocle Layout	2
[@] spiral 3
[\\]dwindle 4
H[] deck 5
TTT bstack 6
=== bstackhoriz 7
HHH grid 8
### nrowgrid 9
--- horizgrid 10
::: gaplessgrid 11
|M| centeredmaster 12
>M> centeredfloatingmaster 13
EOF
