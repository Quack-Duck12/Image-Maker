#include "Color.h"
#include "Images.h"

#include <stdio.h>

// Image Maker Program
int main(){
    Image Img = init_Image(10000, 2000);

    fill_Image(&Img, COLOR_ANTIQUEWHITE);
    draw_circle(&Img, 600, 150, 350, COLOR_CYAN);

    save_Image(&Img, "name.png");

    free_Image(&Img);
}