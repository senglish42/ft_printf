/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillarray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:24:11 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:24:12 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_fillarray(char *output, t_param *set)
{
	int	len;
	int	count;

	count = 0;
	len = (int)ft_strlen(output);
	if (!output || (set->type == 's'
			&& set->precision == 0 && set->width < len))
		count = 0;
	else if (*output == '0' && len == 1)
		count = ft_numzero(set, len);
	else if (set->width <= set->precision)
		count = ft_prec(output, set, len);
	else if (set->width > set->precision)
	{
		if (set->minus == 1 || (set->zero == 1 && set->precision == -1))
			count = ft_widthminus(output, set, len);
		else if (set->zero == 1 || set->zero == -1)
			count = ft_widthzero(output, set, len);
	}
	free(output);
	output = NULL;
	return (count);
}
