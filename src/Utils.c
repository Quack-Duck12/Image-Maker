#include "Utils.h"

int64_t clamp(int64_t value, int64_t min, int64_t max){
    if(value > max) return max;
    if(value < min) return min;

    return value;
}

uint64_t clampU(uint64_t value, uint64_t min, uint64_t max){
    if(value > max) return max;
    if(value < min) return min;

    return value;
}

double clampF(double value, double min, double max){
    if(value > max) return max;
    if(value < min) return min;

    return value;
}

float distance(uint64_t startX, uint64_t startY, uint64_t endX, uint64_t endY){
    float dx = (float)(endX - startX);
    float dy = (float)(endY - startY);
    return sqrtf((dx*dx) + (dy*dy));
}

uint64_t distanceU(uint64_t startX, uint64_t startY, uint64_t endX, uint64_t endY){
    uint64_t dx = (endX - startX);
    uint64_t dy = (endY - startY);
    return ((dx*dx) + (dy*dy));
}

double avgInt(int a, int b){
    return (a + b) / 2.0;
}

double avgDouble(double a, double b){
    return (a + b) / 2.0;
}

char* getFileFormat(const char* filepath){

    const char* dot = strrchr(filepath, '.');
    if (!dot || dot[1] == '\0') return strdup("");

    dot++;

    char* format = strdup(dot);
    if (!format) return NULL;

    for (char* p = format; *p; p++){
        *p = tolower((unsigned char)*p);
    }

    return format;
}