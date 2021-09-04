/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 30;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 30;       /* vert inner gap between windows */
static const unsigned int gappoh    = 30;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 30;       /* vert outer gap between windows and screen edge */
static const int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *alttrayname      = "tray";    /* Polybar tray instance name */
static const char *altbarcmd        = "$HOME/bar.sh"; /* Alternate bar launch command */
static const char *fonts[]          = { "monospace:size=10" };
static const char dmenufont[]       = "monospace:size=10";
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#bbbbbb";
static const char col_gray4[]       = "#eeeeee";
static const char col_cyan[]        = "#81A2BE";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
};

/* tagging */
static const char *tags[] = { "", "", "", "", "", "", "", "", "", "" };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      						instance    		  title     tags mask  		switchtotag   iscentered   isfloating   monitor */
  { "qutebrowser",    				      NULL,     NULL,     	1,	       				1,         	0,           0,            0 },
  { "Brave-browser",  				      NULL,     NULL,     	1,	       				1,         	0,           0,            0 },
  { "firefox",        				      NULL,     NULL,     	1,	       				1,         	0,           0,            0 },
  { "Nightly",        				      NULL,     NULL,     	1,	       				1,         	0,           0,            0 },
  { "Google-chrome",  				      NULL,     NULL,     	1,	       				1,         	0,           0,            0 },
  { "Ghostery Dawn",  				      NULL,     NULL,     	1,	       				1,         	0,           0,            0 },
  { "Vivaldi-snapshot",				      NULL,     NULL,     	1,	       				1,         	0,           0,            0 },
  { "Surf",           				      NULL,     NULL,     	1,	       				1,         	0,           0,            0 },
  { "ncmpcpp",   						  			NULL,  		NULL,     	1 << 3,    				1,         	0,			 		 0,		       	 1 },
  { "URxvt",          				      NULL,     NULL,     	1 << 1,    				1,         	0,           0,            0 },
  { "Transmission-gtk",				      NULL,     NULL,     	1 << 2,    				1,         	0,           0,            0 },
  { "SoulseekQt",						  			NULL,     NULL,     	1 << 2,    				1,         	0,           0,            0 },
  { "Thunar",		    				  			NULL,     NULL,     	1 << 4,    				1,         	0,           0,            0 },
  { "Sxiv",		    				      		NULL,     NULL,     	1 << 4,    				1,         	1,           1,            0 },
  { "File-roller",    				      NULL,     NULL,     	1 << 4,    				1,         	1,           1,            0 },
  { "mpv",          					  		NULL,     NULL,     	1 << 4,    				1,         	0,           1,            0 },
  { "Subl",		    				      		NULL,     NULL,     	1 << 6,    				1,         	0,           0,            0 },
  { "code-oss",	    				      	NULL,     NULL,     	1 << 6,    				1,         	0,           0,            0 },
  { "Code",		    				      		NULL,     NULL,     	1 << 6,    				1,         	0,           0,            0 },
  { "steam",          				      NULL,		  NULL,     	1 << 7,    				1,         	0,           0,            0 },
  { "Slack",          				      NULL,     NULL,     	1 << 7,    				1,         	0,           0,            1 },
  { "Easytag",	    				      	NULL,     NULL,     	1 << 8,    				1,         	1,           0,            0 },
  { "Xfce4-taskmanager",				  	NULL,     NULL,     	1 << 9,    				1,         	1,           0,            1 },
  { "Nitrogen",						      		NULL,     NULL,     	1 << 9,    				1,         	1,           1,            1 },
  { "Xfce4-appearance-settings", 		NULL,    	NULL, 	  	1 << 9,    				1,         	1,    		 	 1,            1 },
  { "Xfce4-mouse-settings", 			  NULL, 		NULL, 	  	1 << 9,    				1,         	1,    		 	 1,            1 },
  { "Gpick", 							  				NULL, 		NULL, 	  	0,    	   				1,         	1,    		 	 1,            0 },
  { "Sxiv", 							  				NULL, 		NULL, 	  	0,    	   				1,         	1,    		 	 1,            0 },
  { "MuPDF", 							  				NULL, 		NULL, 	  	0,    	   				1,         	1,    		 	 1,            0 },
  { "Lxappearance",   				      NULL, 		NULL, 	  	1 << 9,    				1,         	1,    		 	 1,            1 },
  { "Blueman-manager", 				      NULL, 		NULL, 	  	1 << 9,    				1,         	1,    		 	 1,            1 },
  { "Gnome-builder",  				      NULL, 		NULL, 	  	1 << 6,    				1,         	1,    		 	 0,            0 },
  { "Solaar", 						      		NULL, 		NULL, 	  	1 << 9,    				1,         	1,    		 	 1,            1 },
  { "Piper", 							  				NULL, 		NULL, 	  	1 << 9,    				1,         	1,    		 	 1,            1 },
  { "Gucharmap", 						  			NULL, 		NULL, 	  	1 << 6,    				1,         	1,    		 	 1,            0 },
  { "Gimp", 							  				NULL, 		NULL, 	  	1 << 9,    				1,         	1,    		 	 1,            0 },
  { "St",	            				  		NULL,     NULL,       1 << 1,    				1,         	0,           0,            0 },
  { "firefox",					"GtkFileChooserDialog",    "Save File",   0,	 	    0,          1,           1,			   		 0 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 1; /* 1 will force focus on the fullscreen window */
static const int attachdirection = 2;    /* 0 default, 1 above, 2 aside, 3 below, 4 bottom, 5 top */

#include "fibonacci.c"
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "󰕰",      tile }, /* first entry is default */
	{ "󱇚",    	 dwindle },	
	{ "󰕯",      NULL },    /* no layout function means floating behavior */
	{ "󰃚",      monocle },
 	{ "[@]",     spiral },
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

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *roficmd[] 	= { "rofi", "-show", "drun", "-show-icons", NULL };
static const char *clipcmd[] 	= {"/usr/bin/clip", NULL};
static const char *dmenucmd[] 	= {"/usr/bin/dmenu.sh", NULL};
static const char *termcmd[]  	= { "st", NULL };
static const char *browsercmd[] = { "vivaldi-snapshot", NULL };
static const char *surfcmd[] 	= { "surf", NULL };
static const char *ffcmd[] 		= { "firefox", NULL };
static const char *qutecmd[] 	= { "qutebrowser", NULL };
static const char *exitcmd[] 	= { "/usr/bin/stop.sh", NULL };
static const char *munext[]  	= { "/usr/bin/mpc", "next", NULL };
static const char *muprev[]  	= { "/usr/bin/mpc", "prev", NULL };
static const char *mupause[]  	= { "/usr/bin/mpc", "toggle", NULL };
static const char *filecmd[] 	= { "thunar", NULL };
static const char *editcmd[] 	= { "subl", NULL };
static const char *vimcmd[] 	= { "gvim", NULL };
static const char *mutecmd[] 	= { "amixer", "-q", "set", "Master", "toggle", NULL };
static const char *volupcmd[] 	= { "amixer", "-q", "set", "Master", "1%+", "unmute", NULL };
static const char *voldowncmd[] = { "amixer", "-q", "set", "Master", "1%-", "unmute", NULL };
static const char scratchpadname[] = "scratchpad";
static const char *scratchpadcmd[] = { "st", "-t", scratchpadname, "-g", "120x34", NULL };

