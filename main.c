/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:33:49 by amusel            #+#    #+#             */
/*   Updated: 2017/03/09 14:33:50 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill.h"

void	rrdd(struct s_li *temp, int i, int k)
{
	char	*at;
	char	*str;
	int		flag;

	flag = -1;
	at = (char *)malloc(sizeof(at) * 10);
	while (get_next_line(0, &str))
	{
		str = ft_strjoin(str, "\n");
		temp->str = ft_strjoin(temp->str, str);
		if (ft_strstr(str, "001 "))
			temp->strlen = (int)ft_strlen(str);
		if (ft_strstr(str, "Piece") && flag < 0)
		{
			while (str[++i] && !(str[i] != ' ' && k > -1))
				while (str[i] > 47 && str[i] < 58)
					at[++k] = str[i++];
			flag = ft_atoi(at);
			break ;
		}
	}
	pieceparse(temp, flag);
	if (ft_strstr(temp->str, "$$$ exec p2 : [./filler]"))
		temp->player = 'X';
}

int		algo(struct s_li *temp, int i, int *map)
{
	int		v;
	int		res;
	int		plen;

	res = 0;
	v = -1;
	plen = ft_strclen(temp->piece, '\n') + 1;
	while (temp->piece[++v] != '\0')
	{
		if (temp->piece[v] == '\n')
		{
			i += temp->strlen;
			v++;
		}
		if (temp->piece[v] == '*')
			res += map[i + (v % plen)];
	}
	return (res);
}

int		fu(struct s_li *temp, int i)
{
	int j;
	int flag;
	int plen;

	flag = -1;
	j = -1;
	plen = ft_strclen(temp->piece, '\n') + 1;
	while (temp->piece[++j] != '\0' && flag < 1)
	{
		if (temp->piece[j] == '\n')
		{
			i += temp->strlen;
			j++;
		}
		if (temp->piece[j] == '*' && temp->str[i + (j % plen)] == temp->player)
			flag++;
		else if (temp->piece[j] == '*' && temp->str[i + (j % plen)] != '.')
			flag += 10;
		if (temp->str[i + (j % (plen))] != '.' && \
			temp->str[i + (j % (plen))] != 'O' && \
			temp->str[i + (j % (plen))] != 'X')
			flag += 10;
	}
	return (flag == 0 ? 1 : 0);
}

int		out(struct s_li *temp, int i, int k)
{
	int		j;
	char	*str;

	str = temp->str;
	j = -1;
	while (str[++i] && k != 1000)
		if (str[i] == '0' && str[i + 1] == '0' && str[i + 2] == '0')
			k = 1000;
	recurs(temp, --i, &j, &k);
	if (j == -100 || k == -100)
	{
		write(1, "0 0\n", 4);
		return (0);
	}
	j++;
	ft_putnbr(j);
	write(1, " ", 1);
	k++;
	ft_putnbr(k);
	write(1, "\n", 1);
	return (1);
}

int		main(void)
{
	int			i;
	int			k;
	struct s_li	*temp;

	temp = (struct s_li *)malloc(sizeof(temp) * 300);
	temp->player = 'O';
	while (1)
	{
		i = -1;
		k = -1;
		temp->i = 10000000;
		temp->str = ft_strnew(100);
		ft_strclr(temp->str);
		rrdd(temp, i, k);
		i = -1;
		while (temp->str[++i])
			if (temp->str[i] == temp->player - 32)
				temp->str[i] = temp->player;
		i = -1;
		if (out(temp, i, k) == 0)
			break ;
	}
	get_next_line(-1, NULL);
	return (0);
}
