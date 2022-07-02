#if !defined VEC_H
#define VEC_H

#include <stdlib.h>

struct vec {
	double *data;
	size_t size;
};

extern void vec_append(struct vec *v, double d);

extern void vec_destr(struct vec *v);
extern void delete_vec(struct vec *v);
extern struct vec *new_vec(size_t n);
extern void vec_constr(struct vec *v, size_t n);
extern void vec_set(struct vec *v, size_t i, double val);

#endif /* VEC_H */