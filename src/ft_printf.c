/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:24:40 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:24:41 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	t_param	set;
	int		count;

	count = 0;
	va_start(ap, str);
	while (*str)
	{
		while (*str != '\0' && *str != '%')
			count = count + ft_putcharlen_fd(*str++, 1);
		if (*str == '%')
		{
			set = settings();
			ft_init(ap, (char *)(++str), &set, "iucspxXd%");
			count = count + ft_args(ap, &set);
		}
		while (*str && *str++ != set.type)
			continue ;
	}
	va_end(ap);
	return (count);
}
