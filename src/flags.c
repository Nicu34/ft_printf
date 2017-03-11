/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:45:54 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:45:56 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	init_flags(t_flg **flags)
{
	(*flags)->diez = 0;
	(*flags)->zero = 0;
	(*flags)->minus = 0;
	(*flags)->plus = 0;
	(*flags)->space = 0;
}

void	set_flag(t_flg *flags, char c)
{
	if (c == '0' && flags->minus == 0)
		flags->zero = 1;
	else if (c == '-')
	{
		flags->minus = 1;
		flags->zero = 0;
	}
	else if (c == ' ' && flags->plus == 0)
		flags->space = 1;
	else if (c == '+')
	{
		flags->plus = 1;
		flags->space = 0;
	}
	else if (c == '#')
		flags->diez = 1;
}

void	unset_flags_unsigned(t_flg *flags)
{
	flags->plus = 0;
	flags->space = 0;
}

char	*do_octal_diez(char *str, int diez)
{
	if (diez && ft_strcmp(str, "0"))
	{
		str = ft_strjoin("0", str);
	}
	return (str);
}

char	*do_hexa_diez(char *str, int diez, char conv, int *bytes)
{
	if (diez && ft_strcmp(str, "0"))
	{
		if (conv == 'x')
			ft_putstr("0x");
		else
			ft_putstr("0X");
		*bytes += 2;
	}
	return (str);
}
