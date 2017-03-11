/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:46:44 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:46:46 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	ft_wstrlen(wchar_t *str)
{
	int				i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (str[i])
	{
		len += get_wchar_len(str[i]);
		i++;
	}
	return (len);
}
