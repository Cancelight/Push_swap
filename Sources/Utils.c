/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:28:35 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/08 15:33:07 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

p_list	*push_lstnew(void *content)
{
	p_list	*r ;

	r = malloc (sizeof(p_list));
	if (r == NULL)
		return (0);
	r->content = (void *)content;
	r->index = -1;
	r->next = NULL;
	return (r);
}

void	exit_game(char *str)
{
	ft_printf("%s", str);
	exit(0);
}
