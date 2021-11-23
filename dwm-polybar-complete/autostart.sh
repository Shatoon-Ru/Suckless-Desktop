/usr/lib/polkit-gnome/polkit-gnome-authentication-agent-1 &
gnome-keyring-daemon --start --components=pkcs11 &
nm-applet --no-agent &
volumeicon &
blueman-applet &
numlockx &
slstatus &
unclutter &
/usr/bin/setxkbmap -option terminate:ctrl_alt_bksp
xcompmgr -CnfF -I-.010 -O-.03 -D3 -t-3 -l-3 -r4.2 -o.03 &
mpd &
mpdscribble &
/usr/bin/cursor &
/usr/bin/greenclip daemon &
thunar --daemon &
xfce4-power-manager &
sleep 3 && xfsettingsd &
/usr/bin/start-pulseaudio-x11 &
paplay /usr/share/sounds/freedesktop/stereo/service-login.oga &
yams &
conky -c ~/.conky/np &
~/.fehbg &
~/.config/polybar/launch.sh &