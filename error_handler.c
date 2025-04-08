void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit(1);
}

void	ft_free(t_stack **lst)
{
	t_stack	**tmp;

	if (!lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		(*lst)->nbr = 0;
		free(*lst);
		*lst = tmp;
	}
}
