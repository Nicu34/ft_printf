/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_uu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:50:49 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:50:50 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_uu(va_list ap, int *bytes, t_content *cont)
{
	unsigned int	n;
	char			*str;

	cont->flags->plus = 0;
	cont->flags->space = 0;
	if (cont->precision_value)
		cont->flags->zero = 0;
	if (!cont->lenmod)
	{
		n = va_arg(ap, unsigned int);
		str = ft_utoa_base((long long)n, 10, "0123456789abcdef");
		print_signed_d(str, bytes, cont);
	}
	else
		process_uu_with_len("0123456789abcdef", ap, bytes, cont);
}

char	*process_uu_with_len2(char *tab, va_list ap, t_content *cont)
{
	char		*str;
	t_ouxxconv	*n;

	n = (t_ouxxconv*)malloc(sizeof(t_ouxxconv));
	str = NULL;
	if (!ft_strcmp(cont->lenmod, "l"))
	{
		n->ulongint = va_arg(ap, unsigned long);
		str = ft_utoa_base((long long)(n->ulongint), 10, tab);
	}
	else if (!ft_strcmp(cont->lenmod, "j"))
	{
		n->uintmax = va_arg(ap, uintmax_t);
		str = ft_utoa_base((long long)(n->uintmax), 10, tab);
	}
	else if (!ft_strcmp(cont->lenmod, "z"))
	{
		n->sizet = va_arg(ap, size_t);
		str = ft_utoa_base((long long)(n->sizet), 10, tab);
	}
	return (str);
}

void	process_uu_with_len(char *tab, va_list ap, int *bytes, t_content *cont)
{
	char		*str;
	t_ouxxconv	*n;

	str = NULL;
	n = (t_ouxxconv*)malloc(sizeof(t_ouxxconv));
	if (!ft_strcmp(cont->lenmod, "hh"))
	{
		n->uchar = va_arg(ap, unsigned int);
		str = ft_utoa_base((long long)(n->uchar), 10, tab);
	}
	else if (!ft_strcmp(cont->lenmod, "ll"))
	{
		n->ullint = va_arg(ap, unsigned long long);
		str = ft_utoa_base((long long)(n->ullint), 10, tab);
	}
	else if (!ft_strcmp(cont->lenmod, "h"))
	{
		n->ushortint = va_arg(ap, unsigned int);
		str = ft_utoa_base((long long)(n->ushortint), 10, tab);
	}
	else
		str = process_uu_with_len2(tab, ap, cont);
	if (str)
		print_signed_d(str, bytes, cont);
}
