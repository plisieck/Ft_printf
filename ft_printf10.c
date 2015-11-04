/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf10.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 14:48:33 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 16:35:23 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*treat_conv_k(va_list ap)
{
	struct tm	*dt;
	char		b[11];
	time_t		ts;
	char		*str;

	str = NULL;
	ts = va_arg(ap, int);
	dt = localtime(&ts);
	strftime(b, sizeof(b), "%d/%m/20%y", dt);
	str = ft_strdup(b);
	return (str);
}

char	*treat_conv_q(va_list ap, t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	str = ft_strdup(convertion_base(4, va_arg(ap, int), "", 0));
	str = treat_options(str, opt, c[*i], 0);
	return (str);
}

char	*treat_conv_t(va_list ap, t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	str = ft_strdup(convertion_base(3, va_arg(ap, int), "", 0));
	str = treat_options(str, opt, c[*i], 0);
	return (str);
}

char	*treat_conv_big_q(va_list ap, t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	str = ft_strdup(convertion_base(5, va_arg(ap, int), "", 0));
	str = treat_options(str, opt, c[*i], 0);
	return (str);
}

char	*treat_conv_f(va_list ap, t_specs opt, char *c, int *i)
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
