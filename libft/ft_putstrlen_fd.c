/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrlen_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:25:43 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:25:44 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	ft_putstrlen_fd(char *s, int fd)
{
	int	a;

	if (!s || !fd)
		return (0);
	a = 0;
	while (*(s + a))
		write (fd, s + a++, 1);
	return (a);
}
