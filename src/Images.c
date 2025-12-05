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

    /* Create One Row Full of color */
    uint8_t* row = malloc(rowSize);
    for (size_t i = 0; i < rowSize; i += 3) {
        row[i]     = clr.r;
        row[i + 1] = clr.g;
        row[i + 2] = clr.b;
    }

    /* Then copy the row in all rows using memcpy for speed */
    for (uint32_t y = 0; y < I->height; y++) {
        memcpy(I->buffer + y * rowSize, row, rowSize);
    }

    free(row);
}



void save_Image(Image* I, const char* file_name) {
    uint64_t stride = I->width * 3;
    if (!stbi_write_png(file_name, I->width, I->height, 3, I->buffer, stride)){
        fprintf(stderr, "Failed to save image: %s\n", file_name);
    }
}
