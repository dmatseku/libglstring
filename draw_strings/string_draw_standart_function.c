#include <lgs.h>

void*	string_draw_standart_function(t_string const *const restrict string, void *const restrict param)
{
	(void)param;

	if (!string->active)
		return ((void*)0);
	glBindTexture(GL_TEXTURE_2D, string->texture);
	glBindVertexArray(string->vao);
	glUniform3f(glGetUniformLocation(g_lgs_string_shader_program, "model"),
					   string->position.x, string->position.y, string->position.z);
	glUniform4f(glGetUniformLocation(g_lgs_string_shader_program, "user_color"),
				string->color.x, string->color.y, string->color.z, string->color.w);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	return ((void*)0);
}

