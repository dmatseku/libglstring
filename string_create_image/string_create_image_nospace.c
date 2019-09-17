#include <lgs.h>

static inline t_symbol*	set_symbols_on_left(t_symbol* lst, const int32_t left)
{
	while (lst->next)
	{
		lst->pos_x -= left;
		lst = lst->next;
	}
	lst->pos_x -= left;
	return (lst);
}

static unsigned char*	create_image(t_symbol* lst, int *const restrict width,
									  int *const restrict height, const int32_t left,
									  const int32_t top, const int32_t bottom)
{
	t_symbol const *const	last = set_symbols_on_left(lst, left);
	unsigned char *restrict	image;
	size_t					x;
	size_t					y;
	unsigned char const *	buffer;
	int						pitch;

	*height = bottom - top;
	*width = last->pos_x + last->width;

	if (!(image = (unsigned char*)malloc(sizeof(unsigned char) * *height * *width * 4)))
		return (0);
	memset(image, 0, sizeof(unsigned char) * *height * *width * 4);

	while (lst)
	{
		buffer = ((FT_BitmapGlyph)lst->glyph)->bitmap.buffer;
		pitch = ((FT_BitmapGlyph)lst->glyph)->bitmap.pitch;
		y = 0;
		while (y < lst->height)
		{
			x = 0;
			while (x < lst->width)
			{
				image[(lst->pos_y + y - top) * *width * 4 + (lst->pos_x + x) * 4 + 3]
						= buffer[y * (pitch) + x];
				x++;
			}
			y++;
		}
		lst = lst->next;
	}
	return (image);
}

unsigned char*			string_create_image_nospace(char const * const restrict str,
		const int pix_size, int *const restrict width, int *const restrict height)
{
	t_symbol*		symbols;
	unsigned char*	res;
	int32_t			left;
	int32_t			bottom;
	int32_t			top;

	if (!str || !(*str))
		return (0);
	FT_Set_Pixel_Sizes(g_ftface, 0, pix_size);
	if (!(symbols = create_symbols_list_nospace(str, strlen(str), &left, &top, &bottom)))
		return (0);
	res = create_image(symbols, width, height, left, top, bottom);
	symbol_free_list(symbols);
	return (res);
}