// colors.h
#ifndef COLOR_H_
#define COLOR_H_

#include "Utils.h"

#include <stdint.h>

#pragma pack(push, 1)
typedef struct {
    uint8_t r, g, b;
}Color;
#pragma pack(pop)

static const Color COLOR_NULL          = {0x00, 0x00, 0x00};

/* Auto generated */
// ===== ACHROMATIC COLORS =====
static const Color COLOR_GRAY          = {0x80, 0x80, 0x80};
static const Color COLOR_DIMGRAY       = {0x69, 0x69, 0x69};
static const Color COLOR_DARKGRAY      = {0xA9, 0xA9, 0xA9};
static const Color COLOR_SILVER        = {0xC0, 0xC0, 0xC0};
static const Color COLOR_LIGHTGRAY     = {0xD3, 0xD3, 0xD3};
static const Color COLOR_GAINSBORO     = {0xDC, 0xDC, 0xDC};
static const Color COLOR_LAVENDER      = {0xE6, 0xE6, 0xFA};
static const Color COLOR_LINEN         = {0xFA, 0xF0, 0xE6};
static const Color COLOR_OLDLACE       = {0xFD, 0xF5, 0xE6};
static const Color COLOR_WHITESMOKE    = {0xF5, 0xF5, 0xF5};
static const Color COLOR_HONEYDEW      = {0xF0, 0xFF, 0xF0};
static const Color COLOR_SEASHELL      = {0xFF, 0xF5, 0xEE};
static const Color COLOR_LAVENDERBLUSH = {0xFF, 0xF0, 0xF5};
static const Color COLOR_ALICEBLUE     = {0xF0, 0xF8, 0xFF};
static const Color COLOR_FLORALWHITE   = {0xFF, 0xFA, 0xF0};
static const Color COLOR_MINTCREAM     = {0xF5, 0xFF, 0xFA};
static const Color COLOR_AZURE         = {0xF0, 0xFF, 0xFF};
static const Color COLOR_IVORY         = {0xFF, 0xFF, 0xF0};
static const Color COLOR_GHOSTWHITE    = {0xF8, 0xF8, 0xFF};
static const Color COLOR_SNOW          = {0xFF, 0xFA, 0xFA};
static const Color COLOR_WHITE         = {0xFF, 0xFF, 0xFF};
static const Color COLOR_BLACK         = {0x00, 0x00, 0x00};

// ===== RED COLORS =====
static const Color COLOR_RED           = {0xFF, 0x00, 0x00};
static const Color COLOR_CRIMSON       = {0xDC, 0x14, 0x3C};
static const Color COLOR_FIREBRICK     = {0xB2, 0x22, 0x22};
static const Color COLOR_BROWN         = {0xA5, 0x2A, 0x2A};
static const Color COLOR_DARKRED       = {0x8B, 0x00, 0x00};
static const Color COLOR_TOMATO        = {0xFF, 0x63, 0x47};
static const Color COLOR_MAROON        = {0x80, 0x00, 0x00};
static const Color COLOR_INDIANRED     = {0xCD, 0x5C, 0x5C};
static const Color COLOR_DEEPPINK      = {0xFF, 0x14, 0x93};
static const Color COLOR_SALMON        = {0xFA, 0x80, 0x72};
static const Color COLOR_LIGHTCORAL    = {0xF0, 0x80, 0x80};
static const Color COLOR_PALEVIOLETRED = {0xDB, 0x70, 0x93};
static const Color COLOR_HOTPINK       = {0xFF, 0x69, 0xB4};
static const Color COLOR_ROSYBROWN     = {0xBC, 0x8F, 0x8F};
static const Color COLOR_LIGHTPINK     = {0xFF, 0xB6, 0xC1};
static const Color COLOR_PINK          = {0xFF, 0xC0, 0xCB};
static const Color COLOR_MISTYROSE     = {0xFF, 0xE4, 0xE1};

// ===== ORANGE COLORS =====
static const Color COLOR_CHOCOLATE   = {0xD2, 0x69, 0x1E};
static const Color COLOR_CORAL       = {0xFF, 0x7F, 0x50};
static const Color COLOR_ORANGERED   = {0xFF, 0x45, 0x00};
static const Color COLOR_SANDYBROWN  = {0xF4, 0xA4, 0x60};
static const Color COLOR_LIGHTSALMON = {0xFF, 0xA0, 0x7A};
static const Color COLOR_DARKSALMON  = {0xE9, 0x96, 0x7A};
static const Color COLOR_SIENNA      = {0xA0, 0x52, 0x2D};
static const Color COLOR_SADDLEBROWN = {0x8B, 0x45, 0x13};
static const Color COLOR_PEACHPUFF   = {0xFF, 0xDA, 0xB9};

