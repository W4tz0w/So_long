/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verif_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:29:22 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/01/17 17:29:24 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_verif_map(t_game *game);
void	ft_verif_rows(t_game *game);
void	ft_verif_columns(t_game *game);
void	ft_count_map_params(t_game *game);
void	ft_verify_map_params(t_game *game);
void	ft_convert_coins(t_game *game);

void	ft_verif_map(t_game *game)
{
	ft_verif_rows(game);
	ft_verif_columns(game);
	ft_count_map_params(game);
	ft_verify_map_params(game);
	ft_convert_coins(game);
}

void	ft_verif_rows(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
	{
		if (game->map.full[i][0] != WALL)
			ft_error_msg("Invalid Map. \
There's a Wall missing from the first row.\n\
The Map must be surrounded by walls!.", game);
		else if (game->map.full[i][game->map.columns - 1] != WALL)
		{
			ft_error_msg("Invalid Map. \
There's a Wall missing from the last row.\n\
The Map must be surrounded by walls!.", game);
		}
		i++;
	}
}

void	ft_verif_columns(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.columns)
	{
		if (game->map.full[0][i] != WALL)
			ft_error_msg("Invalid Map. \
There's a Wall missing from the first column.\n\
The Map must be surrounded by walls!.", game);
		else if (game->map.full[game->map.rows - 1][i] != WALL)
			ft_error_msg("Invalid Map. \
There's a Wall missing from the last column.\n\
The Map must be surrounded by walls!.", game);
		i++;
	}
}

void	ft_count_map_params(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (!ft_strchr("CEP01", game->map.full[y][x]))
				ft_error_msg("Invalid Map. Not expected map parameter.", game);
			else if (game->map.full[y][x] == PLAYER)
			{
				game->map.players++;
				game->map.player.x = x;
				game->map.player.y = y;
			}
			else if (game->map.full[y][x] == COINS)
				game->map.coins++;
			else if (game->map.full[y][x] == MAP_EXIT)
				game->map.exit++;
			x++;
		}
		y++;
	}
}

void	ft_verify_map_params(t_game *game)
{
	if (game->map.coins == 0)
		ft_error_msg("Bad map! You forgot the collectibles, sunshine.", game);
	else if (game->map.exit == 0)
		ft_error_msg("About the map...how do you plan to escape it?", game);
	else if (game->map.players != 1)
		ft_error_msg("The subject never required me to do a co_op!", game);
}
