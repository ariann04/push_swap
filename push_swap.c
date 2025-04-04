int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack	*b;
	
	a = process(argc, argv);
	if (!a || check_dup(a))
	{
		ft_free(&a);
		ft_error;
	}
	if (!check_sorted(a))
		cases(&a);
	ft_free(&a);
	return (0);
}
