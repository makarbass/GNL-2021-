/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <bpatrici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:37:24 by bpatrici          #+#    #+#             */
/*   Updated: 2022/01/21 13:34:04 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_linestr(char *str)
{
	char	*line;
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_malloc(i + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		line[i] = str[i];
		i++;
	}
	return (line);
}

char	*ft_strcut(char *str)
{
	char	*line;
	int		i;
	int		j;

	j = 0;
	while (str[j])
		j++;
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		i++;
	line = ft_malloc((j - i) + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (str[i + j])
	{
		line[j] = str[i + j];
		j++;
	}
	return (line);
}

char	*ft_parseline(char **str)
{
	char	*tmp;
	char	*line;

	tmp = ft_strdup(*str);
	ft_freestr(str);
	line = ft_linestr(tmp);
	*str = ft_strcut(tmp);
	free(tmp);
	return (line);
}

void	ft_readstr(int fd, char	**str)
{
	int		rd;
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;

	tmp = NULL;
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, buffer, BUFFER_SIZE);
		if (rd == -1)
		{
			ft_freestr(str);
			return ;
		}
		buffer[rd] = '\0';
		tmp = ft_strdup(*str);
		ft_freestr(str);
		*str = ft_strjoin(tmp, buffer);
		ft_freestr(&tmp);
		if (ft_strchr(*str, '\n'))
			break ;
	}
}

char	*get_next_line(int fd)
{
	char		*read_line;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	read_line = NULL;
	ft_readstr(fd, &str);
	if (str)
		read_line = ft_parseline(&str);
	if (!read_line || *read_line == '\0')
	{
		ft_freestr(&read_line);
		ft_freestr(&str);
		return (NULL);
	}
	return (read_line);
}
