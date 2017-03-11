/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:46:27 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:46:28 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa_base(unsigned long long n, long long base, char *table)
{
	int		i;
	char	sign;
	char	*aux;

	i = 0;
	sign = 0;
	aux = ft_strnew(32);
	if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		aux[i++] = table[ft_abs(n % base)];
		n /= base;
	}
	aux = ft_strrev(aux);
	return (aux);
}
