#include <lgs.h>

static void	delete_elem(t_string* elem)
{
	free(elem->verts);
	free(elem->indices);
	glDeleteVertexArrays(1, &elem->vao);
	glDeleteBuffers(1, &elem->vbo);
	glDeleteBuffers(1, &elem->ebo);
	free(elem->view);
	free(elem->translate);
	free(elem->rotate);
	free(elem->scale);
	free(elem->projection);
	free(elem);
}

void	string_delete_one(size_t index)
{
	t_string* tmp;
	t_string* tmp1;

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