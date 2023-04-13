/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 16:03:40 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/13 14:21:06 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	push_op(p_list *stack_c, p_list *stack_d, char *str)
{
	p_list *temp;

	if (ft_lstsize(stack_c <= 0))
		return ;
	temp = stack_c->next;
	while(temp->next->next != NULL)
		temp = temp->next;
	ft_lstadd_back(&stack_d, ft_lstlast(stack_c));
	temp->next = NULL;
	free(temp);
	ft_printf("%s\n", str);
}

void	rotate_op(p_list *stack_c, char *str)
{
	p_list *temp;

	if (ft_lstsize(stack_c) <= 2)
		return ;
	temp = stack_c->next;
	stack_c->next = stack_c->next->next;
	ft_lstadd_back(stack_c, temp);
	free(temp);
	ft_printf("%s\n", str);
}

void	rerotate_op(p_list *stack_c, char *str)
{
	p_list *temp;
	p_list *stemp;

	if (ft_lstsize(stack_c) <= 2)
		return ;
	temp = stack_c;
	while (temp->next->next != NULL)
		temp = temp->next;
	stemp = temp->next;
	temp->next = NULL;
	ft_lstadd_front(stack_c, stemp);
	free(stemp);
	free(temp);
	ft_printf("%s\n", str);
}
