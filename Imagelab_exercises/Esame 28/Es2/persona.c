#include "persona.h"

bool persona_scrivi(const struct persona *p, FILE *f)
{
	if (fwrite(p->nome, strlen(p->nome), 1, f) != 1)
		return false;
	if (fwrite("", 1, 1, f) != 1)
		return false;
	if (fwrite(&p->eta, 2, 1, f) != 1)
		return false;
	if (fwrite(&p->sesso, 1, 1, f) != 1)
		return false;
	return true;

}

