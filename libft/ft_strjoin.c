/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:25:53 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:25:54 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*a;
	int		b;
	int		c;

	if (!s1 || !s2)
		return (NULL);
	a = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	b = 0;
	c = 0;
	if (a == NULL)
		return (NULL);
	while (s1[b])
	{
		a[b] = s1[b];
		b++;
	}
	while (s2[c])
		a[b++] = s2[c++];
	a[b] = '\0';
	return (a);
}
