/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senglish <senglish@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 13:25:19 by senglish          #+#    #+#             */
/*   Updated: 2021/10/19 13:25:20 by senglish         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

typedef struct s_list
{
	int		minus;
	int		zero;
	int		width;
	int		precision;
	char	type;
}			t_param;

int		ft_printf(const char *str, ...);
int		ft_fillarray(char *output, t_param *set);
void	ft_init(va_list ap, char *str, t_param *set, char *args);
t_param	settings(void);
int		ft_args(va_list ap, t_param *set);
int		ft_widthminus(char *output, t_param *set, int len);
int		ft_widthzero(char *output, t_param *set, int len);
int		ft_prec(char *output, t_param *set, int len);
char	*ft_typeofu(unsigned int num);
int		ft_numzero(t_param *set, int len);
char	*ft_typeofcapx(unsigned int num, t_param *set);
int		ft_fillstr(char *output, t_param *set);
int		ft_fillchr(char c, t_param *set);
char	*ft_typeofx(unsigned long num, t_param *set);

#endif
