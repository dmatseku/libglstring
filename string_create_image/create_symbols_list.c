#include <lgs.h>

static FT_Glyph		getGlyph(FT_Face face, uint32_t charcode)
{
	FT_Load_Char(face, charcode, FT_LOAD_RENDER);

	FT_Glyph glyph = 0;
	FT_Get_Glyph(face->glyph, &glyph);
	return (glyph);
}

static FT_Pos		getKerning(FT_Face face, uint32_t leftCharcode, uint32_t rightCharcode)
{
	const FT_UInt left_index = FT_Get_Char_Index(face, leftCharcode);
	const FT_UInt right_index = FT_Get_Char_Index(face, rightCharcode);
	FT_Vector delta;

	FT_Get_Kerning(face, left_index, right_index, FT_KERNING_DEFAULT, &delta);
	return (delta.x);
}

static t_symbol*	create_symbol(int32_t pos_x, FT_Int left, FT_Int top,
								unsigned int rows, unsigned int width, FT_Glyph glyph)
{
	t_symbol *const res = (t_symbol *const)malloc(sizeof(t_symbol));

	if (!res)
		return (0);
	res->next = 0;
	res->glyph = glyph;
	res->pos_x = ((pos_x >> 6) + left);
	res->pos_y = -top;
	res->width = width;
	res->height = rows;
	return (res);
}

t_symbol*			create_symbols_list(char* str, size_t str_len, int32_t* left)
{
	t_symbol*		lst;
	t_symbol*		tmp;
	int32_t			pos_x;
	size_t			i;
	FT_Glyph		glyph;
	FT_BitmapGlyph	bglyph;
	char			prev_char;

	*left = INT32_MAX;
	i = 0;
	prev_char = 0;
	pos_x = 0;
	lst = 0;
	while (i < str_len)
	{
		glyph = getGlyph(g_ftface, str[i]);
		if (!glyph)
			continue ;
		if (prev_char)
			pos_x += getKerning(g_ftface, prev_char, str[i]);
		prev_char = str[i];
		bglyph = (FT_BitmapGlyph)glyph;
		if (!(tmp = create_symbol(pos_x, bglyph->left, bglyph->top,
						bglyph->bitmap.rows, bglyph->bitmap.width, glyph)))
			return (0);
		symbol_addend(&lst, tmp);
		pos_x += (glyph->advance.x >> 10);
		*left = (*left > tmp->pos_x ? tmp->pos_x : *left);
		i++;
	}
	return (lst);
}
