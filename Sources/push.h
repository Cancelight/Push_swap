/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:35:38 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/13 14:22:39 by bkiziler         ###   ########.fr       */
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
void	size_apart(int ac, char **av, t_list *stack_a);
int		push_alnum(char *str);
void	exit_game(char *str);
int		push_atoi(const char *s);
p_list	*push_lstnew(void *content);
void	swap_op(p_list *stack_c, char *str);
void	rerotate_op(p_list *stack_c, char *str);
void	push_op(p_list *stack_c, p_list *stack_d, char *str);
void	rotate_op(p_list *stack_c, char *str);
void	insert_index(p_list *stack_a);
void	arrange_stack(p_list *stack_a, p_list *stack_b, int bit);



//bir sort ile sırala indexlerini al  ve index üzerinden işlem yap i
//indexi -1'den başlat ve min değer bul
//ac kontrol etme bağlı listeye aktardıktan sonra liste sayısını kontrol et

//split + itoa => listeye aktarım (-1 kısmını unutma)

#endif
