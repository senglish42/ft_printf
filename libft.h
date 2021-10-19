/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:25:22 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:25:23 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>

int		ft_atoi(const char *str);
void	*ft_memchr(const void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *s1);
int		ft_putcharlen_fd(char c, int fd);
int		ft_putstrlen_fd(char *s, int fd);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_itoa(int n);

#endif
