#include "algebra.h"

int	ft_is_square(t_matrix m)
{
	if (m->rows == m->collumns)
		return 1;
	return 0;
}
