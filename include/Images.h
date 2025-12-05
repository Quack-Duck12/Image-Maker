#ifndef IMAGES_H_
#define IMAGES_H_

#include "Utils.h"
#include "Color.h"

#include <stdlib.h>
#include <stdint.h>

typedef struct{
    uint64_t width;
    uint64_t height;
    uint8_t* buffer;
} Image;

Image   init_Image(uint16_t Width, uint16_t Height);
void    free_Image(Image* I);

void    fill_Image(Image* I, Color clr);

void    draw_rect(Image* I, uint64_t PosX, uint64_t PosY, uint64_t width, uint64_t height, Color clr);
void    draw_circle(Image* I, uint64_t PosX, uint64_t PosY, uint64_t radius, Color clr);

void    save_Image(Image* I, const char* file_name);

#endif /* IMAGES_H_ */