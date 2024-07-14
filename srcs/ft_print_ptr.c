/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelat <adelat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:07:59 by adelat            #+#    #+#             */
/*   Updated: 2024/07/14 14:55:54 by adelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_uputhexa(uintptr_t nb, char h)
{
	char c;

	if (nb / 16 != 0)
		ft_puthexa(nb / 16, h);
	if (nb % 16 < 10)
		c = (nb % 16) + '0';
	else if (nb % 16 >= 10 && h == 'x')
		c = (nb % 16) + 'a' - 10;
	else if (nb % 16 >= 10 && h == 'X')
		c = (nb % 16) + 'A' - 10;
	write(1, &c, 1);
}

void	ft_print_ptr(unsigned long long *ptr)
{
	if (ptr)
	{
		write(1, "0x", 2);
		ft_uputhexa(ptr, 'x');
	}
	else
		write(1, "0", 1);
}