// ===== YELLOW COLORS =====
static const Color COLOR_YELLOW               = {0xFF, 0xFF, 0x00};
static const Color COLOR_GOLD                 = {0xFF, 0xD7, 0x00};
static const Color COLOR_ORANGE               = {0xFF, 0xA5, 0x00};
static const Color COLOR_GOLDENROD            = {0xDA, 0xA5, 0x20};
static const Color COLOR_DARKORANGE           = {0xFF, 0x8C, 0x00};
static const Color COLOR_DARKGOLDENROD        = {0xB8, 0x86, 0x0B};
static const Color COLOR_KHAKI                = {0xF0, 0xE6, 0x8C};
static const Color COLOR_DARKKHAKI            = {0xBD, 0xB7, 0x6B};
static const Color COLOR_PERU                 = {0xCD, 0x85, 0x3F};
static const Color COLOR_BURLYWOOD            = {0xDE, 0xB8, 0x87};
static const Color COLOR_TAN                  = {0xD2, 0xB4, 0x8C};
static const Color COLOR_PALEGOLDENROD        = {0xEE, 0xE8, 0xAA};
static const Color COLOR_NAVAJOWHITE          = {0xFF, 0xDE, 0xAD};
static const Color COLOR_OLIVE                = {0x80, 0x80, 0x00};
static const Color COLOR_WHEAT                = {0xF5, 0xDE, 0xB3};
static const Color COLOR_MOCCASIN             = {0xFF, 0xE4, 0xB5};
static const Color COLOR_BISQUE               = {0xFF, 0xE4, 0xC4};
static const Color COLOR_LEMONCHIFFON         = {0xFF, 0xFA, 0xCD};
static const Color COLOR_BLANCHEDALMOND       = {0xFF, 0xEB, 0xCD};
static const Color COLOR_LIGHTGOLDENRODYELLOW = {0xFA, 0xFA, 0xD2};
static const Color COLOR_PAPAYAWHIP           = {0xFF, 0xEF, 0xD5};
static const Color COLOR_ANTIQUEWHITE         = {0xFA, 0xEB, 0xD7};
static const Color COLOR_CORNSILK             = {0xFF, 0xF8, 0xDC};
static const Color COLOR_BEIGE                = {0xF5, 0xF5, 0xDC};
static const Color COLOR_LIGHTYELLOW          = {0xFF, 0xFF, 0xE0};

// ===== GREEN COLORS =====
static const Color COLOR_GREEN          = {0x00, 0x80, 0x00};
static const Color COLOR_DARKGREEN      = {0x00, 0x64, 0x00};
static const Color COLOR_FORESTGREEN    = {0x22, 0x8B, 0x22};
static const Color COLOR_SEAGREEN       = {0x2E, 0x8B, 0x57};
static const Color COLOR_DARKOLIVEGREEN = {0x55, 0x6B, 0x2F};
static const Color COLOR_LIMEGREEN      = {0x32, 0xCD, 0x32};
static const Color COLOR_OLIVEDRAB      = {0x6B, 0x8E, 0x23};
static const Color COLOR_LIME           = {0x00, 0xFF, 0x00};
static const Color COLOR_MEDIUMSEAGREEN = {0x3C, 0xB3, 0x71};
static const Color COLOR_LAWNGREEN      = {0x7C, 0xFC, 0x00};
static const Color COLOR_YELLOWGREEN    = {0x9A, 0xCD, 0x32};
static const Color COLOR_SPRINGGREEN    = {0x00, 0xFF, 0x7F};
static const Color COLOR_CHARTREUSE     = {0x7F, 0xFF, 0x00};
static const Color COLOR_DARKSEAGREEN   = {0x8F, 0xBC, 0x8F};
static const Color COLOR_GREENYELLOW    = {0xAD, 0xFF, 0x2F};
static const Color COLOR_LIGHTGREEN     = {0x90, 0xEE, 0x90};
static const Color COLOR_PALEGREEN      = {0x98, 0xFB, 0x98};

