#include "algebra.h"

t_matrix ft_2D_90_degree_rot(t_matrix matrix)
{
	t_matrix rotation_matrix = ft_input("2x2\n0 -1\n1 0");
	t_matrix m;

	m = ft_multiplication(matrix, rotation_matrix);
	ft_matrix_destructor(rotation_matrix);
	return (m);
}

t_matrix ft_2D_180_degree_rot(t_matrix matrix)
{
	t_matrix rotation_matrix = ft_input("2x2\n-1 0\n0 -1");
	t_matrix m;

	m = ft_multiplication(matrix, rotation_matrix);
	ft_matrix_destructor(rotation_matrix);
	return (m);
}

t_matrix ft_2D_270_degree_rot(t_matrix matrix)
{
	t_matrix rotation_matrix = ft_input("2x2\n0 1\n-1 0");
	t_matrix m;

	m = ft_multiplication(matrix, rotation_matrix);
	ft_matrix_destructor(rotation_matrix);
	return (m);
}
