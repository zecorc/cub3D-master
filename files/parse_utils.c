/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:12:04 by gcrocett          #+#    #+#             */
/*   Updated: 2021/04/24 13:13:38 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

char    *skip_space(char *line)
{
    if(*line == ' ')
    {
        while (*line == ' ')
            line++;
    }
    return(line);
}

int		ft_isdigit(int arg)
{
	if (arg > 47 && arg < 58)
		return (1);
	return (0);
}

void    init_par(t_alls *sts)
{
    sts->ceiling_color.t = 0;
    sts->ceiling_color.r = 0;
    sts->ceiling_color.g = 0;
    sts->ceiling_color.b = 0;
    sts->floor_color.t = 0;
    sts->floor_color.r = 0;
    sts->floor_color.g = 0;
    sts->floor_color.b = 0;
    sts->fov = 0;
    sts->resolution.x = 0;
    sts->resolution.y = 0;
    sts->paths.n_path = NULL;
    sts->paths.s_path = NULL;
    sts->paths.e_path = NULL;
    sts->paths.w_path = NULL;
    sts->paths.sprite_path = NULL;
}

int     check_ext(t_alls *st, char *ext)
{
    int i;

    i = 0;
    while(st->paths.map_path[i] != '\0')
    {
        i++;
    }
    if (i > 4 && st->paths.map_path[i-1] == ext[2] && st->paths.map_path[i-2] == ext[1] 
            && st->paths.map_path[i-3] == ext[0] && st->paths.map_path[i-4] == '.')
    {
        return (1);
    }
    else 
        return (0);
}

int     count_until_next_space(char *line)
{
    int i;

    i = 0;
    while (line[i] != ' ' && line[i] != '\0' && line[i] != ',')
    {
        i++;
    }
    return (i);
}