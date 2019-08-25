#include <lgs.h>

static char	create_shader_program(void)
{
	char				log[512];
	GLint				success;
	GLuint				vshader;
	GLuint				fshader;
	GLchar const *const	v_shader_str = get_standart_vertix_shader();
	GLchar const *const	f_shader_str = get_standart_fragment_shader();


	vshader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vshader, 1, &v_shader_str , 0);
	glCompileShader(vshader);
	glGetShaderiv(vshader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vshader, 512, NULL, log);
		printf("%s\n", log);
		return(0);
	}


	fshader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fshader, 1, &f_shader_str, 0);
	glCompileShader(fshader);
	glGetShaderiv(fshader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fshader, 512, NULL, log);
		printf("%s\n", log);
		return(0);
	}


	g_lgs_string_shader_program = glCreateProgram();
	glAttachShader(g_lgs_string_shader_program, vshader);
	glAttachShader(g_lgs_string_shader_program, fshader);
	glLinkProgram(g_lgs_string_shader_program);
	glGetProgramiv(g_lgs_string_shader_program, GL_LINK_STATUS, &success);
	if (!success)
	{
		glGetProgramInfoLog(g_lgs_string_shader_program, 512, NULL, log);
		printf("%s\n", log);
		return(0);
	}
	glDeleteShader(vshader);
	glDeleteShader(fshader);
	return (1);
}

char	string_init(char const *const restrict font)
{
	g_string_lst = 0;
	g_ftface = 0;
	if (!(create_shader_program()))
		return (0);
	FT_Init_FreeType(&g_ftlibrary);
	if (!(g_ftlibrary))
		return (0);
	if (FT_New_Face(g_ftlibrary, font, 0, &g_ftface) != FT_Err_Ok)
		return (0);
	return (1);
}