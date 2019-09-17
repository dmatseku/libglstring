#include <lgs.h>
#include <libmatrix.h>

void	string_update_vbo_all(const int w_width, const int w_height)
{
	t_string*		elem;
	t_vec4			left_top;
	t_vec4			left_bottom;
	t_vec4			right_top;
	t_vec4			right_bottom;
	const t_mat4	proj = mat4_orthographic(-(w_width / 2), w_width / 2 + w_width % 2,
				-(w_height / 2), w_height / 2 + w_height % 2, 0.001f, 100.0f);

	elem = g_string_lst;
	while (elem)
	{
		left_top = mat_vec_4_mult(proj, vec4
		(
				-(elem->image_width / 2),
				elem->image_height / 2 + elem->image_height % 2,
				1.0f, 1.0f));

		left_bottom = mat_vec_4_mult(proj, vec4
		(
				-(elem->image_width / 2),
				-(elem->image_height / 2),
				1.0f, 1.0f));

		right_top = mat_vec_4_mult(proj, vec4
		(
				elem->image_width / 2 + elem->image_width % 2,
				elem->image_height / 2 + elem->image_height % 2,
				1.0f, 1.0f));

		right_bottom = mat_vec_4_mult(proj, vec4
		(
				elem->image_width / 2 + elem->image_width % 2,
				-(elem->image_height / 2),
				1.0f, 1.0f));

		elem->verts[0] = left_bottom.x;
		elem->verts[1] = left_bottom.y;
		elem->verts[4] = left_top.x;
		elem->verts[5] = left_top.y;
		elem->verts[8] = right_bottom.x;
		elem->verts[9] = right_bottom.y;
		elem->verts[12] = right_top.x;
		elem->verts[13] = right_top.y;

		glBindBuffer(GL_ARRAY_BUFFER, elem->vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 16, elem->verts, STRING_DRAW);

		elem = elem->next;
	}
}