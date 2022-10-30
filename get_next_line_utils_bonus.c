/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils_bonus.c                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pyevtush <pyevtush@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/25 20:21:13 by pyevtush      #+#    #+#                 */
/*   Updated: 2022/10/30 18:34:28 by pyevtush      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (!s)
		return (0);
	len = 0;
	while (s[len])
		++len;
	return (len);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*res;

	if (!s1 && !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!res)
		return (free(s1), NULL);
	i = 0;
	j = 0;
	while (i < s1_len)
		res[j++] = s1[i++];
	i = 0;
	while (i < s2_len)
		res[j++] = s2[i++];
	res[j] = '\0';
	free(s1);
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	size_t	size;
	size_t	i;

	if (!s1)
		return (NULL);
	size = ft_strlen(s1);
	res = (char *)malloc((size + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (i < size)
	{
		res[i] = s1[i];
		++i;
	}
	res[i] = '\0';
	return (res);
}

char	*reset_str(char *str)
{
	int		index;
	char	*res;

	index = new_line_index(str) + 1;
	res = ft_strdup(str + index);
	free(str);
	return (res);
}

int	new_line_index(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
		++i;
	return (i);
}