#include <X11/XF86keysym.h>
#include "focusurgent.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY, 											XK_d,  	   spawn, 		     {.v = roficmd } },
	{ MODKEY,       					      XK_t, 		 spawn,          {.v = termcmd } },
	{ MODKEY,                       XK_grave,  togglescratch,  {.v = scratchpadcmd } },
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY|Mod4Mask,              XK_h,      incrgaps,       {.i = +1 } },
	{ MODKEY|Mod4Mask,              XK_l,      incrgaps,       {.i = -1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_h,      incrogaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_l,      incrogaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_h,      incrigaps,      {.i = +1 } },
	{ MODKEY|Mod4Mask|ControlMask,  XK_l,      incrigaps,      {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_0,      togglegaps,     {0} },
	{ MODKEY|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },
	{ MODKEY,                       XK_y,      incrihgaps,     {.i = +1 } },
	{ MODKEY,                       XK_o,      incrihgaps,     {.i = -1 } },
	{ MODKEY|ControlMask,           XK_y,      incrivgaps,     {.i = +1 } },
	{ MODKEY|ControlMask,           XK_o,      incrivgaps,     {.i = -1 } },
	{ MODKEY|Mod4Mask,              XK_y,      incrohgaps,     {.i = +1 } },
	{ MODKEY|Mod4Mask,              XK_o,      incrohgaps,     {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_y,      incrovgaps,     {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_o,      incrovgaps,     {.i = -1 } },
	{ MODKEY,                       XK_Return, zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ControlMask,           XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ControlMask,           XK_space,  setlayout,      {0} },
	{ MODKEY,                       XK_r,      setlayout,      {.v = &layouts[3]} },
	{ MODKEY|ShiftMask,             XK_r,      setlayout,      {.v = &layouts[4]} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY|ShiftMask,             XK_f,      togglefullscr,  {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	TAGKEYS(                        XK_0,                      9)
	TAGKEYS(                        XK_F1,                     0)
	TAGKEYS(                        XK_F2,                     1)
	TAGKEYS(                        XK_F3,                     2)
	TAGKEYS(                        XK_F4,                     3)
	TAGKEYS(                        XK_F5,                     4)
	TAGKEYS(                        XK_F6,                     5)
	TAGKEYS(                        XK_F7,                     6)
	TAGKEYS(                        XK_F8,                     7)
	TAGKEYS(                        XK_F9,                     8)
	TAGKEYS(                        XK_F10,                    9)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {1} },
	{ MODKEY,                       XK_u,      focusurgent,    {0} },
	{ MODKEY|ShiftMask,							XK_w,			 spawn,		       SHCMD("qutebrowser") },
	{ MODKEY|ShiftMask|ControlMask,	XK_w,			 spawn,		       SHCMD("google-chrome-stable") },
	{ MODKEY,												XK_l,      spawn,		       SHCMD("slock") },
	{ MODKEY,												XK_m,		   spawn,		       SHCMD("st -c ncmpcpp -e ncmpcpp") },
	{ 0,														XK_Print,  spawn,		       SHCMD("/usr/bin/scr") },
	{ ShiftMask,										XK_Print,  spawn,		       SHCMD("teiler") },
	{ 0, XF86XK_AudioMute,			            	 spawn,		       SHCMD("amixer sset Master toggle") },
	{ 0, XF86XK_AudioLowerVolume, 						 spawn, 		   	 {.v = voldowncmd } },
	{ 0, XF86XK_AudioRaiseVolume, 						 spawn, 		   	 {.v = volupcmd } },
	{ 0, XF86XK_AudioMute, 										 spawn, 		   	 {.v = mutecmd } },
	{ 0, XF86XK_AudioPrev,										 spawn,		   		 {.v = muprev } },
	{ 0, XF86XK_AudioNext,										 spawn,		   		 {.v = munext } },
	{ 0, XF86XK_AudioPause,										 spawn,		   		 {.v = mupause } },
	{ 0, XF86XK_AudioPlay,										 spawn,		   		 {.v = mupause } },
	{ 0, XF86XK_AudioStop,										 spawn,		   		 {.v = mupause } },
	{ 0, XF86XK_AudioRewind,									 spawn,		   		 SHCMD("mpc seek -10") },
	{ 0, XF86XK_AudioForward,									 spawn,		   		 SHCMD("mpc seek +10") },
	{ MODKEY,												XK_w,			 spawn,		   		 {.v = ffcmd } },
	{ MODKEY|ControlMask,						XK_u,			 spawn,		   		 {.v = qutecmd } },
	{ MODKEY|ControlMask,						XK_w,			 spawn,		   		 {.v = surfcmd } },
	{ MODKEY|ControlMask,						XK_v,			 spawn,		   		 {.v = browsercmd } },
	{ MODKEY,												XK_x,			 spawn,		   		 {.v = exitcmd } },
	{ MODKEY,												XK_e,			 spawn,		   		 {.v = editcmd } },
	{ MODKEY|ShiftMask, 						XK_e,			 spawn,		   		 {.v = vimcmd } },
	{ MODKEY|ShiftMask,							XK_p,			 spawn,		   		 {.v = clipcmd } },
	{ MODKEY,												XK_f,			 spawn,		   		 {.v = filecmd } },
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
