/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appended.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:10:41 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/14 16:56:43 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	size_apart(int ac, char **av, t_blist **stack_a)
{
	int		i;
	int		k;
	char	**temp;
	int		count;

	i = 1;
	while(i < ac)
	{
		k = 0;
		count = 0;
		temp = push_split(av[i++], 32, &count);
		while(k < count)
			push_lstadd_back(stack_a, push_lstnew(push_atoi(temp[k++]), -1));
		k = 0;
		while (k < count)
			free(temp[k++]);
		free(temp);
	}
}
