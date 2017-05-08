/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:33:56 by amusel            #+#    #+#             */
/*   Updated: 2017/03/09 17:41:09 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

void	pieceparse(struct s_li *temp, int flag)
{
	int		i;
	char	*str;

	i = 0;
	temp->piece = ft_strnew(100);
	ft_strclr(temp->piece);
	while (--flag != -1)
	{
		get_next_line(0, &str);
		str = ft_strjoin(str, "\n");
		temp->piece = ft_strjoin(temp->piece, str);
	}
	while (temp->piece[i] != '\0')
		i++;
	temp->piece[i - 1] = '\0';
	i = -1;
	while (temp->str[++i])
		if (temp->str[i] == 'P' && temp->str[i + 1] == 'i')
			while (temp->str[i])
				temp->str[i++] = '\0';
}

int		*upndown(int k, struct s_li *temp, int i, int *map)
{
	int c;
	int j;

	j = k;
	while (j > -1)
	{
		c = k + 1;
		while (--c > 0)
		{
			if (map[i + (c * temp->strlen) + j] > k)
				map[i + (c * temp->strlen) + j] = k;
			if (map[i + (c * temp->strlen) - j] > k)
				map[i + (c * temp->strlen) - j] = k;
		}
		j--;
	}
	return (map);
}

int		*mapgen(struct s_li *temp, int *map)
{
	int		i;
	int		k;
	char	mark;

	if (temp->player == 'O')
		mark = 'X';
	else
		mark = 'O';
	i = -1;
	while (temp->str[++i] != '\0')
		if (temp->str[i] == mark)
		{
			k = 0;
			while (++k != temp->strlen - 4)
			{
				if (map[i + k] > k)
					map[i + k] = k;
				if (map[i - k] > k)
					map[i - k] = k;
				map = upndown(k, temp, i, map);
			}
		}
	return (map);
}

int		*recup(int *a, int *b, int *i, int *map)
{
	int v;

	v = -1;
	*a = -100;
	*b = -100;
	(*i)--;
	map = (int *)malloc(sizeof(map) * 10002);
	while (++v < 10000)
		map[v] = 1000;
	return (map);
}

void	recurs(struct s_li *temp, int i, int *j, int *k)
{
	int a;
	int b;
	int h;
	int *map;

	map = recup(&a, &b, &i, NULL);
	map = mapgen(temp, map);
	while (temp->str[++i])
	{
		i += 3;
		*k = -1;
		while (temp->str[++i] != '\n')
		{
			if (fu(temp, i) == 1 && (h = algo(temp, i, map)) < temp->i)
			{
				temp->i = h;
				a = (*k);
				b = (*j);
			}
			(*k)++;
		}
		(*j)++;
	}
	(*k) = a;
	(*j) = b;
}
