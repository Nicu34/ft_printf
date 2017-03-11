/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:50:13 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:50:14 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_print_structure(t_print *prt)
{
	prt->sign = ft_strdup("");
	prt->string = ft_strdup("");
	prt->prec = ft_strdup("");
	prt->wbefore = ft_strdup("");
	prt->wafter = ft_strdup("");
}

int		value_of(int precision, int number)
{
	if (precision > number)
		return (precision);
	else
		return (number);
}

void	print_shit(t_print *prt, int *bytes)
{
	if (prt->wbefore[0] == '0')
	{
		ft_putstr(prt->sign);
		ft_putstr(prt->wbefore);
	}
	else
	{
		ft_putstr(prt->wbefore);
		ft_putstr(prt->sign);
	}
	ft_putstr(prt->prec);
	ft_putstr(prt->string);
	ft_putstr(prt->wafter);
	*bytes = *bytes + ft_strlen(prt->sign) + ft_strlen(prt->wbefore) +
		ft_strlen(prt->wafter) + ft_strlen(prt->string) + ft_strlen(prt->prec);
}

void	set_len_prec(t_print *prt, char padd, t_content *cont)
{
	if (cont->precision_value > ft_strlen(prt->string))
	{
		prt->prec = ft_strnew(cont->precision_value -
				ft_strlen(prt->string));
		ft_memset(prt->prec, '0', cont->precision_value -
				ft_strlen(prt->string));
	}
	if (cont->width_value > ft_strlen(prt->prec) + ft_strlen(prt->string) +
			ft_strlen(prt->sign) && cont->width_value)
		prt = set_len_prec2(prt, padd, cont);
	else if (cont->precision_value < ft_strlen(prt->string) &&
			cont->width_value > ft_strlen(prt->string) + ft_strlen(prt->sign))
	{
		prt->wbefore = ft_strnew(cont->width_value - ft_strlen(prt->string));
		ft_memset(prt->wbefore, padd, cont->width_value -
				ft_strlen(prt->string));
	}
}

void	print_signed_d(char *str, int *bytes, t_content *cont)
{
	char	padd;
	t_print	*prt;

	prt = (t_print*)malloc(sizeof(t_print));
	init_print_structure(prt);
	padd = ' ';
	if ((str[0] == '-' && cont->flags->plus) || (str[0] == '-'))
	{
		prt->sign = ft_strdup("-");
		ft_strcpy(str, str + 1);
	}
	else if (cont->flags->space)
		prt->sign = ft_strdup(" ");
	else if (cont->flags->plus)
		prt->sign = ft_strdup("+");
	prt->string = ft_strdup(str);
	if (cont->flags->zero)
		padd = '0';
	set_len_prec(prt, padd, cont);
	print_shit(prt, bytes);
}
