/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:24:44 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:24:45 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

t_param	settings(void)
{
	t_param	set;

	set.minus = 0;
	set.zero = -1;
	set.width = 0;
	set.precision = -1;
	set.type = ' ';
	return (set);
}
