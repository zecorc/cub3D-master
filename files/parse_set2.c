/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_set2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:14:25 by gcrocett          #+#    #+#             */
/*   Updated: 2021/04/24 13:14:39 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

int     parse_sprite(char *line, t_alls *sts)
{
    int len;
    int count;

    line++;
    count = 0;
    line = skip_space(line);
    if (sts->paths.sprite_path != NULL)
        return (260);
    len = count_until_next_space(line);
    sts->paths.sprite_path = (char *)malloc(sizeof(char) * (len +1));
    if (sts->paths.sprite_path == NULL)
        return (261);
    while (*line != ' ' && *line != '\0')
    {
        sts->paths.sprite_path[count] = *line;
        count ++;
        line++;
    }
    sts->paths.sprite_path[count] = '\0';
    return (1);
}

int     parse_floor(char *line, t_alls *sts)
{
    int err;

    line++;
    line = skip_space(line);
    if (sts->floor_color.r != 0 || sts->floor_color.g != 0 ||sts->floor_color.b != 0)
        return (262);
    err = copy_nbr(&sts->floor_color.r, line);
    if (err == 0)
        return (263);
    line = skip_until_next_char(line, ',');
    line = skip_v(line);
    err = copy_nbr(&sts->floor_color.g, line);
    if (err == 0)
        return (263);
    line = skip_until_next_char(line, ',');
    line = skip_v(line);
    err = copy_nbr(&sts->floor_color.b, line);
    if (err == 0)
        return (263);
    return (1);
}

int     parse_ceiling(char *line, t_alls *sts)
{
    int err;

    line++;
    line = skip_space(line);
    if (sts->ceiling_color.r != 0 || sts->ceiling_color.g != 0 ||sts->ceiling_color.b != 0)
        return (264);
    err = copy_nbr(&sts->ceiling_color.r, line);
    if (err == 0)
        return (265);
    line = skip_until_next_char(line, ',');
    line = skip_v(line);
    err = copy_nbr(&sts->ceiling_color.g, line);
    if (err == 0)
        return (265);
    line = skip_until_next_char(line, ',');
    line = skip_v(line);
    err = copy_nbr(&sts->ceiling_color.b, line);
    if (err == 0)
        return (265);
    return (1);
}

int     start_map_parse(char *line, t_alls *sts, int fd)
{
    int map_line;
    int line_len;
    int i;

    i = 0;
    map_line = count_map_line(sts);
    sts->map = (char **)malloc(sizeof(char *) * (map_line + 1));
    if (sts->map == NULL)
        return (0);
    while (map_line > 0)
    {
        line_len = ft_strlen(line);
        sts->map[i] = (char *)malloc(sizeof(char) * line_len);
        if (sts->map[i] == NULL)
            return (0);
        sts->map[i] = line;
        get_next_line(fd, &line);
        map_line--;
        i++;
    }
    sts->map[i] = NULL;
    return (4242);
}