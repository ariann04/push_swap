int	atoi2(char **argv)
{
	int				sign;
	long long int	i;

	i = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n' || *str == '\f'
			|| *str == '\v' || *str == '\r')
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((mod * i) > 2147483647 || (mod * 1) < -2147483647)
		ft_error();
	return (mod * i);
}

t_stack	sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	tmp = split(argv[1], 32);
	while (tmp[i])
	{
		j = atoi_2(tmp[i]);
		ft_add_back(&a, stack_new(j));
		i++;
	}
	ft_freestr(tmp);
	free(tmp);
	return (a);
}

t_stack	process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	a = NULL;
	i = 1;
	if (argc < 2)
		ft_error();
	if (argc == 2)
		a = sub_process(argv);
	while (i < argc)
	{
		j = atoi_2(argv[i]);
		ft_add_back(&a, stack_new(j));
		i++;
	}
	return (a);
}
