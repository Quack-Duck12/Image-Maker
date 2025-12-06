#pragma once

#include "colors.h"
#include "utils.h"

#pragma pack(push, 1)
typedef struct {
    size_t WIDTH;
    size_t HEIGHT;
    Color* buffer;
} FRAME;
#pragma pack(pop)

// Constructor and Destroctor

static inline FRAME createFrame(const size_t Width, const size_t Height){
    FRAME f;
    f.WIDTH = Width;
    f.HEIGHT = Height;

    f.buffer = (Color*)calloc(Width * Height, sizeof(Color));
    if (!f.buffer){ perror("calloc failed"); f.WIDTH = f.HEIGHT = 0;}

    return f;
}

static inline FRAME createEmptyFrame(const size_t Width, const size_t Height){
    FRAME f;
    f.WIDTH = Width;
    f.HEIGHT = Height;

    return f;
}

static inline FRAME inherit(FRAME fold){
    FRAME f;
    f.WIDTH = fold.WIDTH;
    f.HEIGHT = fold.HEIGHT;
    f.buffer = fold.buffer;
    
    return f;
}

static inline void freeFrame(FRAME* f) {
    if (f && f->buffer) {
        free(f->buffer);
        f->buffer = NULL;
    }
}

/* Functions */

static inline void fill(FRAME* f, Color c){
    if (!f || !f->buffer) return;
    size_t totalPixel = f->HEIGHT * f->WIDTH;

    for(size_t i = 0; i < totalPixel; i++)
    f->buffer[i] = c;
}

static inline void setColor(FRAME* f, vectorI pos, Color c){
    if (!f || !f->buffer) return;
    if (pos.X >= f->WIDTH || pos.Y >= f->HEIGHT) return;
    f->buffer[pos.Y * f->WIDTH + pos.X] = c;
}

static inline Color getColor(FRAME* f, vectorI pos, Color c){
    if (!f || !f->buffer) return COLOR_NULL;
    if (pos.X >= f->WIDTH || pos.Y >= f->HEIGHT) return COLOR_NULL;
    return(f->buffer[pos.Y * f->WIDTH + pos.X]);
}

static inline void setPixel(FRAME* f, vectorI pos, Color c, float alpha){
    if(!f || !f->buffer) return;
    if (pos.X >= f->WIDTH || pos.Y >= f->HEIGHT) return;

    Color old = f->buffer[pos.Y * f->WIDTH + pos.X];
    f->buffer[pos.Y * f->WIDTH + pos.X] = lerpColor(old, c, alpha);
}

static inline void setRow(FRAME* f, size_t row, vectorI coloumCords, Color c){
    if (!f || !f->buffer) return;
    if (coloumCords.X >= f->WIDTH || coloumCords.Y >= f->WIDTH) return;
    if(row > f->HEIGHT) return;


}