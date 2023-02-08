/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 10:11:30 by marvin            #+#    #+#             */
/*   Updated: 2022/12/25 10:11:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <unistd.h>
# include <stdlib.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

size_t			ft_strlen(const char *s);

char			*ft_strchr(const char *s, int c);

char			*ft_strjoin(char *s1, char *s2);

char			*get_next_line(int fd);

#endif