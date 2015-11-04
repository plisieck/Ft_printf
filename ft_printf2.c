/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/07 17:20:13 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 16:23:45 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		verif_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strminijoin(char const *s1, char c)
{
	char	*str;
	int		len;

	len = ft_strlen(s1) + 2;
	str = (char *)malloc(sizeof(char) * len);
	if (!str)
		return (NULL);
	ft_strcpy(str, s1);
	if (ft_strlen(str) == 0)
		str[0] = c;
	else
		str[ft_strlen(str)] = c;
	str[len] = '\0';
	return (str);
}

void	check_flags(const char *format, int *i, char *c)
{
	while (format[*i] && verif_str("#0-+ ", format[*i]))
	{
		if (format[*i] == '#')
			*c |= 0x10;
		else if (format[*i] == '0' && !(*c & 0x04))
			*c |= 0x08;
		else if (format[*i] == '-')
		{
			*c &= 0x17;
			*c |= 0x04;
		}
		else if (format[*i] == '+')
		{
			*c &= 0x1E;
			*c |= 0x02;
		}
		else if (format[*i] == ' ' && !(*c & 0x02))
			*c |= 0x01;
		(*i)++;
	}
}

void	check_modificator2(const char *format, int *i, char *c)
{
	(*i)++;
	if (format[*i] && format[*i] == 'h')
	{
		(*i)++;
		*c |= 0x02;
	}
	else if (!(*c & 0x02))
		*c |= 0x01;
}

void	check_modificator1(const char *format, int *i, char *c)
{
	(*i)++;
	if (format[*i] && format[*i] == 'l')
	{
		(*i)++;
		*c |= 0x08;
	}
	else if (!(*c & 0x08))
		*c |= 0x04;
}
