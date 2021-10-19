/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeofcapx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:24:47 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:24:47 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_typeofcapx(unsigned int num, t_param *set)
{
	char	*from;
	int		a;

	a = 0;
	from = ft_typeofx(num, set);
	if (!from)
		return (NULL);
	while (*(from + a))
	{
		if (*(from + a) >= 'a' && *(from + a) <= 'f')
			*(from + a) = *(from + a) - 32;
		a++;
	}
	*(from + a) = '\0';
	return (from);
}
