/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:46:18 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:46:19 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putwstr(wchar_t *str, int *bytes)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putwchar(str[i]);
		*bytes += get_wchar_len(str[i]);
		i++;
	}
}
