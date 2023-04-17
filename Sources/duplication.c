/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplication.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:24:55 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/17 15:46:45 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	duplication(int a, int b, int i)
{
	if (a == b && i != -1 && i != 0)
		exit_game("Error:Duplicated number.\n");
}
