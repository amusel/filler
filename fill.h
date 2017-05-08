/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amusel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 14:34:05 by amusel            #+#    #+#             */
/*   Updated: 2017/03/09 17:38:39 by amusel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_H
# define FILL_H

# include "libft/libft.h"
# include "libft/ft_printf.h"

struct		s_li
{
	char	*str;
	char	*piece;
	char	player;
	int		strlen;
	int		i;
};

void		pieceparse(struct s_li *temp, int flag);
int			*mapgen(struct s_li *temp, int *map);
void		recurs(struct s_li *temp, int i, int *j, int *k);
int			fu(struct s_li *temp, int i);
int			algo(struct s_li *temp, int i, int *map);
#endif
