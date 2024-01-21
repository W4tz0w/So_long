/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daddy_cool <daddy_cool@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 17:28:27 by daddy_cool        #+#    #+#             */
/*   Updated: 2024/01/22 00:18:49 by daddy_cool       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdlib.h>
# include "../libraries/mlx/mlx.h"
# include "../libraries/Libft/libft.h"

# define IMG_HEIGHT			32
# define IMG_WIDTH			32

# define WALL				'1'
# define FLOOR 				'0'
# define COINS  			'C'
# define PLAYER				'P'
# define MAP_EXIT 		 	'E'
# define COIN_1 		 	'9'
# define COIN_2 		 	'8'
# define COIN_3 		 	'7'
# define COIN_4 		 	'6'
# define ALL_4_COINS		"6789"

# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2

# define KEY_LEFT  			123
# define KEY_RIGHT 			124
# define KEY_DOWN  			125
# define KEY_UP  			126

# define KEY_Q				12
# define KEY_ESC			53

# define FRONT				1
# define LEFT				2
# define RIGHT				3
# define BACK				4

# define WALL_XPM			"assets/solal/wall.xpm"
# define FLOOR_XPM			"assets/solal/floor.xpm"
# define COINS_1_XPM		"assets/solal/coin_1.xpm"
# define COINS_2_XPM		"assets/solal/coin_2.xpm"
# define COINS_3_XPM		"assets/solal/coin_3.xpm"
# define COINS_4_XPM		"assets/solal/coin_4.xpm"
# define P_FRONT_XPM		"assets/solal/player/front.xpm"
# define P_LEFT_XPM			"assets/solal/player/left.xpm"
# define P_RIGHT_XPM		"assets/solal/player/right.xpm"
# define P_BACK_XPM			"assets/solal/player/back.xpm"
# define OPEN_EXIT_XPM		"assets/solal/exit-open.xpm"
# define EXIT_CLOSED_XPM	"assets/solal/exit-closed.xpm"

# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

typedef enum e_bool
{
	false = 0,
	true = 1
}	t_bool;

typedef struct s_position
{
	int	x;
	int	y;
}	t_positon;

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_map
{
	char		**full;
	int			rows;
	int			columns;
	int			coins;
	int			exit;
	int			players;
	t_positon	player;
}	t_map;

typedef struct s_game
{
	void		*mlx_ptr;
	void		*win_ptr;
	char		*buf;
	int			movements;
	int			p_sprite;
	t_map		map;
	t_bool		map_alloc;
	t_image		wall;
	t_image		floor;
	t_image		coins1;
	t_image		coins2;
	t_image		coins3;
	t_image		coins4;
	t_image		open_exit;
	t_image		exit_closed;
	t_image		p_front;
	t_image		p_left;
	t_image		p_right;
	t_image		p_back;
}	t_game;

void	ft_verif_args(int argc, char **argv, t_game *game);
void	ft_init_map(t_game *game, char *argv);
char	*ft_sl_join(char **s1, const char *s2);
void	ft_check_for_empty_line(char *map, t_game *game);
void	ft_init_vars(t_game *game);
void	ft_verif_map(t_game *game);
void	ft_verif_rows(t_game *game);
size_t	ft_strlen_line(const char *str);
void	ft_verif_columns(t_game *game);
void	ft_count_map_params(t_game *game);
void	ft_verify_map_params(t_game *game);
void	ft_convert_coins(t_game *game);
void	ft_convert_map(t_game *game, int y, int x, int i);
void	ft_init_mlx(t_game *game);
void	ft_init_sprites(t_game *game);
t_image	ft_new_sprite(void *mlx, char *path, t_game *game);
int		ft_render_game(t_game *game);
void	ft_identify_sprite(t_game *game, int x, int y);
void	ft_render_player(t_game *game, int x, int y);
void	ft_render_sprite(t_game *game, t_image sprite, int column, int line);
void	ft_print_movements(t_game *game);
int		ft_key_hook(int keysym, t_game *game);
void	ft_player_move(t_game *game, int x, int y, int p_sprite);
int		ft_victory(t_game *game);
int		ft_error_msg(char *message, t_game *game);
int		ft_quit_game(t_game *game);
void	ft_free_all_game(t_game *game);
void	ft_destroy_images(t_game *game);
void	ft_free_game(t_game *game);

#endif
