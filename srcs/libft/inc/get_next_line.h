/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damohen <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 10:33:18 by damohen           #+#    #+#             */
/*   Updated: 2025/01/08 12:47:42 by damohen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	char			*str_buf;
	struct s_list	*next;
}			t_list;
void	ft_bzero(void	*s, size_t n);
char	*join_free(char *buffer_static, char *buffer);
char	*delete_line(char *bufer_static);
char	*ft_line(char *buffer_static);
char	*read_file(int fd, char *buffer_static, int byte_read);
char	*get_next_line(int fd);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s);
char	*ft_strchr(const char *s, int c);
t_list	*find_last_node(t_list *list);
int		ft_strlen(const char *s);
#endif
