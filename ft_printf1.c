/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 20:16:57 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 16:56:29 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	check_modificator(const char *format, int *i, char *c)
{
	while (format[*i] && verif_str("hljz", format[*i]))
	{
		if (format[*i] == 'z')
		{
			(*i)++;
			*c |= 0x20;
			return ;
		}
		else if (format[*i] == 'j' && !(*c & 0x20))
		{
			(*i)++;
			*c |= 0x10;
			return ;
		}
		else if (format[*i] == 'l' && !(*c & 0x20) && !(*c & 0x10))
			return (check_modificator1(format, i, c));
		else if (format[*i] == 'h' && !(*c & 0x20) &&
				!(*c & 0x10) && !(*c & 0x08) && !(*c & 0x04))
			return (check_modificator2(format, i, c));
		(*i)++;
	}
}

int		check_larg(va_list ap, const char *format, int *i, char *flags)
{
	char	*str;
	int		larg;

	str = ft_strnew(0);
	while (format[*i] && (verif_str("0123456789", format[*i]) ||
				format[*i] == '*'))
	{
		str = ft_strminijoin(str, format[*i]);
		if (format[*i] == '*' && format[*i - 1] != '.')
		{
			(*i)++;
			larg = va_arg(ap, int);
			if (larg < 0)
			{
				larg = -larg;
				*flags &= 0x17;
				*flags |= 0x04;
			}
			return (larg);
		}
		(*i)++;
	}
	return (ft_atoi(str));
}

int		check_precision(va_list ap, const char *format, int *i)
{
	char	*str;
	int		prec;

	str = ft_strnew(0);
	while (format[*i] && (verif_str("0123456789", format[*i]) ||
				format[*i] == '*'))
	{
		str = ft_strminijoin(str, format[*i]);
		if (format[*i] == '*')
		{
			(*i)++;
			prec = va_arg(ap, int);
			if (prec < 0)
				prec = -1;
			return (prec);
		}
		(*i)++;
	}
	return (ft_atoi(str));
}

t_specs	init_structure(t_specs opt)
{
	opt.flags = 0;
	opt.largeur = 0;
	opt.precision = -1;
	opt.modif = 0;
	return (opt);
}

wchar_t	*ft_wstrncpy(wchar_t *dst, wchar_t *src, size_t n)
{
	unsigned int	i;
	int				j;
	size_t			k;

	i = -1;
	k = 0;
	while (src[++i])
	{
		j = ft_strlen(convertion_base(2, src[i], "", 0));
		if (j <= 7)
			k += 1;
		else if (j <= 11)
			k += 2;
		else if (j <= 16)
			k += 3;
		else
			k += 4;
		if (k > n)
			break ;
		dst[i] = src[i];
	}
	while (++i < n)
		dst[i] = '\0';
	return (dst);
}
