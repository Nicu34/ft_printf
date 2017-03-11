/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:49:58 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 17:18:26 by mvoina           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_d(va_list ap, int *bytes, t_content *cont)
{
	int		n;
	char	*str;

	if (cont->precision_value)
		cont->flags->zero = 0;
	if (!cont->lenmod)
	{
		n = va_arg(ap, int);
		str = ft_itoa_base((long long)n, 10, "0123456789");
		print_signed_d(str, bytes, cont);
	}
	else
		process_d_with_len(ap, bytes, cont);
}

void	process_d_with_len(va_list ap, int *bytes, t_content *cont)
{
	char			*str;
	t_dconversion	*n;

	n = (t_dconversion*)malloc(sizeof(t_dconversion));
	if (!ft_strcmp(cont->lenmod, "hh"))
	{
		n->schar = va_arg(ap, int);
		str = ft_itoa_base((long long)(n->schar), 10, "0123456789");
	}
	else if (!ft_strcmp(cont->lenmod, "h"))
	{
		n->shortint = va_arg(ap, int);
		str = ft_itoa_base((long long)(n->shortint), 10, "0123456789");
	}
	else
	{
		str = NULL;
		process_d_with_len_2(ap, bytes, cont, str);
		str = NULL;
	}
	if (str)
		print_signed_d(str, bytes, cont);
}

void	process_d_with_len_2(va_list ap, int *bytes,
		t_content *cont, char *str)
{
	t_dconversion	*n;

	n = (t_dconversion*)malloc(sizeof(t_dconversion));
	if (!ft_strcmp(cont->lenmod, "ll"))
	{
		n->llint = va_arg(ap, long long);
		str = ft_itoa_base((long long)(n->llint), 10, "0123456789");
	}
	else if (!ft_strcmp(cont->lenmod, "l"))
	{
		n->longint = va_arg(ap, long);
		str = ft_itoa_base((long long)(n->longint), 10, "0123456789");
	}
	else if (!ft_strcmp(cont->lenmod, "j"))
	{
		n->intmax = va_arg(ap, intmax_t);
		str = ft_itoa_base((long long)(n->intmax), 10, "0123456789");
	}
	else if (!ft_strcmp(cont->lenmod, "z"))
	{
		n->sizet = va_arg(ap, size_t);
		str = ft_itoa_base((long long)(n->sizet), 10, "0123456789");
	}
	print_signed_d(str, bytes, cont);
}
