#!/bin/bash

# Start notification daemon
swaync &

# Start waybar
waybar &

# Start clipboard manager
wl-paste --type text --watch cliphist store &
wl-paste --type image --watch cliphist store &

# Start wallpaper daemon (assuming swww, as it's common in Hyprland)
swww-daemon &
# You can set your wallpaper here, for example:
# swww img /path/to/your/wallpaper.jpg &

# Start other background processes
# nm-applet --indicator &
