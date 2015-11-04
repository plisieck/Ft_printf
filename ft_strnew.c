/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 23:00:21 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 18:48:31 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*str;

	if (size >= 4294967296)
		return (NULL);
	str = ft_memalloc(size + 1);
	if (!str)
		return (NULL);
	return (str);
}
