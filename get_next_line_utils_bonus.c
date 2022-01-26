/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <bpatrici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:43:57 by bpatrici          #+#    #+#             */
/*   Updated: 2022/01/21 13:37:44 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s && s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == c)
		return ((char *)(s + i));
	return (NULL);
}

void	ft_freestr(char **str)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
}

char	*ft_malloc(int size)
{
	int		i;
	char	*new;

	new = (char *) malloc((size) * sizeof(char));
	if (!new)
		return (NULL);
	i = 0;
	while (i < size)
		new[i++] = '\0';
	return (new);
}

char	*ft_strjoin(char *str, char *buffer)
{
	char	*res;
	int		i;
	int		j;

	if (!buffer)
		return (NULL);
	i = 0;
	while (str && str[i])
		i++;
	j = 0;
	while (buffer && buffer[j])
		j++;
	res = ft_malloc(i + j + 1);
	if (res == NULL)
		return (res);
	i = -1;
	while (str[++i] != '\0')
		res[i] = str[i];
	j = 0;
	while (buffer[j] != '\0')
		res[i++] = buffer[j++];
	return (res);
}

char	*ft_strdup(const char *s1)
{
	char	*res;
	int		i;

	if (!s1)
		return (ft_strdup(""));
	i = 0;
	while (s1[i])
		i++;
	res = ft_malloc(i + 1);
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	return (res);
}
