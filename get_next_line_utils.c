/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:54:09 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/21 17:43:17 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s != (char)c)
		if (!*s++)
			return (0);
	return ((char *)s);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*buffer;
	size_t	total;
	size_t	i;

	if (count == 0 || size == 0)
		return (NULL);
	total = count * size;
	buffer = malloc(total);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < total)
	{
		((unsigned char *)buffer)[i] = 0;
		i++;
	}
	return (buffer);
}


char	*ft_strjoin_free(char *buffer, char const *temp_buffer)
{
	char		*new_buffer;
	size_t		size;
	size_t		i;
	size_t		j;
	
	size = 0;
	if (buffer)
		size += ft_strlen(buffer);
	if (temp_buffer)
		size += ft_strlen(temp_buffer);
	new_buffer = malloc(sizeof(char) * (size + 1));
	if (!new_buffer)
		return (NULL);
	i = 0;
	while (buffer && buffer[i])
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	j = 0;
	while (temp_buffer && temp_buffer[j])
		new_buffer[i++] = temp_buffer[j++];
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}

char	*cleanbuf(char *buffer)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new = ft_calloc(ft_strlen(buffer + i) + 1, 1);
	if (!new)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	while (buffer[i] != '\0')
		new[j++] = buffer[i++];
	free(buffer);
	return (new);
}

