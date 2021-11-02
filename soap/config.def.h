/* See LICENSE file for copyright and license details. */

/* special command for directories */
static const char *dircmd = "st -e noice %s";

static const Pair pairs[] = {
	/*  regex                                   action */
	{ "\\.pdf$",                                "mupdf %s"            }, // pdf
	{ "\\.(jpg|png|tiff|gif)$",                 "sxiv -a %s"          }, // image
	{ "\\.(avi|mp4|mkv|mp3|ogg|flac|mov|wav)$", "ffplay %s"           }, // audio/video
	{ "\\.(html|svg)$",                         "firefox %s"          }, // local html and svg
	{ "^(http://|https://)?(www\\.)",           "firefox %s"          }, // web URI link
	{ "^magnet:\?",                             "transmission-gtk %s" }, // magnet URI link
	{ "^steam:\?",                              "steam %s"            }, // steam URI link
	{ "^slack:\?",                              "slack %s"            }, // slack URI link
	{ "^file:\?",                               "st -e vim %s"        }, // file URI link
	{ ".",                                      "st -e vim %s"        }, // catch-all default
};
