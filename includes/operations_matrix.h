#ifndef MATRIX_OPERATIONS_MATRIX_H
# define MATRIX_OPERATIONS_MATRIX_H

# include <libmatrix_structs.h>

t_matrix*	m_rotate(t_matrix* m, float degree, t_vector rotate);

t_matrix*	m_rotate_new(float degree, t_vector rotate);

t_matrix*	m_scale(t_matrix* matrix, t_vector scale);

t_matrix*	m_scale_new(t_vector scale);

t_matrix*	m_translate(t_matrix* matrix, t_vector translate);

t_matrix*	m_translate_new(t_vector translate);

t_matrix*	m_yawpitchroll(t_matrix* matrix, float yaw, float pitch, float roll);

t_matrix*	m_yawpitchroll_new(float yaw, float pitch, float roll);

t_matrix*	m_camera(t_vector pos, t_vector target, t_vector up);

t_matrix*	m_orthographic(float left, float right, float bottom, float top, float near, float far);

t_matrix*	m_perspective(float fov, float ar, float near, float far);

#endif