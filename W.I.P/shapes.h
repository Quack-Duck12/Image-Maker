#pragma once

#include "frame.h"
#include "utils.h"

static inline vectorI getEndVector(vectorI start, vectorI dimensions) { return addVectorInt(addVectorsInt(start, dimensions), 1);}

static inline void drawRectangle(FRAME* f, vectorI pos, vectorI rect, Color c){
    if (!f || !f->buffer) return;
    if (pos.X >= f->WIDTH || pos.Y >= f->HEIGHT) return;
    if (rect.X > f->WIDTH - pos.X || rect.Y > f->HEIGHT - pos.Y) return;

    vectorI end = getEndVector(pos, rect);

    for (size_t y = pos.Y; y < end.Y; y++) {
        for (size_t x = pos.X; x < end.X; x++) {
            setColor(f, (vectorI){x, y}, c);
        }
    }
}

static inline void drawRelativeRectangle(FRAME* f, vectorI start,
                                         vectorI end, Color c){
    if (!f || !f->buffer) return;
    if (start.X >= f->WIDTH || start.Y >= f->HEIGHT) return;
    if (end.X >= f->WIDTH || end.Y >= f->HEIGHT) return;

    vectorI pos;
    pos.X = start.X < end.X ? start.X : end.X;
    pos.Y = start.Y < end.Y ? start.Y : end.Y;

    vectorI rect;
    rect.X  = (size_t)abs((int64_t)end.X - (int64_t)start.X);
    rect.Y = (size_t)abs((int64_t)end.Y - (int64_t)start.Y);

    size_t xMax = pos.X + rect.X;
    size_t yMax = pos.Y + rect.Y;
    
    if (xMax > f->WIDTH) xMax = f->WIDTH;
    if (yMax > f->HEIGHT) yMax = f->HEIGHT;

    for (size_t y = pos.Y; y <= yMax; y++){
        for (size_t x = pos.X; x <= xMax; x++){
            setColor(f, (vectorI){x, y}, c);
        }
    }
}

static inline void drawCircle(FRAME* f, vectorI pos, size_t radius, Color c){
    if (!f || !f->buffer) return;
    if (pos.X >= f->WIDTH || pos.Y >= f->HEIGHT) return;
    if (pos.X < 0 || pos.Y < 0) return;
    if(radius + pos.X > f->WIDTH || pos.X < radius) return;
    if(radius + pos.Y > f->HEIGHT || pos.Y < radius) return;

    size_t r2 = radius * radius;

    for (size_t y = pos.Y - radius; y <= pos.Y + radius; y++){
        for (size_t x = pos.X - radius; x <= pos.X + radius; x++){
            int dx = x - pos.X;
            int dy = y - pos.Y;
            if (dx*dx + dy*dy <= r2){ setColor(f, (vectorI){x, y}, c);}
        }
    }
}

static inline void drawHollowCircle(FRAME* f, vectorI pos, size_t radius, Color c){
    if (!f || !f->buffer) return;
    if (pos.X >= f->WIDTH || pos.Y >= f->HEIGHT) return;
    if (pos.X < 0 || pos.Y < 0) return;
    if(radius + pos.X > f->WIDTH || pos.X < radius) return;
    if(radius + pos.Y > f->HEIGHT || pos.Y < radius) return;

    size_t r2 = radius * radius;

    for (size_t y = pos.Y - radius; y <= pos.Y + radius; y++){
        for (size_t x = pos.X - radius; x <= pos.X + radius; x++){
            int dx = x - pos.X;
            int dy = y - pos.Y;
            uint32_t d2 = dx*dx + dy*dy;
            if (d2 <= r2 && d2 >= r2 - (2 * radius - 1)) { setColor(f, (vectorI){x, y}, c);}
        }
    }
}

