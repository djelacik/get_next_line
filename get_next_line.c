/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:58:36 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/21 16:27:10 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_to_buffer(int fd, char *buffer)
{
	char	*temp_buffer;
	int		bytes_read;

	if (!buffer)
	{
		buffer = malloc(1);
		buffer[0] = '\0';
	}
	temp_buffer = malloc(BUFFER_SIZE + 1);
	if (!temp_buffer)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0 && !ft_strchr(buffer, '\n'))
	{
		bytes_read = read(fd, temp_buffer, BUFFER_SIZE);
 		if (bytes_read < 0)
		{
			free(temp_buffer);
			return (buffer);
		}
		temp_buffer[bytes_read] = '\0';
		buffer = ft_strjoin_free(buffer, temp_buffer);
	}
	free(temp_buffer);
	return (buffer);
}

static char	*extract_line(char **buffer)
{
	char	*line;
	int		i;
	int		new_line_flag;

	i = 0;
	while((*buffer)[i] && (*buffer)[i] != '\n')
		i++;
	new_line_flag = 0;
	if ((*buffer)[i] == '\n')
		new_line_flag = 1;
	line = (char *)malloc(sizeof(char) * (i + new_line_flag + 1));
	if (!line)
		return (NULL);
	i = 0;
	while ((*buffer)[i] && (*buffer)[i] != '\n')
	{
		line[i] = (*buffer)[i];
		i++;
	}
	return (line);
}


char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = read_to_buffer(fd, buffer);
	if (!buffer)
	{
		free(buffer);
		return (NULL);
	}
	line = extract_line(&buffer);
	buffer = cleanbuf(buffer);
	if (!line && !*buffer)
	{
		free(line);
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