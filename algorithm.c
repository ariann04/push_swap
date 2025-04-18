#include "push_swap.h"

int	atoi2(const char *str)
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
	if (!*str || !ft_isdigit(*str))
		ft_error();
	while (*str)
	{
		if (!ft_isdigit(*str))
			ft_error();
		i = i * 10 + (*str - 48);
		str++;
	}
	if ((sign * i) > 2147483647 || (sign * i) < -2147483648)
		ft_error();
	return (sign * i);
}

t_stack	*sub_process(char **argv)
{
	t_stack	*a;
	char	**tmp;
	int		i;
	int		j;

	i = 0;
	tmp = split_spaces(argv[1]);
	a = NULL;
	while (tmp[i])
	{
		j = atoi2(tmp[i]);
		ft_lstadd_back(&a, ft_lstnew(j));
		i++;
	}
	free_array(tmp);
	return (a);
}

t_stack	*process(int argc, char **argv)
{
	t_stack	*a;
	int		i;
	int		j;

	a = NULL;
	i = 1;
	if (argc < 2)
		 ft_error();
	if (argc == 2 && ft_strchr(argv[1], ' '))
	{
		a = (sub_process(argv));
		return (a);
	}
	while (i < argc)
	{
		j = atoi2(argv[i]);
		ft_lstadd_back(&a, ft_lstnew(j));
		i++;
	}
	return (a);
}
