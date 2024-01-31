/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quit_game_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:30:12 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/01/31 14:50:49 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_victory(t_game *game);
int	ft_quit_game(t_game *game);
int	ft_error_msg(char *message, t_game *game);

int	ft_victory(t_game *game)
{
	ft_printf(CYAN"\n			Movements: %d\n"RESET, ++game->movements);
	ft_printf(GREEN"BRAVO BRO <3\n"RESET);
	ft_free_all_game(game);
	exit (EXIT_FAILURE);
}

int	ft_quit_game(t_game *game)
{
	ft_printf(RED"RAGE QUIT\n"RESET);
	ft_printf(CYAN"Movements: %d\n"RESET, game->movements);
	ft_free_all_game(game);
	exit (EXIT_FAILURE);
}

int	ft_error_msg(char *message, t_game *game)
{
	if (game->map_alloc == true)
		ft_free_game(game);
	free(game);
	ft_printf(RED"Error\n"GREY"%s\n"RESET, message);
	exit (EXIT_FAILURE);
}

int	ft_killed(t_game *game)
{
	if (game->map_alloc == true)
		ft_free_game(game);
	free(game);
	ft_printf(RED"R.I.P\n"GREY"t'es mort en nullos\n"RESET);
	ft_printf(CYAN"Movements: %d\n"RESET, game->movements);
	exit (EXIT_FAILURE);
}
