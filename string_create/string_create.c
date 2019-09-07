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

int		string_create(char const *const restrict str, const t_vector position,
		const int pix_size, const t_vector color, GLFWwindow *const restrict window)
{
	size_t								width;
	size_t								height;
	unsigned char const *const restrict	image = string_create_image(str, pix_size, &width, &height);
	t_string *const restrict			string = string_create_vao(image, width, height, window);

	string->position = position;
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