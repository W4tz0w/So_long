/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_hook_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:30:31 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/02/03 00:48:03 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int		ft_key_hook(int keysym, t_game *game);
void	ft_p_move(t_game *game, int x, int y, int p_sprite);

int	ft_key_hook(int keysym, t_game *game)
{
	if (keysym == KEY_UP || keysym == KEY_W)
		ft_p_move(game, game->map.player.y - 1, game->map.player.x, BACK);
	if (keysym == KEY_LEFT || keysym == KEY_A)
		ft_p_move(game, game->map.player.y, game->map.player.x - 1, LEFT);
	if (keysym == KEY_RIGHT || keysym == KEY_D)
		ft_p_move(game, game->map.player.y, game->map.player.x + 1, RIGHT);
	if (keysym == KEY_DOWN || keysym == KEY_S)
		ft_p_move(game, game->map.player.y + 1, game->map.player.x, FRONT);
	if (keysym == KEY_Q || keysym == KEY_ESC)
		ft_quit_game(game);
	return (0);
}

void	ft_p_move(t_game *game, int new_y, int new_x, int p_sprite)
{
	int	last_x;
	int	last_y;

	game->p_sprite = p_sprite;
	last_x = game->map.player.x;
	last_y = game->map.player.y;
	if (game->map.full[new_y][new_x] == MAP_EXIT && game->map.coins == 0)
		ft_victory(game);
	else if ((game->map.full[new_y][new_x] == FLOOR)
	|| (ft_strchr(ALL_4_COINS, game->map.full[new_y][new_x]) != 0))
	{
		game->map.full[last_y][last_x] = FLOOR;
		if (ft_strchr(ALL_4_COINS, game->map.full[new_y][new_x]) != 0)
			game->map.coins--;
		game->map.player.x = new_x;
		game->map.player.y = new_y;
		game->map.full[new_y][new_x] = PLAYER;
		game->movements++;
		ft_render_game(game);
	}
	else if ((game->map.full[new_y][new_x] == ENEMY_1)
	|| (game->map.full[new_y][new_x] == ENEMY_2))
		ft_killed(game);
}
