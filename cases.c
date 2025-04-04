void	cases(t_stack **a, t_stack **b)
{
	if ((*a)->next->next == NULL)
		sort2(a);
	if (ft_lstsize(a) == 3)
		sort3(a);
}
