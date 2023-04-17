/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:58:39 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/17 12:17:31 by bkiziler         ###   ########.fr       */
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

char	**protect(void)
{
	char	**rtn;

	rtn = ft_calloc(1, sizeof(char *));
	rtn[0] = NULL;
	return (rtn);
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
		return (protect());
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
	if (s[i] == 43 || s[i] == 45)
	{
		if (s[i] == 45 && apControl(s[i + 1]))
			np *= -1;
		i++;
	}
	while (s[i] >= 48 && s[i] <= 57)
	{
		back = back * 10 + (s[i] - 48) * np;
		if (back > 2147483647)
			exit_game("The number exceeds the integer limit.");
		if (back < -2147483648)
			exit_game("The number exceeds the integer limit.");
		i++;
	}
	return ((int)back);
}

int	push_alnum(char *str)
{
	while (*str)
	{
		if (!(*str <= 13 && *str >= 9) && *str != 32 && *str != 43 \
		&& *str != 45 && !(*str >= 48 && *str <= 57))
			exit_game("Invalid string");
		str++;
	}
	return (1);
}

// iki eksi geldiğinde atoi 0 döndürüyor sıkıntılı muhtemlen hallet
