/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:28:35 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/13 16:42:54 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

t_blist	*push_lstnew(int content)
{
	t_blist	*r ;

	r = malloc (sizeof(t_blist));
	if (r == NULL)
		return (0);
	r->content = content;
	r->index = -1;
	r->next = NULL;
	return (r);
}

void	exit_game(char *str)
{
	ft_printf("%s", str);
	exit(0);
}

int	push_lstsize(t_blist *lst)
{
	int	count;

	count = 0;
	while (lst != NULL)
	{
			lst = lst->next;
			count ++;
	}
	return (count);
}

void	push_lstadd_front(t_blist **lst, t_blist *new)
{
		new -> next = (*lst);
		(*lst) = new;
}

void	push_lstadd_back(t_blist **lst, t_blist *new)
{
	if (!lst || !new)
		return ;
	if (!*lst)
		(*lst) = new;
	else
	{
		(push_lstlast(*lst))-> next = new;
		(push_lstlast(*lst))-> next = NULL;
	}
}

t_blist	*push_lstlast(t_blist *lst)
{
	if (lst != NULL)
	{
		while (lst -> next != NULL)
			lst = lst -> next;
		return (lst);
	}
	return (0);
}
