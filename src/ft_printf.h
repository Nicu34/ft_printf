/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmuresan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 16:51:52 by nmuresan          #+#    #+#             */
/*   Updated: 2016/03/12 19:43:16 by nmuresan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FT_PRINTF_H
# define __FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include "libft/libft.h"
# include <stdio.h>
# define FLAGS "#0-+ "
# define SPECIFIERS "frbBndiouxXcspSCDUO%"
# define PRECISION ".0123456789-*"
# define FIELD_WIDTH "0123456789*"
# define L_MODIFIERS "hljz"
# define HH "hh"
# define LL "ll"
# define RED "\x1b[31m"
# define GREEN "\x1b[32m"
# define YELLOW "\x1b[33m"
# define BLUE	"\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN	"\x1b[36m"
# define WHITE	"\x1b[37m"
# define NORMAL "\x1b[0m"

typedef struct				s_flg
{
	int						diez;
	int						zero;
	int						minus;
	int						plus;
	int						space;
}							t_flg;

typedef struct				s_content
{
	t_flg					*flags;
	char					*lenmod;
	int						precision_value;
	int						width_value;
}							t_content;

typedef struct				s_dconversion
{
	char					schar;
	short					shortint;
	long					longint;
	long long				llint;

	intmax_t				intmax;
	size_t					sizet;
}							t_dconversion;

typedef struct				s_ouxxconv

{
	unsigned char			uchar;
	unsigned short			ushortint;
	unsigned long			ulongint;
	unsigned long long		ullint;
	uintmax_t				uintmax;
	size_t					sizet;
}							t_ouxxconv;

typedef struct				s_flot
{
	float					simple;
	long double				fldouble;
}							t_flot;

typedef	struct				s_print
{
	char					*sign;
	char					*string;
	char					*prec;
	char					*wbefore;
	char					*wafter;
}							t_print;

int							ft_printf(char *fmt, ...);

void						init_flags(t_flg	**flags);
int							value_of(int precision, int number);
char						*ft_itoa_base(long long number, long long base,
		char *tab);
char						*ft_utoa_base(unsigned long long number,
		long long base, char *tab);

void						process_desc(char *desc, va_list ap, int *bytes);
void						process_invalid(char *desc, int *bytes);
int							get_descriptor_len(char *s);
int							ft_process_format(va_list ap, char *fmt,
		char *descriptor);
int							ft_abs(int n);

t_flg						*set_all_flags(char *desc);
int							set_fieldwidth(char *desc, va_list ap);
int							set_precision(char *desc, va_list ap);
char						*set_lenmodifier(char *desc);
t_content					*set_content(char *desc, va_list ap);

void						process_d(va_list ap, int *bytes, t_content *cont);
void						process_d_with_len_2(va_list ap, int *bytes,
		t_content *cont, char *str);
void						print_d(char *str, int *bytes, t_content *cont);
void						process_d_with_len(va_list ap, int *bytes,
		t_content *cont);
void						init_print_structure(t_print *prt);
void						print_shit(t_print *prt, int *bytes);
void						print_signed_d(char *str, int *bytes,
		t_content *cont);
void						set_flag(t_flg *flags, char c);
void						unset_flags_unsigned(t_flg *flags);
void						process_xx(char conv, va_list ap, int *bytes,
		t_content *cont);
void						process_xx_with_len(char *tab, va_list ap,
		int *bytes, t_content *cont);

void						process_uu(va_list ap, int *bytes,
		t_content *cont);
void						process_uu_with_len(char *tab, va_list ap,
		int *bytes, t_content *cont);

void						process_oo(va_list ap, int *bytes,
		t_content *cont);
void						process_oo_with_len(char *tab, va_list ap,
		int *bytes, t_content *cont);
char						*process_oo_with_len_2(char *tab, va_list ap,
		t_content *cont, t_ouxxconv *n);
char						*do_octal_diez(char *str, int diez);
char						*do_hexa_diez(char *str, int diez, char conv,
		int *bytes);

void						process_cc(unsigned char conv, va_list ap,
		int *bytes, t_content *cont);
void						process_upper_c(va_list ap, int *bytes,
		t_content *cont);

void						flags_init_for_cc(t_content **cont);

void						process_p(va_list ap, int *bytes,
		t_content *cont);
void						process_p_2(int *bytes, t_content *cont,
		char *str);
char						*work_precision(char *string, int prec);
void						process_ss(va_list ap, int *bytes,
		t_content *cont);
void						ft_putwchar(wchar_t chr);
int							get_wchar_len(wchar_t chr);
void						process_upper_c(va_list ap, int *bytes,
		t_content *cont);
unsigned int				ft_wstrlen(wchar_t *str);
wchar_t						*work_wprec(wchar_t *str, int prec);
void						process_upper_s(va_list ap, int *bytes,
		t_content *cont);
void						process_n(va_list ap, int *bytes);
void						process_b(va_list ap, int *bytes, t_content *cont);
void						process_r(va_list ap, int *bytes, t_content *cont);
void						print_wnull(char *str, t_content *cont, int *bytes);
void						ft_putwstr(wchar_t *str, int *bytes);
void						process_desc_2(char *desc, va_list ap, int *bytes,
		t_content *new);
int							prec_pos(char *desc);
t_print						*set_len_prec2(t_print *prt, char padd,
		t_content *cont);

#endif
