#ifndef VECTOR_VAR_H
# define VECTOR_VAR_H

# include <math.h>
# include <structs.h>


t_vector	vector_var_create(float x, float y, float z, float w);

t_vector 	vector_var_add(t_vector vector_1, t_vector vector_2);

t_vector 	vector_var_addscalar(t_vector vector, float scalar);

t_vector 	vector_var_sub(t_vector vector_1, t_vector vector_2);

t_vector 	vector_var_subscalar(t_vector vector, float scalar);

t_vector 	vector_var_divscalar(t_vector vector, float scalar);

t_vector 	vector_var_multscalar(t_vector vector, float scalar);

t_vector	vector_var_normal(t_vector vector);

t_vector	vector_var_rev(t_vector vector);

float		vector_var_smult(t_vector vector_1, t_vector vector_2);

t_vector	vector_var_vmult(t_vector vector_1, t_vector vector_2);

#endif
