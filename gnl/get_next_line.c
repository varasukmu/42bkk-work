/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasukmua <wrp.sukmuang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:45:33 by vasukmua          #+#    #+#             */
/*   Updated: 2025/11/06 16:07:22 by vasukmua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_free_and_return(char *ptr1, char *ptr2)
{
	if (ptr1)
		free(ptr1);
	if (ptr2)
		free(ptr2);
	return (NULL);
}

static char	*read_until_nl(int fd, char *stash)
{
	char	*buf;
	ssize_t	bytes;
	char	*temp;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (ft_free_and_return(stash, NULL));
	bytes = 1;
	while ((!stash || !ft_strchr(stash, '\n')) && bytes > 0)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes < 0)
			return (ft_free_and_return(buf, stash));
		buf[bytes] = '\0';
		if (bytes > 0)
		{
			temp = stash;
			stash = ft_strjoin(stash, buf);
			free(temp);
			if (!stash)
				return (ft_free_and_return(buf, NULL));
		}
	}
	free(buf);
	return (stash);
}

static char	*extract(char *stash)
{
	size_t	i;
	size_t	j;
	char	*line;

	i = 0;
	j = 0;
	if (!stash || !stash[0])
		return (NULL);
	while (stash[i] && stash[i] != '\n')
		i++;
	line = malloc(i + 2);
	if (!line)
		return (NULL);
	while (stash[j] && stash[j] != '\n')
	{
		line[j] = stash[j];
		j++;
	}
	if (stash[j] == '\n')
		line[j++] = '\n';
	line[j] = '\0';
	return (line);
}

static char	*update(char *stash)
{
	size_t	i;
	size_t	j;
	char	*new_stash;

	i = 0;
	j = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (NULL);
	}
	i++;
	new_stash = malloc(ft_strlen(stash) - i + 1);
	if (!new_stash)
		return (ft_free_and_return(stash, NULL));
	while (stash[i])
		new_stash[j++] = stash[i++];
	new_stash[j] = '\0';
	free(stash);
	return (new_stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_until_nl(fd, stash);
	if (!stash)
		return (NULL);
	line = extract(stash);
	if (!line)
	{
		stash = ft_free_and_return(stash, NULL);
		return (NULL);
	}
	stash = update(stash);
	return (line);
}
