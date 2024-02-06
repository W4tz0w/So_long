/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animate_enemies.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 23:58:31 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/02/04 00:07:58 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_check_space_for_enimations(t_game *game)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 1;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.full[y][x] == ENEMIES)
			{
				game->enemy[i] = ft_check_4_directions(x, y);
				i++;
			}
			x++;
		}
		y++;
	}
}
