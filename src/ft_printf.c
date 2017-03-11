/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:50:28 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/11 16:52:59 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_descriptor_len(char *s)
{
	int		i;

	i = 0;
	while (ft_strchr(FLAGS, s[i]))
		i++;
	while (ft_strchr(FIELD_WIDTH, s[i]))
		i++;
	while (ft_strchr(FLAGS, s[i]))
		i++;
	while (ft_strchr(PRECISION, s[i]) || ft_strchr(FLAGS, s[i]))
		i++;
	while (ft_strstr(HH, (s + i)) || ft_strstr(LL, (s + i)))
		i += 2;
	while (ft_strchr(L_MODIFIERS, s[i]))
		i++;
	return (i + 2);
}

int		check_color2(char *fmt, int *i)
{
	int		init;

	init = *i;
	if (!ft_strncmp(fmt + *i, "yellow", 6) && fmt[*i + 6] == '%')
	{
		ft_putstr(YELLOW);
		*i += 6;
	}
	else if (!ft_strncmp(fmt + *i, "white", 5) && fmt[*i + 5] == '%')
	{
		ft_putstr(WHITE);
		*i += 5;
	}
	else if (!ft_strncmp(fmt + *i, "magenta", 7) && fmt[*i + 7] == '%')
	{
		ft_putstr(MAGENTA);
		*i += 7;
	}
	else if (!ft_strncmp(fmt + *i, "normal", 6) && fmt[*i + 6] == '%')
	{
		ft_putstr(NORMAL);
		*i += 6;
	}
	return (*i - init);
}

int		check_color(char *fmt, int *i, int init)
{
	init = *i;
	if (!ft_strncmp(fmt + *i, "red", 3) && fmt[*i + 3] == '%')
	{
		ft_putstr(RED);
		*i += 3;
	}
	else if (!ft_strncmp(fmt + *i, "blue", 4) && fmt[*i + 4] == '%')
	{
		ft_putstr(BLUE);
		*i += 4;
	}
	else if (!ft_strncmp(fmt + *i, "cyan", 4) && fmt[*i + 4] == '%')
	{
		ft_putstr(CYAN);
		*i += 4;
	}
	else if (!ft_strncmp(fmt + *i, "green", 5) && fmt[*i + 5] == '%')
	{
		ft_putstr(GREEN);
		*i += 5;
	}
	else
		return (check_color2(fmt, i));
	return (*i - init);
}

int		ft_process_format(va_list ap, char *fmt, char *descriptor)
{
	int		i;
	int		bytes;
	int		len;

	i = 0;
	bytes = 0;
	len = 1;
	while (fmt[i])
		if (fmt[i] == '%')
		{
			if (fmt[i + 1] != 0)
				len = get_descriptor_len(fmt + i + 1);
			descriptor = ft_strsub(fmt, i, len);
			if (ft_strchr(SPECIFIERS, descriptor[len - 1]))
				process_desc(descriptor, ap, &bytes);
			else if (len > 1)
				process_invalid(descriptor, &bytes);
			i += len;
		}
		else if (!check_color(fmt, &i, len))
		{
			ft_putchar(fmt[i++]);
			bytes++;
		}
	return (bytes);
}

int		ft_printf(char *fmt, ...)
{
	va_list ap;
	int		bytes;
	char	*descriptor;

	descriptor = NULL;
	bytes = 0;
	va_start(ap, fmt);
	bytes = ft_process_format(ap, fmt, descriptor);
	va_end(ap);
	return (bytes);
}
