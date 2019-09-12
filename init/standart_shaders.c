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
	"uniform vec3					 model;"
	"\n"
	"out vec2                        texture_coords;\n"
	"\n"
	"void main()\n"
	"{\n"
	"    gl_Position = vec4(position.xy + model.xy, model.z, 1.0f);\n"
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
	"    color = vec4(sampled_color.xyz + user_color.xyz, sampled_color.w * user_color.w);\n"
	"}");
}
