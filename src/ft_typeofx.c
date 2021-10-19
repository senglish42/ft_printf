/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeofx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:24:55 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:24:56 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_hexadecimal(unsigned long n, char *hex, int count, char *kek)
{
	if (n >= 16)
	{
		kek[--count] = hex[n % 16];
		ft_hexadecimal(n / 16, hex, count, kek);
	}
	else
		kek[--count] = hex[n];
	return (kek);
}

char	*ft_typeofx(unsigned long num, t_param *set)
{
	static char		hex[] = "0123456789abcdef";
	int				count;
	char			*kek;
	unsigned long	x;

	if (num == 0 && set->type != 'X' && set->precision == 0)
	{
		kek = (char *)malloc(sizeof (char) * 1);
		kek[0] = '\0';
		return (kek);
	}
	count = 0;
	x = num;
	while (++count && x / 16 != 0)
		x = x / 16;
	kek = (char *)malloc(sizeof (char) * count + 1);
	if (!kek)
		return (NULL);
	kek[count] = '\0';
	kek = ft_hexadecimal(num, hex, count, kek);
	return (kek);
}
