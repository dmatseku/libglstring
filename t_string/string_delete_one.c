#include <lgs.h>

static void	delete_elem(t_string *const restrict elem)
{
	free(elem->verts);
	free(elem->indices);
	glDeleteVertexArrays(1, &elem->vao);
	glDeleteBuffers(1, &elem->vbo);
	glDeleteBuffers(1, &elem->ebo);
	glDeleteTextures(1, &elem->texture);
	free(elem);
}

void	string_delete_one(const size_t index)
{
	t_string*		 tmp;
	t_string const * tmp1;

	tmp = g_string_lst;
	if (tmp->index == index)
	{
		g_string_lst = tmp->next;
		delete_elem(tmp);
		return ;
	}
	while (tmp->next && tmp->next->index != index)
		tmp = tmp->next;
	tmp1 = tmp->next;
	if (!tmp->next)
		return ;
	tmp->next = tmp1->next;
	delete_elem(tmp);
}