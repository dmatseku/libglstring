#ifndef VECTOR_VAR_H
# define VECTOR_VAR_H

# include <math.h>
# include <libmatrix_structs.h>

# define vec4(x, y, z, w) (t_vector){x, y, z, w}
# define vec3(x, y, z) (t_vector){x, y, z, 1.0f}
# define vec2(x, y) (t_vector){x, y, 1.0f, 1.0f}


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
