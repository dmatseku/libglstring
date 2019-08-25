#include <lgs.h>

static	GLfloat*	set_verts(const size_t width, const size_t height,
								GLFWwindow *const restrict window)
{
	GLfloat *const restrict	res = (GLfloat*)malloc(sizeof(GLfloat) * 16);
	int						w_width;
	int 					w_height;

	glfwGetFramebufferSize(window, &w_width, &w_height);

	const float				x = -((float)width) / w_width;
	const float				y = -((float)height) / w_height;
	const float				x1 = ((float)width) / w_width - 2.0f / w_width;
	const float				y1 = ((float)height) / w_height - 2.0f / w_height;

	if (!res)
		return (0);
	res[0] = x;
	res[1] = y;
	res[2] = 0.0f;
	res[3] = 1.0f;
	res[4] = x;
	res[5] = y1;
	res[6] = 0.0f;
	res[7] = 0.0f;
	res[8] = x1;
	res[9] = y;
	res[10] = 1.0f;
	res[11] = 1.0f;
	res[12] = x1;
	res[13] = y1;
	res[14] = 1.0f;
	res[15] = 0.0f;
	return (res);
}

static GLuint*	set_indices(void)
{
	GLuint *const restrict	res = (GLuint*)malloc(sizeof(GLuint) * 6);

	if (!res)
		return (0);
	res[0] = 0;
	res[1] = 1;
	res[2] = 2;
	res[3] = 3;
	res[4] = 2;
	res[5] = 1;
	return (res);
}

static GLuint	set_texture(unsigned char const *const restrict image,
		const int width, const int height)
{
	GLuint	texture;
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
	return (texture);
}

t_string*	string_create_vao(unsigned char const *const restrict image, const size_t width,
		const size_t height, GLFWwindow *const restrict window)
{
	t_string *const string = (t_string *const)malloc(sizeof(t_string));

	if (!image || !string
		|| !(string->verts = set_verts(width, height, window))
		|| !(string->indices = set_indices()))
		return (0);
	string->texture = set_texture(image, width, height);
	string->next = 0;
	if (!set_vao_vbo_ebo(string))
		return (0);
	return (string);
}