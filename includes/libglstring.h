#ifndef GLSTRING_LIBGLSTRING_H
#define GLSTRING_LIBGLSTRING_H

# include <libmatrix.h>
# include <GLFW/glfw3.h>
# include <libglstring_structs.h>
# include <libmatrix_structs.h>


int				string_create(char const * str, t_vec3 position, int pix_size,
						 			t_vec4 color, GLFWwindow* window);

int				string_create_nospace(char const * str, t_vec3 position, int pix_size,
									t_vec4 color, GLFWwindow* window);

char			string_init(char const * font);

void			string_delete_one(size_t index);

void			string_draw(void);

unsigned char*	string_create_image(char const * str, int pix_size, int* width, int* height);

unsigned char*	string_create_image_nospace(char const * str, int pix_size,
													int* width, int* height);

t_string*		string_get_elem(size_t index);

void			string_update_vbo(t_string const * string, int w_width, int w_height);

void			string_update_vbo_index(size_t index, int w_width, int w_height);

void			string_update_vbo_all(int w_width, int w_height);

char			string_update_index(size_t index, char const * str, int w_width, int w_height);

char			string_update_index_nospace(size_t index, char const * str,
									int w_width, int w_height);

char			string_update(t_string* string, char const * str, int w_width, int w_height);

char			string_update_nospace(t_string* string, char const * str,
									int w_width, int w_height);

#endif
