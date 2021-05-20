/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 2;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 0;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const int usealtbar          = 1;        /* 1 means use non-dwm status bar */
static const char *altbarclass      = "Polybar"; /* Alternate bar class name */
static const char *altbarcmd        = "$HOME/.config/polybar/bar.sh"; /* Alternate bar launch command */

static const int startontag         = 1;        /* 0 means no tag active on start */
static const unsigned int baralpha = 0xd0;



typedef struct {
	const char *name;
	const void *cmd;
} Sp;
const char *spcmd1[] = {"st", "-n", "spterm", "-g", "144x41", NULL };
const char *spcmd2[] = {"st", "-n", "spfm", "-g", "144x41", "-e", "lf", NULL };

//const char *spcmd3[] = {"st", "-n", "spw", "-g", "120x34","-e", "vim", "/home/ajrv/Documents/quicknotes/\"$(date +\"%h%e %R\")\"", NULL};

const char *spcmd3[] = {"st", "-n", "spw", "-g", "144x41","-e", "vim", "/home/ajrv/Documents/quicknotes/quicknotes", NULL};
static Sp scratchpads[] = {
	/* name          cmd  */
	{"spterm",      spcmd1},
	{"spranger",    spcmd2},
	{"spw",   spcmd3},
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9"};

//static const char *tags[] = { "", "", "", "", "", "", "", "", "" };
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",	  NULL,			NULL,		0,				1,			 -1 },
	{ "Firefox",  NULL,			NULL,		1 << 8,			0,			 -1 },
	{ NULL,		  "spterm",		NULL,		SPTAG(0),		1,			 -1 },
	{ NULL,		  "spfm",		NULL,		SPTAG(1),		1,			 -1 },
	{ NULL,		  "spw",		NULL,		SPTAG(2),		1,			 -1 },

};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 0;    /* 1 means respect size hints in tiled resizals */


#define FORCE_VSPLIT 1  /* nrowgrid layout: force two clients to always split vertically */
#include "vanitygaps.c"

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "[M]",      monocle },
	{ "[@]",      spiral },
	{ "[\\]",     dwindle },
	{ "H[]",      deck },
	{ "TTT",      bstack },
	{ "===",      bstackhoriz },
	{ "HHH",      grid },
	{ "###",      nrowgrid },
	{ "---",      horizgrid },
	{ ":::",      gaplessgrid },
	{ "|M|",      centeredmaster },
	{ ">M>",      centeredfloatingmaster },
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ NULL,       NULL },
};



/* key definitions */

/*Custom*/
#define XK_prtsc        0x0000ff61
/*Custom_End*/

#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "rofi", "-show", "drun", NULL };
static const char *termcmd[]  = { "st", NULL };
static const char *layoutmenu_cmd = "layoutmenu.sh";

/* Extras*/
static const char *browsercmd[] = { "qutebrowser", NULL };
static const char *filemanager[] = { "dolphin", NULL };


static const char *upvol[] = { "amixer" ,"set" ,"'Master'", "5%+", NULL };
static const char *downvol[] =  { "amixer" ,"set" ,"'Master'", "5%-", NULL };



static const char *screen_[] = {"screen", "-s", "/home/ajrv/Pictures/Screenshots/", NULL};
static const char *screen_clip[] = {"screen", "-s", NULL};
static const char *screen_img_txt[] = {"img_to_txt", NULL};
static const char *ytdownloader[] = { "ytdownloader.sh" , NULL };
static const char *imgtolink[] = { "imgtolink", NULL };
static const char *filetolink[] = { "filetolink", NULL };

static const char *changelayout[] = { "change_layout.sh", NULL };

static const char *shut[] = { "shutscript.sh", NULL };
static const char *volume_auto[] = { "volume_auto_mute", NULL };

static const char *moviess[] = { "/home/ajrv/Videos/1337x/rofimovie.sh", NULL };
static const char *tstop[] = { "transmission_stop.sh", NULL };

#include "shiftview.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
/*Custom*/
    /*Print*/
        { ControlMask,                  XK_prtsc,  spawn,          {.v = screen_img_txt } },
        { ShiftMask,                    XK_prtsc,  spawn,          {.v = screen_clip } },
        { MODKEY,                       XK_prtsc,  spawn,          {.v = screen_ } },

        { MODKEY|ShiftMask,                       XK_m,  spawn,          {.v = moviess } },
        { MODKEY|ShiftMask,                       XK_t,  spawn,          {.v = tstop } },
        /*VolumeControl*/
        { ControlMask,                  XK_F4,     spawn,          {.v = upvol } },
        { ControlMask,                  XK_F3,     spawn,          {.v = downvol } },
        { ControlMask,                  XK_F2,     spawn,          {.v = volume_auto } },


        /*Shortcuts for Applications*/
        { ControlMask,                  XK_4,      spawn,          {.v = browsercmd } },
        { MODKEY, 			XK_e,      spawn, 	       {.v = filemanager } },
        /*Shiftview*/
        { MODKEY,                       XK_n,      shiftview,      {.i = +1 } },
        { MODKEY,                       XK_b,      shiftview,      {.i = -1 } },

        /*Custom Scripts*/
        { MODKEY|Mod1Mask,              XK_y,      spawn,          {.v = ytdownloader } },
        { Mod1Mask,                     XK_prtsc,  spawn,          {.v = imgtolink } },
        { MODKEY,                       XK_g,      spawn,          {.v = filetolink } },


	{ MODKEY,            		XK_s,  	   togglescratch,  {.ui = 0 } },
	{ MODKEY,            		XK_u,	   togglescratch,  {.ui = 1 } },
	{ MODKEY,            		XK_x,	   togglescratch,  {.ui = 2 } },

	{ MODKEY,            		XK_c,	  spawn,     {.v = changelayout } },

