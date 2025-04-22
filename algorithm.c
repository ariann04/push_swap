/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblagoev <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 21:22:14 by tblagoev          #+#    #+#             */
/*   Updated: 2025/04/23 00:30:25 by tblagoev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	atoi2(const char *str)
{
	int				sign;
	long long int	i;

	sign = 1;
	i = 0;
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
	if (!*str)
		ft_error();
	while (*str)
	{
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
		if (!ft_isnumber(tmp[i]))
			ft_error();
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
		if (!ft_isnumber(argv[i]))
			ft_error();
		j = atoi2(argv[i]);
		ft_lstadd_back(&a, ft_lstnew(j));
		i++;
	}
	return (a);
}
