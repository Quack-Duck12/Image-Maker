#include "Images.h"

int main(){
    Image i = init_Image(900, 600);

    fill_Image(&i, CYAN);

    save_Image(&i, "LOL.png");

    free_Image(&i);
}