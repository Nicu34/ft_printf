/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:49:52 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:49:53 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_p(va_list ap, int *bytes, t_content *cont)
{
	void	*ptr;
	char	*str;
	int		flg;
	int		zero;

	zero = cont->flags->zero;
	flg = cont->flags->minus;
	init_flags(&(cont->flags));
	cont->flags->minus = flg;
	cont->flags->zero = zero;
	ptr = va_arg(ap, void*);
	str = ft_strdup("0x");
	if (!(cont->precision_value == -1))
		str = ft_strjoin(str, ft_utoa_base((long long)ptr,
					16, "0123456789abcdef"));
	if (cont->precision_value == -1 || (!ft_strcmp(str, "0x0") && \
		cont->precision_value > 0))
	{
		ft_putstr("0x");
		*bytes += 2;
		str = ft_strdup("");
	}
	process_p_2(bytes, cont, str);
}

void	process_p_2(int *bytes, t_content *cont, char *str)
{
	if (cont->precision_value >= 0 && cont->width_value > 0 &&
			cont->precision_value > cont->width_value)
	{
		ft_putstr("0x");
		*bytes += 2;
		str = ft_strcpy(str, str + 2);
	}
	if (cont->flags->zero)
	{
		ft_putstr("0x");
		*bytes += 2;
		str = ft_strcpy(str, str + 2);
		cont->width_value -= 2;
	}
	if (cont->precision_value == -1)
		cont->precision_value = 0;
	print_signed_d(str, bytes, cont);
}
