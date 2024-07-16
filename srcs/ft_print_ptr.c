/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelat <adelat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:07:59 by adelat            #+#    #+#             */
/*   Updated: 2024/07/16 22:39:57 by adelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_uputhexa(uintptr_t nb, char h, int rvalue)
{
	char c;

	if (nb / 16 != 0)
		rvalue += ft_puthexa(nb / 16, h, rvalue);
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

int	ft_print_ptr(unsigned long long *ptr)
{
	int	rvalue;

	rvalue = 0;
	if (ptr)
	{
		write(1, "0x", 2);
		rvalue = ft_uputhexa(ptr, 'x', 0);
		rvalue += 2;
	}
	else
	{
		write(1, "0", 1);
		rvalue++;
	}
	return rvalue;
}