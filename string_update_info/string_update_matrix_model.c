#include <lgs.h>

void	string_update_matrix_model(t_string *const restrict string, t_matrix *const restrict matrix)
{

	free(string->model);
	string->model = matrix_to_array(matrix);
}