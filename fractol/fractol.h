/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hseffian <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/31 12:02:20 by hseffian          #+#    #+#             */
/*   Updated: 2019/11/20 00:37:50 by hseffian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <fcntl.h>
# include "mlx.h"
# include "./get_next_line/get_next_line.h"
# include <math.h>

typedef struct	s_fractol
{
	void *ptr;
	void *win;
	void *image;
	int *data;
	int img_win;
	int is_fract;
	int bits_per_pixel;
	int size_line;
	int endian;
	double z_r;
	double z_i;
	double c_r;
	double c_i;
	int it;
	int it_max;
	int color;
	double x;
	double y;
	double perv;
	double zoom;
}				t_fractol;

#endif
