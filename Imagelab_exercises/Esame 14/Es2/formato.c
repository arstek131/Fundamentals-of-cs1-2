#define _CRT_SECURE_NO_WARNINGS
#include "formato.h"

int is_hex(const char *s)
{
	if (s == NULL)
		return 0;
	else
	{
		char *tmp = malloc((strlen(s) + 1) * sizeof(char));
		strcpy(tmp, s);
		for (size_t i = 0; i < strlen(s); i++)
		{
			tmp[i] = tolower(tmp[i]);
		}

		if (tmp[0] == '0' && tmp[1] == 'x')
		{
			if (strlen(tmp) >= 11)
			{
				free(tmp);
				return 0;
			}

			if(strlen(tmp)<=2)
			{
				free(tmp);
				return 0;
			}
			
			for (size_t i = 2; i < strlen(tmp); i++)
			{
				if (tmp[i] !='0' && tmp[i] != '1' && tmp[i] != '2' && tmp[i] != '3' && tmp[i] != '4' && tmp[i] != '5' && tmp[i] != '6' && tmp[i] != '7' && tmp[i] != '8' && tmp[i] != '9' && tmp[i] != 'a' && tmp[i] != 'b' && tmp[i] != 'c' && tmp[i] != 'd' && tmp[i] != 'e' && tmp[i] != 'f')
				{
					free(tmp);
					return 0;
				}
					
			}
			free(tmp);
			return 1;
		}
		free(tmp);
		return 0;
	}

	return 0;
}