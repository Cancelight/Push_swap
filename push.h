/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:35:38 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/07 19:02:06 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

# include "./libft/libft.h"
# include "./printf/ft_printf.h"
# include <stdlib.h>
# include <unistd.h>


typedef struct s_list{
	int	content;
	int	index;
	struct s_list *next;
}			p_list;

char	**push_split(char const *s, char c, int *count);
char	**apart(int ac, char **av, t_list *stack_a);


//bir sort ile sırala indexlerini al  ve index üzerinden işlem yap i
//indexi -1'den başlat ve min değer bul
//ac kontrol etme bağlı listeye aktardıktan sonra liste sayısını kontrol et

//split + itoa => listeye aktarım (-1 kısmını unutma)

#endif
