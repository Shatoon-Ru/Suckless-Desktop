/*See LICENSE file for copyright and license details. */

#include <X11/XF86keysym.h> // media keys

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int gappx     = 0;        /* gaps between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 10;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int savefloats         = 1;        /* 0 means default behaviour, 1 = savefloats patch */
static const int attachmode         = 2;        /* 0 master (default), 1 = above, 2 = aside, 3 = below, 4 = bottom */
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Bar"; /* Alternate bar class name */
static const char *alttrayname      = "tray";    /* Polybar tray instance name */
static const char *altbarcmd        = "$HOME/.config/polybar/launch.sh"; /* Alternate bar launch command */
static const char *fonts[]          = { "Inter:size=10.5", "Font Awesome 5 Pro:style=Solid:pixelsize=12:antialias=true", "Font Awesome 5 Brands:style=Solid:pixelsize=12:antialias=true", "Material Design Icons:Regular:pixelsize=19:antialias=true" };
static const char dmenufont[]       = "noto:size=14";
static const char col_gray1[]       = "#141414";
static const char col_gray2[]       = "#282828";
static const char col_gray3[]       = "#353535";
static const char col_gray4[]       = "#c6c6c6";
static const char col_gray5[]       = "#fffefe";
static const char col_gray6[]       = "#282828";
static const char col_gray7[]       = "#212121";
static const char col_cyan[]        = "#7e9cb9";
static const char col_blue[]        = "#6699cc";
static const char col1[]            = "#98971a";
static const char col2[]            = "#d79921";
static const char col3[]            = "#458588";
static const char col4[]            = "#b16286";
static const char col5[]            = "#689d6a";
static const char col6[]            = "#a89984";
static const char *colors[][3]      = {
    /*               fg         bg         border   */
    [SchemeNorm] = { col_gray4, col_gray7, col_gray2 },
    [SchemeSel]  = { col_cyan, col_gray7,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
    /* xprop(1):
     *  WM_CLASS(STRING) = instance, class
     *  WM_NAME(STRING) = title
     *  WM_WINDOW_ROLE(STRING) = role
     */
   /* class                         instance    title       tags mask     switchtag    isfloating   monitor */
   { "qutebrowser",                 NULL,       NULL,       1,            1,             0,           0 },
   { "Brave-browser",               NULL,       NULL,       1,            1,             0,           0 },
   { "firefox",                     NULL,       NULL,       1,            1,             0,           0 },
   { "Surf",                        NULL,       NULL,       1,            1,             0,           0 },
   { "ncmpcpp",                     NULL,       NULL,       1 << 3,       1,             1,           0 },
   { "Sonata",                      NULL,       NULL,       1 << 3,       1,             0,           0 },
   { "Nicotine",                    NULL,       NULL,       1 << 2,       0,             0,           0 },
   { "St",                          NULL,       NULL,       1 << 1,       1,             0,           0 },
   { "Alacritty",                   NULL,       NULL,       1 << 1,       1,             0,           0 },
   { "st",                          NULL,       NULL,       1 << 1,       1,             0,           0 },
   { "URxvt",                       NULL,       NULL,       1 << 1,       1,             0,           0 },
   { "Transmission-gtk",            NULL,       NULL,       1 << 2,       1,             0,           0 },
   { "SoulseekQt",                  NULL,       NULL,       1 << 2,       1,             0,           0 },
   { "Thunar",                      NULL,       NULL,       1 << 4,       1,             0,           0 },
   { "Sxiv",                        NULL,       NULL,       1 << 4,       1,             1,           0 },
   { "File-roller",                 NULL,       NULL,       1 << 4,       1,             1,           0 },
   { "mpv",                         NULL,       NULL,       1 << 4,       1,             1,           0 },
   { "Subl",                        NULL,       NULL,       1 << 6,       1,             0,           0 },
   { "nvim",                        NULL,       NULL,       1 << 6,       1,             0,           0 },
   { "code-oss",                    NULL,       NULL,       1 << 6,       1,             0,           0 },
   { "Code",                        NULL,       NULL,       1 << 6,       1,             0,           0 },
   { "Slack",                       NULL,       NULL,       1 << 7,       1,             0,           0 },
   { "Easytag",                     NULL,       NULL,       1 << 8,       1,             0,           0 },
   { "Xfce4-taskmanager",           NULL,       NULL,       1 << 9,       1,             0,           0 },
   { "Nitrogen",                    NULL,       NULL,       1 << 9,       1,             1,           0 },
   { "Xfce4-appearance-settings",   NULL,       NULL,       1 << 9,       1,             1,           0 },
   { "Xfce4-mouse-settings",        NULL,       NULL,       1 << 9,       1,             1,           0 },
   { "Gpick",                       NULL,       NULL,       0,            1,             1,           0 },
   { "Sxiv",                        NULL,       NULL,       0,            1,             1,           0 },
   { "MuPDF",                       NULL,       NULL,       0,            1,             1,           0 },
   { "Lxappearance",                NULL,       NULL,       1 << 9,       1,             1,           0 },
   { "Blueman-manager",             NULL,       NULL,       1 << 9,       1,             1,           0 },
   { "Pavucontrol",                 NULL,       NULL,       1 << 9,       1,             1,           0 },
   { "Gnome-builder",               NULL,       NULL,       1 << 6,       1,             0,           0 },
   { "Solaar",                      NULL,       NULL,       1 << 9,       1,             1,           0 },
   { "Piper",                       NULL,       NULL,       1 << 9,       1,             1,           0 },
   { "Gucharmap",                   NULL,       NULL,       1 << 6,       1,             1,           0 },
   { "Gimp",                        NULL,       NULL,       1 << 9,       1,             1,           0 },
   { "firefox",   "GtkFileChooserDialog",   "Save File",    0,            1,             1,           0 },
   { "firefox",                "Toolkit", "Picture-in-Picture",      0,   1,             1,           0 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

/*#include "fibonacci.c"*/
static const Layout layouts[] = {
    /* symbol     arrange function */
    { "󰕴",     dwindle },    /* first entry is default */
    { "󰃚",     monocle },
    { "󰡃",     spiral },
    { "󰕰",     tile },
    { "><>",    NULL },    /* no layout function means floating behavior */
    { NULL,     NULL },
};

/* key definitions */
#define MODKEY Mod1Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

#define APP_BROWSER     "firefox"
#define APP_BROWSER_    "firefox --private-window"
#define APP_QUTE        "qutebrowser"
#define APP_SURF        "surf"
#define APP_FILE        "thunar"
#define APP_EDITOR      "emacs"
#define APP_EDIT        "subl"
#define APP_NVIM        "st -c nvim -e nvim"
#define APP_MUSIC       "alacritty --class ncmpcpp,ncmpcpp -e ncmpcpp"
#define APP_MUSIC_      "st -g 200x80 -c ncmpcpp -e ncmpcpp"
#define APP_DUNSTHIST   "dunstctl history-pop"
#define APP_DUNSTCLOSE  "dunstctl close"
#define APP_CLIP        "greenclip print | sed '/^$/d' | dmenu -l 10 -p clipboard | xargs -r -d'\n' -I '{}' greenclip print '{}'"
#define APP_EXIT        "/usr/bin/dmenu_logout"
#define APP_DMENU       "/usr/bin/dmenu.sh"
#define APP_VOLU        "/usr/bin/volume up"
#define APP_VOLD        "/usr/bin/volume down"
#define APP_MUTE        "amixer -q set Master toggle"
#define APP_MPDTOG      "mpc toggle"
#define APP_MPDSTOP     "mpc stop"
#define APP_MPDNEXT     "mpc next"
#define APP_MPDPREV     "mpc prev"
#define APP_MPDREW      "mpc seek -10"
#define APP_MPDFAST     "mpc seek +10"
#define APP_SCROT       "/usr/bin/scr"
#define APP_SCROT_      "teiler"
#define APP_LOCK        "slock"

/* commands */
static char dmenumon[2]            = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[]      = {"dmenu_run_history", NULL};
static const char *termcmd[]       = { "st", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

#include "mpdcontrol.c"
#include <X11/XF86keysym.h>
static Key keys[] = {
    /* modifier                   key                     function             argument */
  { MODKEY,                       XK_F2,                  spawn,               SHCMD(APP_QUTE) },
  { MODKEY,                       XK_F3,                  spawn,               SHCMD(APP_SURF) },
  { MODKEY,                       XK_F4,                  spawn,               SHCMD(APP_EDITOR)},
  { MODKEY,                       XK_m,                   spawn,               SHCMD(APP_MUSIC_) },
  { ControlMask,                  XK_grave,               spawn,               SHCMD(APP_DUNSTHIST) },
  { ControlMask,                  XK_space,               spawn,               SHCMD(APP_DUNSTCLOSE) },
  { MODKEY,                       XK_l,                   spawn,               SHCMD(APP_LOCK) },
  { 0,                            XK_Print,               spawn,               SHCMD(APP_SCROT) },
  { ShiftMask,                    XK_Print,               spawn,               SHCMD(APP_SCROT_) },
  { 0, XF86XK_AudioMute,                                  spawn,               SHCMD(APP_MUTE) },
  { 0, XF86XK_AudioRaiseVolume,                           spawn,               SHCMD(APP_VOLU) },
  { 0, XF86XK_AudioLowerVolume,                           spawn,               SHCMD(APP_VOLD) },
  { 0, XF86XK_AudioPrev,                                  spawn,               SHCMD(APP_MPDPREV) },
  { 0, XF86XK_AudioNext,                                  spawn,               SHCMD(APP_MPDNEXT) },
  { 0, XF86XK_AudioPause,                                 spawn,               SHCMD(APP_MPDTOG) },
  { 0, XF86XK_AudioPlay,                                  spawn,               SHCMD(APP_MPDTOG) },
  { 0, XF86XK_AudioStop,                                  spawn,               SHCMD(APP_MPDSTOP) },
  { 0, XF86XK_AudioRewind,                                spawn,               SHCMD(APP_MPDREW) },
  { 0, XF86XK_AudioForward,                               spawn,               SHCMD(APP_MPDFAST) },
  { MODKEY,                       XK_w,                   spawn,               SHCMD(APP_BROWSER)  },
  { MODKEY|ShiftMask,             XK_w,                   spawn,               SHCMD(APP_BROWSER_) },
  { MODKEY,                       XK_x,                   spawn,               SHCMD(APP_EXIT) },
  { MODKEY|ShiftMask,             XK_e,                   spawn,               SHCMD(APP_NVIM) },
  { MODKEY|ShiftMask,             XK_p,                   spawn,               SHCMD(APP_CLIP)},
  { MODKEY,                       XK_f,                   spawn,               SHCMD(APP_FILE) },
  { MODKEY,                       XK_e,                   spawn,               SHCMD(APP_EDIT)  },
/*{ MODKEY,                       XK_m,                   spawn,               SHCMD("alacritty --class ncmpcpp,ncmpcpp -e ncmpcpp") },*/
  { MODKEY,                       XK_space,               spawn,               {.v = dmenucmd } },
  { MODKEY,                       XK_t,                   spawn,               {.v = termcmd } },
  { MODKEY,                       XK_grave,               togglescratch,       {.v = scratchpadcmd } },
  { MODKEY,                       XK_Tab,                 togglescratch,       {.v = scratchpadcmd } },
  { MODKEY|ShiftMask,             XK_Tab,                 focusstack,          {.i = +1 } },
  { MODKEY,                       XK_b,                   togglebar,           {0} },
  { MODKEY,                       XK_j,                   focusstack,          {.i = +1 } },
  { MODKEY,                       XK_k,                   focusstack,          {.i = -1 } },
  { MODKEY,                       XK_i,                   incnmaster,          {.i = +1 } },
  { MODKEY|ShiftMask,             XK_d,                   incnmaster,          {.i = -1 } },
  { MODKEY,                       XK_h,                   setmfact,            {.f = -0.05} },
  { MODKEY,                       XK_l,                   setmfact,            {.f = +0.05} },
  { MODKEY,                       XK_Return,              zoom,                {0} },
  { MODKEY,                       XK_q,                   killclient,          {0} },
  { MODKEY,                       XK_F11,                 fullscreen,          {0} },
  { MODKEY|ShiftMask,             XK_t,                   setlayout,           {.v = &layouts[0]} },
  { MODKEY|ShiftMask,             XK_f,                   setlayout,           {.v = &layouts[1]} },
  { MODKEY|ShiftMask,             XK_m,                   setlayout,           {.v = &layouts[2]} },
  { MODKEY|ControlMask,           XK_r,                   setlayout,           {.v = &layouts[3]} },
  { MODKEY|ShiftMask,             XK_r,                   setlayout,           {.v = &layouts[4]} },
  { MODKEY|ShiftMask,             XK_space,               togglefloating,      {0} },
  { MODKEY|ShiftMask,             XK_j,                   rotatestack,         {.i = +1 } },
  { MODKEY|ShiftMask,             XK_k,                   rotatestack,         {.i = -1 } },
  { MODKEY|ControlMask,           XK_0,                   view,                {.ui = ~0 } },
  { MODKEY|ShiftMask,             XK_0,                   tag,                 {.ui = ~0 } },
  { MODKEY,                       XK_comma,               focusmon,            {.i = -1 } },
  { MODKEY,                       XK_period,              focusmon,            {.i = +1 } },
  { MODKEY|ShiftMask,             XK_comma,               tagmon,              {.i = -1 } },
  { MODKEY|ShiftMask,             XK_period,              tagmon,              {.i = +1 } },
  { MODKEY|Mod4Mask,              XK_u,                   incrgaps,            {.i = +1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_u,                   incrgaps,            {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_i,                   incrigaps,           {.i = +1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_i,                   incrigaps,           {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_o,                   incrogaps,           {.i = +1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_o,                   incrogaps,           {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_6,                   incrihgaps,          {.i = +1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_6,                   incrihgaps,          {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_7,                   incrivgaps,          {.i = +1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_7,                   incrivgaps,          {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_8,                   incrohgaps,          {.i = +1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_8,                   incrohgaps,          {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_9,                   incrovgaps,          {.i = +1 } },
  { MODKEY|Mod4Mask|ShiftMask,    XK_9,                   incrovgaps,          {.i = -1 } },
  { MODKEY|Mod4Mask,              XK_0,                   togglegaps,          {0} },
  { MODKEY|Mod4Mask|ShiftMask,    XK_0,                   defaultgaps,         {0} },
  TAGKEYS(                        XK_1,                                        0)
  TAGKEYS(                        XK_2,                                        1)
  TAGKEYS(                        XK_3,                                        2)
  TAGKEYS(                        XK_4,                                        3)
  TAGKEYS(                        XK_5,                                        4)
  TAGKEYS(                        XK_6,                                        5)
  TAGKEYS(                        XK_7,                                        6)
  TAGKEYS(                        XK_8,                                        7)
  TAGKEYS(                        XK_9,                                        8)
  TAGKEYS(                        XK_0,                                        9)
  { MODKEY|ShiftMask,             XK_q,                   quit,                {0} },
  { MODKEY|ControlMask|ShiftMask, XK_q,                   quit,                {1} },
  { MODKEY,                       XK_F1,                  mpdchange,           {.i = -1} }, // Previous Song
  { MODKEY|ShiftMask,             XK_F1,                  mpdchange,           {.i = +1} }, // Next Song
  { MODKEY,                       XK_Escape,              mpdcontrol,          {0} },       // Toggle Play/Pause
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
    /* click                event mask      button          function        argument */
    { ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
    { ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
    { ClkWinTitle,          0,              Button2,        zoom,           {0} },
    { ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
    { ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
    { ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
    { ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
    { ClkClientWin,         MODKEY,         Button4,        rotatestack,    {.i = +1 } },
    { ClkClientWin,         MODKEY,         Button5,        rotatestack,    {.i = -1 } },
    { ClkTagBar,            0,              Button1,        view,           {0} },
    { ClkTagBar,            0,              Button3,        toggleview,     {0} },
    { ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
    { ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

static const char *ipcsockpath = "/tmp/dwm.sock";
static IPCCommand ipccommands[] = {
  IPCCOMMAND(  view,                1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggleview,          1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tag,                 1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  toggletag,           1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  tagmon,              1,      {ARG_TYPE_UINT}   ),
  IPCCOMMAND(  focusmon,            1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  focusstack,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  zoom,                1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  incnmaster,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  killclient,          1,      {ARG_TYPE_SINT}   ),
  IPCCOMMAND(  togglefloating,      1,      {ARG_TYPE_NONE}   ),
  IPCCOMMAND(  setmfact,            1,      {ARG_TYPE_FLOAT}  ),
  IPCCOMMAND(  setlayoutsafe,       1,      {ARG_TYPE_PTR}    ),
  IPCCOMMAND(  quit,                1,      {ARG_TYPE_NONE}   )
};
