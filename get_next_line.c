/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fichmawi <fichmawi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 10:18:38 by fichmawi          #+#    #+#             */
/*   Updated: 2025/11/18 22:24:03 by fichmawi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*join_free(char *extruct, char *buf)
{
	char	*join;

	join = ft_strjoin(extruct, buf);
	free(extruct);
	return (join);
}

char	*read_extruct(int fd, char *extruct)
{
	char	*buf;
	int		octets;

	if (!extruct)
		extruct = ft_calloc(1, 1);
	buf = malloc((BUF_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	octets = 1;
	while (octets > 0)
	{
		octets = read(fd, buf, BUF_SIZE);
		if (octets == -1)
		{
			free (extruct);
			free (buf);
			return (NULL);
		}
		buf[octets] = '\0';
		extruct = join_free(extruct, buf);
		if (ft_strchr(extruct, '\n') != NULL)
			break ;
	}
	free (buf);
	return (extruct);
}

char	*my_line(char *extruct)
{
	int		i;
	char	*line;

	if(!extruct || !extruct[0])
		return NULL;
	i = 0;
	while (extruct[i] && extruct[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	if (!line)
		return (NULL);
	i = 0;
	while (extruct[i] && extruct[i] != '\n')
	{
		line[i] = extruct[i];
		i++;
	}
	if (extruct[i] && extruct[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*clean_extruct(char *extruct)
{
	int		i;
	int		j;
	char	*clean;

	i = 0;
	while (extruct[i] && extruct[i] != '\n')
		i++;
	if (!extruct[i])
	{
		free (extruct);
		return (NULL);
	}
	clean = ft_calloc((ft_strlen(extruct) - i + 1), sizeof(*extruct));
	if (!clean)
		return (NULL);
	j = 0;
	i++;
	while (extruct[i])
		clean[j++] = extruct[i++];
	free (extruct);
	return (clean);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*extruct;

	if (fd < 0 || BUF_SIZE <= 0)
		return (NULL);
	extruct = read_extruct(fd, extruct);
	if (!extruct)
		return (NULL);
	line = my_line(extruct);
	extruct = clean_extruct(extruct);
	return (line);
}