static inline void drawBoundaryBox(FRAME* f, vectorI start, vectorI end, size_t thickness, Color c, short alignment){
    if (!f || !f->buffer) return;
    if (start.X >= f->WIDTH || start.Y >= f->HEIGHT) return;
    if (start.X < 0 || start.Y < 0) return;
    if (end.X >= f->WIDTH || end.Y >= f->HEIGHT ) return;
    if (end.X < 0 || end.Y < 0 ) return;
    if (thickness < 1) return;
    --thickness;
    
    vectorI topLeft, topRight, bottomLeft, bottomRight;
    topLeft = (vectorI){min(start.X, end.X), min(start.Y, end.Y)};
    bottomRight = (vectorI){max(start.X, end.X), max(start.Y, end.Y)};
    bottomLeft = crissCrossVectorInt(topLeft, bottomRight);
    topRight = crossCrissVectorInt(topLeft, bottomRight);
    
    if(thickness > 0){
        
        if(alignment < 0){
            drawRelativeRectangle(f, topLeft, yMoreVectorInt(topRight, thickness), c);
            drawRelativeRectangle(f, bottomRight, xLessVectorInt(topRight, thickness), c);
            
            drawRelativeRectangle(f, topLeft, xMoreVectorInt(bottomLeft, thickness), c);
            drawRelativeRectangle(f, bottomRight, yLessVectorInt(bottomLeft, thickness), c);
        }
        else if(alignment > 0){
            if(topLeft.X - thickness < 0 || topLeft.Y - thickness < 0) return;
            if(bottomRight.X + thickness >= f->WIDTH || bottomRight.Y + thickness >= f->HEIGHT) return;
            
            topRight = yLessVectorInt(xMoreVectorInt(topRight, thickness), thickness);
            drawRelativeRectangle(f, topLeft, topRight, c);
            drawRelativeRectangle(f, bottomRight, topRight, c);
            
            bottomLeft = yMoreVectorInt(xLessVectorInt(bottomLeft, thickness), thickness);
            drawRelativeRectangle(f, yLessVectorInt(topLeft, thickness), bottomLeft, c);
            drawRelativeRectangle(f, xMoreVectorInt(bottomRight, thickness), bottomLeft, c);
        }
        else{
            thickness += (thickness % 2); // turns even
            thickness /= 2;
            
            if(topLeft.X - thickness < 0 || topLeft.Y - thickness < 0) return;
            if(bottomRight.X + thickness >= f->WIDTH || bottomRight.Y + thickness >= f->HEIGHT) return;
            
            drawRelativeRectangle(f, topLeft, yMoreVectorInt(topRight, thickness), c);
            drawRelativeRectangle(f, bottomRight, xLessVectorInt(topRight, thickness), c);
            
            drawRelativeRectangle(f, topLeft, xMoreVectorInt(bottomLeft, thickness), c);
            drawRelativeRectangle(f, bottomRight, yLessVectorInt(bottomLeft, thickness), c);
            
            topRight = yLessVectorInt(xMoreVectorInt(topRight, thickness), thickness);
            drawRelativeRectangle(f, topLeft, topRight, c);
            drawRelativeRectangle(f, bottomRight, topRight, c);
            
            bottomLeft = yMoreVectorInt(xLessVectorInt(bottomLeft, thickness), thickness);
            drawRelativeRectangle(f, yLessVectorInt(topLeft, thickness), bottomLeft, c);
            drawRelativeRectangle(f, xMoreVectorInt(bottomRight, thickness), bottomLeft, c);
        }
    }
    else{
        drawRelativeRectangle(f, topLeft, topRight, c);
        drawRelativeRectangle(f, topRight, bottomRight, c);
        drawRelativeRectangle(f, bottomRight, bottomLeft, c);
        drawRelativeRectangle(f, bottomLeft, topLeft, c);
    }
    #ifdef DEGBU
    setColor(f, topLeft, COLOR_YELLOW);
    setColor(f, topRight, COLOR_YELLOW);
    setColor(f, bottomLeft, COLOR_YELLOW);
    setColor(f, bottomRight, COLOR_YELLOW);
    #endif
}

