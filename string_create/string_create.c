#include <lgs.h>

int	string_create(char* str, float x, float y, int pix_size)
{
	size_t					width;
	size_t					height;
	t_string*				string;
	t_matrix*				matrix;
	unsigned char *const	image = string_create_image(str, pix_size, &width, &height);

	if (!image || !(string = string_create_vao(x, y, image, width, height)))
		return (-1);
	if (!(matrix = matrix_create(4, 4)))
		return (-1);
	string->projection = matrix_to_array(matrix);
	string->model = matrix_to_array(matrix);
	string->view = matrix_to_array(matrix);
	matrix_free(matrix);
	if (!string->projection || !string->model || !string->view)
		return (-1);
	string_add(&g_string_lst, string);
	return (string->index);
}