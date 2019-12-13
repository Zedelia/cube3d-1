/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_f_convert.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: tclaudel <tclaudel@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2019/12/10 09:56:11 by tclaudel     #+#   ##    ##    #+#       */
/*   Updated: 2019/12/13 10:11:04 by tclaudel    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "cube3d.h"

static	int		ft_all_digit(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int		ft_set_color(char *token)
{
	int		color;

	color = ft_atoi(token);
	if (color < 0 || color > 255)
		ft_error("Problem with color detected");
	return (color);
}

static void		ft_tok(char **token, t_cube3d *cub, t_color *color)
{
	if (token[4])
		ft_error("too mant arguments");
	if (ft_all_digit(token[1]))
		color->rgb.r = ft_set_color(token[1]);
	else
		ft_error("not a valid nomber");
	if (ft_all_digit(token[2]))
		color->rgb.g = ft_set_color(token[2]);
	else
		ft_error("not a valid nomber");
	if (ft_all_digit(token[3]))
		color->rgb.b = ft_set_color(token[3]);
	else
		ft_error("not a valid nomber");
	cub->f = color->color;
}

void			ft_f_convert(char **token, t_cube3d *cub, t_color *color)
{
	if ((cub->f != -1))
		ft_error("can't redefine parameter");
	ft_dprintf(1, "floor color\t: ");
	if (token[1] && token[2] && token[3])
		ft_tok(token, cub, color);
	else
		ft_error("problem with args for color");
	ft_dprintf(1, "\e[48;2;%d;%d;%dm     \e[0m\t",
			color->rgb.r, color->rgb.g, color->rgb.b);
	ft_dprintf(1, "R: %d, G: %d, B: %d\n",
		color->rgb.r, color->rgb.g, color->rgb.b);
}
