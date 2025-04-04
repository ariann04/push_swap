void	sa(t_stack **a, int print)
{
	t_stack	*tmp;

	if(!*a || !(*a)->next)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = (*a)->next;
	(*a)->next = tmp;
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int print)
{
	sa(b, 0);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, print)
{
	sa(a, 0);
	sb(b, 0);
	if (print)
		write(1, "ss\n", 3);
}
