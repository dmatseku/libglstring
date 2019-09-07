#include <lgs.h>

void	string_update_vbo_all(const int w_width, const int w_height)
{
	t_string*	elem;
	float		x;
	float		y;
	float		x1;
	float		y1;

	elem = g_string_lst;
	while (elem)
	{
		x = -((float)elem->image_width - 1) / (float)w_width + 2.0f / (float)w_width / 4;
		y = -((float)elem->image_height - 1) / (float)w_height + 2.0f / (float)w_height / 4;
		x1 = ((float)elem->image_width + 1) / (float)w_width - 2.0f / (float)w_width / 4;
		y1 = ((float)elem->image_height + 1) / (float)w_height - 2.0f / (float)w_height / 4;

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

		elem = elem->next;
	}
}