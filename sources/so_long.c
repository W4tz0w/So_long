/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:28:36 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/01/20 17:48:14 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char	**argv)
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	ft_verif_args(argc, argv, game);
	ft_init_map(game, argv[1]);
	ft_init_vars(game);
	ft_verif_map(game);
	ft_init_mlx(game);
	ft_init_sprites(game);
	ft_render_game(game);
	mlx_hook(game->win_ptr, 2, 0, ft_key_hook, game);
	mlx_hook(game->win_ptr, 17, 0, ft_quit_game, game);
	mlx_hook(game->win_ptr, 12, 0, ft_render_game, game);
	mlx_loop(game->mlx_ptr);
	ft_free_all_game(game);
}

/* Add 	system("leaks -atExit -- ./so_long"); on macOS too check for leaks */
/* Or just 	system("leaks ./so_long") on Linux */
