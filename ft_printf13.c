/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf13.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 16:47:16 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 17:41:45 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*treat_convs2(va_list ap, t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	if (c[*i] == 'b')
		str = treat_conv_b(ap, opt, c, i);
	else if (c[*i] == 'k')
		str = treat_conv_k(ap);
	else if (c[*i] == 'q')
		str = treat_conv_q(ap, opt, c, i);
	else if (c[*i] == 't')
		str = treat_conv_t(ap, opt, c, i);
	else if (c[*i] == 'Q')
		str = treat_conv_big_q(ap, opt, c, i);
	else if (c[*i] == 'f' || c[*i] == 'F')
		str = treat_conv_f(ap, opt, c, i);
	else if (c[*i] == 'e' || c[*i] == 'E')
		str = treat_conv_e(ap, opt, c, i);
	else if (c[*i] == 'g' || c[*i] == 'G')
		str = treat_conv_g(ap, opt, c, i);
	else if (c[*i] == 'd' || c[*i] == 'i')
		str = treat_conv_d(ap, opt, c, i);
	return (str);
}

char	*treat_convs3(va_list ap, t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	if (c[*i] == 'D')
		str = treat_conv_big_d(ap, opt, c, i);
	else if (c[*i] == 'p')
		str = treat_conv_p(ap, opt, c, i);
	else if (c[*i] == 'o')
		str = treat_conv_o(ap, opt, c, i);
	return (str);
}

char	*treat_convs(va_list ap, t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	if (verif_str("bkqtQfFeEgGdi", c[*i]))
		str = treat_convs2(ap, opt, c, i);
	else if (verif_str("Dpo", c[*i]))
		str = treat_convs3(ap, opt, c, i);
	else if (c[*i] == 'O')
		str = treat_conv_big_o(ap, opt, c, i);
	else if (c[*i] == 'u')
		str = treat_conv_u(ap, opt, c, i);
	else if (c[*i] == 'U')
		str = ft_strdup(convertion_base(10,
		va_arg(ap, unsigned long long int), "", 0));
	else if (c[*i] == 'x')
		str = treat_conv_x(ap, opt, c, i);
	else if (c[*i] == 'X')
		str = treat_conv_big_x(ap, opt, c, i);
	else if (c[*i] == '%')
		str = treat_conv_pourcent(opt, c, i);
	return (str);
}
