#if !defined VEC_H
#define VEC_H

#include <stdlib.h>

struct vec {
    int *data;
    size_t size;
};

extern void vec_constr(struct vec *v, size_t n);
extern void vec_destr(struct vec *v);
extern struct vec *new_vec(size_t n);
extern void delete_vec(struct vec *v);
extern void vec_set(struct vec *v, size_t i, int val);
extern int vec_get(const struct vec *v, size_t i);
extern size_t vec_size(const struct vec *v);
extern double media(const struct vec *pv);

#endif /* VEC_H */