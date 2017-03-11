/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:49:12 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:49:13 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	flags_init_for_cc(t_content **cont)
{
	(*cont)->flags->diez = 0;
	(*cont)->flags->plus = 0;
	(*cont)->flags->space = 0;
}

void	process_upper_c(va_list ap, int *bytes, t_content *cont)
{
	wchar_t		text;

	flags_init_for_cc(&cont);
	text = va_arg(ap, int);
	ft_putwchar(text);
	*bytes += get_wchar_len(text);
}

void	process_cc(unsigned char conv, va_list ap, int *bytes, t_content *cont)
{
	int		prec;

	if (!cont->lenmod)
	{
		prec = cont->precision_value;
		flags_init_for_cc(&cont);
		cont->precision_value = 0;
		if (conv != '%')
			conv = va_arg(ap, int);
		if ((conv == 0 || conv == '%') && cont->width_value > 0)
			cont->width_value -= 1;
		if (cont->flags->minus)
		{
			ft_putchar(conv);
			print_signed_d("", bytes, cont);
		}
		else
		{
			print_signed_d("", bytes, cont);
			ft_putchar(conv);
		}
		*bytes += 1;
	}
	else
		process_upper_c(ap, bytes, cont);
}
