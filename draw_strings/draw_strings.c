#include <lgs.h>

void	string_draw(void)
{
	t_string* lst;

	lst = g_string_lst;
	while (lst)
	{
		glUseProgram(lst->shader_program);
		lst->draw_func(lst, 0);
		lst = lst->next;
	}
	glBindTexture(GL_TEXTURE_2D, 0);
	glBindVertexArray(0);
}
