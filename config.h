/* bread's dwl */
/* patches: */
/* rotate clients */
/* vanity-gaps 0.7 */
/* client opacity focus */
/* custom float */

/* Taken from https://github.com/djpohly/dwl/issues/466 */
#define COLOR(hex)    { ((hex >> 24) & 0xFF) / 255.0f, \
                        ((hex >> 16) & 0xFF) / 255.0f, \
                        ((hex >> 8) & 0xFF) / 255.0f, \
                        (hex & 0xFF) / 255.0f }
/* appearance */
static const int sloppyfocus               = 1;  /* focus follows mouse */
static const int bypass_surface_visibility = 0;  /* 1 means idle inhibitors will disable idle tracking even if it's surface isn't visible  */
static const int smartgaps                 = 0;  /* 1 means no outer gap when there is only one window */
static const int monoclegaps               = 0;  /* 1 means outer gaps in monocle layout */
static const unsigned int borderpx         = 2;  /* border pixel of windows */
static const unsigned int gappih           = 10; /* horiz inner gap between windows */
static const unsigned int gappiv           = 10; /* vert inner gap between windows */
static const unsigned int gappoh           = 12; /* horiz outer gap between windows and screen edge */
static const unsigned int gappov           = 12; /* vert outer gap between windows and screen edge */
static const float rootcolor[]             = COLOR(0x24273aff);
static const float bordercolor[]           = COLOR(0x24273aff);
static const float focuscolor[]            = COLOR(0x8aadf4ff);
static const float urgentcolor[]           = COLOR(0xff0000ff);
/* This conforms to the xdg-protocol. Set the alpha to zero to restore the old behavior */
static const float fullscreen_bg[]         = {0.0f, 0.0f, 0.0f, 1.0f}; /* You can also use glsl colors */
static const int respect_monitor_reserved_area = 0;  /* 1 to monitor center while respecting the monitor's reserved area, 0 to monitor center */
static const float default_opacity_unfocus = 0.9f;
static const float default_opacity_focus   = 1.0f;

/* tagging - TAGCOUNT must be no greater than 31 */
#define TAGCOUNT (9)

/* logging */
static int log_level = WLR_ERROR;

/* NOTE: ALWAYS keep a rule declared even if you don't use rules (e.g leave at least one example) */
static const Rule rules[] = {
        /* app_id  title  tags mask  isfloating  alpha unfocus  monitor x y w h*/
        /* examples: */
        { "EXAMPLE",  NULL,       0,       1,      default_opacity_unfocus, -1, -1, -1, -1.0f, -1.0f }, 
        { "kitty",     NULL,       0,       1,      0.69f,    -1, -1, -1, 1090.0f, 850.0f },
        { "Emacs",     NULL,       0,       0,      0.88f,    -1, -1, -1, -1.0f, -1.0f },
        { "nautilus",  NULL,       0,       1,      0.88f,    -1, -1, -1, 1500.0f, 900.0f },
        { "pavucontrol", NULL,     0,       1,      0.88f,    -1, -1, -1, 1020.0f, 700.0f },
        { "peaclock",  NULL,       0,       1,      0.88f,    -1, 100, 100, 100.0f, 200.0f },
        { "cg-timer",  NULL,       0,       1,      0.69f,    -1, 900, 10, 1000.0f, 250.0f },
        { "org.gnome.Loupe", NULL, 0,       1,      1.0f,     -1, -1, -1, 1090.0f, 850.0f },
        { "xdg-desktop-portal-gtk", NULL, 0, 1,    0.88f,    -1, -1, -1, 1020.0f, 700.0f },
        { "kitty",    "fzf",       0,      1,      1.0f,      -1, 310, 200, 1300.0f, 0.4f },
        { "kitty",    "menu",      0,      1,      1.0f,      -1, 710, 300, 500.0f, 0.35f },
};


/* layout(s) */
static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "",      tile },
	{ "",      NULL },    /* no layout function means floating behavior */
	{ "",      monocle },
};

