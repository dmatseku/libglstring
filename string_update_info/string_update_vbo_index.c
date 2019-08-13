#include <lgs.h>

void	string_update_vbo_index(size_t index, int w_width, int w_height)
{
	t_string* elem = string_get_elem(index);
	float x = -((float)elem->image_width) / w_width;
	float y = -((float)elem->image_height) / w_height;
	float x1 = ((float)elem->image_width) / w_width - 2.0f / w_width;
	float y1 = ((float)elem->image_height) / w_height - 2.0f / w_height;

	elem->verts[0] = x;
	elem->verts[1] = y;
	elem->verts[4] = x;
	elem->verts[5] = y1;
	elem->verts[8] = x1;
	elem->verts[9] = y;
	elem->verts[12] = x1;
	elem->verts[13] = y1;

	glBindBuffer(GL_ARRAY_BUFFER, elem->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 16, elem->verts, STRING_DRAW);
}