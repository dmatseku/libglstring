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
#include <libmatrix_structs.h>
#include <libglstring_structs.h>

#define STRING_DRAW GL_DYNAMIC_DRAW

FT_Library			g_ftlibrary;

FT_Face				g_ftface;

GLuint				g_lgs_string_shader_program;

t_string*			g_string_lst;


char*				strjoin(char* str1, char* str2);

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
