/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 20:20:28 by pyevtush      #+#    #+#                 */
/*   Updated: 2022/10/28 21:54:03 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	is_newline_exist(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		++i;
	}
	return (0);
}

char	*extract_str(char *s)
{
	int		size;
	int		i;
	char	*res;

	size = new_line_index(s) + 1;
	res = (char *) malloc ((size + 1) * sizeof(char));
	i = 0;
	while (i < size)
	{
		res[i] = s[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}

char	*return_line(char **str)
{
	char		*line;

	line = NULL;
	if (is_newline_exist(*str))
	{
		line = extract_str(*str);
		*str = reset_str(*str);
	}
	else if (ft_strlen(*str))
	{
		line = ft_strdup(*str);
		free(*str);
		*str = NULL;
	}
	else
	{
		free(*str);
		*str = NULL;
	}
	return (line);
}

char	*read_from_file(int fd, char *str)
{
	int			bytes;
	char		*buffer;

	bytes = 1;
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!is_newline_exist(str) && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			if (str)
				free(str);
			return (free(buffer), NULL);
		}
		buffer[bytes] = '\0';
		str = ft_strjoin(str, buffer);
		if (!str)
			return (free(buffer), NULL);
	}
	return (free(buffer), str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*strs[256];

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 256)
		return (NULL);
	strs[fd] = read_from_file(fd, strs[fd]);
	if (!strs[fd])
		return (NULL);
	line = return_line(&strs[fd]);
	return (line);
}
