#include <stdio.h>
// Objective is to solve normal quadratic equations
// eg: x² + 12x + 5
// gonna have input be in the format of ax² + bx + c
// the formula is of course x = (-b +- sqrt(b² - 4ac)) / 2a

// Finding an x such that x² = a is equal to finding a root of  f(x) = x² - a
// Newton method: Xn+1 = Xn - f(Xn)/f'(Xn) = Xn - (X²n - a) / 2Xn = (Xn + a/Xn)/2
float ft_sqrt(float a)
{
	float x, calc;

	if (a > 4)
		x = (int)a >> 1;
	else
		x = 1;
	for (int i = 0; i < 10; i++)
	{
		calc = (x + a / x) / 2;
		x = calc;
	}
	return x;
}

void ft_solver(float a, float b, float c)
{
	float result, discriminant;

	discriminant = ft_sqrt((b*b) - 4 * a * c);
	printf("x = %.2f V x = %.2f\n", (-b + discriminant) / (2 * a), (-b - discriminant) / (2 * a));
}

int	main(int argc, char **argv)
{
	ft_solver(1, 3, 1);
	return 0;
}
