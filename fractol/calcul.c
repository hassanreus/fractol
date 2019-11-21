/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:36:00 by hseffian          #+#    #+#             */
/*   Updated: 2019/11/20 21:36:02 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	madelbrot_cl(t_fractol *fractol, int i, int j)
{
	fractol->c_r = i/ fractol->zoom + fractol->x;
	fractol->c_i = j / fractol->zoom + fractol->y;
	fractol->z_r = 0;
	fractol->z_i = 0;
	fractol->it = 0;
	while (fractol->z_r * fractol->z_r + fractol->z_i *
			fractol->z_i < 4 && fractol->it < fractol->it_max)
	{
		fractol->perv = fractol->z_r;
		fractol->z_r = fractol->z_r * fractol->z_r -
			fractol->z_i * fractol->z_i + fractol->c_r;
		fractol->z_i = 2 * fractol->z_i * fractol->perv + fractol->c_i;
		fractol->it++;
	}
	if (fractol->it == fractol->it_max)
		put_pixel(fractol, i, j, 0x000000);
	else
		put_pixel(fractol, i, j, (fractol->color * fractol->it));
}

void	julia_cl(t_fractol *fractol, int i, int j)
{
	fractol->z_r = i/ fractol->zoom + fractol->x;
	fractol->z_i = j/ fractol->zoom + fractol->y;
	fractol->it = 0;
	while (fractol->z_r * fractol->z_r + fractol->z_i *
			fractol->z_i < 4 && fractol->it < fractol->it_max)
	{
		fractol->perv = fractol->z_r;
		fractol->z_r = fractol->z_r * fractol->z_r -
			fractol->z_i * fractol->z_i + fractol->c_r;
		fractol->z_i = 2 * fractol->z_i * fractol->perv + fractol->c_i;
		fractol->it++;
	}
	if (fractol->it == fractol->it_max)
		put_pixel(fractol, i, j, 0x000000);
	else
		put_pixel(fractol, i, j, (fractol->color * fractol->it));
}

int		julia_new(int x, int y ,t_fractol *fractol)
{
	if (fractol->mouse == 1)
	{
		fractol->c_r = x / fractol->zoom;
		fractol->c_i = y / fractol->zoom;
		draw(fractol);
	}
	return (0);
}

void	br(t_fractol *fractol, int i, int j)
{
	fractol->c_r = i/ fractol->zoom + fractol->x;
	fractol->c_i = j / fractol->zoom + fractol->y;
	fractol->z_r = 0;
	fractol->z_i = 0;
	fractol->it = 0;
	while (fractol->z_r * fractol->z_r + fractol->z_i *
			fractol->z_i < 4 && fractol->it < fractol->it_max)
	{
		fractol->perv = fractol->z_r;
		fractol->z_r = fractol->z_r * fractol->z_r -
			fractol->z_i * fractol->z_i + fractol->c_r;
		fractol->z_i = 2 * __ABS(fractol->z_i * fractol->perv) + fractol->c_i;
		fractol->it++;
	}
	if (fractol->it == fractol->it_max)
		put_pixel(fractol, i, j, 0x000000);
	else
		put_pixel(fractol, i, j, (fractol->color * fractol->it));
}

void	new_o(t_fractol *fractol, int i, int j)
{
	fractol->c_r = i/ fractol->zoom + fractol->x;
	fractol->c_i = j / fractol->zoom + fractol->y;
	fractol->z_r = 0;
	fractol->z_i = 0;
	fractol->it = 0;
	while (fractol->z_r * fractol->z_r + fractol->z_i *
			fractol->z_i < 4 && fractol->it < fractol->it_max)
	{
		fractol->perv = fractol->z_r;
		fractol->z_r = fractol->z_r * fractol->z_r -
			fractol->z_i * fractol->z_i + fractol->c_r;
		fractol->z_i = fractol->z_i * fractol->perv + fractol->c_i;
		fractol->it++;
	}
	if (fractol->it == fractol->it_max)
		put_pixel(fractol, i, j, 0x000000);
	else
		put_pixel(fractol, i, j, (fractol->color * fractol->it));
}