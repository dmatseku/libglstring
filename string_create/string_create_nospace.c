#include <lgs.h>
#include <operations_matrix.h>
#include <vector_var.h>

static float*	cpy(float const *const restrict matrix)
{
	float *const restrict res = (float*)malloc(sizeof(float) * 16);

	if (!res)
		return (0);
	memcpy(res, matrix, 16 * sizeof(float));
	return (res);
}

int		string_create_nospace(char const *const restrict str, const float x, const float y,
				 const int pix_size, const t_vector color, GLFWwindow *const restrict window)
{
	size_t								width;
	size_t								height;
	unsigned char const *const restrict	image = string_create_image_nospace(str, pix_size, &width, &height);
	t_string *const restrict			string = string_create_vao(image, width, height, window);
	t_matrix *const restrict			matrix = m_translate_new(vec4(x, y, 0.0f, 1.0f));

	if (!string || !matrix)
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