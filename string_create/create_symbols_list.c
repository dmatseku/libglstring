#include <lgs.h>

static FT_Glyph	getGlyph(FT_Face face, uint32_t charcode)
{
	FT_Load_Char(face, charcode, FT_LOAD_RENDER);

	FT_Glyph glyph = (FT_Glyph)malloc(sizeof(FT_GlyphRec));
	if (!glyph)
		return (0);
	FT_Get_Glyph(face->glyph, &glyph);
	return (glyph);
}

static FT_Pos	getKerning(FT_Face face, uint32_t leftCharcode, uint32_t rightCharcode)
{
	const FT_UInt leftIndex = FT_Get_Char_Index(face, leftCharcode);
	const FT_UInt rightIndex = FT_Get_Char_Index(face, rightCharcode);
	FT_Vector delta;

	FT_Get_Kerning(face, leftIndex, rightIndex, FT_KERNING_DEFAULT, &delta);
	return (delta.x);
}

t_symbol*		create_symbols_list(char* str, size_t str_len)
{
	t_symbol*		lst;
	t_symbol*		tmp;
	int32_t			posX;
	size_t			i;
	FT_Glyph		glyph;
	FT_BitmapGlyph	bglyph;
	char			prev_char;

	g_left = INT32_MAX;
	g_top = INT32_MAX;
	g_bottom = INT32_MIN;
	i = 0;
	prev_char = 0;
	posX = 0;
	lst = 0;
	while (i < str_len)
	{
		glyph = getGlyph(g_ftface, str[i]);
		if (!glyph)
			continue ;
		if (prev_char)
			posX += getKerning(g_ftface, prev_char, str[i]);
		prev_char = str[i];
		bglyph = (FT_BitmapGlyph)glyph;
		if (!(tmp = symbol_new((posX >> 6) + bglyph->left, -bglyph->top,
								bglyph->bitmap.rows, bglyph->bitmap.width, glyph)))
			return (0);
		symbol_addend(&lst, tmp);
		posX += (glyph->advance.x >> 10);
		g_left = (g_left > tmp->pos_x ? tmp->pos_x : g_left);
		g_top = (g_top > tmp->pos_y ? tmp->pos_y : g_top);
		g_bottom = (g_bottom > tmp->pos_y + tmp->height ?
					g_bottom : tmp->pos_y + tmp->height);
		i++;
	}
	return (lst);
}
