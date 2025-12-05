#ifndef COLOR_H_
#define COLOR_H_

#include <stdint.h>

typedef struct {
    uint8_t r, g, b;
} Color;

Color get_Color(uint8_t r, uint8_t g, uint8_t b);

static const Color BLACK   = {0, 0, 0};
static const Color WHITE   = {255, 255, 255};

static const Color RED     = {255, 0, 0};
static const Color GREEN   = {0, 255, 0};
static const Color BLUE    = {0, 0, 255};

static const Color YELLOW  = {255, 255, 0};
static const Color CYAN    = {0, 255, 255};
static const Color PURPLE  = {255, 0, 255};

#endif /* COLOR_H_ */
