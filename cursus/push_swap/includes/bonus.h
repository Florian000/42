/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fgranger <fgranger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/30 11:08:39 by fgranger          #+#    #+#             */
/*   Updated: 2023/12/30 14:46:27 by fgranger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

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
void	free_stack(t_stack **stack);

//Get_data
t_stack	*get_data(int size, char **argv);

//checks
int		check_duplicates(t_stack *stack_a);
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

#endif