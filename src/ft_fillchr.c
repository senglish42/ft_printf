/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:24:15 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:24:16 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_fillchr(char c, t_param *set)
{
	int	count;

	count = 0;
	if (set->minus == 1)
	{
		count = ft_putcharlen_fd(c, 1);
		while (set->width-- > 1)
			count = count + ft_putcharlen_fd(32, 1);
	}
	else if (set->zero == 1)
	{
		while (set->width-- > 1)
			count = count + ft_putcharlen_fd('0', 1);
		count = count + ft_putcharlen_fd(c, 1);
	}
	else
	{
		while (set->width-- > 1)
			count = count + ft_putcharlen_fd(32, 1);
		count = count + ft_putcharlen_fd(c, 1);
	}
	return (count);
}
