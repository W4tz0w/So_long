/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_game.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:29:59 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/01/17 17:30:00 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_render_game(t_game *game);
void	ft_identify_sprite(t_game *game, int x, int y);
void	ft_render_player(t_game *game, int x, int y);
void	ft_render_sprite(t_game *game, t_image sprite, int column, int line);
void	ft_print_movements(t_game *game);

int	ft_render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			ft_identify_sprite(game, y, x);
			x++;
		}
		y++;
	}
	ft_print_movements(game);
	return (0);
}

void	ft_identify_sprite(t_game *game, int y, int x)
{
	char	parameter;

	parameter = game->map.full[y][x];
	if (parameter == WALL)
		ft_render_sprite (game, game->wall, y, x);
	else if (parameter == FLOOR)
		ft_render_sprite (game, game->floor, y, x);
	else if (parameter == COIN_1)
		ft_render_sprite (game, game->coins1, y, x);
	else if (parameter == COIN_2)
		ft_render_sprite (game, game->coins2, y, x);
	else if (parameter == COIN_3)
		ft_render_sprite (game, game->coins3, y, x);
	else if (parameter == COIN_4)
		ft_render_sprite (game, game->coins4, y, x);
	else if (parameter == MAP_EXIT)
	{
		if (game->map.coins == 0)
			ft_render_sprite (game, game->open_exit, y, x);
		else
			ft_render_sprite (game, game->exit_closed, y, x);
	}
	else if (parameter == PLAYER)
		ft_render_player (game, y, x);
}

void	ft_render_player(t_game *game, int y, int x)
{
	if (game->p_sprite == FRONT)
		ft_render_sprite (game, game->p_front, y, x);
	if (game->p_sprite == LEFT)
		ft_render_sprite (game, game->p_left, y, x);
	if (game->p_sprite == RIGHT)
		ft_render_sprite (game, game->p_right, y, x);
	if (game->p_sprite == BACK)
		ft_render_sprite (game, game->p_back, y, x);
}

void	ft_render_sprite(t_game *game, t_image sprite, int line, int column)
{
	mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
	sprite.xpm_ptr, column * sprite.x, line * sprite.y);
}

void	ft_print_movements(t_game *game)
{
	char			*movements;
	char			*str;
	static int		i;

	movements = ft_itoa(game->movements);
	str = ft_strjoin("Movements : ", movements);
	if (i == 1)
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 42, 21, 999999999, str);
		i--;
	}
	else if (i == 0)
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 42, 21, 0, str);
		i++;
	}
	free(movements);
	free(str);
}
