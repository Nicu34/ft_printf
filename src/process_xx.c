/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:51:03 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:51:04 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_xx(char conv, va_list ap, int *bytes, t_content *cont)
{
	unsigned int	n;
	char			*str;

	str = NULL;
	unset_flags_unsigned(cont->flags);
	if (!cont->lenmod)
	{
		n = va_arg(ap, unsigned int);
		if (conv == 'x')
			str = ft_utoa_base((long long)n, 16, "0123456789abcdef");
		else
			str = ft_utoa_base((long long)n, 16, "0123456789ABCDEF");
		str = do_hexa_diez(str, cont->flags->diez, conv, bytes);
		if (!(cont->flags->diez && cont->precision_value == -1 && \
			ft_strlen(str) == 1 && str[0] == '0'))
			print_signed_d(str, bytes, cont);
	}
	else
	{
		if (conv == 'x')
			process_xx_with_len("0123456789abcdef", ap, bytes, cont);
		else
			process_xx_with_len("0123456789ABCDEF", ap, bytes, cont);
	}
}

char	*process_xx_with_len2(char *tab, va_list ap, t_content *cont,
		t_ouxxconv *n)
{
	char	*str;

	str = NULL;
	if (!ft_strcmp(cont->lenmod, "l"))
	{
		n->ulongint = va_arg(ap, unsigned long);
		str = ft_utoa_base((long long)(n->ulongint), 16, tab);
	}
	else if (!ft_strcmp(cont->lenmod, "ll"))
	{
		n->ullint = va_arg(ap, unsigned long long);
		str = ft_utoa_base((long long)(n->ullint), 16, tab);
	}
	else if (!ft_strcmp(cont->lenmod, "j"))
	{
		n->uintmax = va_arg(ap, uintmax_t);
		str = ft_utoa_base((long long)(n->uintmax), 16, tab);
	}
	else if (!ft_strcmp(cont->lenmod, "z"))
	{
		n->sizet = va_arg(ap, size_t);
		str = ft_utoa_base((long long)(n->sizet), 16, tab);
	}
	return (str);
}

void	process_xx_with_len(char *tab, va_list ap, int *bytes, t_content *cont)
{
	char		*str;
	t_ouxxconv	*n;

	str = NULL;
	n = (t_ouxxconv*)malloc(sizeof(t_ouxxconv));
	if (!ft_strcmp(cont->lenmod, "hh"))
	{
		n->uchar = va_arg(ap, unsigned int);
		str = ft_utoa_base((long long)(n->uchar), 16, tab);
	}
	else if (!ft_strcmp(cont->lenmod, "h"))
	{
		n->ushortint = va_arg(ap, unsigned int);
		str = ft_utoa_base((long long)(n->ushortint), 16, tab);
	}
	else
		str = process_xx_with_len2(tab, ap, cont, n);
	if (tab[10] == 'A')
		str = do_hexa_diez(str, cont->flags->diez, 'x', bytes);
	else
		str = do_hexa_diez(str, cont->flags->diez, 'X', bytes);
	cont->precision_value = 0;
	if (str)
		print_signed_d(str, bytes, cont);
}
