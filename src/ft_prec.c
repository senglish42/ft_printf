/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:24:33 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:24:34 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_prec(char *output, t_param *set, int len)
{
	int	count;

	count = 0;
	if (ft_strchr(output, '-'))
	{
		count = ft_putcharlen_fd('-', 1);
		output++;
		len--;
	}
	if (set->type == 'p')
	{
		count = count + ft_putstrlen_fd("0x", 1);
		while (set->precision-- - len + 2 > 0)
			count = count + ft_putcharlen_fd('0', 1);
		count = count + ft_putstrlen_fd(output + 2, 1);
		return (count);
	}
	while (set->precision-- - len > 0)
		count = count + ft_putcharlen_fd('0', 1);
	count = count + ft_putstrlen_fd(output, 1);
	return (count);
}
