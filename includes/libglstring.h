#ifndef GLSTRING_LIBGLSTRING_H
#define GLSTRING_LIBGLSTRING_H

# include <libmatrix.h>
# include <GLFW/glfw3.h>
# include <libglstring_structs.h>
# include <libmatrix_structs.h>


int				string_create(char* str, float x, float y, int pix_size,
						t_vector color, GLFWwindow* window);

char			string_init(char* font);

void			string_delete_one(size_t index);

void			string_draw(void);

unsigned char*	string_create_image(char* str, int pix_size, size_t *width, size_t *height);

t_string*		string_get_elem(size_t index);

void			string_update_vbo(t_string* string, int w_width, int w_height);

void			string_update_vbo_index(size_t index, int w_width, int w_height);

void			string_update_vbo_all(int w_width, int w_height);

char			string_update_index(size_t index, char* str, int w_width, int w_height);

char			string_update(t_string* string, char* str, int w_width, int w_height);

void			string_update_matrix_model(t_string* string, t_matrix* matrix);

#endif
