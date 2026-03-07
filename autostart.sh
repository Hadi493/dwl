#!/bin/bash

# Start notification daemon
swaync &

# Start waybar
waybar &

# Start clipboard manager
wl-paste --type text --watch cliphist store &
wl-paste --type image --watch cliphist store &
~/.config/hypr/scripts/clipboard_sync.sh &

# Start wallpaper daemon
swww-daemon &
~/.config/hypr/scripts/restore_wallpaper.sh &

# Start swayosd-server
swayosd-server &

# Start hypridle
~/.config/hypr/scripts/run_hypridle.sh &

# Theme recovery
wal -R &

# Other Hyprland services
walker --gapplication-service &
elephant &
~/.config/hypr/scripts/xdg_launch.sh &

# Environment sync
dbus-update-activation-environment --systemd WAYLAND_DISPLAY XDG_CURRENT_DESKTOP &
