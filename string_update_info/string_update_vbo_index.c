#include <lgs.h>

void	string_update_vbo_index(const size_t index, const int w_width, const int w_height)
{
	t_string const *const restrict	elem = string_get_elem(index);
	const float						x = -((float)elem->image_width - 1) / (float)w_width + 2.0f / (float)w_width / 4;
	const float						y = -((float)elem->image_height - 1) / (float)w_height + 2.0f / (float)w_height / 4;
	const float						x1 = ((float)elem->image_width + 1) / (float)w_width - 2.0f / (float)w_width / 4;
	const float						y1 = ((float)elem->image_height + 1) / (float)w_height - 2.0f / (float)w_height / 4;

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