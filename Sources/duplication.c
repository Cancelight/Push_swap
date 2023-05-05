/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplication.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 13:24:55 by bkiziler          #+#    #+#             */
/*   Updated: 2023/05/05 15:09:10 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	duplication(int a, int b, int i)
{
	if (a == b && i != 0)
		exit_game("Error:Duplicated number.\n");
}