static void drawLine(FRAME* f, vectorI start, vectorI end, float thickness, Color c){
    int steep = abs(end.Y - start.Y) > abs(end.X - start.X);
    if(steep){
        int tmp; tmp = start.X; start.X = start.Y; start.Y = tmp;
        tmp = end.X; end.X = end.Y; end.Y = tmp;
    }
    
    if(start.X > end.X){
        int tmp; tmp = start.X; start.X = end.X; end.X = tmp;
        tmp = start.Y; start.Y = end.Y; end.Y = tmp;
    }
    
    int dx = end.X - start.X;
    int dy = end.Y - start.Y;
    float gradient = dx == 0 ? 1.0f : (float)dy / dx;
    
    // First endpoint
    float xEnd = roundf((float)start.X);
    float yEnd = start.Y + gradient * (xEnd - start.X);
    float xGap = 1.0f - fmodf((start.X + 0.5f), 1.0f);
    int xPixel1 = (int)xEnd;
    int yPixel1 = (int)floorf(yEnd);
    float intery = yEnd + gradient;
    
    // Draw thickness at first endpoint
    for(int t = -(int)(thickness/2); t <= (int)(thickness/2); t++){
        if(steep){
            setColor(f, (vectorI){yPixel1 + t, xPixel1}, multColorScalar(c, (1 - (yEnd - yPixel1)) * xGap));
            setColor(f, (vectorI){yPixel1 + t + 1, xPixel1}, multColorScalar(c, (yEnd - yPixel1) * xGap));
        } else {
            setColor(f, (vectorI){xPixel1, yPixel1 + t}, multColorScalar(c, (1 - (yEnd - yPixel1)) * xGap));
            setColor(f, (vectorI){xPixel1, yPixel1 + t + 1}, multColorScalar(c, (yEnd - yPixel1) * xGap));
        }
    }
    
    // Second endpoint
    xEnd = roundf((float)end.X);
    yEnd = end.Y + gradient * (xEnd - end.X);
    xGap = fmodf((end.X + 0.5f), 1.0f);
    int xPixel2 = (int)xEnd;
    int yPixel2 = (int)floorf(yEnd);
    
    for(int t = -(int)(thickness/2); t <= (int)(thickness/2); t++){
        if(steep){
            setColor(f, (vectorI){yPixel2 + t, xPixel2}, multColorScalar(c, (1 - (yEnd - yPixel2)) * xGap));
            setColor(f, (vectorI){yPixel2 + t + 1, xPixel2}, multColorScalar(c, (yEnd - yPixel2) * xGap));
        } else {
            setColor(f, (vectorI){xPixel2, yPixel2 + t}, multColorScalar(c, (1 - (yEnd - yPixel2)) * xGap));
            setColor(f, (vectorI){xPixel2, yPixel2 + t + 1}, multColorScalar(c, (yEnd - yPixel2) * xGap));
        }
    }
    
    // Main loop
    if(steep){
        for(int x = xPixel1 + 1; x < xPixel2; x++){
            int yInt = (int)floorf(intery);
            float fPart = intery - yInt;
            for(int t = -(int)(thickness/2); t <= (int)(thickness/2); t++){
                setColor(f, (vectorI){yInt + t, x}, multColorScalar(c, 1 - fPart));
                setColor(f, (vectorI){yInt + t + 1, x}, multColorScalar(c, fPart));
            }
            intery += gradient;
        }
    } else {
        for(int x = xPixel1 + 1; x < xPixel2; x++){
            int yInt = (int)floorf(intery);
            float fPart = intery - yInt;
            for(int t = -(int)(thickness/2); t <= (int)(thickness/2); t++){
                setColor(f, (vectorI){x, yInt + t}, multColorScalar(c, 1 - fPart));
                setColor(f, (vectorI){x, yInt + t + 1}, multColorScalar(c, fPart));
            }
            intery += gradient;
        }
    }
}

