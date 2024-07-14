/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelat <adelat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:18:22 by adelat            #+#    #+#             */
/*   Updated: 2024/07/14 14:57:39 by adelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(va_list args, char c)
{
	int	rvalue;
	
	rvalue = 0;
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == 's')
		ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int));
	else if (c == 'u')
		ft_uputnbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		ft_puthexa(va_arg(args, unsigned int), c);
	else if (c == '%')
		write(1, "%", 1);
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		i;
	int		rvalue;

	va_start(args, str);
	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			rvalue += ft_percent(args, str[i + 1]);
			i = i + 2;
		}
	}
}