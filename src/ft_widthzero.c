/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_widthzero.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:25:04 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:25:05 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_widthzero(char *output, t_param *set, int len)
{
	int	count;

	count = 0;
	if (ft_strchr(output, '-'))
		set->precision++;
	if (set->zero == -1 && set->precision == -1)
		set->precision = len;
	if (set->zero == 1 && set->precision == -1)
		set->precision = set->width;
	else if (set->precision < len)
		set->precision = len;
	while (set->width-- - set->precision > 0)
		count = count + ft_putcharlen_fd(32, 1);
	if (ft_strchr(output, '-'))
	{
		count = count + ft_putcharlen_fd('-', 1);
		output++;
	}
	while (set->precision-- - len > 0)
		count = count + ft_putcharlen_fd('0', 1);
	count = count + ft_putstrlen_fd(output, 1);
	return (count);
}
