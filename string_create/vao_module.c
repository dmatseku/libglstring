#include <lgs.h>

char	set_vao_vbo_ebo(t_string *const restrict string)
{
	glGenVertexArrays(1, &(string->vao));
	glGenBuffers(1, &(string->vbo));
	glGenBuffers(1, &(string->ebo));

	glBindVertexArray(string->vao);

	glBindBuffer(GL_ARRAY_BUFFER, string->vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 16, string->verts, STRING_DRAW);

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, string->ebo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(GLuint) * 6, string->indices, STRING_DRAW);

	glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), (GLvoid*)(2 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);

	glBindVertexArray(0);

	return (1);
}
