/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:54:09 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/18 20:12:35 by djelacik         ###   ########.fr       */
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

char	*ft_strjoin_free(char *s1, char const *s2, unsigned long max_size)
{
	char				*buffer_p;
	char				*buffer;
	char				*temp_p;
	unsigned long		i;
	unsigned long		size;
	
	size = (ft_strlen(s1) + ft_strlen(s2));
	if (max_size < size)
		size = max_size;
	buffer = (char *)malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	buffer_p = buffer;
	i = 0;
	temp_p = s1;
	while (*s1 && i++ < max_size)
		*buffer++ = *s1++;
	while (*s2 && i++ < max_size)
		*buffer++ = *s2++;
	*buffer++ = 0;
	free(temp_p);
	return (buffer_p);
}
