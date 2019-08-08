#include <lgs.h>

static inline t_symbol*	set_symbols_on_left(t_symbol* lst)
{
	while (lst->next)
	{
		lst->pos_x -= g_left;
		lst = lst->next;
	}
	lst->pos_x -= g_left;
	return (lst);
}

static unsigned char*	create_image(t_symbol* lst, size_t *width, size_t *height)
{
	t_symbol *const	last = set_symbols_on_left(lst);
	unsigned char*	image;
	size_t			x;
	size_t			y;
	unsigned char*	pixel;
	FT_Bitmap		bitmap;

	*height = g_bottom - g_top;
	*width = last->pos_x + last->width;
	if (!(image = (unsigned char*)malloc(sizeof(unsigned char) * *height * *width * 4)))
		return (0);
	bzero(image, sizeof(unsigned char) * *height * *width * 4);
	while (lst)
	{
		bitmap = ((FT_BitmapGlyph)lst->glyph)->bitmap;
		y = 0;
		while (y < lst->height)
		{
			x = 0;
			while (x < lst->width)
			{
				pixel = bitmap.buffer + (y * bitmap.pitch + x) * 4;
				image[(y * bitmap.pitch + lst->pos_x + x) * 4] = pixel[0];
				image[(y * bitmap.pitch + lst->pos_x + x) * 4 + 1] = pixel[1];
				image[(y * bitmap.pitch + lst->pos_x + x) * 4 + 2] = pixel[2];
				image[(y * bitmap.pitch + lst->pos_x + x) * 4 + 3] = pixel[3];
				x++;
			}
			y++;
		}
		lst = lst->next;
	}
	return (image);
}



unsigned char*			string_create_image(char* const str, const int pix_size, size_t *width, size_t *height)
{
	t_symbol*		symbols;
	unsigned char*	res;

	if (!str || !(*str))
		return (0);
	FT_Set_Pixel_Sizes(g_ftface, 0, pix_size);
	if (!(symbols = create_symbols_list(str, strlen(str))))
		return (0);
	set_symbols_on_left(symbols);
	res = create_image(symbols, width, height);
	symbol_free_list(symbols);
	return (res);
}
