#include <lgs.h>
#include <libmatrix.h>

void	string_update_vbo(t_string const *const restrict string,
							const int w_width, const int w_height)
{
	t_vec4			left_top;
	t_vec4			left_bottom;
	t_vec4			right_top;
	t_vec4			right_bottom;
	const t_mat4	proj = mat4_orthographic(-(w_width / 2),
			w_width / 2 + w_width % 2, -(w_height / 2), w_height / 2 + w_height % 2, 0.001f, 100.0f);

	left_top = mat_vec_4_mult(proj, vec4
	(
			-(string->image_width / 2),
			string->image_height / 2 + string->image_height % 2,
			1.0f, 1.0f));

	left_bottom = mat_vec_4_mult(proj, vec4
	(
			-(string->image_width / 2),
			-(string->image_height / 2),
			1.0f, 1.0f));

	right_top = mat_vec_4_mult(proj, vec4
	(
			string->image_width / 2 + string->image_width % 2,
			string->image_height / 2 + string->image_height % 2,
			1.0f, 1.0f));

	right_bottom = mat_vec_4_mult(proj, vec4
	(
			string->image_width / 2 + string->image_width % 2,
			-(string->image_height / 2),
			1.0f, 1.0f));

	string->verts[0] = left_bottom.x;
	string->verts[1] = left_bottom.y;
	string->verts[4] = left_top.x;
	string->verts[5] = left_top.y;
	string->verts[8] = right_bottom.x;
	string->verts[9] = right_bottom.y;
	string->verts[12] = right_top.x;
	string->verts[13] = right_top.y;

	glBindBuffer(GL_ARRAY_BUFFER, string->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 16, string->verts, STRING_DRAW);
}