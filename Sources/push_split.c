/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:58:39 by bkiziler          #+#    #+#             */
/*   Updated: 2023/05/23 18:51:41 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int	countc(char const *a, char b)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (a[i])
	{
		if ((a[i] == b && ((a[i + 1] != '\0') && a[i + 1] != b)))
			count++;
		i++;
	}
	if (a[0] != b)
		count ++;
	return (count);
}

char	**push_split(char *s, char c, int *count)
{
	int		i;
	int		a;
	int		n;
	char	**ptr;

	a = 0;
	i = 0;
	n = 0;
	if (!s || s[0] == 0)
		return (NULL);
	*count = countc(s, c);
	ptr = ft_calloc(*count + 1, sizeof(char *));
	if (ptr == NULL)
		return (NULL);
	while (a < *count)
	{
		while (s[i] == c)
			i++;
		n = i;
		while (s[i] != c && s[i])
			i++;
		ptr[a++] = ft_substr(s, n, i - n);
	}
	return (ptr);
}

int	push_atoi(char *s)
{
	int		i;
	long	back;
	int		np;

	back = 0;
	np = 1;
	i = 0;
	while (((s[i] <= 13 && s[i] >= 9) || s[i] == 32))
		i++;
	if ((s[i] == 43 || s[i] == 45) && (ap_control(s[i + 1])))
	{
		if (s[i] == 45)
			np *= -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		back = back * 10 + (s[i] - 48) * np;
		if (back > 2147483647)
			exit_game("Error\n");
		if (back < -2147483648)
			exit_game("Error\n");
		i++;
	}
	return ((int)back);
}

int	push_alnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!(str[i] <= 13 && str[i] >= 9) && str[i] != 32 && str[i] != 43 \
		&& str[i] != 45 && !(str[i] >= 48 && str[i] <= 57))
			exit_game("Error\n");
		if ((str[i] >= 48 && str[i] <= 57) && (!(str[i + 1] >= 48 \
		&& str[i + 1] <= 57) && !(str[i + 1] <= 13 && str[i + 1] >= 9) \
		&& str[i + 1] != 32 && str[i + 1] != 0))
			exit_game("Error\n");
		i++;
	}
	i = 0;
	while(str[i] == 32)
	{
		i++;
		if (!str[i])
			exit_game("Error\n");
	}
	return (1);
}
