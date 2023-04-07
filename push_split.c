/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bkiziler <bkiziler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 17:58:39 by bkiziler          #+#    #+#             */
/*   Updated: 2023/04/07 18:59:57 by bkiziler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

static int	countc(char const *a, char b)
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

static char	**protect(void)
{
	char	**rtn;

	rtn = ft_calloc(1, sizeof(char *));
	rtn[0] = NULL;
	return (rtn);
}

char	**push_split(char const *s, char c, int *count)
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
