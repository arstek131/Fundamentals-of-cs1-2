#include "formato.h"

int main()
{
	char s[] = "0x123";

	int r = is_hex(s);

	printf("%d", r);

	return 0;
}