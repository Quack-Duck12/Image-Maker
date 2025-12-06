#include "Color.h"

Color color(uint8_t r, uint8_t g, uint8_t b){
    return (Color){r, g, b};
}

Color addColor(Color a, Color b){
    Color c = {
        clampU(a.r + b.r, 0, 255),
        clampU(a.g + b.g, 0, 255),
        clampU(a.b + b.b, 0, 255)
    };
    return c;
}

Color subColor(Color a, Color b){
    Color c = {
        clampU(a.r - b.r, 0, 255),
        clampU(a.g - b.g, 0, 255),
        clampU(a.b - b.b, 0, 255)
    };
    return c;
}

Color multColor(Color a, Color b){
    Color c = {
        clampU((uint16_t)(a.r * b.r / 255), 0, 255),
        clampU((uint16_t)(a.g * b.g / 255), 0, 255),
        clampU((uint16_t)(a.b * b.b / 255), 0, 255)
    };
    return c;
}

Color multColorScalar(Color a, float factor){
    Color c = {
        clampU((uint16_t)(a.r * factor), 0, 255),
        clampU((uint16_t)(a.g * factor), 0, 255),
        clampU((uint16_t)(a.b * factor), 0, 255)
    };
    return c;
}

Color avgColorLinear(Color a, Color b){
    Color c = {
        (uint8_t)(((int)a.r + (int)b.r) / 2),
        (uint8_t)(((int)a.g + (int)b.g) / 2),
        (uint8_t)(((int)a.b + (int)b.b) / 2)
    };
    return c;
}

Color avgColorGamma(Color a, Color b){
    float Ra, Ga, Ba, Rb, Gb, Bb, Rc, Gc, Bc;
    Ra = sqrt((float)a.r / 255.0f);
    Ga = sqrt((float)a.g / 255.0f);
    Ba = sqrt((float)a.b / 255.0f);

    Rb = sqrt((float)b.r / 255.0f);
    Gb = sqrt((float)b.g / 255.0f);
    Bb = sqrt((float)b.b / 255.0f);

    Rc = pow(avgDouble(Ra, Rb), 2) * 255;
    Gc = pow(avgDouble(Ga, Gb), 2) * 255;
    Bc = pow(avgDouble(Ba, Bb), 2) * 255;

    return color(
        clampU((uint16_t)Rc, 0, 255),
        clampU((uint16_t)Gc, 0, 255),
        clampU((uint16_t)Bc, 0, 255)
    );
}

Color lerpColor(Color a, Color b, float alpha){
    Color c = {
        clampU((uint16_t)(a.r * (1 - alpha) + b.r * alpha), 0, 255),
        clampU((uint16_t)(a.g * (1 - alpha) + b.g * alpha), 0, 255),
        clampU((uint16_t)(a.b * (1 - alpha) + b.b * alpha), 0, 255)
    };
    return c;
}