/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf12.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 16:18:05 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 16:52:31 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		opt2(t_specs opt, char *c, int *i, char **str)
{
	if (*str[0] == 0)
	{
		if (!(opt.flags & 0x04))
		{
			*str = treat_options(*str, opt, c[*i], 1);
			ft_putstr(*str);
		}
		ft_putchar(0);
		if (opt.flags & 0x04)
		{
			*str = treat_options(*str, opt, c[*i], 1);
			ft_putstr(*str);
		}
		(*i)++;
		return (ft_strlen(*str) + 1);
	}
	else
		*str = treat_options(*str, opt, c[*i], 0);
	return (0);
}

wchar_t	*ft_option_big_c(va_list ap)
{
	wchar_t *wstr;

	wstr = (wchar_t*)malloc(sizeof(wchar_t) * 2);
	wstr[0] = va_arg(ap, int);
	wstr[1] = '\0';
	return (wstr);
}

int		ft_option_big_c2(t_specs opt, char *c, int *i, wchar_t **wstr)
{
	if (*wstr[0] == 0)
	{
		if (!(opt.flags & 0x04))
		{
			*wstr = wtrt_opt(L"", opt, c[*i], 1);
			ft_wputstr(*wstr);
		}
		ft_putchar(0);
		if (opt.flags & 0x04)
		{
			*wstr = wtrt_opt(L"", opt, c[*i], 1);
			ft_wputstr(*wstr);
		}
		(*i)++;
		return (ft_wstrlen(*wstr) + 1);
	}
	else
		*wstr = wtrt_opt(*wstr, opt, c[*i], 0);
	return (0);
}

void	split_if(char *str, int **i)
{
	if (str)
	{
		ft_putstr(str);
		(**i)++;
	}
}

int		split_if2(wchar_t **wstr, int *i)
{
	if (*wstr)
	{
		ft_wputstr(*wstr);
		(*i)++;
		return (ft_wstrlen(*wstr));
	}
	return (0);
}
