#include "vec.h"

void vec_constr(struct vec *v, size_t n)
{
	v->data = malloc(n * sizeof(double));
	v->size = n;
}

struct vec *new_vec(size_t n)
{
	struct vec *v = malloc(sizeof(struct vec));
	vec_constr(v, n);
	return v;
}

void vec_set(struct vec *v, size_t i, double val)
{
	v->data[i] = val;
}

int vec_get(const struct vec *v, size_t i)
{
    return v->data[i];
}

void vec_destr(struct vec *v)
{
	free(v->data);
	v->data = NULL;
	v->size = 0;
}

void delete_vec(struct vec *v)
{
	vec_destr(v);
	free(v);
}

void vec_append(struct vec *v, double d)
{
	
	v->data = realloc(v->data, (v->size + 1) * sizeof(double));
	v->size++;
	v->data[v->size-1] = d;
}
