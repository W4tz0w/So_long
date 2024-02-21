/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:35:56 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/02/21 22:51:47 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_render_coins(t_game *game, int y, int x, char prm);
void	ft_render_enemies(t_game *game, int line, int column);
int		ft_player_proximity_0(t_game *game, int y, int x);
int		ft_player_proximity_1(t_game *game, int y, int x);

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

void	ft_render_enemies(t_game *game, int line, int column)
{
	int	y;
	int	x;

	y = line;
	x = column;
	if (ft_player_proximity_0(game, y, x) == 1)
		ft_render_sprite(game, game->enemy1_1, y, x);
	else if (ft_player_proximity_1(game, y, x) == 1)
		ft_render_sprite(game, game->enemy1_2, y, x);
	else
		ft_render_sprite(game, game->enemy2_1, y, x);
}

int	ft_player_proximity_0(t_game *game, int y, int x)
{
	if (game->map.full[y][x + 1] == PLAYER)
		return (1);
	else if (game->map.full[y][x - 1] == PLAYER)
		return (1);
	else if (game->map.full[y + 1][x] == PLAYER)
		return (1);
	else if (game->map.full[y - 1][x] == PLAYER)
		return (1);
	else
		return (0);
}

int	ft_player_proximity_1(t_game *game, int y, int x)
{
	if (game->map.full[y + 1][x + 1] == PLAYER)
		return (1);
	else if (game->map.full[y - 1][x + 1] == PLAYER)
		return (1);
	else if (game->map.full[y - 1][x - 1] == PLAYER)
		return (1);
	else if (game->map.full[y + 1][x - 1] == PLAYER)
		return (1);
	else
		return (0);
}
