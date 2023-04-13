/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:16:29 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/13 18:33:58 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap_op(t_blist **stack_c)
{
	t_blist	*temp;

	if (push_lstsize(*stack_c) <= 1)
		return ;
	temp = (*stack_c)->next->next;
	(*stack_c)->next = NULL;
	push_lstadd_front(stack_c, temp);
	free(temp);
}

void	insert_index(t_blist **stack_a)
{
	int		i;
	int		size;
	t_blist	*min;
	t_blist	*temp;

	i = 0;
	size = push_lstsize(*stack_a);
	while (i < size)
	{
		min = *stack_a;
		while (min->index != -1 && min != NULL)
			min = min->next;
		temp = *stack_a;
		while (temp != NULL)
		{
			if (min->content > temp->content && temp->index == -1)
				min = temp;
			temp = temp->next;
		}
		min->index = i++;
	}
	free(temp);
	free(min);
}

int	max_bit(int a)
{
	int	b;

	b = 0;
	while (a)
	{
		ft_printf("b:%d\n", b);
		a = a >> 1;
		b++;
	}
	return (b);
}

void	arrange_stack(t_blist **stack_a, t_blist **stack_b, int bit)
{
	int		k;
	t_blist	*temp;

	k = -1;
	temp = *stack_a;
	ft_printf("bit:%d\n", bit);
	while (++k <= bit)
	{
		while (temp != NULL)
		{
			if (temp->index >> k & 1)
			{
				rotate_op(stack_a);
				ft_printf("welp");
				write_op("ra");
			}
			else
				push_op(stack_a, stack_b, "pb");
		}
		while (*stack_b != NULL)
			push_op(stack_b, stack_a, "pa");
	}
}

int	control(t_blist *stack_a)
{
	int	i;

	i = 0;
	while (stack_a != NULL)
	{
		ft_printf("%d\n", stack_a->index);
		if (stack_a->index != i)
		{
			ft_printf("k");
			return (1);
		}
		i++;
		stack_a = stack_a->next;
	}
	return (0);
}


// 1.
// bunu yaparken leak bırakabilirsin sorun değil önemli olan yapman.
// bir main tanımla bir fonksiyon.
// fonksiyon parametre olarak herhangi bir tipte bir pointer alıcak.
// bu pointer'ın tuttuğu adresi **pointer kullanmadan değiştir.

//2.
//bunu da yaparken leak bırakabilirsin.
//bir main ve bir fonksiyon tanımla.
//fonksiyon parametre olarak double pointer alıcak ve tutulan ana root adresi değiştir.
//mainden **tanımlamadan.


//BUNLARIN HEPSİNİ YAPARKEN KAFANDAN DEĞİL SIRASIYLA ALGORİTMASINI YAZ.
//ALGORİTMA ÖĞRENMEK İÇİN SORU ÇÖZME BUNUN YERİNE ÇOK BASİT DE OLSA ALGORİTMA YAZ.


// Bir algoritma yazmaya başlarken ki adımlar.

// birincisi konu ne ? ne yapıcaksın bunu öğren
// ikincisi öğrendin main kurdun.
// elemanları alırken. şimdi bu projelerin hata mesajlarını yap.
// sonrasında kafanda kuruyorsan algoritmayı böl kendine göre parçala.
// so_long; ->.ber uzantısı kontrol
// map'i okursun
// map uzunluğu doğurumu map hatalımı girişmiş kontrol.

// map içeriğini kontrol ettin oyuncuun yerini buldun.
// map valid map.

// oyunu kurmaya başladın.
// resimler. açılmaları mlx'e kaydetmek.
// while döngüsü ile basmak.
