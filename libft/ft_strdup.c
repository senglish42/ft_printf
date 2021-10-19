/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:25:50 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:25:51 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strdup(const char *s1)
{
	char	*a;
	int		b;

	b = (int)ft_strlen(s1);
	a = (char *)malloc(sizeof(char) * (b + 1));
	if (!a)
		return (NULL);
	*(a + b) = '\0';
	while (b-- > 0)
		*(a + b) = *(s1 + b);
	return (a);
}
