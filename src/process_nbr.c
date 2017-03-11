/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:49:17 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 17:17:15 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_n(va_list ap, int *bytes)
{
	int		*n;

	n = va_arg(ap, int*);
	*n = *bytes;
}

void	process_b(va_list ap, int *bytes, t_content *cont)
{
	unsigned int	n;
	char			*str;

	n = va_arg(ap, unsigned int);
	str = ft_utoa_base((unsigned long long)n, 2, "01");
	print_signed_d(str, bytes, cont);
}

void	print_non_pr(char c)
{
	if (c == '\n')
		ft_putstr("\\n");
	if (c == '\f')
		ft_putstr("\\f");
	if (c == '\r')
		ft_putstr("\\r");
	if (c == '\t')
		ft_putstr("\\t");
	if (c == '\v')
		ft_putstr("\\v");
	if (c == '\0')
		ft_putstr("\\0");
	if (c == '\a')
		ft_putstr("\\a");
	if (c == '\b')
		ft_putstr("\\b");
	if (c == '\r')
		ft_putstr("\\r");
}

void	process_r(va_list ap, int *bytes, t_content *cont)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(ap, char *);
	if (!str && cont->precision_value != -1)
	{
		ft_putstr("(null)");
		*bytes += 6;
	}
	else if (cont->precision_value != -1)
		while (i <= ft_strlen(str))
		{
			if (!ft_isprint(str[i]) && str[i] < 127)
				print_non_pr(str[i]);
			else
				ft_putchar(str[i]);
			i++;
			*bytes += 1;
		}
}
