/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: milmi <milmi@student.1337.ma>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 05:08:48 by milmi             #+#    #+#             */
/*   Updated: 2021/01/18 15:05:43 by milmi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# define BUFFER_SIZE 10

size_t			ft_strlen(const char *str);
void			*ft_memcpy(void *dest, char *src, size_t n);
char			*ft_strjoin(char **s1, char **s2);
char			*ft_strchr(const char *s, int c);
int				get_next_line(int fd, char **line);
char			*ft_strdup(char *str1);
#endif
