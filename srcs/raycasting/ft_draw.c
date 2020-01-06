/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_draw.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2020/01/03 14:35:55 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2020/01/06 15:53:11 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

void	ft_draw_floor(t_cub *c, int x)
{
	int	i;

	i = c->draw_end;
	while (i < c->res[1])
	{
		c->dp_data[i * c->res[0] + x] = c->f;
		i++;
	}
}

void	ft_draw_ceiling(t_cub *c, int x)
{
	int	i;

	i = 0;
	while (i < c->draw_start)
	{
		c->dp_data[i * c->res[0] + x] = c->c;
		i++;
	}
}

void	ft_draw(t_cub *c, int x)
{
	int color;
	int	i;

	i = c->draw_start;
	if (c->side_hited == 1)
		color = 255 / 2;
	else
		color = 255;
	while (i < c->draw_end)
	{
		c->dp_data[i * c->res[0] + x] = color;
		i++;
	}
	ft_draw_floor(c, x);
	ft_draw_ceiling(c, x);
}
