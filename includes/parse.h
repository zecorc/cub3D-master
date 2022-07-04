/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <gcrocett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 13:16:18 by gcrocett          #+#    #+#             */
/*   Updated: 2022/07/04 14:11:01 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "./structs.h"

int     start_parsing(t_alls *sts);
int     foreach_line(char *line, t_alls *sts, int fd);
char    *skip_space(char *line);
int		ft_isdigit(int arg);
void    init_par(t_alls *sts);
int     check_ext(t_alls *st, char *ext);
//int     parse_res(char *line, t_alls *sts);
void    set_res(t_alls *sts);
int     parse_no(char *line, t_alls *sts);
int     parse_so(char *line, t_alls *sts);
int     parse_we(char *line, t_alls *sts);
int     parse_ea(char *line, t_alls *sts);
int     parse_sprite(char *line, t_alls *sts);
int     parse_floor(char *line, t_alls *sts);
int     parse_ceiling(char *line, t_alls *sts);
int     start_map_parse(char *line, t_alls *sts, int fd);
int     count_until_next_space(char *line);
int     copy_nbr(int *dest, char *line);
int     count_map_line(t_alls *sts);
char    *skip_until_bn(char *buf);
int		ft_atoi(char *str);
char    *skip_v(char *line);
char    *skip_until_next_char(char *buf, char character);
int     check_next_char(char *line, char num);

#endif
