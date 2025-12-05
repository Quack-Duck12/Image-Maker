#ifndef UTILS_H_
#define UTILS_H_

#include <stdint.h>
#include <math.h>
#include <string.h>
#include <ctype.h>


int64_t     clamp(int64_t value, int64_t min, int64_t max);
uint64_t    clampU(uint64_t value, uint64_t min, uint64_t max);
double      clampF(double value, double min, double max);

float       distance(uint64_t startX, uint64_t startY, uint64_t endX, uint64_t endY);
uint64_t    distanceU(uint64_t startX, uint64_t startY, uint64_t endX, uint64_t endY);

char* getFileFormat(const char* filepath);

#endif /* UTILS_H_ */