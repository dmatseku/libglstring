#include <lgs.h>

void	symbol_addend(t_symbol** const lst, t_symbol* const elem)
{
	t_symbol* tmp;

	if (!(*lst))
	{
		*lst = elem;
	}
	else
	{
		tmp = *lst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = elem;
	}
}