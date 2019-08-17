#ifndef LIBMATRIX_STRUCTS_H
#define LIBMATRIX_STRUCTS_H

# include <stdio.h>

typedef struct	s_vector
{
	float 		x;
	float		y;
	float		z;
	float		w;
}				t_vector;

typedef	struct	s_matrix
{
	size_t		i;
	size_t		j;
	float 		**mat;
}				t_matrix;

#endif
