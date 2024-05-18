/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:58:36 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/18 20:03:29 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_all_to_buffer(int fd, char *buffer)
{
	char	*temp_buffer;
	int		bytes_read;

	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(temp_buffer);
		return (buffer);
	}
	temp_buffer[bytes_read] = '\0';
	buffer = ft_strjoin_free(buffer, temp_buffer, 888888888);
	return (buffer);
}

static char	*extract_line(char **buffer)
{
	char		*line;
	char		*newline_pos;

	newline_pos = *buffer;
	while (*newline_pos && *newline_pos != '\n')
		newline_pos++;
	line = ft_strjoin_free("", *buffer, newline_pos - *buffer + 1);
	if (!line)
		return (NULL);
	*buffer = ++newline_pos;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_all_to_buffer(fd, buffer);
	if (!buffer)
		return (NULL);
	line = extract_line(&buffer);
	if (line && !*buffer)
	{
		free(line);
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (line);
}
#include <fcntl.h>
#include <stdio.h>
int main(void)
{
    int fd;
    char *line;

    fd = open("test.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);
    }
    close(fd);
    return 0;
}