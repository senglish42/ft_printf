/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:24:23 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:24:24 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_strmin(char *output, t_param *set, int count);
int	ft_strzero(char *output, t_param *set, int count);
int	ft_strnbr(char *output, t_param *set, int count);

int	ft_fillstr(char *output, t_param *set)
{
	int	count;
	int	len;

	if (output == NULL)
		output = "(null)";
	count = 0;
	len = (int)ft_strlen(output);
	if (set->zero == 1 && set->precision == len)
		return (0);
	if (set->precision == -1 || set->precision > len)
		set->precision = len;
	if (set->minus == 1)
		return (ft_strmin(output, set, count));
	else if (set->zero == 1)
		return (ft_strzero(output, set, count));
	else
		return (ft_strnbr(output, set, count));
}

int	ft_strmin(char *output, t_param *set, int count)
{
	int	num;

	num = 0;
	while (output[num] != '\0' && set->minus == 1 && set->precision > count)
		count = count + ft_putcharlen_fd(output[num++], 1);
	while (set->minus == 1 && set->width - count > 0)
		count = count + ft_putcharlen_fd(32, 1);
	return (count);
}

int	ft_strzero(char *output, t_param *set, int count)
{
	int	num;

	num = 0;
	while (set->zero == 1 && set->width - set->precision > count)
		count = count + ft_putcharlen_fd('0', 1);
	while (output[num] != '\0' && set->zero == 1 && set->precision-- > 0)
		count = count + ft_putcharlen_fd(output[num++], 1);
	return (count);
}

int	ft_strnbr(char *output, t_param *set, int count)
{
	int	num;

	num = 0;
	while (set->zero == -1 && set->width - set->precision > count)
		count = count + ft_putcharlen_fd(32, 1);
	while (output[num] != '\0'
		&& set->zero == -1 && set->precision-- > 0 && *output)
		count = count + ft_putcharlen_fd(output[num++], 1);
	return (count);
}
