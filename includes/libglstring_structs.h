#ifndef LIBGLSTRING_STRUCTS_H
#define LIBGLSTRING_STRUCTS_H

#include <stdio.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H

typedef struct	s_string t_string;

typedef struct	s_symbol t_symbol;

struct			s_symbol
{
	FT_Glyph	glyph;
	t_symbol*	next;
	int			pos_x;
	int			pos_y;
	size_t		height;
	size_t		width;
};

struct			s_string
{
	void*		(*draw_func)(t_string*, void*);
	GLuint		shader_program;
	GLuint		texture;
	GLfloat*	verts;
	GLuint*		indices;
	t_vector	color;
	float*		view;
	float*		projection;
	float*		scale;
	float*		rotate;
	float*		translate;
	GLuint		vbo;
	GLuint		ebo;
	GLuint		vao;
	size_t		image_width;
	size_t		image_height;
	size_t		index;
	int			pix_size;
	t_string*	next;
	char		active;
	float		x;
	float		y;
};

#endif