/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_coins_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:35:56 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/01/31 16:36:24 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_render_coins(t_game *game, int y, int x, char prm)
{
	if (prm == COIN_1)
		ft_render_sprite (game, game->coins1, y, x);
	else if (prm == COIN_2)
		ft_render_sprite (game, game->coins2, y, x);
	else if (prm == COIN_3)
		ft_render_sprite (game, game->coins3, y, x);
	else if (prm == COIN_4)
		ft_render_sprite (game, game->coins4, y, x);
}

void	ft_convert_enemies(t_game *game)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 4;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.full[y][x] == ENEMIES)
			{
				i++;
				if (i == 7)
					i = 5;
			}
			ft_convert_map(game, y, x, i);
			x++;
		}
		y++;
	}
}
