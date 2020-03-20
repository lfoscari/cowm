/* See LICENSE file for copyright and license details. */

/* appearance */
static unsigned int borderpx  = 0;        /* border pixel of windows */
static unsigned int gappx     = 10;       /* gap pixel between windows */
static unsigned int snap      = 0;        /* snap pixel */
static int showbar            = 1;        /* 0 means no bar */
static int topbar             = 1;        /* 0 means bottom bar */

// Margin
static const int vertmargin   = 10;       /* vertical margin of bar */
static const int sidemargin   = 10;       /* horizontal margin of bar */

// Padding
static const int vertpadding  = 10;        /* vertical padding of bar */
static const int sidepadding  = 10;        /* horizontal padding of bar */

static const char *fonts[]    = { "Iosevka SS10:style=Bold:size=11:antialias=true:autohint=false" };
static const char dmenufont[] = "Iosevka SS10:style=Bold:size=11:antialias=true:autohint=false";

static char norm_fg[] = "#FFFFFF";
static char norm_bg[] = "#000000";
static char norm_border[] = "#000000";

static char sel_fg[] = "#000000";
static char sel_bg[] = "#FFFFFF";
static char sel_border[] = "#000000";

static char *colors[][3]      = {
    /*               fg           bg         border               */
    [SchemeNorm] = { norm_fg,     norm_bg,   norm_border },
    [SchemeSel]  = { sel_fg,      sel_bg,    sel_border },
};

static const unsigned int alphas[][3] = {
	/*               fg      bg       border     */
	[SchemeNorm] = { OPAQUE, OPAQUE, OPAQUE },
	[SchemeSel]  = { OPAQUE, OPAQUE, OPAQUE },
};

/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6" };
static const char *alttags[] = { "1.", "2.", "3.", "4.", "5.", "6." };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
    { "feh",      NULL,       NULL,       1,            1,           1 },
};

/* layout(s) */
static const float mfact     = 0.5; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;   /* number of clients in master area */
static const int resizehints = 0;   /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
    /* symbol     arrange function */
    { "[]=",      tile },    /* first entry is default */
    { "><>",      NULL },    /* no layout function means floating behavior */
    { "[M]",      monocle },
};

#define LEFT    0xff51
#define RIGHT   0xff53
#define UP	    0xff52
#define DOWN    0xff54

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
    { MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
    { MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
    { MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },
    /* TODO: LEFT e RIGHT per cambiare tag
    { MODKEY,                       LEFT,     view,           {.ui = 1 << (TAG - 1)} },
    { MODKEY,                       RIGHT,    view,           {.ui = 1 << (TAG + 1)} }, */

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", norm_bg, "-nf", norm_fg, "-sb", sel_bg, "-sf", sel_fg, NULL };
static const char *termcmd[]  = { "urxvt", NULL };

static Key keys[] = {
    /* modifier                     key        function        argument */
    { MODKEY,                       XK_space,  spawn,          {.v = dmenucmd } },
    { MODKEY,                       XK_Return, spawn,          {.v = termcmd } },
    { MODKEY,                       XK_b,      togglebar,      {0} },
    { MODKEY,                       DOWN,      focusstack,     {.i = +1 } },
    { MODKEY,                       UP,        focusstack,     {.i = -1 } },
    { MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
    { MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
    { MODKEY|ShiftMask,             LEFT,      setmfact,       {.f = -0.05} },
    { MODKEY|ShiftMask,             RIGHT,     setmfact,       {.f = +0.05} },
    { MODKEY|ShiftMask,             UP,        setcfact,       {.f = +0.25} },
    { MODKEY|ShiftMask,             DOWN,      setcfact,       {.f = -0.25} },
    { MODKEY|ShiftMask,             XK_o,      setcfact,       {.f =  0.00} },
    { MODKEY|ShiftMask,             XK_Return, zoom,           {0} },
    { MODKEY,                       XK_Tab,    view,           {0} },
    { MODKEY,                       XK_q,      killclient,     {0} },
    { MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
    { MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
    { MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
    { MODKEY,                       XK_l,  	   setlayout,      {0} },
    { MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
    { MODKEY,                       XK_0,      view,           {.ui = ~0 } },
    { MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
    // { MODKEY,                    RIGHT, 	   inctag,         {.ui = +1 } },
    // { MODKEY,                    LEFT, 	   inctag,         {.ui = -1 } },
    { MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
    { MODKEY,                       XK_period, focusmon,       {.i = +1 } },
    { MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
    { MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
    { MODKEY|ShiftMask,             XK_r,      xrdb,           {.v = NULL } },
    TAGKEYS(                        XK_1,                      0)
    TAGKEYS(                        XK_2,                      1)
    TAGKEYS(                        XK_3,                      2)
    TAGKEYS(                        XK_4,                      3)
    TAGKEYS(                        XK_5,                      4)
    TAGKEYS(                        XK_6,                      5)
    TAGKEYS(                        XK_7,                      6)
    TAGKEYS(                        XK_8,                      7)
    TAGKEYS(                        XK_9,                      8)
    { MODKEY|ShiftMask,             XK_q,      quit,           {0} },
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
