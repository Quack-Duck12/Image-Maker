#include "Color.h"
#include "Images.h"

#include <stdio.h>

int main(){
    Image Img = init_Image(300, 300);

    Color c = get_Color(0xAA, 0x77, 0x11);

    fill_Image(&Img, c);
    draw_circle(&Img, 150, 150, 50, CYAN);

    save_Image(&Img, "name.png");

    free_Image(&Img);
}