#include <lgs.h>

void	string_update_vbo(t_string* string, int w_width, int w_height)
{
	float x = -((float)string->image_width) / w_width;
	float y = -((float)string->image_height) / w_height;
	float x1 = ((float)string->image_width) / w_width - 2.0f / w_width;
	float y1 = ((float)string->image_height) / w_height - 2.0f / w_height;

	string->verts[0] = x;
	string->verts[1] = y;
	string->verts[4] = x;
	string->verts[5] = y1;
	string->verts[8] = x1;
	string->verts[9] = y;
	string->verts[12] = x1;
	string->verts[13] = y1;

	glBindBuffer(GL_ARRAY_BUFFER, string->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 16, string->verts, STRING_DRAW);
}