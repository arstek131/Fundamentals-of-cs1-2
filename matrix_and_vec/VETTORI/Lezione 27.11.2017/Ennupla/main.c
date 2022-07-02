#include "vec.h"

int main(void)
{
    struct vec *px = new_vec(5);
        
    vec_set(px, 0, 7);
    vec_set(px, 1, 12);
    vec_set(px, 2, 3);
    vec_set(px, 3, 67);
    vec_set(px, 4, 34);
    double m = media(px);

    delete_vec(px);
}
