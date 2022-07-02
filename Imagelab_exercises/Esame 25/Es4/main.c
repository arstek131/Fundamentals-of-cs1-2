#include "unici.h"

int main()
{
	int myVec[] = { 2, 4, 5, 4, 5, 5, 7, 9 };
	size_t myDim = sizeof(myVec) / sizeof(myVec[0]);
	size_t newDim = 0;

	int *newVec = unici(myVec, myDim, &newDim);


	return 0;
}