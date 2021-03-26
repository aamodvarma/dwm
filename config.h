/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const unsigned int gappih    = 20;       /* horiz inner gap between windows */
static const unsigned int gappiv    = 10;       /* vert inner gap between windows */
static const unsigned int gappoh    = 10;       /* horiz outer gap between windows and screen edge */
static const unsigned int gappov    = 10;       /* vert outer gap between windows and screen edge */
static       int smartgaps          = 1;        /* 1 means no outer gap when there is only one window */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */


static const char *fonts[]     = {"Mononoki Nerd Font:size=9:antialias=true:autohint=true",
                                  "Hack:size=8:antialias=true:autohint=true",
                                  "JoyPixels:size=10:antialias=true:autohint=true"};
static const char col_1[]  = "#282c34"; /* background color of bar */
static const char col_2[]  = "#282c34"; /* border color unfocused windows */
static const char col_3[]  = "#d7d7d7";
static const char col_4[]  = "#924441"; /* border color focused windows and tags */


static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_3, col_1, col_2 },
	[SchemeSel]  = { col_3, col_4,  col_4  },
};

/* tagging */

static const char *tags[] = { "", "", "", "", "", "", "", "", "" };
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "Firefox",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.50; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */


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


/* Extras*/
static const char *browsercmd[] = { "brave", NULL };
static const char *filemanager[] = { "nautilus", NULL };


static const char *upvol[] = { "amixer" ,"set" ,"'Master'", "5%+", NULL };
static const char *downvol[] =  { "amixer" ,"set" ,"'Master'", "5%-", NULL };



static const char *screen_[] = {"screen", "-s", "/home/ajrv/Pictures/Screenshots/", NULL};
static const char *screen_clip[] = {"screen", "-s", NULL};
static const char *screen_img_txt[] = {"img_to_txt", NULL};
static const char *ytdownloader[] = { "ytdownloader.sh" , NULL };
static const char *imgtolink[] = { "imgtolink", NULL };
static const char *filetolink[] = { "filetolink", NULL };

static const char *volume_auto[] = { "volume_auto_mute", NULL };


#include "shiftview.c"
static Key keys[] = {
	/* modifier                     key        function        argument */
/*Custom*/
    /*Print*/
    { ControlMask,                  XK_prtsc,  spawn,          {.v = screen_img_txt } },
    { ShiftMask,                    XK_prtsc,  spawn,          {.v = screen_clip } },
    { MODKEY,                       XK_prtsc,  spawn,          {.v = screen_ } },
    /*VolumeControl*/
    { ControlMask,                  XK_F4,     spawn,          {.v = upvol } },
    { ControlMask,                  XK_F3,     spawn,          {.v = downvol } },
    { ControlMask,                  XK_F2,     spawn,          {.v = volume_auto } },


    /*Shortcuts for Applications*/
    { ControlMask,                  XK_4,      spawn,          {.v = browsercmd } },
    { MODKEY, 			    XK_e,      spawn, 	       {.v = filemanager } },
    /*Shiftview*/
    { MODKEY,                       XK_n,      shiftview,      {.i = +1 } },
    { MODKEY,                       XK_b,      shiftview,      {.i = -1 } },

    /*Custom Scripts*/
    { MODKEY|Mod1Mask,              XK_y,      spawn,          {.v = ytdownloader } },
    { Mod1Mask,                     XK_prtsc,  spawn,          {.v = imgtolink } },
    { MODKEY,                       XK_c,      spawn,          {.v = filetolink } },


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
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[5]} },

        { MODKEY,                       XK_y,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_y,      setlayout,      {.v = &layouts[3]} },

	{ MODKEY,                       XK_u,      setlayout,      {.v = &layouts[4]} },
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
