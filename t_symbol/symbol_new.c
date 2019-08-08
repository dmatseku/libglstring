#include <lgs.h>

t_symbol *symbol_new(const size_t pos_x, const size_t pos_y,
		const size_t height, const size_t width, FT_Glyph glyph)
{
	t_symbol* res;

	if (!(res = (t_symbol*)malloc(sizeof(t_symbol))))
		return (0);
	res->next = 0;
	res->glyph = glyph;
	res->height = height;
	res->width = width;
	res->pos_x = pos_x;
	res->pos_y = pos_y;
	return (res);
}