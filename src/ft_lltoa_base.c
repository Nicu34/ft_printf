/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:46:09 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:46:10 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(long long n, long long base, char *table)
{
	int		i;
	char	sign;
	char	*aux;

	i = 0;
	sign = 0;
	if (n < 0)
		sign = 1;
	aux = ft_strnew(32);
	if (n == 0)
		aux[0] = '0';
	while (n != 0)
	{
		aux[i++] = table[ft_abs(n % base)];
		n /= base;
	}
	if (sign && base == 10)
		aux[i] = '-';
	aux = ft_strrev(aux);
	return (aux);
}
