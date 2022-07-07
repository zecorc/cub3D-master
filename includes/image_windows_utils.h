/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_windows_utils.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:49:34 by gcrocett          #+#    #+#             */
/*   Updated: 2022/07/07 20:03:17 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_WINDOWS_UTILS_H
# define IMAGE_WINDOWS_UTILS_H

# define RESX 1920
# define RESY 1080
# define MSPD 0.1
# define RSPD 0.1

# include "./structs.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

void            verticalStripe(t_img_data *img, int x, int drawStart, int drawEnd, int color);
t_img_data      *create_image(int size_x, int size_y, void *mlx_image);
//void            create_image_windows(void   *mlx_windows, t_img_data *img_data, void *mlx_image);
int             render_next_frame(t_alls *sts);
void            mlx_pixel_put_fast(t_img_data *img_data, int x, int y, int color);
int		        make_color(int t, int r, int g, int b);
int             get_t(int trgb);
int	            get_r(int trgb);
int	            get_g(int trgb);
int	            get_b(int trgb);
void            on_w(t_alls *sts);
void            on_s(t_alls *sts);
void            on_a(t_alls *sts);
void            on_d(t_alls *sts);
void            on_left(t_alls *sts);
void            on_right(t_alls *sts);

#endif
