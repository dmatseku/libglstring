#include <lgs.h>
#include <operations_matrix.h>
#include <vector_var.h>

int	string_create(char* str, float x, float y, int pix_size, t_vector color, GLFWwindow* window)
{
	size_t					width;
	size_t					height;
	t_string*				string;
	t_matrix*				matrix;
	unsigned char *const	image = string_create_image(str, pix_size, &width, &height);

	if (!image || !(string = string_create_vao(image, width, height, window)))
		return (-1);
	if (!(matrix = m_translate_new(vector_var_create(x, y, 0.0f, 1.0f))))
		return (-1);
	string->model = matrix_to_array(matrix);
	matrix_free(matrix);
	if (!(matrix = matrix_create(4, 4)))
		return (-1);
	string->projection = matrix_to_array(matrix);
	string->view = matrix_to_array(matrix);
	matrix_free(matrix);
	if (!string->projection || !string->model || !string->view)
		return (-1);
	string->color = color;
	string->shader_program = g_lgs_string_shader_program;
	string->draw_func = string_draw_standart_function;
	string->image_height = height;
	string->image_width = width;
	string->pix_size = pix_size;
	string->active = 1;
	string_add(&g_string_lst, string);
	return (string->index);
}