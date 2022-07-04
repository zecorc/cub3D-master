/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gam3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:57:39 by gcrocett          #+#    #+#             */
/*   Updated: 2021/04/13 16:57:46 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

t_vec2  *create_vec2(double x, double y)
{
    t_vec2  *vec2;

    vec2 = malloc(sizeof(t_vec2));
    if(vec2 == 0)
        return(0);
    vec2->x = x;
    vec2->y = y;
    return (vec2);
}

t_cam   *create_cam(t_vec2 init_pos, t_vec2 direction, t_vec2 cam_plane)
{
    t_cam   *camera;

    camera = malloc(sizeof(t_cam));
    if (camera == 0)
        return (0);
    camera->eyepos.x = init_pos.x;
    camera->eyepos.y = init_pos.y;
    camera->direction.x = direction.x;
    camera->direction.y = direction.y;
    camera->camscreen.x = cam_plane.x;
    camera->camscreen.y = cam_plane.y;
    return (camera);
} 


