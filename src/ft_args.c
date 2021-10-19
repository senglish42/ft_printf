/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:23:14 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:23:15 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	type_of_p(va_list ap, t_param *set)
{
	char	*output1;
	char	*output2;
	int		count;

	output1 = ft_typeofx(va_arg(ap, unsigned long), set);
	output2 = ft_strjoin("0x", output1);
	count = ft_fillarray(output2, set);
	free(output1);
	output1 = NULL;
	return (count);
}

int	ft_args(va_list ap, t_param *set)
{
	int	count;

	count = 0;
	if (set->type == 'd' || set->type == 'i')
		count = ft_fillarray(ft_itoa(va_arg(ap, int)), set);
	else if (set->type == 'u')
		count = ft_fillarray(ft_typeofu(va_arg(ap, unsigned long)), set);
	else if (set->type == 'x')
		count = ft_fillarray(ft_typeofx(va_arg(ap, unsigned int), set), set);
	else if (set->type == 'X')
		count = ft_fillarray(ft_typeofcapx
				(va_arg(ap, unsigned long), set), set);
	else if (set->type == 'p')
		count = type_of_p(ap, set);
	else if (set->type == 'c')
		count = ft_fillchr(va_arg(ap, int), set);
	else if (set->type == 's')
		count = ft_fillstr(va_arg(ap, char *), set);
	else if (set->type == '%')
		count = ft_fillchr('%', set);
	return (count);
}
