/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_mem_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:31:24 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/01/20 01:48:07 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_free_all_game(t_game *game);
void	ft_destroy_images(t_game *game);
void	ft_free_game(t_game *game);

void	ft_free_all_game(t_game *game)
{
	ft_destroy_images(game);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	ft_free_game(game);
	free(game->mlx_ptr);
	free(game);
	exit(0);
}

void	ft_destroy_images(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->wall.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->floor.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->coins1.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->coins2.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->coins3.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->coins4.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->p_front.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->p_left.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->p_right.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->p_back.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_closed.xpm_ptr);
	mlx_destroy_image(game->mlx_ptr, game->open_exit.xpm_ptr);
}

void	ft_free_game(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.rows)
		free(game->map.full[i++]);
	free(game->map.full);
}
