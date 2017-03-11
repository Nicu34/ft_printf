/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:46:34 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:46:35 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwchar(wchar_t chr)
{
	if (chr <= 0x7f)
		ft_putchar(chr);
	else if (chr <= 0x7ff)
	{
		ft_putchar((chr >> 6) + 0xc0);
		ft_putchar((chr & 0x3f) + 0x80);
	}
	else if (chr <= 0xffff)
	{
		ft_putchar((chr >> 12) + 0xe0);
		ft_putchar(((chr >> 6) & 0x3f) + 0x80);
		ft_putchar((chr & 0x3f) + 0x80);
	}
	else if (chr <= 0x10ffff)
	{
		ft_putchar((chr >> 18) + 0xf0);
		ft_putchar(((chr >> 12) & 0x3f) + 0x80);
		ft_putchar(((chr >> 6) & 0x3f) + 0x80);
		ft_putchar((chr & 0x3f) + 0x80);
	}
}
