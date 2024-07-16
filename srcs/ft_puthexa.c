/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelat <adelat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:37:00 by adelat            #+#    #+#             */
/*   Updated: 2024/07/16 22:47:08 by adelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthexa(unsigned int nb, char h, int rvalue)
{
	char c;

	if (nb / 16 != 0)
		rvalue = ft_puthexa(nb / 16, h);
	if (nb % 16 < 10)
		c = (nb % 16) + '0';
	else if (nb % 16 >= 10 && h == 'x')
		c = (nb % 16) + 'a' - 10;
	else if (nb % 16 >= 10 && h == 'X')
		c = (nb % 16) + 'A' - 10;
	write(1, &c, 1);
	rvalue++;
	return rvalue;
}