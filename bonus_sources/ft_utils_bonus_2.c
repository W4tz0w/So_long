/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 15:35:56 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/02/06 01:02:18 by daddy_cool       ###   ########.fr       */
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

void	ft_animation(void *param)
{
	t_game		*game;
	static int	count;
	static int	flag;

	game = param;
	++count;
	if (count > ANIMATION_SPEED)
	{
		if (flag == 0)
		{
			// game->xpm.enemy1_1_xpm = "assets/solal/enemy1_2.xpm";
			flag = animate_enemies(game, flag);
		}
		else if (flag == 1)
		{
			// game->xpm.enemy1_1_xpm = "assets/solal/enemy1_1.xpm";
			flag = animate_enemies(game, flag);
		}
		count = 1;
	}
}

int	animate_enemies(t_game *game, int flag)
{
	game->flag = flag;
	ft_render_game(game);
	if (flag == 0)
		return (1);
	if (flag == 1)
		return (0);
	return (1);
}

void	ft_render_enemies(t_game *game, int enemy_type, int line, int column)
{
	int t;
	int y;
	int x;
	
	y = line;
	x = column;
	t = enemy_type;
	if (game->flag == 0)
	{
		if (game->map.full[y][x + 1] == FLOOR)
			mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->enemy2_1.xpm_ptr, column * game->enemy1_1.x, line * game->enemy1_1.y);
		else if (game->map.full[y][x - 1] == FLOOR)
		{
			mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->enemy2_1.xpm_ptr, (column - 1) * game->enemy1_1.x, line * game->enemy1_1.y);
			mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->floor.xpm_ptr, column * game->floor.x, line * game->floor.y);
		}
		else
			mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->enemy1_1.xpm_ptr, column * game->enemy2_1.x, line * game->enemy2_1.y);
	}
	else if (game->flag == 1)
	{
		if (game->map.full[y][x + 1] == FLOOR)
		{
			mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->floor.xpm_ptr, column * game->floor.x, line * game->floor.y);
			mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->enemy2_2.xpm_ptr, (column + 1) * game->enemy1_2.x, line * game->enemy1_2.y);
		}
		else if (game->map.full[y][x - 1] == FLOOR)
			mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->enemy2_2.xpm_ptr, column * game->enemy1_2.x, line * game->enemy1_2.y);
		else
			mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
			game->enemy1_2.xpm_ptr, column * game->enemy2_2.x, line * game->enemy2_2.y);
	}
	t++;
}
	



	
// 	if (game->flag == 0 && t == 1 && game->map.full[y][x + 1] == FLOOR)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy1_1.xpm_ptr, (column + 1) * game->enemy1_1.x, line * game->enemy1_1.y);
// 	else if (game->flag == 0 && t == 2 && game->map.full[y][x + 1] == FLOOR)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy2_1.xpm_ptr, (column + 1) * game->enemy2_1.x, line * game->enemy2_1.y);
// 	else if (game->flag == 1 && t == 1 && game->map.full[y][x + 1] == FLOOR)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy1_2.xpm_ptr, column * game->enemy1_2.x, line * game->enemy1_2.y);
// 	else if (game->flag == 1 && t == 2 && game->map.full[y][x + 1] == FLOOR)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy2_2.xpm_ptr, column * game->enemy2_2.x, line * game->enemy2_2.y);
// 	else if (game->flag == 0 && t == 1)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy1_1.xpm_ptr, column * game->enemy1_1.x, line * game->enemy1_1.y);
// 	else if (game->flag == 0 && t == 2)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy2_1.xpm_ptr, column * game->enemy2_1.x, line * game->enemy2_1.y);
// 	else if (game->flag == 1 && t == 1)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy1_2.xpm_ptr, column * game->enemy1_2.x, line * game->enemy1_2.y);
// 	else if (game->flag == 1 && t == 2)
// 		mlx_put_image_to_window (game->mlx_ptr, game->win_ptr, \
// 		game->enemy2_2.xpm_ptr, column * game->enemy2_2.x, line * game->enemy2_2.y);
// }

// void	ft_animation(void *param)
// {
// 	t_game		*game;
// 	static int	count;
// 	static int	flag;
// 	void		*mlx;

// 	mlx = game->mlx_ptr;
// 	game = param;
// 	++count;
// 	if (count > ANIMATION_SPEED)
// 	{
// 		if (flag == 0)
// 		{
// 			game->xpm.enemy1_1_xpm = "assets/solal/enemy1_2.xpm";
// 			flag = animate_enemies(game, flag, game->xpm.enemy1_1_xpm);
// 		}
// 		else if (flag == 1)
// 		{
// 			game->xpm.enemy1_1_xpm = "assets/solal/enemy1_2.xpm";
// 			flag = animate_enemies(game, flag, game->xpm.enemy1_1_xpm);
// 		}
// 		count = 1;
// 	}
// }

// int	animate_enemies(t_game *game, int flag, char *path)
// {
// 	mlx_delete_image(game->mlx, game->img.strong[i].image);
// 	place_png_to_img(game, &game->img.strong[i].image, path);
// 	mlx_image_to_window(game->mlx, game->img.strong[i].image, \
// 		strong_x * IMG_WIDTH, strong_y * IMG_HEIGHT);
// 	i++;
// 	if (i == game->map.strongs && flag == 0)
// 		return (1);
// 	if ((i == game->map.strongs && flag == 1) || flag == 0)
// 		return (0);
// 	return (1);
// }
