/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_desc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:50:43 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:50:44 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	process_invalid(char *desc, int *bytes)
{
	t_print		*prt;
	char		padd;
	t_content	*cont;

	cont = set_content(desc, 0);
	prt = (t_print*)malloc(sizeof(t_print));
	init_print_structure(prt);
	padd = ' ';
	if (cont->flags->zero)
		padd = '0';
	prt->string = ft_strnew(2);
	prt->string[0] = desc[ft_strlen(desc) - 1];
	if (cont->width_value > 1 && cont->flags->minus)
	{
		prt->wafter = ft_strnew(cont->width_value - 1);
		ft_strset(prt->wafter, padd, cont->width_value - 1);
	}
	else if (cont->width_value > 1 && !cont->flags->minus)
	{
		prt->wbefore = ft_strnew(cont->width_value - 1);
		ft_strset(prt->wbefore, padd, cont->width_value - 1);
	}
	print_shit(prt, bytes);
}

void	process_desc(char *desc, va_list ap, int *bytes)
{
	int			len;
	t_content	*new;

	new = set_content(desc, ap);
	len = ft_strlen(desc);
	if (desc[len - 1] == 'c' || (desc[len - 1] == '%' && len > 1))
		process_cc(desc[len - 1], ap, bytes, new);
	else if (desc[len - 1] == 'p')
		process_p(ap, bytes, new);
	else if (desc[len - 1] == 's')
		process_ss(ap, bytes, new);
	else if (desc[len - 1] == 'C')
		process_upper_c(ap, bytes, new);
	else if (desc[len - 1] == 'S')
		process_upper_s(ap, bytes, new);
	else if (desc[len - 1] == 'n')
		process_n(ap, bytes);
	else if (desc[len - 1] == 'b' || desc[len - 1] == 'b')
		process_b(ap, bytes, new);
	else if (desc[len - 1] == 'r' || desc[len - 1] == 'r')
		process_r(ap, bytes, new);
	process_desc_2(desc, ap, bytes, new);
}

void	process_desc_3(char *desc, va_list ap, int *bytes, t_content *new)
{
	int		len;

	len = ft_strlen(desc);
	if (desc[len - 1] == 'U')
	{
		new->lenmod = ft_strdup("l");
		process_uu(ap, bytes, new);
	}
	else if (desc[len - 1] == 'o')
		process_oo(ap, bytes, new);
	else if (desc[len - 1] == 'O')
	{
		new->lenmod = ft_strdup("l");
		process_oo(ap, bytes, new);
	}
}

void	process_desc_2(char *desc, va_list ap, int *bytes, t_content *new)
{
	int		len;

	len = ft_strlen(desc);
	if (new->precision_value != -1)
	{
		if (desc[len - 1] == 'd' || desc[len - 1] == 'i')
			process_d(ap, bytes, new);
		else if (desc[len - 1] == 'D')
		{
			new->lenmod = ft_strdup("l");
			process_d_with_len(ap, bytes, new);
		}
		else if (desc[len - 1] == 'x' || desc[len - 1] == 'X')
			process_xx(desc[len - 1], ap, bytes, new);
		else if (desc[len - 1] == 'u')
			process_uu(ap, bytes, new);
		else
			process_desc_3(desc, ap, bytes, new);
	}
}
