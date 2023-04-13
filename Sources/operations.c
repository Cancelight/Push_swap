/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:03:40 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/13 19:04:23 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	push_op(t_blist **stack_c, t_blist **stack_d, char *str)
{
	t_blist *temp;

	if (push_lstsize(*stack_c) <= 0)
		return ;
	temp = *stack_c;
	while(temp->next->next != NULL)
		temp = temp->next;
	push_lstadd_back(stack_d, push_lstlast(*stack_c));
	temp->next = NULL;
	ft_printf("%s\n", str);
}

void	rotate_op(t_blist **stack_c)
{
	t_blist *temp;

	if (push_lstsize(*stack_c) <= 2)
		return ;
	temp = *stack_c;
	(*stack_c) = (*stack_c)->next;
	temp->next = NULL;
	push_lstadd_back(stack_c, temp);
	ft_printf("why\n");
	return ;
}

void	rerotate_op(t_blist **stack_c)
{
	t_blist *temp;
	t_blist *stemp;

	if (push_lstsize(*stack_c) <= 2)
		return ;
	temp = *stack_c;
	while (temp->next->next != NULL)
		temp = temp->next;
	stemp = temp->next;
	temp->next = NULL;
	push_lstadd_front(stack_c, stemp);
}

void	write_op(char *str)
{
	ft_printf("%s\n", str);
}
