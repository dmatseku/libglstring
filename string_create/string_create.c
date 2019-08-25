#include <lgs.h>
#include <operations_matrix.h>
#include <vector_var.h>

static float*	cpy(float* matrix)
{
	float* res = (float*)malloc(sizeof(float) * 16);

	if (!res)
		return (0);
	memcpy(res, matrix, 16 * sizeof(float));
	return (res);
}

int		string_create(char* str, float x, float y, int pix_size, t_vector color, GLFWwindow* window)
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
	string->translate = matrix->mat;
	free(matrix);
	string->rotate = cpy(string->translate);
	string->rotate[12] = 0;
	string->rotate[13] = 0;
	string->scale = cpy(string->rotate);
	string->projection = cpy(string->rotate);
	string->view = cpy(string->rotate);
	if (!string->projection || !string->scale || !string->translate
			|| !string->rotate || !string->view)
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