/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf11.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 15:22:29 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 16:35:55 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*treat_conv_s(va_list ap, t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	str = ft_strdup(va_arg(ap, char *));
	str = treat_options(str, opt, c[*i], 0);
	return (str);
}

wchar_t	*treat_conv_big_s(va_list ap, t_specs opt, char *c, int *i)
{
	wchar_t *wstr;

	wstr = NULL;
	wstr = ft_wstrdup(va_arg(ap, wchar_t *));
	wstr = wtrt_opt(wstr, opt, c[*i], 0);
	return (wstr);
}

char	*treat_conv_pourcent(t_specs opt, char *c, int *i)
{
	char *str;

	str = NULL;
	str = ft_strdup("%");
	str = treat_options(str, opt, c[*i], 0);
	return (str);
}

char	*treat_else(t_specs opt, char *c, int *i)
{
	char *str;

	str = (char *)malloc(sizeof(char) * 2);
	str[0] = c[*i];
	str[1] = '\0';
	str = treat_options(str, opt, c[*i], 0);
	return (str);
}

char	*ft_option_c(va_list ap)
{
	char *str;

	str = (char*)malloc(sizeof(char) * 2);
	str[0] = va_arg(ap, int);
	str[1] = '\0';
	return (str);
}