/* monitors */
/* (x=-1, y=-1) is reserved as an "autoconfigure" monitor position indicator
 * WARNING: negative values other than (-1, -1) cause problems with Xwayland clients
 * https://gitlab.freedesktop.org/xorg/xserver/-/issues/899
*/
/* NOTE: ALWAYS add a fallback rule, even if you are completely sure it won't be used */
static const MonitorRule monrules[] = {
	/* name       mfact  nmaster scale layout       rotate/reflect                x    y */
	/* example of a HiDPI laptop monitor: */
	{ "eDP-1_example",    0.5f,  1,      2,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
	{ NULL,               0.55f, 1,      1,    &layouts[0], WL_OUTPUT_TRANSFORM_NORMAL,   -1,  -1 },
};

/* keyboard */
static const struct xkb_rule_names xkb_rules = {
	/* can specify fields: rules, model, layout, variant, options */
	/* example:
	.options = "ctrl:nocaps",
	*/
	.options = "ctrl:nocaps",
};

/* increased for faster typing */
static const int repeat_rate = 75;
static const int repeat_delay = 150;

/* Trackpad */
static const int tap_to_click = 1;
static const int tap_and_drag = 1;
static const int drag_lock = 1;
static const int natural_scrolling = 0;
static const int disable_while_typing = 1;
static const int left_handed = 0;
static const int middle_button_emulation = 0;
/* You can choose between:
LIBINPUT_CONFIG_SCROLL_NO_SCROLL
LIBINPUT_CONFIG_SCROLL_2FG
LIBINPUT_CONFIG_SCROLL_EDGE
LIBINPUT_CONFIG_SCROLL_ON_BUTTON_DOWN
*/
static const enum libinput_config_scroll_method scroll_method = LIBINPUT_CONFIG_SCROLL_2FG;

/* You can choose between:
LIBINPUT_CONFIG_CLICK_METHOD_NONE
LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS
LIBINPUT_CONFIG_CLICK_METHOD_CLICKFINGER
*/
static const enum libinput_config_click_method click_method = LIBINPUT_CONFIG_CLICK_METHOD_BUTTON_AREAS;

/* You can choose between:
LIBINPUT_CONFIG_SEND_EVENTS_ENABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED
LIBINPUT_CONFIG_SEND_EVENTS_DISABLED_ON_EXTERNAL_MOUSE
*/
static const uint32_t send_events_mode = LIBINPUT_CONFIG_SEND_EVENTS_ENABLED;

/* You can choose between:
LIBINPUT_CONFIG_ACCEL_PROFILE_FLAT
LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE
*/
static const enum libinput_config_accel_profile accel_profile = LIBINPUT_CONFIG_ACCEL_PROFILE_ADAPTIVE;
static const double accel_speed = 0.0;

/* You can choose between:
LIBINPUT_CONFIG_TAP_MAP_LRM -- 1/2/3 finger tap maps to left/right/middle
LIBINPUT_CONFIG_TAP_MAP_LMR -- 1/2/3 finger tap maps to left/middle/right
*/
static const enum libinput_config_tap_button_map button_map = LIBINPUT_CONFIG_TAP_MAP_LRM;

/* If you want to use the windows key for MODKEY, use WLR_MODIFIER_LOGO */
#define MODKEY WLR_MODIFIER_LOGO

#define TAGKEYS(KEY,SKEY,TAG) \
	{ MODKEY,                    KEY,            view,            {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL,  KEY,            toggleview,      {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_SHIFT, SKEY,           tag,             {.ui = 1 << TAG} }, \
	{ MODKEY|WLR_MODIFIER_CTRL|WLR_MODIFIER_SHIFT,SKEY,toggletag, {.ui = 1 << TAG} }

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static const char *term[] = { "kitty", NULL };
static const char *browser[] = { "google-chrome-stable", NULL };

static const Key keys[] = {
        /* Note that Shift changes certain key codes: c -> C, 2 -> at, etc. */
        /* modifier                  key                 function        argument */

        /* core programs */
        { MODKEY,                    XKB_KEY_Return,     spawn,          {.v = term} },
        { MODKEY,                    XKB_KEY_q,          killclient,     {0} },
        { MODKEY,                    XKB_KEY_d,          spawn,          SHCMD("rofi -show drun -config ~/.config/rofi/drun.rasi") },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_A,          spawn,          SHCMD("tofi-drun -c ~/.config/tofi/configA --drun-launch=true") },
        { MODKEY,                    XKB_KEY_e,          spawn,          SHCMD("nautilus") },
        { MODKEY,                    XKB_KEY_c,          spawn,          SHCMD("emacs") },
        { MODKEY,                    XKB_KEY_b,          spawn,          SHCMD("google-chrome-stable") },
        { WLR_MODIFIER_ALT,          XKB_KEY_b,          spawn,          SHCMD("brave") },
        { WLR_MODIFIER_ALT,          XKB_KEY_e,          spawn,          SHCMD("emacs") },
        { WLR_MODIFIER_ALT,          XKB_KEY_t,          spawn,          SHCMD("twitter") },
        { WLR_MODIFIER_ALT,          XKB_KEY_y,          spawn,          SHCMD("youtube") },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_V,          spawn,          SHCMD("vesktop-wayland") },
        { MODKEY,                    XKB_KEY_v,          spawn,          SHCMD("cliphist list | tofi -c ~/.config/tofi/configV | cliphist decode | wl-copy") },
        { MODKEY,                    XKB_KEY_f,          togglefullscreen, {0} },
        { MODKEY,                    XKB_KEY_space,      togglefloating, {0} },
        { MODKEY,                    XKB_KEY_n,          spawn,          SHCMD("~/.config/waybar/scripts/notification_center.sh") },
        { MODKEY,                    XKB_KEY_l,          spawn,          SHCMD("hyprlock") },
        { MODKEY,                    XKB_KEY_Escape,     spawn,          SHCMD("wlogout") },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_M,          quit,           {0} },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_X,          quit,           {0} },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_R,          spawn,          SHCMD("systemctl reboot") },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_P,          spawn,          SHCMD("systemctl poweroff") },
        { MODKEY,                    XKB_KEY_w,          spawn,          SHCMD("~/.config/hypr/scripts/wallpaper_select.sh") },
        { MODKEY,                    XKB_KEY_Print,      spawn,          SHCMD("hyprshot -m window -o ~/Pictures/screenshots -f $(date +%Y-%m-%d_%H-%M-%S).png") },
        { 0,                         XKB_KEY_Print,      spawn,          SHCMD("flameshot gui") },
        { WLR_MODIFIER_SHIFT,        XKB_KEY_Print,      spawn,          SHCMD("hyprshot -m region -o ~/Pictures/screenshots -f $(date +%Y-%m-%d_%H-%M-%S).png") },
        { WLR_MODIFIER_CTRL,         XKB_KEY_Escape,     spawn,          SHCMD("killall waybar || waybar") },
        { MODKEY,                    XKB_KEY_t,          spawn,          SHCMD("cg-timer") },
        { MODKEY,                    XKB_KEY_z,          zoom,           {0} },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Z,          spawn,          SHCMD("boomer") },
        { MODKEY,                    XKB_KEY_a,          spawn,          SHCMD("pavucontrol") },
        { WLR_MODIFIER_ALT,          XKB_KEY_c,          spawn,          SHCMD("kitty peaclock") },

        /* navigation */
        { MODKEY,                    XKB_KEY_j,          focusstack,     {.i = +1} },
        { MODKEY,                    XKB_KEY_k,          focusstack,     {.i = -1} },
        { MODKEY,                    XKB_KEY_Left,       focusstack,     {.i = +1} },
        { MODKEY,                    XKB_KEY_Right,      focusstack,     {.i = -1} },
        { MODKEY,                    XKB_KEY_Up,         focusstack,     {.i = -1} },
        { MODKEY,                    XKB_KEY_Down,       focusstack,     {.i = +1} },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Left,       rotate_clients, {.i = +1} },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_Right,      rotate_clients, {.i = -1} },
        { WLR_MODIFIER_ALT,          XKB_KEY_Tab,        view,           {0} },

        /* layout */
        { MODKEY,                    XKB_KEY_h,          setmfact,       {.f = -0.05f} },
        { MODKEY,                    XKB_KEY_l,          setmfact,       {.f = +0.05f} },
        { MODKEY,                    XKB_KEY_Tab,        view,           {0} },

        /* monitors */
        { MODKEY,                    XKB_KEY_comma,      focusmon,       {.i = WLR_DIRECTION_LEFT} },
        { MODKEY,                    XKB_KEY_period,     focusmon,       {.i = WLR_DIRECTION_RIGHT} },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_less,       tagmon,         {.i = WLR_DIRECTION_LEFT} },
        { MODKEY|WLR_MODIFIER_SHIFT, XKB_KEY_greater,    tagmon,         {.i = WLR_DIRECTION_RIGHT} },

        /* media keys */
        { 0, XKB_KEY_XF86AudioMute,         spawn, SHCMD("wpctl set-mute @DEFAULT_AUDIO_SINK@ toggle") },
        { 0, XKB_KEY_F8,                    spawn, SHCMD("swayosd-client --output-volume lower") },
        { 0, XKB_KEY_F9,                    spawn, SHCMD("swayosd-client --output-volume raise") },
        { 0, XKB_KEY_F6,                    spawn, SHCMD("swayosd-client --brightness +5") },
        { 0, XKB_KEY_F5,                    spawn, SHCMD("swayosd-client --brightness -5") },
        { 0, XKB_KEY_XF86AudioNext,         spawn, SHCMD("playerctl next") },
        { 0, XKB_KEY_XF86AudioPrev,         spawn, SHCMD("playerctl previous") },
        { 0, XKB_KEY_XF86AudioPlay,         spawn, SHCMD("playerctl play-pause") },
        { 0, XKB_KEY_XF86AudioPause,        spawn, SHCMD("playerctl play-pause") },
        { 0, XKB_KEY_F1,                    spawn, SHCMD("killall gammastep || gammastep -O 3500") },
        { 0, XKB_KEY_F2,                    defaultgaps,    {0} },
        { 0, XKB_KEY_F3,                    spawn, SHCMD("brightnessctl set 100%+") },
        { 0, XKB_KEY_F4,                    spawn, SHCMD("cheese") },
        { 0, XKB_KEY_F10,                   spawn, SHCMD("wpctl set-mute @DEFAULT_AUDIO_SOURCE@ toggle && notify-send -u normal -t 1000 'Microphone' 'toggled'") },

        /* gaps */
        { MODKEY|WLR_MODIFIER_LOGO,  XKB_KEY_equal,      incgaps,       {.i = +1 } },
        { MODKEY|WLR_MODIFIER_LOGO,  XKB_KEY_minus,      incgaps,       {.i = -1 } },
        { MODKEY|WLR_MODIFIER_LOGO,  XKB_KEY_0,          togglegaps,     {0} },

        TAGKEYS(          XKB_KEY_1, XKB_KEY_exclam,                     0),
        TAGKEYS(          XKB_KEY_2, XKB_KEY_at,                         1),
        TAGKEYS(          XKB_KEY_3, XKB_KEY_numbersign,                 2),
        TAGKEYS(          XKB_KEY_4, XKB_KEY_dollar,                     3),
        TAGKEYS(          XKB_KEY_5, XKB_KEY_percent,                    4),
        TAGKEYS(          XKB_KEY_6, XKB_KEY_asciicircum,                5),
        TAGKEYS(          XKB_KEY_7, XKB_KEY_ampersand,                  6),
        TAGKEYS(          XKB_KEY_8, XKB_KEY_asterisk,                   7),
        TAGKEYS(          XKB_KEY_9, XKB_KEY_parenleft,                  8),

        /* Ctrl-Alt-Backspace and Ctrl-Alt-Fx used to be handled by X server */
        { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_Terminate_Server, quit, {0} },
#define CHVT(n) { WLR_MODIFIER_CTRL|WLR_MODIFIER_ALT,XKB_KEY_XF86Switch_VT_##n, chvt, {.ui = (n)} }
        CHVT(1), CHVT(2), CHVT(3), CHVT(4), CHVT(5), CHVT(6),
        CHVT(7), CHVT(8), CHVT(9), CHVT(10), CHVT(11), CHVT(12),
};


static const Button buttons[] = {
	{ MODKEY, BTN_LEFT,   moveresize,     {.ui = CurMove} },
	{ MODKEY, BTN_MIDDLE, togglefloating, {0} },
	{ MODKEY, BTN_RIGHT,  moveresize,     {.ui = CurResize} },
};
