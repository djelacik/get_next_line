/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:54:09 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/20 19:13:36 by djelacik         ###   ########.fr       */
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

char	*ft_strjoin_free(char *buffer, char const *temp_buffer)
{
	char		*new_buffer;
	size_t		size;
	size_t		i;
	size_t		j;
	
	i = 0;
	while (temp_buffer[i] && temp_buffer[i] != '\n')
		i++;
	size = 0;
	if (buffer)
		size = ft_strlen(buffer);
	new_buffer = malloc(sizeof(char) * (size + i + 1));
	if (!new_buffer)
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	j = 0;
	while (temp_buffer[j])
		new_buffer[i++] = temp_buffer[j++];
	if (temp_buffer[j] == '\n')
		new_buffer[i++] = '\n';
	new_buffer[i] = '\0';
	free(buffer);
	return (new_buffer);
}
