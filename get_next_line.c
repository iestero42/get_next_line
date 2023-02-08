/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 10:11:27 by marvin            #+#    #+#             */
/*   Updated: 2022/12/25 10:11:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_save(char *stored_lines)
{
	int		i;
	char	*str;

	i = 0;
	while (stored_lines[i] != '\0' && stored_lines[i] != '\n')
		i++;
	if (stored_lines[i] == '\0')
	{
		free(stored_lines);
		return (NULL);
	}
	str = malloc(sizeof(char) * (ft_strlen(stored_lines) - i + 1));
	if (!str)
		return (NULL);
	i++;
	ft_strlcpy(str, &stored_lines[i], ft_strlen(stored_lines) - i + 1);
	free(stored_lines);
	return (str);
}

static char	*ft_lseek(char *stored_lines)
{
	char	*str;
	int		i;

	i = 0;
	if (stored_lines[i] == '\0')
		return (NULL);
	while (stored_lines[i] != '\0' && stored_lines[i] != '\n')
		i++;
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	ft_strlcpy(str, stored_lines, i + 1);
	if (stored_lines[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

static char	*ft_read(int fd, char *stored_lines)
{
	char	*buf;
	int		readed;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	readed = 1;
	while (!ft_strchr(stored_lines, '\n') && readed != '\0')
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[readed] = '\0';
		stored_lines = ft_strjoin(stored_lines, buf);
	}
	free(buf);
	return (stored_lines);
}

char	*get_next_line(int fd)
{
	static char	*stored_lines;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free (stored_lines);
		stored_lines = NULL;
		return (0);
	}
	stored_lines = ft_read(fd, stored_lines);
	if (!stored_lines)
		return (NULL);
	line = ft_lseek(stored_lines);
	stored_lines = ft_save(stored_lines);
	return (line);
}
