#define _CRT_SECURE_NO_WARNINGS
#include "palindroma.h"

bool palindroma(const char *str)
{
	if (str == NULL)
		return false;

	int boh = strcmp(str, "");
	if (!boh)
		return false;

	if (strlen(str) == 1)
		return true;
	
	char *tmp = malloc((strlen(str) + 1) * sizeof(char));
	strcpy(tmp, str);


	size_t temp = strlen(str)-1;
	int flag = 0;
	for (size_t i = 0; i < strlen(str); i++)
	{
		if (str[i] == tmp[temp])
			flag++;
		temp--;
	}

	//printf("%d", flag);

	free(tmp);

	if (flag == strlen(str))
		return true;
	else
		return false;

}