/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:25:35 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:25:36 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			a;
	unsigned char	*b;

	if (!s)
		return (NULL);
	a = 0;
	b = (unsigned char *)s;
	while (a < n)
	{
		if (b[a++] == (unsigned char)c)
			return (b + a);
	}
	return (NULL);
}
