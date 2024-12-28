/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/03 23:21:38 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/30 13:55:14 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"

typedef struct s_stack
{
	int				number;
	int				index;
	int				median;
	int				cost;
	struct s_stack	*target;
	struct s_stack	*next;
}			t_stack;

//stack
t_stack	*create_node(int number, int index);
void	push_stack(t_stack **stack, int number, int index);
void	print_stack(t_stack *stack);
int		len_stack(t_stack *stack);
void	free_stack(t_stack **stack);

//Get_data
t_stack	*get_data(int size, char **argv);
void	get_stack(t_stack **stack_a, char **items);
void	free_string_array(char **array);

//checks
int		check_num(char *item);
int		check_duplicates(t_stack *stack_a);
int		check_size(char *item);
int		check_sorted(t_stack *stack);

//moves
void	ra(t_stack **stack, int print);
void	rb(t_stack **stack, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int print);
void	rra(t_stack **stack, int print);
void	rrb(t_stack **stack, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int print);
void	pa(t_stack **stack_s, t_stack **stack_d, int print);
void	pb(t_stack **stack_s, t_stack **stack_d, int print);
void	sa(t_stack **stack, int print);
void	sb(t_stack **stack, int print);
void	ss(t_stack **stack_a, t_stack **stack_b, int print);
void	sy(t_stack **a, t_stack **b, int nb, void (*f)(t_stack**,
				t_stack**, int));
void	rotate(t_stack **stack, int nb, void (*f)(t_stack**, int));

// sort
void	ft_sort_stack(t_stack **stack_a);
void	init_nodes(t_stack *stack);
void	init_target(t_stack *stack_s, t_stack *stack_t);
void	get_costs(t_stack *stack);
t_stack	*get_min(t_stack *stack);
t_stack	*get_cheapest(t_stack *stack);

#endif
