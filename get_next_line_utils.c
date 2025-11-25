/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fichmawi <fichmawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 11:14:04 by fichmawi          #+#    #+#             */
/*   Updated: 2025/11/24 10:09:10 by fichmawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *str)
{
	int	i;
	
	if(!str)
		return 0;
	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	if(!s)
		return NULL;
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*join;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	join = malloc(len_s1 + len_s2 + 1);
	if (!join)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		join[i] = s1[i];
		i++;
	}
	j = 0;
	while (j < len_s2)
		join[i++] = s2[j++];
	join[i] = '\0';
	return (join);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*p;

	if (num == 0 || size == 0)
		return (malloc(1));
	if (num > SIZE_MAX / size)
		return (NULL);
	p = malloc(num * size);
	if (!p)
		return (NULL);
	ft_bzero(p, num * size);
	return (p);
}
