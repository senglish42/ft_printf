/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numzero.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:24:29 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:24:30 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_numzero(t_param *set, int len)
{
	int	count;

	count = 0;
	if (set->minus == 1 || (set->zero == 1 && set->precision == -1))
	{
		if ((set->minus == 1 || set->width <= 0) && set->precision == -1)
			set->precision = len;
		while ((set->zero == 1 && set->precision == -1
				&& set->width-- > 0) || (set->precision-- > 0))
			count = count + ft_putcharlen_fd('0', 1);
		while (set->width > count)
			count = count + ft_putcharlen_fd(32, 1);
	}
	else if (set->minus != 1)
	{
		if (set->precision == -1)
			set->precision = len;
		while (set->width-- - set->precision > 0)
			count = count + ft_putcharlen_fd(32, 1);
		while (set->precision-- > 0)
			count = count + ft_putcharlen_fd('0', 1);
	}
	return (count);
}
