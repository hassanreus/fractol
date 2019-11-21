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
# define __ABS(x) (x > 0 ? x : -x)
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
	int mouse;
	int all;
	void	(*type_fract)(struct s_fractol *, int, int);
}				t_fractol;

void		control(t_fractol *fractol);
void		control_v1(t_fractol *fractol);
void        free_by(t_fractol *fractol);
void		draw(t_fractol *fractol);
void        init(t_fractol *fractol, char *av);
void		put_pixel(t_fractol *fractol, int x, int y, int color);
void		madelbrot_cl(t_fractol *fractol, int i, int j);
void		julia_cl(t_fractol *fractol, int i, int j);
int			julia_new(int x, int y ,t_fractol *fractol);
int			get_color(int all);
void	br(t_fractol *fractol, int i, int j);
void	new_o(t_fractol *fractol, int i, int j);

#endif
