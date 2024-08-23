#include "algebra.h"

t_matrix ft_matrixalloc(int rows, int collumns)
{
	t_matrix ret;
	int i = 0;

	ret = malloc(sizeof(_matrix));
	ret->collumns = collumns;
	ret->rows = rows;
	ret->matrix = malloc(sizeof(float *) * rows);
	while (i < rows)
	{
		ret->matrix[i] = malloc(sizeof(float) * collumns);
		i++;
	}
	return ret;
}

void ft_matrix_destructor(t_matrix m)
{
	int r = 0;

	if (m == NULL)
		return ;
	while (r != m->rows)
	{
		free(m->matrix[r]);
		r++;
	}
	free(m->matrix);
	free(m);
}

t_matrix ft_input(const char *str)
{
    int rows, collumns;
    int m_row = 0, m_col = 0;
    int negative_flag = 0;
    t_matrix s_matrix;

    // str format nxn_n... eg: 1x1_1
    // 3x2
    // 2_3_4
    // 6_8_9
    //
    // [ 2 3 4 ]
    // [ 6 8 9 ]
    rows = str[0] - 48;
    collumns = str[2] - 48;
    s_matrix = ft_matrixalloc(rows, collumns);
    for (int i = 4; str[i]; i++)
    {
        if (str[i] == '\n')
        {
            m_row++;
            m_col = 0;
        }
        else if(str[i] == '-')
        {
            negative_flag = 1; 
        }
        else if (str[i] != ' ')
        {
            s_matrix->matrix[m_row][m_col] = str[i] - 48;
            if (negative_flag)
            {
                s_matrix->matrix[m_row][m_col] = -s_matrix->matrix[m_row][m_col];
                negative_flag = 0;
            }
            m_col++;
        }
    }
    return s_matrix;
}

void ft_displaymatrix(const t_matrix s_matrix)
{
    int r = 0, c = 0;

    if (s_matrix == NULL)
    {
        printf("----\n");
        return;
    }
    while (r != s_matrix->rows)
    {
        printf("[ ");
        while (c != s_matrix->collumns)
        {
            printf("%.2f", s_matrix->matrix[r][c]);
            c++;
            printf(" ");
        }
        printf("]");
        printf("\n");
        c = 0;
        r++;
    }
    printf("\n");
}

t_complex_num	ft_complexnum_init(float real, float imaginary)
{
	t_complex_num num;
	num = malloc(sizeof(_complex_num));
	num->real = real;
	num->imaginary = imaginary;
	return num;
}

void	ft_print_imaginarynum(t_complex_num num)
{
	printf("%.2f + %.2fi", num->real, num->imaginary);
}