// ===== CYAN COLORS =====
static const Color COLOR_CYAN              = {0x00, 0xFF, 0xFF};
static const Color COLOR_DEEPSKYBLUE       = {0x00, 0xBF, 0xFF};
static const Color COLOR_DARKTURQUOISE     = {0x00, 0xCE, 0xD1};
static const Color COLOR_TURQUOISE         = {0x40, 0xE0, 0xD0};
static const Color COLOR_MEDIUMTURQUOISE   = {0x48, 0xD1, 0xCC};
static const Color COLOR_MEDIUMSPRINGGREEN = {0x00, 0xFA, 0x9A};
static const Color COLOR_LIGHTSEAGREEN     = {0x20, 0xB2, 0xAA};
static const Color COLOR_AQUAMARINE        = {0x7F, 0xFF, 0xD4};
static const Color COLOR_MEDIUMAQUAMARINE  = {0x66, 0xCD, 0xAA};
static const Color COLOR_SKYBLUE           = {0x87, 0xCE, 0xEB};
static const Color COLOR_DARKCYAN          = {0x00, 0x8B, 0x8B};
static const Color COLOR_CADETBLUE         = {0x5F, 0x9E, 0xA0};
static const Color COLOR_PALETURQUOISE     = {0xAF, 0xEE, 0xEE};
static const Color COLOR_LIGHTBLUE         = {0xAD, 0xD8, 0xE6};
static const Color COLOR_TEAL              = {0x00, 0x80, 0x80};
static const Color COLOR_POWDERBLUE        = {0xB0, 0xE0, 0xE6};
static const Color COLOR_LIGHTCYAN         = {0xE0, 0xFF, 0xFF};
static const Color COLOR_DARKSLATEGRAY     = {0x2F, 0x4F, 0x4F};

// ===== BLUE COLORS =====
static const Color COLOR_BLUE            = {0x00, 0x00, 0xFF};
static const Color COLOR_MEDIUMBLUE      = {0x00, 0x00, 0xCD};
static const Color COLOR_DARKBLUE        = {0x00, 0x00, 0x8B};
static const Color COLOR_NAVY            = {0x00, 0x00, 0x80};
static const Color COLOR_ROYALBLUE       = {0x41, 0x69, 0xE1};
static const Color COLOR_DODGERBLUE      = {0x1E, 0x90, 0xFF};
static const Color COLOR_MIDNIGHTBLUE    = {0x19, 0x19, 0x70};
static const Color COLOR_SLATEBLUE       = {0x6A, 0x5A, 0xCD};
static const Color COLOR_DARKSLATEBLUE   = {0x48, 0x3D, 0x8B};
static const Color COLOR_MEDIUMSLATEBLUE = {0x7B, 0x68, 0xEE};
static const Color COLOR_STEELBLUE       = {0x46, 0x82, 0xB4};
static const Color COLOR_CORNFLOWERBLUE  = {0x64, 0x95, 0xED};
static const Color COLOR_SLATEGRAY       = {0x70, 0x80, 0x90};
static const Color COLOR_LIGHTSLATEGRAY  = {0x77, 0x88, 0x99};
static const Color COLOR_LIGHTSKYBLUE    = {0x87, 0xCE, 0xFA};
static const Color COLOR_LIGHTSTEELBLUE  = {0xB0, 0xC4, 0xDE};

// ===== PURPLE COLORS =====
static const Color COLOR_PURPLE          = {0x80, 0x00, 0x80};
static const Color COLOR_DARKMAGENTA     = {0x8B, 0x00, 0x8B};
static const Color COLOR_INDIGO          = {0x4B, 0x00, 0x82};
static const Color COLOR_MEDIUMVIOLETRED = {0xC7, 0x15, 0x85};
static const Color COLOR_DARKVIOLET      = {0x94, 0x00, 0xD3};
static const Color COLOR_DARKORCHID      = {0x99, 0x32, 0xCC};
static const Color COLOR_BLUEVIOLET      = {0x8A, 0x2B, 0xE2};
static const Color COLOR_MEDIUMORCHID    = {0xBA, 0x55, 0xD3};
static const Color COLOR_MEDIUMPURPLE    = {0x93, 0x70, 0xDB};
static const Color COLOR_ORCHID          = {0xDA, 0x70, 0xD6};
static const Color COLOR_MAGENTA         = {0xFF, 0x00, 0xFF};
static const Color COLOR_VIOLET          = {0xEE, 0x82, 0xEE};
static const Color COLOR_PLUM            = {0xDD, 0xA0, 0xDD};
static const Color COLOR_THISTLE         = {0xD8, 0xBF, 0xD8};

Color       color(uint8_t r, uint8_t g, uint8_t b);

Color       addColor(Color a, Color b);
Color       subColor(Color a, Color b);

Color       multColor(Color a, Color b);
Color       multColorScalar(Color a, float factor);

Color       avgColorLinear(Color a, Color b);
Color       avgColorGamma(Color a, Color b);

Color       lerpColor(Color a, Color b, float alpha);

#endif /* COLOR_H_ */