#include "algebra.h"

int main(int argc, char **argv)
{
	if (argv[1][0] == '0')
	{
		t_complex_num num1 = ft_complexnum_init(1, 4);
		t_complex_num num2 = ft_complexnum_init(5, 1);

		printf("First num: ");
		ft_print_imaginarynum(num1);
		printf("\n");
		printf("Second num: ");
		ft_print_imaginarynum(num2);
		printf("\n");

		t_complex_num mult = ft_complex_multiplication(num1, num2);
		printf("Mult: ");
		ft_print_imaginarynum(mult);
		printf("\n");
	}

	if (argv[1][0] == '1')
	{
		char *str = "2x2\n1 2\n4 5";
		t_matrix matrix = ft_input(str);
		ft_displaymatrix(matrix);
		char *str2 = "2x3\n2 1 3\n-5 4 -7";
		t_matrix matrix2 = ft_input(str2);
		ft_displaymatrix(matrix2);

		t_matrix matrix3 = ft_multiplication(matrix, matrix2);
		ft_displaymatrix(matrix3);
		t_matrix matrix4 = ft_input("3x3\n-2 -1 2\n2 1 4\n-3 3 -1");
		ft_displaymatrix(matrix4);
		printf("Determinant: %f", ft_determinant(matrix4));
	}

	return 0;
}
