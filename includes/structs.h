/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 18:55:41 by gcrocett          #+#    #+#             */
/*   Updated: 2021/04/21 18:55:44 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct  s_vec2
{
    double  x;
    double  y;
}               t_vec2;  

typedef struct  s_vec2int
{
    int     x;
    int     y;
}               t_vec2int;  


typedef struct  s_cam
{
    t_vec2  eyepos;
    t_vec2  direction;
    t_vec2  camscreen;
}               t_cam;

typedef struct  s_img_data
{
    void    *image;
    char    *address;
    int     bits_per_pixel;
    int     line_lenght;
    int     endian;
}               t_img_data;

typedef struct  s_color_trgb
{
    int     t;
    int     r;
    int     g;
    int     b;
}               t_color_trgb;

typedef struct  s_path
{
    char    *n_path;
    char    *s_path;
    char    *w_path;
    char    *e_path;
    char    *sprite_path;
    char    *map_path;
}               t_path;

typedef struct  s_alls
{
    t_cam           *camera;
    t_img_data      *image_data;
    t_color_trgb    floor_color;
    t_color_trgb    ceiling_color;
    t_vec2int       resolution;
    t_path          paths;
    int             fov;
    char            **map;

}               t_alls;

#endif