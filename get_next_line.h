/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpatrici <bpatrici@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/21 12:43:30 by bpatrici          #+#    #+#             */
/*   Updated: 2022/01/21 13:33:24 by bpatrici         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1000
# endif

char	*get_next_line(int fd);

char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *str, char *buff);
void	ft_freestr(char **str);
char	*ft_malloc(int size);
char	*ft_strdup(const char *s1);
char	*ft_linestr(char *str);
char	*ft_strcut(char *str);
void	ft_readstr(int fd, char	**str);

#endif
