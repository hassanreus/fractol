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
	char *data;
	int img_win;
	unsigned int color_value;
	int det_image;
	int is_fract;
	int bits_per_pixel;
	int size_line;
	int endian;
}				t_fractol;

#endif
