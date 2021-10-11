#!/usr/bin/env sh

# Terminate already running bar instances
killall -q polybar

# Wait until the processes have been shut down
while pgrep -u $UID -x polybar >/dev/null; do sleep 5; done

# Launch bar1 and bar2
sleep 3; polybar top -r &
sleep 3; polybar vertt -r &
#sleep 3; polybar vertb -r &

