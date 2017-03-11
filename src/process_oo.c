/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_oo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:50:37 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:50:38 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_oo(va_list ap, int *bytes, t_content *cont)
{
	unsigned int	n;
	char			*str;

	str = ft_strdup("");
	unset_flags_unsigned(cont->flags);
	if (cont->flags->diez && cont->precision_value == -1)
		cont->precision_value = 0;
	if (!cont->lenmod)
	{
		n = va_arg(ap, unsigned int);
		str = ft_utoa_base((long long)(n), 8, "0123456789");
		str = do_octal_diez(str, cont->flags->diez);
		print_signed_d(str, bytes, cont);
	}
	else
		process_oo_with_len("0123456789abcdef", ap, bytes, cont);
}

void	process_oo_with_len(char *tab, va_list ap, int *bytes, t_content *cont)
{
	char		*str;
	t_ouxxconv	*n;

	str = NULL;
	n = (t_ouxxconv*)malloc(sizeof(t_ouxxconv));
	if (!ft_strcmp(cont->lenmod, "hh"))
	{
		n->uchar = va_arg(ap, unsigned int);
		str = ft_utoa_base((long long)(n->uchar), 8, tab);
	}
	else if (!ft_strcmp(cont->lenmod, "h"))
	{
		n->ushortint = va_arg(ap, unsigned int);
		str = ft_utoa_base((long long)(n->ushortint), 8, tab);
	}
	else
		str = process_oo_with_len_2(tab, ap, cont, n);
	str = do_octal_diez(str, cont->flags->diez);
	if (str)
		print_signed_d(str, bytes, cont);
}

char	*process_oo_with_len_2(char *tab, va_list ap, t_content *cont,
		t_ouxxconv *n)
{
	char	*str;

	str = NULL;
	if (!ft_strcmp(cont->lenmod, "l"))
	{
		n->ulongint = va_arg(ap, unsigned long);
		str = ft_utoa_base((long long)(n->ulongint), 8, tab);
	}
	else if (!ft_strcmp(cont->lenmod, "ll"))
	{
		n->ullint = va_arg(ap, unsigned long long);
		str = ft_utoa_base((long long)(n->ullint), 8, tab);
	}
	else if (!ft_strcmp(cont->lenmod, "j"))
	{
		n->uintmax = va_arg(ap, uintmax_t);
		str = ft_utoa_base((long long)(n->uintmax), 8, tab);
	}
	else if (!ft_strcmp(cont->lenmod, "z"))
	{
		n->sizet = va_arg(ap, size_t);
		str = ft_utoa_base((long long)(n->sizet), 8, tab);
	}
	return (str);
}
