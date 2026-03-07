#!/bin/bash

# Log autostart execution
echo "Autostart script started at $(date)" >> /home/cyber-green/dwl/autostart.log

# Environment sync (FIRST)
dbus-update-activation-environment --systemd WAYLAND_DISPLAY XDG_CURRENT_DESKTOP &

# Ensure variables are exported for this script's children
export XDG_CURRENT_DESKTOP=dwl
# WAYLAND_DISPLAY is inherited from dwl, but we can ensure it's set
export WAYLAND_DISPLAY="${WAYLAND_DISPLAY:-wayland-0}"

# Start notification daemon
swaync &

# Start waybar
# waybar &

# Start tray applets
nm-applet --indicator &
blueman-applet &

# Start clipboard manager
wl-paste --type text --watch cliphist store &
wl-paste --type image --watch cliphist store &

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
