/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:35:42 by gcrocett          #+#    #+#             */
/*   Updated: 2021/02/10 19:08:30 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/game_utils.h"

char	*split_line(char *save, char **line, int totread)
{
	unsigned int	count;
	char			*temp;

	count = 0;
	while (save[count])
	{
		if (save[count] == '\n')
			break ;
		count++;
	}
	if (count < (unsigned int)ft_strlen(save))
	{
		*line = ft_substr(save, 0, count);
		temp = ft_substr(save, count + 1, ft_strlen(save));
		free(save);
		save = ft_strdup(temp);
		free(temp);
	}
	else if (totread == 0)
	{
		*line = save;
		save = NULL;
	}
	return (save);
}

char	*save_buf(char *buf, char *save)
{
	char	*tmp;

	if (save)
	{
		tmp = ft_strjoin(save, buf);
		free(save);
		save = ft_strdup(tmp);
		free(tmp);
	}
	else
		save = ft_strdup(buf);
	return (save);
}

int		get_next_line(int fd, char **line)
{
	static char	*fds[4096];
	char		buf[BUFFER_SIZE + 1];
	int			totread;

	while ((totread = read(fd, buf, BUFFER_SIZE)))
	{
		if (totread == -1)
			return (-1);
		buf[totread] = '\0';
		fds[fd] = save_buf(buf, fds[fd]);
		if (ft_strchr((const char *)buf, '\n'))
			break ;
	}
	if (totread <= 0 && !fds[fd])
	{
		*line = ft_strdup("");
		return (totread);
	}
	fds[fd] = split_line(fds[fd], line, totread);
	if (totread <= 0 && !fds[fd])
		return (totread);
	return (1);
}
