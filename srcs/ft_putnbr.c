/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelat <adelat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:11:59 by adelat            #+#    #+#             */
/*   Updated: 2024/07/16 22:50:07 by adelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb, int rvalue)
{
	char c;

	if (nb < 0)
	{
		write(1, "-", 1);
		nb = nb * -1;
		rvalue++;
	}
	if (nb / 10 != 0)
		rvalue = ft_putnbr(nb / 10, rvalue);
	c = (nb % 10) + '0';
	write(1, &c, 1);
	rvalue++;
	return rvalue;
}