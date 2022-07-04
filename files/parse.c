/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/21 19:08:48 by gcrocett          #+#    #+#             */
/*   Updated: 2022/07/04 14:10:16 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h"

int    start_parsing(t_alls *sts)
{
    int     ext_ok;
    int     fd;
    char    *line;
    int     ret;
    int     gnl;

    ret = 1;
    gnl = 1;
    ext_ok = check_ext(sts, "cub");
    if (ext_ok == 0)
        return (0);
    init_par(sts);
    fd = open(sts->paths.map_path, O_RDONLY);
    line = (char *)malloc(sizeof(char) * 100);
    if (line == NULL)
        return (0);
    while (ret == 1 && gnl == 1)
    {
    gnl = get_next_line(fd, &line);
    ret = foreach_line(line, sts, fd);
    }
    set_res(sts);
    if (ret != 4242)
        return (ret);
    return(1);
}

int     foreach_line(char *line, t_alls *sts, int fd)
{
    if (check_next_char(line, '1') != 1)
        line = skip_space(line);
//    if (line [0] == 'R')
//       return (parse_res(line, sts));
    if (line[0] == 'N' && line[1] == 'O')
        return (parse_no(line, sts));
    else if (line[0] == 'S' && line[1] == 'O')
        return (parse_so(line, sts));
    else if (line[0] == 'W' && line[1] == 'E')
        return (parse_we(line, sts));
    else if (line[0] == 'E' && line[1] == 'A')
        return (parse_ea(line, sts));
    else if (line[0] == 'S' && line[1] == ' ')
        return (parse_sprite(line, sts));
    else if (line[0] == 'F')
        return (parse_floor(line, sts));
    else if (line[0] == 'C')
        return (parse_ceiling(line, sts));
    else if (line[0] == ' ' || line[0] == '1')
        return (start_map_parse(line, sts, fd));
    else if (line[0] == '\0')
        return(1);
    return (0);
}

int     check_next_char(char *line, char num)
{
    int i;

    i = 0;
    while(line[i] == ' ')
        i++;
    if (line[i] == num)
        return (1);
    return (0);
}






