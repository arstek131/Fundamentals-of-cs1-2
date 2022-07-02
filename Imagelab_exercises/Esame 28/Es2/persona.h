#ifndef PERSONA_H
#define PERSONA_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
struct persona {
	char *nome;
	uint16_t eta;
	char sesso;
};
extern bool persona_scrivi(const struct persona *p, FILE *f);
#endif // !PERSONA_H
