#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <limits.h>
# include "libft/libft.h"

typedef	struct	s_stack
{
	int				content;
	struct s_stack	*next;
}					t_stack;

void	sa(t_stack *a, int print);
void	sb(t_stack *b, int print);
void	ss(t_stack *a, t_stack *b, int print);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a, int print);
void	rb(t_stack **b, int print);
void	rr(t_stack **a, t_stack **b, int print);
void	rra(t_stack **a, int print);
void	rrb(t_stack **b, int print);
void	rrr(t_stack **a, t_stack **b);
t_stack	*process(int argc, char **argv);
t_stack	*sub_process(char **argv);
int		atoi2(const char *str);
void	cases(t_stack **a, t_stack **b);
void	sort2(t_stack **a);
void	sort3(t_stack **a);
void	sort4(t_stack **a, t_stack **b);
void	sort5(t_stack **a, t_stack **b);
int		whitespace(char c);
void	free_array(char **str);
int		count_words(char *str);
char	*get_next_word(char *str);
char	**split_spaces(char *str);
int		checksorted(t_stack *a);
int		check_dup(t_stack *a);
void	ft_error(void);
void	ft_free(t_stack **lst);
t_stack	*ft_lstnew(int content);
t_stack	*ft_lstlast(t_stack *lst);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
#endif
