#ifndef GLSTRING_LGS_H
#define GLSTRING_LGS_H


#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <SOIL/SOIL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <rwfile.h>
#include <matrix.h>
#include <ft2build.h>
#include FT_FREETYPE_H
#include FT_GLYPH_H
#include <stdint.h>

#define STRING_DRAW GL_DYNAMIC_DRAW

typedef struct	s_symbol t_symbol;

typedef struct	s_string t_string;

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
	void*(*draw_func)(t_string*, void*);
	GLuint		shader_program;
	GLuint		texture;
	GLfloat*	verts;
	GLuint*		indices;
	t_vector	color;
	float*		view;
	float*		projection;
	float*		model;
	GLuint		vbo;
	GLuint		ebo;
	GLuint		vao;
	size_t		image_width;
	size_t		image_height;
	size_t		index;
	int			pix_size;
	t_string*	next;
};

FT_Library			g_ftlibrary;

FT_Face				g_ftface;

GLuint				g_lgs_string_shader_program;

t_string*			g_string_lst;


char*				strjoin(char* str1, char* str2);
//
//t_symbol			*symbol_new(size_t pos_x, size_t pos_y, size_t height, size_t width, FT_Glyph glyph);

void				symbol_addend(t_symbol** lst, t_symbol* elem);

void				symbol_free_list(t_symbol* lst);

t_symbol*			create_symbols_list(char* str, size_t str_len, int32_t* left,
										 int32_t* top, int32_t* bottom);

unsigned char*		string_create_image(char* str, int pix_size, size_t *width, size_t *height);

char				set_vao_vbo_ebo(t_string* string);

void				string_add(t_string** lst, t_string* elem);

t_string*			string_create_vao(unsigned char* image, size_t width, size_t height, GLFWwindow* window);

GLchar const *const	get_standart_vertix_shader(void);

GLchar const *const	get_standart_fragment_shader(void);

void*				string_draw_standart_function(t_string* string, void* param);

t_string*			string_get_elem(size_t index);

void				string_update_vbo(t_string* string, int w_width, int w_height);

#endif
