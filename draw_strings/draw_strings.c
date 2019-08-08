#include <lgs.h>

void	string_draw()
{
	t_string* lst;

	glUseProgram(g_string_shader_program);
	lst = g_string_lst;

	while (lst)
	{
		glBindTexture(GL_TEXTURE_2D, lst->texture);
		glBindVertexArray(lst->vao);
		glUniformMatrix4fv(glGetUniformLocation(g_string_shader_program, "model"),
				1, GL_FALSE, lst->model);
		glUniformMatrix4fv(glGetUniformLocation(g_string_shader_program, "view"),
				1, GL_FALSE, lst->view);
		glUniformMatrix4fv(glGetUniformLocation(g_string_shader_program, "projection"),
				1, GL_FALSE, lst->projection);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		lst = lst->next;
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}
