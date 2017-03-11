/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_conv2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:49:01 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:49:03 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		*set_len_prec2(t_print *prt, char padd, t_content *cont)
{
	if (cont->flags->minus == 0)
	{
		prt->wbefore = ft_strnew(cont->width_value -
				value_of(cont->precision_value, ft_strlen(prt->string))
				- ft_strlen(prt->sign));
		ft_memset(prt->wbefore, padd, cont->width_value -
				value_of(ft_strlen(prt->string), cont->precision_value) -
				ft_strlen(prt->sign));
	}
	else
	{
		prt->wafter = ft_strnew(cont->width_value -
				value_of(cont->precision_value, ft_strlen(prt->string))
				- ft_strlen(prt->sign));
		ft_memset(prt->wafter, padd, cont->width_value -
				value_of(ft_strlen(prt->string), cont->precision_value) -
				ft_strlen(prt->sign));
	}
	return (prt);
}
