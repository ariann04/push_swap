#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack	*b;
	
	a = process(argc, argv);
	if (!a || check_dup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (!checksorted(a))
	{
		b = NULL;
		cases(&a, &b);
	}
	ft_free(&a);
	return (0);
}
