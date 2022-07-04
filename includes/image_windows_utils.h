/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_windows_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:49:34 by gcrocett          #+#    #+#             */
/*   Updated: 2022/07/04 14:04:12 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_WINDOWS_UTILS_H
# define IMAGE_WINDOWS_UTILS_H

# define RESX 1920
# define RESY 1080

# include "./structs.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

void            verticalStripe(t_img_data *img, int x, int drawStart, int drawEnd, int color);
t_img_data      *create_image(int size_x, int size_y, void *mlx_image);
void            create_image_windows(int size_x, int size_y, t_img_data *img_data, void *mlx_image);
void            mlx_pixel_put_fast(t_img_data *img_data, int x, int y, int color);
int		        make_color(int t, int r, int g, int b);
int             get_t(int trgb);
int	            get_r(int trgb);
int	            get_g(int trgb);
int	            get_b(int trgb);

#endif
