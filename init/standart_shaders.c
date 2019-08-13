#include <lgs.h>

GLchar const *const	get_standart_vertix_shader(void)
{
	return ((GLchar const *const)
	"#version 450 core\n"
	"\n"
	"layout (location = 0) in vec2   position;\n"
	"\n"
	"layout (location = 1) in vec2   tex;\n"
	"\n"
	"uniform mat4                    model;\n"
	"\n"
	"uniform mat4                    projection;\n"
	"\n"
	"uniform mat4                    view;\n"
	"\n"
	"out vec2                        texture_coords;\n"
	"\n"
	"void main()\n"
	"{\n"
	"    gl_Position = projection * view * model * vec4(position, 0.0f, 1.0f);\n"
	"    texture_coords = tex;\n"
	"}");
}

GLchar const *const	get_standart_fragment_shader(void)
{
	return ((GLchar const *const)
	"#version 450 core\n"
	"\n"
	"in  vec2            texture_coords;\n"
	"\n"
	"out vec4            color;\n"
	"\n"
	"uniform sampler2D   Texture;\n"
	"\n"
	"uniform vec4        user_color;\n"
	"\n"
	"void main()\n"
	"{\n"
	"    vec4 sampled_color = texture(Texture, texture_coords);\n"
	"    color = vec4(sampled_color.x + user_color.x, sampled_color.y + user_color.y,\n"
	"                 sampled_color.z + user_color.z, sampled_color.w * user_color.w);\n"
	"}");
}