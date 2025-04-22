#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack	*b;
	
	if (argc <= 1)
		exit(1);
	a = process(argc, argv);
	if (!a || check_dup(a))
	{
		ft_free(&a);
		ft_error();
	}
	if (checksorted(a))
	{
		ft_free(&a);
		exit(0);
	}
	b = NULL;
	cases(&a, &b);
	ft_free(&a);
	return (0);
}
