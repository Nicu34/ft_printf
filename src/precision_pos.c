/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_pos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:51:36 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:51:37 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		prec_pos(char *desc)
{
	int		i;
	int		pos;

	pos = 0;
	i = 1;
	while (desc[i])
	{
		if (desc[i] == '.')
			pos = i + 1;
		++i;
	}
	return (pos);
}
