#pragma once

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <math.h>

typedef struct{
    int64_t X;
    int64_t Y;
} vectorI;

typedef struct{
    double X;
    double Y;
} vectorF;

static inline vectorF vectorIntToFloat(vectorI vI){
    return (vectorF){(double)vI.X, (double)vI.Y};
}
static inline vectorI vectorFloatToInt(vectorF vF){
    return (vectorI){(int64_t)round(vF.X), (int64_t)round(vF.Y)};
}

static inline vectorI addVectorInt(vectorI a, int64_t b){ return (vectorI){a.X + b, a.Y + b}; }
static inline vectorI subVectorInt(vectorI a, int64_t b){ return (vectorI){a.X - b, a.Y - b}; }

static inline vectorI xMoreVectorInt(vectorI a, int64_t b){ return (vectorI){a.X + b, a.Y}; }
static inline vectorI xLessVectorInt(vectorI a, int64_t b){ return (vectorI){a.X - b, a.Y}; }
static inline vectorI yMoreVectorInt(vectorI a, int64_t b){ return (vectorI){a.X, a.Y + b}; }
static inline vectorI yLessVectorInt(vectorI a, int64_t b){ return (vectorI){a.X, a.Y - b}; }

static inline vectorI addVectorsInt(vectorI a, vectorI b){ return (vectorI){a.X + b.X, a.Y + b.Y}; }
static inline vectorF addVectorsFloat(vectorF a, vectorF b){ return (vectorF){a.X + b.X, a.Y + b.Y}; }
static inline vectorF addVectorsFloatInt(vectorF a, vectorI b){ return (vectorF){a.X + b.X, a.Y + b.Y}; }
static inline vectorI addVectorsIntFloat(vectorI a, vectorF b){ return (vectorI){ a.X + (int64_t)round(b.X), a.Y + (int64_t)round(b.Y) };}

static inline vectorI subVectorsInt(vectorI a, vectorI b){ return (vectorI){a.X - b.X, a.Y - b.Y}; }
static inline vectorF subVectorsFloat(vectorF a, vectorF b){ return (vectorF){a.X - b.X, a.Y - b.Y}; }
static inline vectorF subVectorsFloatInt(vectorF a, vectorI b){ return (vectorF){a.X - b.X, a.Y - b.Y}; }
static inline vectorI subVectorsFloatint(vectorI a, vectorF b){ return (vectorI){ a.X - (int64_t)round(b.X), a.Y - (int64_t)round(b.Y) };}

static inline vectorF multVectorFloat(vectorF v, double s){ return (vectorF){v.X * s, v.Y * s}; }
static inline vectorI multVectorInt(vectorI v, int64_t s){ return (vectorI){v.X * s, v.Y * s}; }
static inline vectorF multVectorIntFloat(vectorI v, double s){ return (vectorF){v.X * s, v.Y * s}; }

static inline double lenVectorFloat(vectorF v){ return sqrt(v.X*v.X + v.Y*v.Y); }
static inline double lenVectorInt(vectorI v){ return sqrt((double)(v.X*v.X + v.Y*v.Y)); }

static inline double nonSqrtLenVectorFloat(vectorF v){ return v.X*v.X + v.Y*v.Y; }
static inline double nonSqrtLenVectorInt(vectorI v){ return (double)(v.X*v.X + v.Y*v.Y); }

// Returns {a.X, b.Y}
static inline vectorI crissCrossVectorInt(vectorI a, vectorI b){ return (vectorI){a.X, b.Y}; }
// Returns {b.X, a.Y}
static inline vectorI crossCrissVectorInt(vectorI a, vectorI b){ return (vectorI){b.X, a.Y}; }
// Returns {a.X, b.Y}
static inline vectorF crissCrossVectorFloat(vectorF a, vectorF b){ return (vectorF){a.X, b.Y}; }
// Returns {a.X, b.Y}
static inline vectorF crossCrissVectorFloat(vectorF a, vectorF b){ return (vectorF){b.X, a.Y}; }

static inline double avgInt(int a, int b){
    return (a + b) / 2.0;
}

static inline double avgDouble(double a, double b){
    return (a + b) / 2.0;
}

static inline int64_t clamp(int64_t value, int64_t minValue, int64_t maxValue){
    if(value > maxValue) return maxValue;
    if(value < minValue) return minValue;
    return value;
}

static inline uint64_t clampU(uint64_t value, uint64_t minValue, uint64_t maxValue){
    if(value > maxValue) return maxValue;
    if(value < minValue) return minValue;
    return value;
}

static inline double clampF(double value, double minValue, double maxValue){
    if(value > maxValue) return maxValue;
    if(value < minValue) return minValue;
    return value;
}