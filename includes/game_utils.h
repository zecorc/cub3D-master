/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 16:53:34 by gcrocett          #+#    #+#             */
/*   Updated: 2021/04/13 16:53:36 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_UTILS_H
# define GAME_UTILS_H

# include "./get_next_line.h"
# include "./parse.h"
# include "../includes/image_windows_utils.h"
# include "./structs.h"
# include "./atoi.h"

t_cam   *create_cam(t_vec2 init_pos, t_vec2 direction, t_vec2 cam_plane);
t_vec2  *create_vec2(double x, double y);

#endif
