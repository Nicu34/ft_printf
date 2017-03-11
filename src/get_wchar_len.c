/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_wchar_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:47:02 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:47:03 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_wchar_len(wchar_t chr)
{
	if (chr < 0x7f)
		return (1);
	if (chr < 0x7ff)
		return (2);
	if (chr < 0xffff)
		return (3);
	return (4);
}
