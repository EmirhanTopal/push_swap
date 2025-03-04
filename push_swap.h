/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 12:32:49 by marvin            #+#    #+#             */
/*   Updated: 2025/03/03 12:32:49 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef	struct s_node
{
	int	data;
	int index;
	struct	s_node *next;
}	t_node;

void	ft_sa(t_node **a);
void	ft_sb(t_node **b);
void	ft_ss(t_node **a, t_node **b);
void	ft_pa(t_node **a, t_node **b);
void	ft_pb(t_node **a, t_node **b);
void	ft_ra(t_node **a);
void	ft_rb(t_node **b);
void	ft_rr(t_node **a, t_node **b);
void	ft_rra(t_node **a);
void	ft_rrb(t_node **b);
void	ft_rrr(t_node **a, t_node **b);
t_node	*ft_init_stack(void);
void	ft_fill_stack(t_node **stack, char **argv);
int		ft_stack_length(t_node *stack);
void	ft_free_stack(t_node **stack);
int		ft_is_number(char *str);
int		ft_has_duplicate(t_node *stack, int num);
int		ft_atoi_check(char *str, int *num);
void 	ft_add_node_end(t_node **stack, int num);
void	ft_add_node_front(t_node **stack, int num);

#endif