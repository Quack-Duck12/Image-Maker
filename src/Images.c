#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

#include "Images.h"

Image init_Image(uint16_t Width, uint16_t Height){
    Image I;
    I.width = Width;
    I.height = Height;
    I.buffer = (uint8_t*)calloc((size_t)Width * Height * 3, sizeof(uint8_t));
    
    if(!I.buffer){
        fprintf(stderr, "Error initializing image buffer: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    return I;
}

void free_Image(Image* I){
    free(I->buffer);
    I->buffer = NULL;
}

void fill_Image(Image* I, Color clr) {
    size_t rowSize = I->width * 3;

    uint8_t* row = malloc(rowSize);
    for (size_t i = 0; i < rowSize; i += 3) {
        row[i]     = clr.r;
        row[i + 1] = clr.g;
        row[i + 2] = clr.b;
    }

    for (uint64_t y = 0; y < I->height; y++) {
        memcpy(I->buffer + y * rowSize, row, rowSize);
    }

    free(row);
}

void draw_rect(Image* I, uint64_t PosX, uint64_t PosY, uint64_t width, uint64_t height, Color clr){

    uint64_t endX = clampU(PosX + width, PosX, I->width);
    uint64_t endY = clampU(PosY + height, PosY, I->height);

    for(uint64_t y = PosY; y < endY; ++y){
        for(uint64_t x = PosX; x < endX; ++x){
            size_t index = (y * I->width + x) * 3;

            I->buffer[index]     = clr.r;
            I->buffer[index + 1] = clr.g;
            I->buffer[index + 2] = clr.b;
        }
    }
}

void draw_circle(Image* I, uint64_t PosX, uint64_t PosY, uint64_t radius, Color clr){
    
    uint64_t startX = clampU(PosX - radius, 0, I->width);
    uint64_t startY = clampU(PosY - radius, 0, I->height);

    uint64_t endX = clampU(PosX + radius, 0, I->width);
    uint64_t endY = clampU(PosY + radius, 0, I->height);

    for(uint64_t y = startY; y < endY; ++y){
        for(uint64_t x = startX; x < endX; ++x){
            if(distanceU(x, y, PosX, PosY) <= radius * radius){
                size_t index = (y * I->width + x) * 3;

                I->buffer[index]     = clr.r;
                I->buffer[index + 1] = clr.g;
                I->buffer[index + 2] = clr.b;
            }
        }
    }
}

void save_Image(Image* I, const char* file_name) {
    uint64_t stride = I->width * 3;
    if (!stbi_write_png(file_name, I->width, I->height, 3, I->buffer, stride)){
        fprintf(stderr, "Failed to save image: %s\n", file_name);
    }
}
