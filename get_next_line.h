/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djelacik <djelacik@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 11:49:54 by djelacik          #+#    #+#             */
/*   Updated: 2024/05/18 20:03:13 by djelacik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 32
#endif

typedef struct	s_gnl
{
	char	*buffer;
	//another struct?
}	t_gnl;

/*
**Function prototypes
*/
char	*get_next_line(int fd);

size_t	ft_strlen(const char *s);
char	*ft_strjoin_free(char *s1, char const *s2, unsigned long max_size);

#endif