/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasukmua <wrp.sukmuang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 21:08:53 by vasukmua          #+#    #+#             */
/*   Updated: 2025/11/05 22:49:17 by vasukmua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	str = (char *) malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (i < ft_strlen(s1))
		str[j++] = s1[i++];
	i = 0;
	while (i < ft_strlen(s2))
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int c)
{
	unsigned int	i;
	char			*tmp;

	if (!str)
		return (NULL);
	tmp = (char *)str;
	i = 0;
	{
		if (tmp[i] == (char)c)
			return (&tmp[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&tmp[i]);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc(ft_strlen(str) + 1);
	if (!ptr)
		return (NULL);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
