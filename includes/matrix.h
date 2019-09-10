#ifndef MATRIX_H
# define MATRIX_H

# include <libmatrix_structs.h>

void		matrix_add(t_matrix* matrix_1, t_matrix const * matrix_2);

t_matrix*	matrix_add_new(t_matrix const * matrix_1, t_matrix const * matrix_2);

void		matrix_addscalar(t_matrix* matrix, float scalar);

void		matrix_cat(t_matrix* matrix_1, t_matrix const * matrix_2);

t_matrix*	matrix_cpy(t_matrix const * matrix);

t_matrix*	matrix_create(size_t i, size_t j);

void		matrix_free(t_matrix* matrix);

t_matrix*	matrix_mult(t_matrix const * matrix_1, t_matrix const * matrix_2);

void		matrix_multscalar(t_matrix* matrix, float scalar);

void		matrix_print(t_matrix const * matrix);

void		matrix_set_unit(t_matrix const * matrix);

void		matrix_sub(t_matrix* matrix_1, t_matrix const * matrix_2);

t_matrix*	matrix_sub_new(t_matrix const * matrix_1, t_matrix const * matrix_2);

void		matrix_subscalar(t_matrix* matrix, float scalar);

#endif
