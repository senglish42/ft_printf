/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:24:26 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:24:27 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	ft_parsewidth(va_list	ap, char *str, t_param *set);
char	*ft_parseprecision(va_list	ap, char *str, t_param *set);
char	ft_type(char *s, char *c);

void	ft_init(va_list	ap, char *str, t_param *set, char *args)
{
	while (*str == '-' || *str == '0')
	{
		if (*str == '-')
			set->minus = 1;
		if (*str++ == '0')
			set->zero = 1;
	}
	while (*str == '.' || (*str >= '0' && *str <= '9')
		|| *str == '-' || *str == '*')
	{
		ft_parsewidth(ap, str, set);
		if (*str++ == '.')
			str = ft_parseprecision(ap, str, set);
	}
	if (*str == '\0')
		return ;
	if (*str == ft_type(str, args))
		set->type = *str;
}

void	ft_parsewidth(va_list	ap, char *str, t_param *set)
{
	if ((*str >= '0' && *str <= '9' && set->width == 0) && set->precision == -1)
		set->width = ft_atoi(str);
	if (*str == '*' && set->width == 0)
	{
		set->width = va_arg(ap, int);
		if (set->width <= 0)
		{
			set->minus = 1;
			set->width = -set->width;
		}
	}
}

char	*ft_parseprecision(va_list	ap, char *str, t_param *set)
{
	set->precision = 0;
	if (*str >= '0' && *str <= '9')
		set->precision = ft_atoi(str);
	if (*str == '*')
	{
		set->precision = va_arg(ap, int);
		if (set->precision < 0)
			set->precision = -1;
		str++;
	}
	return (str);
}

char	ft_type(char *s, char *c)
{
	char	*b;

	if (!s)
		return (0);
	b = (char *)s;
	while (*c)
	{
		if (*b == *c++)
			return (*b);
	}
	return (0);
}
