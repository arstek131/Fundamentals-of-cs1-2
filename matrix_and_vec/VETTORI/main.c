#include "vec.h"

int main()
{
	struct vec *px = new_vec(5);

	vec_set(px, 0, 2.3);
	vec_set(px, 1, 12);
	vec_set(px, 2, 3);
	vec_set(px, 3, 67);
	vec_set(px, 4, 34);
	vec_append(px, 3.5);

	delete_vec(px);
	
	return 0;
}