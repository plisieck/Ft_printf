/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf7.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 23:45:28 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 16:58:29 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*treat_conv_o(va_list ap, t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	if (opt.modif & 0x02)
		str = ft_strdup(convertion_base(8,
					(unsigned char)va_arg(ap, unsigned long long int), "", 0));
	else if (opt.modif & 0x01)
		str = ft_strdup(convertion_base(8,
				(unsigned short)va_arg(ap, unsigned long long int), "", 0));
	else if ((opt.modif & 0x04) || (opt.modif & 0x08) ||
			(opt.modif & 0x10) || (opt.modif & 0x20))
		str = ft_strdup(convertion_base(8,
					va_arg(ap, unsigned long long int), "", 0));
	else
		str = ft_strdup(convertion_base(8, va_arg(ap, unsigned int), "", 0));
	if (ft_strcmp(str, "0") && opt.flags & 0x10)
		str = ft_strjoin("0", str);
	str = treat_options(str, opt, c[*i], 0);
	return (str);
}

char	*treat_conv_big_o(va_list ap, t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	str = ft_strdup(convertion_base(8,
				va_arg(ap, unsigned long long int), "", 0));
	if (ft_strcmp(str, "0") && opt.flags & 0x10)
		str = ft_strjoin("0", str);
	str = treat_options(str, opt, c[*i], 0);
	return (str);
}

char	*treat_conv_u(va_list ap, t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	if (opt.modif & 0x02)
		str = ft_strdup(convertion_base(10,
					(unsigned char)va_arg(ap, unsigned long long int), "", 0));
	else if (opt.modif & 0x01)
		str = ft_strdup(convertion_base(10,
					(unsigned short)va_arg(ap, unsigned long long int), "", 0));
	else if (opt.modif >= 0x04)
		str = ft_strdup(convertion_base(10,
					va_arg(ap, unsigned long int), "", 0));
	else
		str = ft_strdup(convertion_base(10, va_arg(ap, unsigned int), "", 0));
	str = treat_options(str, opt, c[*i], 0);
	return (str);
}

char	*treat_conv_x(va_list ap, t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	if (opt.modif & 0x02)
		str = ft_strdup(convertion_base(16,
					(unsigned char)va_arg(ap, unsigned long long int), "", 0));
	else if (opt.modif & 0x01)
		str = ft_strdup(convertion_base(16,
					(unsigned short)va_arg(ap, unsigned long long int), "", 0));
	else if (opt.modif >= 0x04)
		str = ft_strdup(convertion_base(16,
					va_arg(ap, unsigned long int), "", 0));
	else
		str = ft_strdup(convertion_base(16, va_arg(ap, unsigned int), "", 0));
	if (ft_strcmp(str, "0") && opt.flags & 0x10)
		str = ft_strjoin("0x", str);
	str = treat_options(str, opt, c[*i], 0);
	return (str);
}

char	*treat_conv_big_x(va_list ap, t_specs opt, char *c, int *i)
{
	char	*str;

	str = NULL;
	if (opt.modif & 0x02)
		str = ft_strdup(convertion_base(16,
					(unsigned char)va_arg(ap, unsigned int), "", 1));
	else if (opt.modif & 0x01)
		str = ft_strdup(convertion_base(16,
					(unsigned short)va_arg(ap, unsigned int), "", 1));
	else if (opt.modif >= 0x04)
		str = ft_strdup(convertion_base(16,
					va_arg(ap, unsigned long int), "", 1));
	else
		str = ft_strdup(convertion_base(16, va_arg(ap, unsigned int), "", 1));
	if (ft_strcmp(str, "0") && opt.flags & 0x10)
		str = ft_strjoin("0X", str);
	str = treat_options(str, opt, c[*i], 0);
	return (str);
}
