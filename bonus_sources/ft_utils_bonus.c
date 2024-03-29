/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:29:38 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/02/21 23:14:59 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

char	*ft_sl_join(char **s1, const char *s2);
void	ft_parallel_universe(t_game *game);
void	ft_sprite_path(t_game *game);

void	ft_sprite_path(t_game *game)
{
	game->xpm.wall_xpm = "assets/solal/wall.xpm";
	game->xpm.floor_xpm = "assets/solal/floor.xpm";
	game->xpm.coins1_xpm = "assets/solal/coin_1.xpm";
	game->xpm.coins2_xpm = "assets/solal/coin_2.xpm";
	game->xpm.coins3_xpm = "assets/solal/coin_3.xpm";
	game->xpm.coins4_xpm = "assets/solal/coin_4.xpm";
	game->xpm.front_xpm = "assets/solal/player/front.xpm";
	game->xpm.right_xpm = "assets/solal/player/right.xpm";
	game->xpm.left_xpm = "assets/solal/player/left.xpm";
	game->xpm.back_xpm = "assets/solal/player/back.xpm";
	game->xpm.enemy1_1_xpm = "assets/solal/enemy1_1.xpm";
	game->xpm.enemy2_1_xpm = "assets/solal/enemy2_1.xpm";
	game->xpm.enemy1_2_xpm = "assets/solal/enemy1_2.xpm";
	game->xpm.enemy2_2_xpm = "assets/solal/enemy2_2.xpm";
	game->xpm.exit_open_xpm = "assets/solal/exit-open.xpm";
	game->xpm.exit_closed_xpm = "assets/solal/exit-closed.xpm";
}

void	ft_parallel_universe(t_game *game)
{
	game->xpm.wall_xpm = "assets/solal/player/front.xpm";
	game->xpm.floor_xpm = "assets/solal/coin_1.xpm";
	game->xpm.coins1_xpm = "assets/solal/coin_2.xpm";
	game->xpm.coins2_xpm = "assets/solal/coin_3.xpm";
	game->xpm.coins3_xpm = "assets/solal/floor.xpm";
	game->xpm.coins4_xpm = "assets/solal/player/left.xpm";
	game->xpm.front_xpm = "assets/solal/coin_4.xpm";
	game->xpm.right_xpm = "assets/solal/player/back.xpm";
	game->xpm.left_xpm = "assets/solal/exit-closed.xpm";
	game->xpm.back_xpm = "assets/solal/wall.xpm";
	game->xpm.enemy1_1_xpm = "assets/solal/enemy1_1.xpm";
	game->xpm.enemy1_2_xpm = "assets/solal/enemy1_2.xpm";
	game->xpm.enemy2_1_xpm = "assets/solal/enemy2_1.xpm";
	game->xpm.enemy2_2_xpm = "assets/solal/enemy2_2.xpm";
	game->xpm.exit_open_xpm = "assets/solal/exit-open.xpm";
	game->xpm.exit_closed_xpm = "assets/solal/player/right.xpm";
}

char	*ft_sl_join(char **s1, const char *s2)
{
	char	*str;

	if (!*s1 || !s2)
		return (NULL);
	str = (char *)ft_calloc((ft_strlen(*s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, *s1, ft_strlen(*s1) + 1);
	ft_strlcat(str, s2, ft_strlen(*s1) + ft_strlen(s2) + 1);
	free(*s1);
	return (str);
}
