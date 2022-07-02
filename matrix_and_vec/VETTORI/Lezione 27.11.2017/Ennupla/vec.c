#include "vec.h"

void vec_constr(struct vec *v, size_t n)
{
    v->data = malloc(n * sizeof(int));
    v->size = n;
}
void vec_destr(struct vec *v)
{
    free(v->data);
    v->data = NULL;
    v->size = 0;
}
struct vec *new_vec(size_t n)
{
    struct vec *v = malloc(sizeof(struct vec));
    vec_constr(v, n);
    return v;
}
void delete_vec(struct vec *v)
{
    vec_destr(v);
    free(v);
}
void vec_set(struct vec *v, size_t i, int val)
{
    v->data[i] = val;
}
int vec_get(const struct vec *v, size_t i)
{
    return v->data[i];
}
size_t vec_size(const struct vec *v)
{
    return v->size;
}

double media(const struct vec *pv)
{
    double m = 0.;
    for (size_t i = 0; i < vec_size(pv); ++i)
        m += vec_get(pv, i);
    return m / vec_size(pv);
}

