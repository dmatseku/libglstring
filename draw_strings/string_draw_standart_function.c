#include <lgs.h>

void*	string_draw_standart_function(t_string const *const restrict string, void *const restrict param)
{
	(void)param;

	if (!string->active)
		return ((void*)0);
	glBindTexture(GL_TEXTURE_2D, string->texture);
	glBindVertexArray(string->vao);
	glUniformMatrix4fv(glGetUniformLocation(g_lgs_string_shader_program, "scale"),
					   1, GL_FALSE, string->scale);
	glUniformMatrix4fv(glGetUniformLocation(g_lgs_string_shader_program, "rotate"),
					   1, GL_FALSE, string->rotate);
	glUniformMatrix4fv(glGetUniformLocation(g_lgs_string_shader_program, "translate"),
					   1, GL_FALSE, string->translate);
	glUniformMatrix4fv(glGetUniformLocation(g_lgs_string_shader_program, "view"),
					   1, GL_FALSE, string->view);
	glUniformMatrix4fv(glGetUniformLocation(g_lgs_string_shader_program, "projection"),
					   1, GL_FALSE, string->projection);
	glUniform4f(glGetUniformLocation(g_lgs_string_shader_program, "user_color"),
				string->color.x, string->color.y, string->color.z, string->color.w);
	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
	glBindVertexArray(0);
	return ((void*)0);
}

