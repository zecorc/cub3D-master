/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iwu.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 16:52:29 by gcrocett          #+#    #+#             */
/*   Updated: 2021/03/15 16:52:37 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"
#include <stdio.h>

void    verticalStripe(t_img_data *img, int x, int drawStart, int drawEnd, int color)
{  
    while (drawStart <= drawEnd)
    {
        mlx_pixel_put_fast(img, x, drawStart, color);
        drawStart++;
    }
}

t_img_data  *create_image(int size_x, int size_y, void *mlx_image)
{
    t_img_data *img;
    if (!(img = (t_img_data*)malloc(sizeof(t_img_data))))
        return(0);
    
    mlx_image = mlx_init();
    img->image = mlx_new_image(mlx_image, size_x, size_y);
    img->address= mlx_get_data_addr(img->image, &img->bits_per_pixel, &img->line_lenght, &img->endian);
    return (img);
}

void    create_image_windows(int size_x, int size_y, t_img_data *img_data, void *mlx_image)
{
    void    *mlx_windows;
    int     x;
    int     y;

    x = size_x;
    y = size_y;
    mlx_windows = mlx_new_window(mlx_image, x, y, "TEST");
    mlx_put_image_to_window(mlx_image, mlx_windows, img_data->image, 0, 0);
    mlx_loop(mlx_image);
}

void mlx_pixel_put_fast(t_img_data *img_data, int x, int y, int color)
{
    char *destination;

    destination = img_data->address + (y * img_data->line_lenght + x * (img_data->bits_per_pixel / 8));
    *(unsigned int*)destination = color;
}

int		make_color(int t, int r, int g, int b)
{
    t = (t > 255) ? 255 : (t < 0) ? 0 : (int)t;
    r = (r > 255) ? 255 : (r < 0) ? 0 : (int)r;
    g = (g > 255) ? 255 : (g < 0) ? 0 : (int)g;
    b = (b > 255) ? 255 : (b < 0) ? 0 : (int)b;
	return(t << 24 | r << 16 | g << 8 | b);
}
/*
int		get_t(int trgb)
{
	return (trgb & (0xFF << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xFF << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xFF << 8));
}

int		get_b(int trgb)
{
	return (trgb & 0xFF);
}
*/
