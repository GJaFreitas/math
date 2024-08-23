#include "algebra.h"

// Simple matrix addition
t_matrix ft_addition(t_matrix m_1, t_matrix m_2)
{
	// Check for matrix sizes and compatibility
	if (m_1->rows != m_2->rows)
	{
		printf("Matrix 1: %dx%d\nMatrix 2: %dx%d\nImpossible to add\n", m_1->rows, m_1->collumns, m_2->rows, m_2->collumns);
		return NULL;
	}
	if (m_1->collumns != m_2->collumns)
	{
		printf("Matrix 1 collumns: %d\nMatrix 2 collumns: %d\nImpossible to add", m_1->collumns, m_2->collumns);
		return NULL;
	}

	t_matrix new = ft_matrixalloc(m_1->rows, m_1->collumns);
	int i = 0, j = 0;
	while (i < m_1->collumns)
	{
		while (j < m_1->rows)
		{
			new->matrix[i][j] = m_1->matrix[i][j] + m_2->matrix[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	return new;
}

static float	ft_mult_single_element(int r, int c, t_matrix m1, t_matrix m2)
{
	float val = 0;
	int m1_c = 0, m2_r = 0;

	// The second part of the condition is unecessary and will never be checked, its just for ease of understanding
	while (m1_c < m1->collumns && m2_r < m2->rows)
	{
		val += m1->matrix[r][m1_c] * m2->matrix[m2_r][c];
		m1_c++;
		m2_r++;
	}
	return val;
}

// Simple matrix multiplication
t_matrix ft_multiplication(t_matrix m1, t_matrix m2)
{
	// Check for matrix size and compatibility
	if (m1->collumns != m2->rows)
	{
		printf("Matrix 1: %dx%d\nMatrix 2: %dx%d\nImpossible to multiply\n", m1->rows, m1->collumns, m2->rows, m2->collumns);
	}

	t_matrix new = ft_matrixalloc(m1->rows, m2->collumns);
	int i = 0, j = 0, new_r = 0, new_c = 0;

	while (new_r < new->rows)
	{
		while (new_c < new->collumns)
		{
			new->matrix[new_r][new_c] = ft_mult_single_element(new_r, new_c, m1, m2);
			new_c++;
		}
		new_c = 0;
		new_r++;
	}

	return new;
}

// Basic matrix transposition
t_matrix ft_transpose(t_matrix m)
{
	t_matrix new = ft_matrixalloc(m->collumns, m->rows);
	int r = 0, c = 0;

	while (r < new->rows)
	{
		while (c < new->collumns)
		{
			new->matrix[r][c] = m->matrix[c][r];
			c++;
		}
		c = 0;
		r++;
	}
	return new;
}

static float	ft_determinant_2x2(t_matrix m)
{
	float	result = 0;

	result += m->matrix[0][0] * m->matrix[1][1];
	result += -(m->matrix[0][1] * m->matrix[1][0]);
	return result;
}

// Leibniz formula: aei + bfg + cdh - ceg - bdi - afh
static float	ft_determinant_3x3(t_matrix m)
{
	float	result = 0;

	result += m->matrix[0][0] * m->matrix[1][1] * m->matrix[2][2];
	result += m->matrix[0][1] * m->matrix[1][2] * m->matrix[2][0];
	result += m->matrix[0][2] * m->matrix[1][0] * m->matrix[2][1];
	result += -(m->matrix[0][2] * m->matrix[1][1] * m->matrix[2][0]);
	result += -(m->matrix[0][1] * m->matrix[1][0] * m->matrix[2][2]);
	result += -(m->matrix[0][0] * m->matrix[1][2] * m->matrix[2][1]);
	return result;
}

// Calculates the determinant of a square matrix of size 3 or less 
float	ft_determinant(t_matrix m)
{
	if (!ft_is_square(m))
		return 0;

	if (m->rows == 2)
		return ft_determinant_2x2(m);
	else if (m->rows == 3)
		return ft_determinant_3x3(m);
	else if (m->rows == 1)
	 return m->matrix[0][0];
	else
	{
		printf("Can't calculate the determinant of an nxn matrix where n > 3\n");
		return 0;
	}
}

t_complex_num	ft_complex_multiplication(t_complex_num num1, t_complex_num num2)
{
	float real_part, imaginary_part;

	real_part = num1->real * num2->real;
	// i² = -1
	if (num1->imaginary != 0  && num2->imaginary != 0)
		real_part -= num1->imaginary * num2->imaginary;
	imaginary_part = num1->imaginary * num2->real;
	imaginary_part += num1->real * num2->imaginary;
	return ft_complexnum_init(real_part, imaginary_part);
}

t_complex_num	ft_complex_addition(t_complex_num num1, t_complex_num num2)
{
	return ft_complexnum_init(num1->real + num2->real, num1->imaginary + num2->imaginary);
}
