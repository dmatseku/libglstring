#include <lgs.h>

t_string*	string_get_elem(const size_t index)
{
	t_string* lst;

	lst = g_string_lst;
	while (lst && lst->index != index)
		lst = lst->next;
	return (lst);
}

