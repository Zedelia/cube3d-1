/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_set_sprites.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/09 18:27:13 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/10 11:54:35 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static void		ft_fill_sprites(t_cub *c)
{
	size_t	i;
	size_t	j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (i < c->map_height)
	{
		j = 0;
		while (j < c->map_width)
		{
			if (c->tabmap[i][j] == '2')
			{
				c->sprites[k].pos.x = i + 0.5;
				c->sprites[k].pos.y = j + 0.5;
				c->tabmap[i][j] = 'x';
				k++;
			}
			j++;
		}
		i++;
	}
}

void			ft_set_sprites(t_cub *c)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	c->nb_sprites = 0;
	while (i < c->map_height)
	{
		j = 0;
		while (j < c->map_width)
		{
			if (c->tabmap[i][j] == '2')
				c->nb_sprites++;
			j++;
		}
		i++;
	}
	c->sprites = (t_sprite *)malloc(sizeof(t_sprite) * c->nb_sprites);
	ft_fill_sprites(c);
}
