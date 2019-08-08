#ifndef GLSTRING_LIBGLSTRING_H
#define GLSTRING_LIBGLSTRING_H

char	string_create(char* str, float x, float y, int pix_size);

char	string_init(char* const dir, GLFWwindow* const window);

void	string_delete_one(size_t index);

void	string_draw();

#endif