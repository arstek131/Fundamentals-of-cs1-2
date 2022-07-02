#include "matrix.h"

int main()
{
	/*double a[] = //inizializzo la matrice
	{
		1, 2, 3, 4,
		5, 6, 7, 8,
		9, 10, 11, 12,
		13, 14, 15, 16,
	};*/

	double a[] = //inizializzo la matrice
	{
		1, 2, 3,
		4,5,6,
		7,8,9
	};

	struct matrix m = { 3,3,a };

	struct matrix *k = rotate_v(&m, 5);
	mat_print(&m, stdout);
	printf("\n\n");
	mat_print(k, stdout);



	return 0;
}