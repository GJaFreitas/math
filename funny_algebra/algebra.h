#ifndef algebra_h

#define algebra_h

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int rows;
	int collumns;
	float **matrix;
} _matrix;

typedef struct
{
	float real;
	float imaginary;
} _complex_num;

typedef _matrix *t_matrix;
typedef _complex_num *t_complex_num;

t_matrix ft_matrixalloc(int rows, int collumns);
t_matrix ft_input(const char *str);
void ft_displaymatrix(const t_matrix s_matrix);
void	ft_print_imaginarynum(t_complex_num num);
t_complex_num	ft_complexnum_init(float real, float imaginary);

int	ft_is_square(t_matrix m);

t_matrix ft_addition(t_matrix m_1, t_matrix m_2);
t_matrix ft_multiplication(t_matrix m1, t_matrix m2);
t_complex_num	ft_complex_multiplication(t_complex_num num1, t_complex_num num2);
t_complex_num	ft_complex_addition(t_complex_num num1, t_complex_num num2);

t_matrix ft_transpose(t_matrix m);
float	ft_determinant(t_matrix m);

#endif // !algebra_h
