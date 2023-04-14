/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:03:40 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/14 18:02:37 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	push_op(t_blist **stack_c, t_blist **stack_d, char *str)
{
	t_blist	*temp;

	if (!*stack_c)
		return ;
	temp = *stack_c;
	push_lstadd_front(stack_d, push_lstnew(temp->content, temp->index));
	*stack_c = (*stack_c)->next;
	ft_printf("%s\n", str);
}

void	rotate_op(t_blist **stack_c)
{
	t_blist *temp;

	temp = (*stack_c);
	push_lstadd_back(stack_c, push_lstnew(temp->content, temp->index));
	*stack_c = (*stack_c)->next;
	
}

void	rerotate_op(t_blist **stack_c)
{
	t_blist *temp;

	if (push_lstsize(*stack_c) <= 2)
		return ;
	temp = *stack_c;
	*stack_c = (*stack_c)->next;
	temp->next = NULL;
	push_lstadd_back(stack_c, temp);
}

void	write_op(char *str)
{
	ft_printf("%s\n", str);
}
