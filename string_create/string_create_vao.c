#include <lgs.h>

static	GLfloat*	set_verts(const float x, const float y, const float x1, const float y1)
{
	GLfloat *const	res = (GLfloat*)malloc(sizeof(GLfloat) * 16);

	if (!res)
		return (0);
	res[0] = x;
	res[1] = y;
	res[2] = 0.0f;
	res[3] = 0.0f;
	res[4] = x;
	res[5] = y1;
	res[6] = 0.0f;
	res[7] = 1.0f;
	res[8] = x1;
	res[9] = y;
	res[10] = 1.0f;
	res[11] = 0.0f;
	res[12] = x1;
	res[13] = y1;
	res[14] = 1.0f;
	res[15] = 1.0f;
	return (res);
}

static GLuint*	set_indices(void)
{
	GLuint *const	res = (GLuint*)malloc(sizeof(GLuint) * 6);

	res[0] = 0;
	res[1] = 1;
	res[2] = 2;
	res[0] = 3;
	res[0] = 2;
	res[0] = 1;
	return (res);
}

static GLuint	set_texture(unsigned char* image, int width, int height)
{
	GLuint	texture;
	float border_color[] = { 0.0f, 0.0f, 0.0f, 1.0f };

	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameterfv(GL_TEXTURE_2D, GL_TEXTURE_BORDER_COLOR, border_color);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST_MIPMAP_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	free(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	return	(texture);
}

t_string*	string_create_vao(float x, float y, unsigned char* image, size_t width, size_t height)
{
	t_string *const string = (t_string *const)malloc(sizeof(t_string));

	if (!string
		|| !(string->verts = set_verts(x, y, x + (2.0f / g_w_width * width), y + (2.0f / g_w_height * height)))
		|| !(string->indices = set_indices()))
		return (0);
	string->texture = set_texture(image, width, height);
	string->next = 0;
	if (!set_vao_vbo_ebo(string))
		return (0);
	return (string);
}