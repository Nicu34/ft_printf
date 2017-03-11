/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_ss.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:50:56 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:50:58 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*work_precision(char *string, int prec)
{
	int		steps;
	int		i;
	char	*str;

	str = ft_strdup(string);
	i = ft_strlen(str) - 1;
	steps = 0;
	if (prec > 0)
		steps = ft_strlen(str) - prec;
	while (steps > 0 && ft_strlen(str) > 0)
	{
		str[i] = '\0';
		steps--;
		i--;
	}
	return (str);
}

wchar_t		*work_wprec(wchar_t *str, int prec)
{
	int		steps;
	int		i;
	wchar_t	*new;
	int		j;

	i = 0;
	j = 0;
	steps = ft_wstrlen(str);
	if (prec == 0)
		prec = steps + 2;
	else if (prec < 0)
		return ((wchar_t*)("\0\0\0\0\0\0\0"));
	new = (wchar_t*)malloc(sizeof(wchar_t) * prec + 1);
	while (((i + get_wchar_len(str[i]) <= prec && get_wchar_len(str[i]) <= 1)
				|| (i + get_wchar_len(str[i]) < prec && get_wchar_len(str[i])
					> 1)) && i < steps)
	{
		new[j] = (wchar_t)(str[j]);
		i += get_wchar_len(new[j]);
		j++;
	}
	new[j] = L'\0';
	return (new);
}

int			remaining_width_w(wchar_t *new, t_content *cont)
{
	int		counter;
	int		i;

	counter = 0;
	i = counter;
	while (new[i])
	{
		counter += get_wchar_len(new[i]);
		i++;
	}
	counter = cont->width_value - counter;
	if (counter > 0)
		return (counter);
	else
		return (0);
}

void		process_upper_s(va_list ap, int *bytes, t_content *cont)
{
	wchar_t		*text;
	int			i;
	wchar_t		*new;

	i = 0;
	text = va_arg(ap, wchar_t *);
	flags_init_for_cc(&cont);
	if (text == NULL)
		print_wnull(work_precision("(null)", cont->precision_value),
				cont, bytes);
	else
	{
		new = work_wprec(text, cont->precision_value);
		cont->precision_value = 0;
		cont->width_value = remaining_width_w(new, cont);
		if (!cont->flags->minus)
			print_signed_d("", bytes, cont);
		while (new[i])
		{
			ft_putwchar(new[i]);
			*bytes += get_wchar_len(new[i++]);
		}
		if (cont->flags->minus)
			print_signed_d("", bytes, cont);
	}
}

void		process_ss(va_list ap, int *bytes, t_content *cont)
{
	char	*str;

	flags_init_for_cc(&cont);
	if (!cont->lenmod)
	{
		str = va_arg(ap, char *);
		if (!str)
			str = ft_strdup("(null)");
		if (cont->precision_value == -1)
			str = ft_strdup("");
		else
			str = work_precision(str, cont->precision_value);
		cont->precision_value = 0;
		print_signed_d(str, bytes, cont);
	}
	else
		process_upper_s(ap, bytes, cont);
}
