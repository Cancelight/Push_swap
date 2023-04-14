/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:35:38 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/14 16:56:23 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "../libft/libft.h"
# include "../printf/ft_printf.h"

typedef struct s_blist
{
	int				content;
	int				index;
	struct s_blist	*next;
}			t_blist;

char		**push_split(char *s, char c, int *count);
void	size_apart(int ac, char **av, t_blist **stack_a);
int		push_alnum(char *str);
void	exit_game(char *str);
int		push_atoi(char *s);
t_blist	*push_lstnew(int content, int index);
void	swap_op(t_blist **stack_c);
void	rerotate_op(t_blist **stack_c);
void	push_op(t_blist **stack_c, t_blist **stack_d, char *str);
void	rotate_op(t_blist **stack_c);
void	insert_index(t_blist **stack_a);
void	arrange_stack(t_blist **stack_a, t_blist **stack_b, int bit);
void	write_op(char *str);
int		push_lstsize(t_blist *lst);
int		control(t_blist *stack_a);
void	push_lstadd_front(t_blist **lst, t_blist *new);
t_blist	*push_lstlast(t_blist *lst);
void	push_lstadd_back(t_blist **lst, t_blist *new);
int		max_bit(int a);
void	parse(int ac, char **av, t_blist *stack_a, t_blist *stack_b);

#endif
