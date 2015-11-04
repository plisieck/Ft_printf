/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/08 18:49:18 by plisieck          #+#    #+#             */
/*   Updated: 2015/02/08 18:49:20 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_wstrlen(wchar_t *str)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (str[i])
	{
		j = ft_strlen(convertion_base(2, str[i], "", 0));
		if (j <= 7)
			k += 1;
		else if (j <= 11)
			k += 2;
		else if (j <= 16)
			k += 3;
		else
			k += 4;
		i++;
	}
	return (k);
}
