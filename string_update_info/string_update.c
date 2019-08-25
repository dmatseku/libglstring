#include <lgs.h>

static GLuint	set_texture(unsigned char const *const restrict image,
									const int width, const int height)
{
	GLuint		texture;
	const float	border_color[] = { 0.0f, 0.0f, 0.0f, 1.0f };

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

char	string_update(t_string *const restrict string, char const *const restrict str,
												const int w_width, const int w_height)
{
	unsigned char const *const restrict	image = string_create_image(str, string->pix_size,
			&string->image_width, &string->image_height);

	if (!image)
		return (0);
	glDeleteTextures(1, &string->texture);
	string->texture = set_texture(image, string->image_width, string->image_height);
	string_update_vbo(string, w_width, w_height);
	return (1);
}