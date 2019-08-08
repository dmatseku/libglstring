#include <lgs.h>

static char	create_shader_program(char* const dir)
{
	char*	shader_path;
	int		fd;
	GLuint	vshader,
			fshader;
	GLchar*	shader_str;


	shader_path = strjoin(dir, "/shaders/static_string.vert");
	fd = open(shader_path, O_RDONLY);
	if (!(shader_str = read_all_file(fd)))
		return (0);
	vshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vshader, 1, (GLchar const * const *)(&shader_str), 0);
	glCompileShader(vshader);
	free(shader_path);
	free(shader_str);
	shader_path = strjoin(dir, "/shaders/static_string.frag");
	fd = open(shader_path, O_RDONLY);
	if (!(shader_str = read_all_file(fd)))
		return (0);
	fshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fshader, 1, (GLchar const * const *)(&shader_str), 0);
	glCompileShader(fshader);
	free(shader_path);
	free(shader_str);
	g_string_shader_program = glCreateProgram();
	glAttachShader(g_string_shader_program, vshader);
	glAttachShader(g_string_shader_program, fshader);
	glLinkProgram(g_string_shader_program);
	glDeleteShader(vshader);
	glDeleteShader(fshader);
	return (1);
}

char	string_init(char* const shader_dir, char* font, GLFWwindow* const window)
{
	g_string_lst = 0;
	glfwGetFramebufferSize(window, &g_w_width, &g_w_height);
	if (!(create_shader_program(shader_dir)))
		return (0);
	g_path_to_font = font;
	FT_Init_FreeType(&g_ftlibrary);
	if (!(g_ftlibrary))
		return (0);
	FT_New_Face(g_ftlibrary, g_path_to_font, 0, &g_ftface);
	return (1);
}