/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widthminus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:25:00 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:25:01 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_widthminus(char *output, t_param *set, int len)
{
	int	a;
	int	count;

	a = 0;
	count = 0;
	if (ft_strchr(output, '-'))
	{
		count = ft_putcharlen_fd('-', 1);
		output++;
		set->precision++;
	}
	while ((set->precision > 0 && set->precision - len > a++)
		|| (set->minus == 0 && set->width - len > a++))
		count = count + ft_putcharlen_fd('0', 1);
	count = count + ft_putstrlen_fd(output, 1);
	if (set->minus == 1 && set->width >= len && set->width >= set->precision)
	{
		if (set->precision < len)
			set->precision = len;
		while (set->width-- - set->precision > 0)
			count = count + ft_putcharlen_fd(32, 1);
	}
	return (count);
}
