#include <lgs.h>

void	string_add(t_string* *const lst, t_string *const elem)
{
	t_string* tmp;
	t_string* tmp1;

	if (!*lst)
	{
		*lst = elem;
		elem->index = 0;
		return ;
	}
	tmp = *lst;
	while (tmp->next && tmp->index == tmp->next->index - 1)
		tmp = tmp->next;
	if (!tmp->next)
		tmp->next = elem;
	else
	{
		tmp1 = tmp->next;
		tmp->next = elem;
		elem->next = tmp1;
	}
	elem->index = tmp->index + 1;
}