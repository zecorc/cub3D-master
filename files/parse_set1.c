/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_set1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:13:57 by gcrocett          #+#    #+#             */
/*   Updated: 2022/07/04 14:10:49 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/game_utils.h" 

/*
int     parse_res(char *line, t_alls *sts)
{
    int     err;

    line++;
    if (sts->resolution.x != 0 || sts->resolution.y != 0)
        return (251);
    line = skip_space(line);
    err = copy_nbr(&sts->resolution.x, line);
    if (err == 0)
        return (250);
    line = skip_until_next_char(line, ' ');
    line = skip_space(line);
    err = copy_nbr(&sts->resolution.y, line);
    if (err == 0)
        return (250);
    return (1);
}
*/

void     set_res(t_alls *sts)
{
    sts->resolution.x = RESX;
    sts->resolution.y = RESY;
}

int     parse_no(char *line, t_alls *sts)
{
    int len;
    int count;

    line++;
    line++;
    count = 0;
    line = skip_space(line);
    if (sts->paths.n_path != NULL)
        return (252);
    len = count_until_next_space(line);
    sts->paths.n_path = (char *)malloc(sizeof(char) * (len +1));
    if (sts->paths.n_path == NULL)
        return (253);
    while (*line != ' ' && *line != '\0')
    {
        sts->paths.n_path[count] = *line;
        count ++;
        line++;
    }
    sts->paths.n_path[count] = '\0';
    return (1);
}

int     parse_so(char *line, t_alls *sts)
{
    int len;
    int count;

    line++;
    line++;
    count = 0;
    line = skip_space(line);
    if (sts->paths.s_path != NULL)
        return (254);
    len = count_until_next_space(line);
    sts->paths.s_path = (char *)malloc(sizeof(char) * (len +1));
    if (sts->paths.s_path == NULL)
        return (255);
    while (*line != ' ' && *line != '\0')
    {
        sts->paths.s_path[count] = *line;
        count ++;
        line++;
    }
    sts->paths.s_path[count] = '\0';
    return (1);
}

int     parse_we(char *line, t_alls *sts)
{
    int len;
    int count;

    line++;
    line++;
    count = 0;
    line = skip_space(line);
    if (sts->paths.w_path != NULL)
        return (256);
    len = count_until_next_space(line);
    sts->paths.w_path = (char *)malloc(sizeof(char) * (len +1));
    if (sts->paths.w_path == NULL)
        return (257);
    while (*line != ' ' && *line != '\0')
    {
        sts->paths.w_path[count] = *line;
        count ++;
        line++;
    }
    sts->paths.w_path[count] = '\0';
    return (1);
}

int     parse_ea(char *line, t_alls *sts)
{
    int len;
    int count;

    line++;
    line++;
    count = 0;
    line = skip_space(line);
    if (sts->paths.e_path != NULL)
        return (258);
    len = count_until_next_space(line);
    sts->paths.e_path = (char *)malloc(sizeof(char) * (len +1));
    if (sts->paths.e_path == NULL)
        return (259);
    while (*line != ' ' && *line != '\0')
    {
        sts->paths.e_path[count] = *line;
        count ++;
        line++;
    }
    sts->paths.e_path[count] = '\0';
    return (1);
}
