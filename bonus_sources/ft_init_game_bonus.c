/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:31:09 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/02/05 16:10:06 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_vars(t_game *game);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
t_image	ft_new_sprite(void *mlx, char *path, t_game *game);

void	ft_init_vars(t_game *game)
{
	game->map.coins = 0;
	game->map.exit = 0;
	game->map.enemies = 0;
	game->map.players = 0;
	game->movements = 0;
	game->map.columns = ft_strlen(game->map.full[0]);
	game->p_sprite = FRONT;
}

void	ft_init_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("La création du pointeur \
		'mlx_init' n'a pas marché!", game);
	}
	game->win_ptr = mlx_new_window(game->mlx_ptr, \
	game->map.columns * IMG_WIDTH, game->map.rows * IMG_HEIGHT, "so_long");
	if (game->win_ptr == NULL)
	{
		free(game->mlx_ptr);
		ft_error_msg("La fenêtre s'est échouée. Comme un bateau.", game);
	}
}

void	ft_init_sprites(t_game *game)
{
	void	*mlx;

	mlx = game->mlx_ptr;
	game->wall = ft_new_sprite(mlx, game->xpm.wall_xpm, game);
	game->floor = ft_new_sprite(mlx, game->xpm.floor_xpm, game);
	game->coins1 = ft_new_sprite(mlx, game->xpm.coins1_xpm, game);
	game->coins2 = ft_new_sprite(mlx, game->xpm.coins2_xpm, game);
	game->coins3 = ft_new_sprite(mlx, game->xpm.coins3_xpm, game);
	game->coins4 = ft_new_sprite(mlx, game->xpm.coins4_xpm, game);
	game->p_front = ft_new_sprite(mlx, game->xpm.front_xpm, game);
	game->p_left = ft_new_sprite(mlx, game->xpm.left_xpm, game);
	game->p_right = ft_new_sprite(mlx, game->xpm.right_xpm, game);
	game->p_back = ft_new_sprite(mlx, game->xpm.back_xpm, game);
	game->enemy1_1 = ft_new_sprite(mlx, game->xpm.enemy1_1_xpm, game);
	game->enemy1_2 = ft_new_sprite(mlx, game->xpm.enemy1_2_xpm, game);
	game->enemy2_1 = ft_new_sprite(mlx, game->xpm.enemy2_1_xpm, game);
	game->enemy2_2 = ft_new_sprite(mlx, game->xpm.enemy2_2_xpm, game);
	game->open_exit = ft_new_sprite(mlx, game->xpm.exit_open_xpm, game);
	game->exit_closed = ft_new_sprite(mlx, game->xpm.exit_closed_xpm, game);
}

t_image	ft_new_sprite(void *mlx, char *path, t_game *game)
{
	t_image	sprite;

	sprite.xpm_ptr = mlx_xpm_file_to_image(mlx, path, &sprite.x, &sprite.y);
	if (sprite.xpm_ptr == NULL)
		ft_error_msg("Le sprite n'existe pas. Le coca non plus.", game);
	return (sprite);
}
