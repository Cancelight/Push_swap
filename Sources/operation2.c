/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 17:16:29 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/15 17:10:23 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

void	swap_op(t_blist **stack_c)
{
	t_blist	*temp;

	temp = (*stack_c)->next;
	push_lstadd_front(stack_c, push_lstnew(temp->content, temp->index));
	temp = (*stack_c)->next;
	temp->next = temp->next->next;
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
}

int	max_bit(int a)
{
	int	b;

	b = 0;
	while (a)
	{
		a = a >> 1;
		b++;
	}
	return (b);
}

void	arrange_stack(t_blist **stack_a, t_blist **stack_b, int bit)
{
	int		k;
	int		i;
	t_blist	*temp;

	k = -1;
	while (++k <= bit)
	{
		i = -1;
		temp = *stack_a;
		while (*stack_a != NULL && temp->index != i)
		{
			if (temp->index >> k & 1)
			{
				if (i == -1)
					i = temp->index;
				rotate_op(stack_a);
				write_op("ra");
			}
			else
				push_op(stack_a, stack_b, "pb");
			temp = *stack_a;
		}
		while (push_lstsize(*stack_b))
			push_op(stack_b, stack_a, "pa");
	}
}

int	control(t_blist *stack_a)
{
	int	i;

	i = stack_a->index;
	while (stack_a != NULL)
	{
		if (stack_a->index != i)
			return (1);
		stack_a = stack_a->next;
		i++;
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
