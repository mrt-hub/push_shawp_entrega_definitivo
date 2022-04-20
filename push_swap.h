/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtorrado <mtorrado@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 20:13:13 by mtorrado          #+#    #+#             */
/*   Updated: 2022/04/20 20:01:02 by mtorrado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include    "./libft/libft.h"
# include    <stdio.h>
# include    <stdlib.h>

typedef struct s_dlist
{
	int				content;
	struct s_dlist	*next;
}				t_dlist;

int			ft_strcmp(char *s1, char *s2);
void		ft_exit_error(char *msg, int error);
void		check_argv(t_dlist **stack);
long int	ft_int_atoi(char *s);
long int	ft_check_sig(int neg, int plus, long int ret);
void		del_first_node_lst(t_dlist **stack);

void		rotate(t_dlist **stack, char c);
void		rotate_rr(t_dlist **stack_a, t_dlist **stack_b);
void		reverse_rotate(t_dlist **stack, char c);
void		reverse_rotate_rr(t_dlist **stack_a, t_dlist **stack_b);
void		push(t_dlist **stack, t_dlist **stack_dest, char c);
void		ft_swap(int *content_a, int *content_b, char c);
void		swap_stack(t_dlist *stack, char c);
void		swap_ss(t_dlist *stack_a, t_dlist *stack_b);

t_dlist		*ft_dlstnew(int content);

void		ft_dlstadd_front(t_dlist	**alst, t_dlist *new);
int			ft_dlstsize(t_dlist *lst);

t_dlist		*ft_dlstlast(t_dlist *lst);

void		ft_dlstadd_back(t_dlist **alst, t_dlist *new);
t_dlist		*fill_list(t_dlist **stack_a, char **split_arg);
t_dlist		*ft_lst_dup(t_dlist *stack);
void		ft_lstswp(t_dlist *x, t_dlist *y);
t_dlist		*ft_lstsort(t_dlist *stack);
t_dlist		*ft_lstsort_reverse(t_dlist *stack);

void		free_stack(t_dlist **stack);
int			get_first_pos(t_dlist *stack, t_dlist *stack_a_order);
int			get_last_pos(t_dlist *stack, t_dlist *stack_a_order);
int			check_list_order(t_dlist **stack);
void		print_stacks(t_dlist *stack_a, t_dlist *stack_b);

void		mini_quick_sort(t_dlist **a, t_dlist **b, t_dlist **or);
void		sort_3(t_dlist **stack_a);
int			get_pos(t_dlist **stack_order, t_dlist **stack);
void		quick_sort(t_dlist **a_or, t_dlist **a, t_dlist **b, int len_block);
int			send_to_b(t_dlist **a, t_dlist **b, t_dlist **a_or, t_dlist *p_b);
void		order_list_a(t_dlist **stack_a, t_dlist **stack_b, int len_block);
void		quick_sort_2(t_dlist **a_or, t_dlist **a, t_dlist **b, int len_b);
void		smart_rotate(t_dlist **stack_a, t_dlist **stack_a_order);
void		order_list_a(t_dlist **stack_a, t_dlist **stack_b, int len_block);
void		send_to_a(t_dlist **a, t_dlist **b, t_dlist *b_or);
int			ft_get_len_block(int len);

#endif