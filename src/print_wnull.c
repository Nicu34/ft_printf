/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_wnull.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:48:27 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:48:47 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_wnull(char *str, t_content *cont, int *bytes)
{
	cont->precision_value = 0;
	print_signed_d(str, bytes, cont);
}
