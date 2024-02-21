/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:30:54 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/02/21 23:14:37 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_verif_args(int argc, char **argv, t_game *game);
void	ft_init_map(t_game *game, char *argv);
void	ft_check_for_empty_line(char *map, t_game *game);
void	ft_convert_coins(t_game *game);
void	ft_convert_map(t_game *game, int y, int x, int i);


void	ft_verif_args(int argc, char **argv, t_game *game)
{
	int		map_argv_len;

	game->map_alloc = false;
	if (argc > 2)
		ft_error_msg("Trop d'arguements, frr.", game);
	if (argc < 2)
		ft_error_msg("Je crois que t'as oublié la map.", game);
	map_argv_len = ft_strlen(argv[1]);
	if (!ft_strnstr(&argv[1][map_argv_len - 4], ".ber", 4))
		ft_error_msg("Pour rappel, la map doit être au format .ber", game);
	if (ft_strnstr(&argv[1][map_argv_len - 21], "parallel_universe.ber", 21))
		ft_parallel_universe(game);
	else
		ft_sprite_path(game);
}

void	ft_init_map(t_game *game, char *argv)
{
	char	*map_temp;
	char	*line_temp;
	int		map_fd;

	map_fd = open(argv, O_RDONLY);
	if (map_fd == -1 || (read(map_fd, &game->buf, 1) <= 0))
		ft_error_msg("Je refuse d'ouvrir cette map, gamin.", game);
	lseek(map_fd, 0, SEEK_SET);
	map_temp = ft_strdup("");
	game->map.rows = 0;
	while (true)
	{
		line_temp = get_next_line(map_fd);
		if (line_temp == NULL)
			break ;
		map_temp = ft_sl_join(&map_temp, line_temp);
		free(line_temp);
		game->map.rows++;
	}
	close(map_fd);
	ft_check_for_empty_line(map_temp, game);
	game->map.full = ft_split(map_temp, '\n');
	game->map_alloc = true;
	free(map_temp);
}

void	ft_check_for_empty_line(char *map, t_game *game)
{
	int	i;

	i = 0;
	if (map[0] == '\n')
	{
		free(map);
		ft_error_msg("La première ligne est vide bro.", game);
	}
	else if (map[ft_strlen(map) - 1] == '\n')
	{
		free (map);
		ft_error_msg("La carte comporte une ligne vide à la fin...BRO.", game);
	}
	while (map[i + 1])
	{
		if (map[i] == '\n' && map[i + 1] == '\n')
		{
			free(map);
			ft_error_msg("Et quelque par au milieu coule une rivière.", game);
		}
		i++;
	}
}

void	ft_convert_coins(t_game *game)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	i = 1;
	while (y < game->map.rows)
	{
		x = 0;
		while (x < game->map.columns)
		{
			if (game->map.full[y][x] == COINS)
			{
				i++;
				if (i == 5)
					i = 1;
			}
			ft_convert_map(game, y, x, i);
			x++;
		}
		y++;
	}
}

void	ft_convert_map(t_game *game, int y, int x, int i)
{
	if (game->map.full[y][x] == COINS && i == 1)
		game->map.full[y][x] = COIN_1;
	else if (game->map.full[y][x] == COINS && i == 2)
		game->map.full[y][x] = COIN_2;
	else if (game->map.full[y][x] == COINS && i == 3)
		game->map.full[y][x] = COIN_3;
	else if (game->map.full[y][x] == COINS && i == 4)
		game->map.full[y][x] = COIN_4;
	else if (game->map.full[y][x] == ENEMIES && i == 5)
		game->map.full[y][x] = ENEMY_1;
	else if (game->map.full[y][x] == ENEMIES && i == 6)
		game->map.full[y][x] = ENEMY_2;
}
