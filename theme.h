
static const int vertpad                 =0;  /* vertical padding of bar */
static const int sidepad                 = 0;  /* horizontal padding of bar */

/*static const char *fonts[]     = {"Mononoki Nerd Font:size=9:antialias=true:autohint=true",
                                  "Hack:size=8:antialias=true:autohint=true",
                                  "JoyPixels:size=10:antialias=true:autohint=true"};
				  */
static const char *fonts[]          = { "CaskaydiaCove Nerd Font:size=10" };

static const char col_1[]  = "#282c34"; /* background color of bar */
static const char col_2[]  = "#d7d7d7";
static const char col_3[]  = "#4C657F"; /* border color focused windows and tags */
static const char *colors[][3]      = {

	/*               fg         bg         border   */
	[SchemeNorm] = { col_2, col_1 },
	[SchemeSel]  = { col_2, col_1, col_3  },
	[SchemeStatus]  = { col_3, col_3,  col_1  }, // Statusbar right {text,background,not used but cannot be empty}
	[SchemeTagsSel]  = { col_2, col_3,  col_1  }, // Tagbar left selected {text,background,not used but cannot be empty}
        [SchemeTagsNorm]  = { col_2, col_1,  col_1  }, // Tagbar left unselected {text,background,not used but cannot be empty}
        [SchemeInfoSel]  = { col_2, col_1,  col_1  }, // infobar middle  selected {text,background,not used but cannot be empty}
        [SchemeInfoNorm]  = { col_2, col_1,  col_1  }, // infobar middle  unselected {text,background,not used but cannot be empty}

};