/*Custom_End*/

        { Mod1Mask,                     XK_space,  spawn,          {.v = dmenucmd } },
	{ MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY|ShiftMask,             XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY|ControlMask|ShiftMask, XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY|ControlMask|ShiftMask, XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },


	{ MODKEY|ShiftMask,             XK_h,      setcfact,       {.f = +0.25} },
	{ MODKEY|ShiftMask,             XK_l,      setcfact,       {.f = -0.25} },
        { MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },



	{ Mod1Mask,                     XK_Return, zoom,           {0} },

	{ Mod1Mask|Mod4Mask,              XK_u,      incrgaps,       {.i = +1 } },
	{ Mod1Mask|Mod4Mask|ShiftMask,    XK_u,      incrgaps,       {.i = -1 } },
	{ Mod1Mask|Mod4Mask,              XK_i,      incrigaps,      {.i = +1 } },
	{ Mod1Mask|Mod4Mask|ShiftMask,    XK_i,      incrigaps,      {.i = -1 } },
	{ Mod1Mask|Mod4Mask,              XK_o,      incrogaps,      {.i = +1 } },
	{ Mod1Mask|Mod4Mask|ShiftMask,    XK_o,      incrogaps,      {.i = -1 } },
	{ Mod1Mask|Mod4Mask,              XK_6,      incrihgaps,     {.i = +1 } },
	{ Mod1Mask|Mod4Mask|ShiftMask,    XK_6,      incrihgaps,     {.i = -1 } },
	{ Mod1Mask|Mod4Mask,              XK_7,      incrivgaps,     {.i = +1 } },
	{ Mod1Mask|Mod4Mask|ShiftMask,    XK_7,      incrivgaps,     {.i = -1 } },
	{ Mod1Mask|Mod4Mask,              XK_8,      incrohgaps,     {.i = +1 } },
	{ Mod1Mask|Mod4Mask|ShiftMask,    XK_8,      incrohgaps,     {.i = -1 } },
	{ Mod1Mask|Mod4Mask,              XK_9,      incrovgaps,     {.i = +1 } },
	{ Mod1Mask|Mod4Mask|ShiftMask,    XK_9,      incrovgaps,     {.i = -1 } },
	{ Mod1Mask|Mod4Mask,              XK_0,      togglegaps,     {0} },
	{ Mod1Mask|Mod4Mask|ShiftMask,    XK_0,      defaultgaps,    {0} },



	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY|ShiftMask,             XK_q,      killclient,     {0} },

	 /*Layouts*/
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },

        { MODKEY,                       XK_y,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_y,      setlayout,      {.v = &layouts[3]} },

	{ MODKEY|ShiftMask,             XK_u,      setlayout,      {.v = &layouts[1]} },

	{ MODKEY,                       XK_i,      setlayout,      {.v = &layouts[11]} },
	{ MODKEY|ShiftMask,             XK_i,      setlayout,      {.v = &layouts[12]} },






	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_s,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY,                       XK_space,  setlayout,      {0} },

	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
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
	{ MODKEY|ControlMask|ShiftMask, XK_q,      quit,           {0} },

	{ MODKEY|ControlMask|ShiftMask,	XK_x,	  spawn,     {.v = shut } }
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        layoutmenu,     {0} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY|ShiftMask, Button1,      movemouse,      {.i = 1} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkClientWin,         MODKEY|ShiftMask, Button3,      resizemouse,    {.i = 1} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};

/* signal definitions */
/* signum must be greater than 0 */
/* trigger signals using `xsetroot -name "fsignal:<signum>"` */
static Signal signals[] = {
	/* signum       function        argument  */
	{ 1,            setlayout,      {.v = &layouts[0]} },
	{ 2,            setlayout,      {.v = &layouts[1]} },
        { 3,            setlayout,      {.v = &layouts[2]} },
	{ 4,            setlayout,      {.v = &layouts[3]} },
	{ 5,            setlayout,      {.v = &layouts[4]} },
	{ 6,            setlayout,      {.v = &layouts[5]} },
	{ 7,            setlayout,      {.v = &layouts[6]} },
	{ 8,            setlayout,      {.v = &layouts[7]} },
	{ 9,            setlayout,      {.v = &layouts[8]} },
	{ 10,           setlayout,      {.v = &layouts[9]} },
	{ 11,           setlayout,      {.v = &layouts[10]} },
	{ 12,           setlayout,      {.v = &layouts[11]} },
	{ 13,           setlayout,      {.v = &layouts[12]} },
};