static inline void drawLineSimple(FRAME* f, vectorI start, vectorI end, Color c){
    if (!f || !f->buffer) return;

    int x0 = start.X;
    int y0 = start.Y;
    int x1 = end.X;
    int y1 = end.Y;

    int dx = abs(x1 - x0);
    int dy = abs(y1 - y0);

    int sx = (x0 < x1) ? 1 : -1;
    int sy = (y0 < y1) ? 1 : -1;

    int err = dx - dy;

    while (1) {
        // draw pixel if inside frame
        if (x0 >= 0 && x0 < f->WIDTH && y0 >= 0 && y0 < f->HEIGHT)
            setColor(f, (vectorI){x0, y0}, c);

        if (x0 == x1 && y0 == y1) break;

        int e2 = err * 2;

        if (e2 > -dy) {
            err -= dy;
            x0 += sx;
        }

        if (e2 < dx) {
            err += dx;
            y0 += sy;
        }
    }
}

static inline void drawHollowTriangle(FRAME* f, vectorI v1, vectorI v2, vectorI v3, Color c){
    drawLineSimple(f, v1, v2, c); drawLineSimple(f, v2, v3, c); drawLineSimple(f, v3, v1, c);
}

static inline void drawTriangle(FRAME* f, vectorI v1, vectorI v2, vectorI v3, Color c){
    if (!f || !f->buffer) return;

    if (v2.Y < v1.Y) { vectorI tmp = v1; v1 = v2; v2 = tmp; }
    if (v3.Y < v1.Y) { vectorI tmp = v1; v1 = v3; v3 = tmp; }
    if (v3.Y < v2.Y) { vectorI tmp = v2; v2 = v3; v3 = tmp; }

    int totalHeight = v3.Y - v1.Y;
    if (totalHeight == 0) return;

    int yStart = (v1.Y < 0) ? 0 : v1.Y;
    int yEnd   = (v3.Y >= f->HEIGHT) ? (f->HEIGHT - 1) : v3.Y;

    for (int y = yStart; y <= yEnd && y < v2.Y; y++){

        double ax = (v3.Y != v1.Y) ? v1.X + (v3.X - v1.X) * (double)(y - v1.Y) / (double)(v3.Y - v1.Y)
                                   : (double)v1.X;

        double bx = (v2.Y != v1.Y) ? v1.X + (v2.X - v1.X) * (double)(y - v1.Y) / (double)(v2.Y - v1.Y)
                                   : (double)v1.X;

        if (ax > bx) { double t = ax; ax = bx; bx = t; }

        int xStart = (int)ax;
        int xEnd   = (int)bx;

        if (xStart < 0) xStart = 0;
        if (xEnd >= f->WIDTH) xEnd = f->WIDTH - 1;
        if (xStart > xEnd) continue;

        for (int x = xStart; x <= xEnd; x++)
            setColor(f, (vectorI){x, y}, c);
    }

    for (int y = (yStart > v2.Y ? yStart : v2.Y); y <= yEnd; y++){
        double ax = (v3.Y != v1.Y) ? v1.X + (v3.X - v1.X) * (double)(y - v1.Y) / (double)(v3.Y - v1.Y)
                                   : (double)v1.X;

        double bx = (v3.Y != v2.Y) ? v2.X + (v3.X - v2.X) * (double)(y - v2.Y) / (double)(v3.Y - v2.Y)
                                   : (double)v2.X;

        if (ax > bx) { double t = ax; ax = bx; bx = t; }

        int xStart = (int)ax;
        int xEnd   = (int)bx;

        if (xStart < 0) xStart = 0;
        if (xEnd >= f->WIDTH) xEnd = f->WIDTH - 1;
        if (xStart > xEnd) continue;

        for (int x = xStart; x <= xEnd; x++)
            setColor(f, (vectorI){x, y}, c);
    }
}
