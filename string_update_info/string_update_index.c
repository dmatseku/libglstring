#include <lgs.h>

static GLuint	set_texture(unsigned char const *const restrict image,
									const int width, const int height)
{
	GLuint		texture;
	const float border_color[] = { 0.0f, 0.0f, 0.0f, 1.0f };

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	free((void*)image);
	glBindTexture(GL_TEXTURE_2D, 0);
	return	(texture);
}

char	string_update_index(const size_t index, char const *const restrict str,
									const int w_width, const int w_height)
{
	t_string *const restrict			elem = string_get_elem(index);
	unsigned char const *const restrict	image = string_create_image(str, elem->pix_size,
												  &elem->image_width, &elem->image_height);

	if (!image)
		return (0);
	glDeleteTextures(1, &elem->texture);
	elem->texture = set_texture(image, elem->image_width, elem->image_height);
	string_update_vbo(elem, w_width, w_height);
	return (1);
}
