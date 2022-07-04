/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcrocett <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/18 15:36:07 by gcrocett          #+#    #+#             */
/*   Updated: 2021/02/10 19:04:13 by gcrocett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		count;
	int		count2;
	int		tot_len;
	char	*pt;

	count = 0;
	count2 = 0;
	if (s2 == NULL || s1 == NULL)
		return (NULL);
	tot_len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(pt = (char*)malloc(sizeof(char *) * (tot_len + 1))))
		return (0);
	while (s1[count] != '\0')
	{
		pt[count] = s1[count];
		count++;
	}
	while (s2[count2] != '\0')
	{
		pt[count] = s2[count2];
		count2++;
		count++;
	}
	pt[count] = '\0';
	return (pt);
}

int		ft_strlen(char *str)
{
	int		leng;
	char	*temp;

	temp = str;
	leng = 0;
	if (temp == 0)
		return (0);
	while (*temp != '\0')
	{
		temp++;
		leng++;
	}
	return (leng);
}

char	*ft_strchr(const char *str, int c)
{
	char	car;
	int		i;

	i = 0;
	car = (unsigned char)c;
	while (str[i] != '\0')
	{
		if (str[i] == car)
		{
			return ((char *)str + i);
		}
		i++;
	}
	if (str[i] == car)
		return ((char *)str + i);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (s == NULL)
		return (NULL);
	if (!(str = (char*)malloc(sizeof(*s) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}

char	*ft_strdup(const char *s)
{
	int		count;
	int		len;
	char	*ns;
	char	*sn;

	sn = (char *)s;
	count = 0;
	len = ft_strlen(sn);
	if (!(ns = malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (count < len)
	{
		ns[count] = s[count];
		count++;
	}
	ns[count] = '\0';
	return (ns);
}
