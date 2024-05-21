/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:54:09 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/21 14:57:26 by djelacik         ###   ########.fr       */
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

char    *cleanbuf(char *buffer)
{
    int        i;
    int        j;
    char    *new;

    i = 0;
    while (buffer[i] != '\0' && buffer[i] != '\n')
        i++;
    if (buffer[i] == '\0')
    {
        free(buffer);
        return (NULL);
    }
    new = malloc(ft_strlen(buffer) - i + 1);
    if (!new)
    {
        free(buffer);
        return (NULL);
    }
    i++;
    j = 0;
    while (buffer[i] != '\0')
        new[j++] = buffer[i++];
	new[j] = '\0';
    free(buffer);
    return (new);
}
