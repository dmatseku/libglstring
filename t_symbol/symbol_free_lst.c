#include <lgs.h>

void	symbol_free_list(t_symbol* lst)
{
	t_symbol*	tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		FT_Done_Glyph(tmp->glyph);
		free(tmp);
	}
}