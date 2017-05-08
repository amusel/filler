/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcnt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:21:15 by amusel            #+#    #+#             */
/*   Updated: 2016/12/07 16:23:10 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcnt(char *str)
{
	int i;
	int j;

	i = -1;
	while (str[++i])
		if (str[i] == '\n')
			j++;
	return (j);
}