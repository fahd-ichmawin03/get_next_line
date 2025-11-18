/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fichmawi <fichmawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:14:07 by fichmawi          #+#    #+#             */
/*   Updated: 2025/11/18 22:01:56 by fichmawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUF_SIZE
#  define  BUF_SIZE 1337
# endif

# include <unistd.h>
# include <stdlib.h>
#include <stdint.h>

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
char	*read_extruct(int fd, char *text);
char	*my_line(char *text);
char	*clean_extruct(char *text);
void	*ft_calloc(size_t count, size_t size);

#endif