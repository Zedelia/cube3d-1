/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_cub.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/02 12:33:03 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/23 09:04:19 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void		ft_display_map(t_cub *c)
{
	size_t	i;

	i = 0;
	c->mapcp[(int)c->pos.x][(int)c->pos.y] = '#';
	ft_printf("\nMAP :\n\n");
	while (i < c->map_height)
	{
		ft_printf("%s\n", c->mapcp[i]);
		i++;
	}
	i = 0;
	while (i < c->map_height)
		free(c->mapcp[i++]);
	free(c->mapcp);
}

int			main_loop(t_cub *c)
{
	if (c->victory)
		ft_draw_victory(c);
	if (c->life == 0)
		ft_draw_death(c, 0);
	if (c->collect == c->max_collect)
		ft_next_level(c);
	if (c->rot && c->life && !c->victory)
		ft_rot(c);
	if (c->move && c->life && !c->victory)
		ft_move(c);
	if (c->move_ad && c->life && !c->victory)
		ft_move_ad(c);
	if (c->life && !c->victory)
		ft_raycast(c);
	mlx_put_image_to_window(c->mlx_ptr, c->mlx_win, c->screen.img, 0, 0);
	return (0);
}

void		ft_copy_tab(t_cub *c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	c->mapcp = (char **)malloc(sizeof(char *) * c->map_height);
	while (i < c->map_height)
	{
		j = 0;
		c->mapcp[i] = (char *)malloc(sizeof(char) * c->map_width + 1);
		while (j < c->map_width)
		{
			c->mapcp[i][j] = c->tabmap[i][j];
			j++;
		}
		c->mapcp[i][c->map_width] = 0;
		i++;
	}
}

int			ft_cub(t_cub *c)
{
	if ((c->mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	init_player(c);
	ft_launch_window(c);
	if (c->flag == 's')
	{
		ft_raycast(c);
		ft_save_bitmap("screenshot.bmp", c);
	}
	mlx_hook(c->mlx_win, 2, 0, &ft_key_press, c);
	mlx_hook(c->mlx_win, 3, 0, &ft_key_release, c);
	mlx_hook(c->mlx_win, 17, 0, &ft_close, c);
	mlx_loop_hook(c->mlx_ptr, &main_loop, c);
	mlx_loop(c->mlx_ptr);
	return (1);
}
