/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf8.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 00:12:55 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 16:59:04 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*treat_conv_p(va_list ap, t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	str = ft_strdup(ft_strjoin("0x",
			convertion_base(16, va_arg(ap, unsigned long long int), "", 0)));
	if (!opt.largeur && !opt.precision && !ft_strcmp(str, "0x0"))
		str = ft_strdup("0x");
	else
	{
		if (!ft_strcmp(str, "0x0") && !opt.precision)
			str = ft_strdup("0x");
		if (opt.precision == 0)
			opt.precision = 2;
		str = treat_options(str, opt, c[*i], 0);
	}
	return (str);
}

char	*treat_conv_big_d(va_list ap, t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	if (opt.modif & 0x01)
		str = ft_ltoa((long int)va_arg(ap, long long int));
	else
		str = ft_ltoa(va_arg(ap, long int));
	str = treat_options(str, opt, c[*i], 0);
	return (str);
}

char	*treat_conv_d(va_list ap, t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	if (opt.modif & 0x04)
		str = ft_ltoa(va_arg(ap, long));
	else if (opt.modif >= 8)
		str = ft_ltoa(va_arg(ap, long long));
	else if (opt.modif & 0x02)
		str = ft_itoa((char)va_arg(ap, int));
	else if (opt.modif & 0x01)
		str = ft_itoa((short)va_arg(ap, int));
	else
		str = ft_itoa(va_arg(ap, int));
	str = treat_options(str, opt, c[*i], 0);
	return (str);
}

char	*treat_conv_g(va_list ap, t_specs opt, char *c, int *i)
{
	double			f;
	long long int	ent;
	long long int	dec;
	char			*str;

	str = NULL;
	f = va_arg(ap, double);
	ent = (long long int)f;
	dec = (long long int)((f - (long long int)f) * 10000000);
	dec /= 10;
	if (dec < 0)
		dec = -dec;
	if ((dec & 0xF) >= 10)
		dec += 1;
	str = ft_strjoin(ft_ltoa(ent), ".");
	str = ft_strjoin(str, ft_ltoa(dec));
	str = treat_options(str, opt, c[*i], 0);
	return (str);
}

char	*treat_conv_e(va_list ap, t_specs opt, char *c, int *i)
{
	double			f;
	long long int	ent;
	long long int	dec;
	char			*str;

	str = NULL;
	f = va_arg(ap, double);
	ent = (long long int)f;
	dec = (long long int)((f - (long long int)f) * 10000000);
	dec /= 10;
	if (dec < 0)
		dec = -dec;
	if ((dec & 0xF) >= 10)
		dec += 1;
	str = ft_strjoin(ft_ltoa(ent), ".");
	str = ft_strjoin(str, ft_ltoa(dec));
	str = treat_options(str, opt, c[*i], 0);
	if (c[*i] == 'e')
		str = ft_strjoin(str, "e+00");
	else
		str = ft_strjoin(str, "E+00");
	return (str);
}
