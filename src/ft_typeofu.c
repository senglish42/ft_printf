/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_typeofu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:24:50 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:24:51 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static char	*ft_swapnum(unsigned int n, char *d);
static char	*ft_strrev(char *str);
int			ft_undecad(unsigned int n);

char	*ft_typeofu(unsigned int num)
{
	unsigned int	a;
	char			*u;

	if (!num)
		return (ft_strdup("0"));
	a = ft_undecad(num);
	u = (char *)malloc(sizeof(char) * a + 1);
	if (!u)
		return (NULL);
	u[a] = '\0';
	u = ft_swapnum(num, u);
	if (!u)
		return (NULL);
	u = ft_strrev(u);
	return (u);
}

int	ft_undecad(unsigned int n)
{
	int	a;

	a = 1;
	if (n < 0)
	{
		n = -n;
		a += 1;
	}
	while (n >= 10)
	{
		n = n / 10;
		a += 1;
	}
	return (a);
}

static char	*ft_swapnum(unsigned int n, char *d)
{
	unsigned int	a;
	char			*c;

	a = 0;
	c = (char *)d;
	if (!c)
		return (NULL);
	while (n != 0)
	{
		if (n < 0)
		{
			*(c + a++) = '-';
			n = -n;
		}
		*(c + a++) = n % 10 + 48;
		n = n / 10;
	}
	*(c + a) = '\0';
	return (c);
}

static char	*ft_strrev(char *f)
{
	int		a;
	int		len;
	char	b;

	a = 0;
	len = ft_strlen(f);
	while (len - 1 > a)
	{
		if (*(f + a) == '-')
			a++;
		b = *(f + a);
		*(f + a++) = *(f + len - 1);
		*(f + len-- - 1) = b;
	}
	*(f + ft_strlen(f)) = '\0';
	return (f);
}
