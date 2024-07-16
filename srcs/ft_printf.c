/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelat <adelat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 13:18:22 by adelat            #+#    #+#             */
/*   Updated: 2024/07/16 22:46:47 by adelat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_percent(va_list args, char c)
{
	int	rvalue;
	
	rvalue = 0;
	if (c == 'c')
		rvalue = ft_putchar(va_arg(args, int));
	else if (c == 's')
		rvalue = ft_putstr(va_arg(args, char *));
	else if (c == 'p')
		rvalue = ft_print_ptr(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		rvalue = ft_putnbr(va_arg(args, int), 0);
	else if (c == 'u')
		rvalue = ft_uputnbr(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		rvalue = ft_puthexa(va_arg(args, unsigned int), c, 0);
	else if (c == '%')
	{
		write(1, "%", 1);
		rvalue += 1;
	}
	return rvalue;
}

int	ft_printf(const char *str, ...)
{
	va_list args;
	int		i;
	int		rvalue;

	va_start(args, str);
	rvalue = 0;
	i = 0;
	while(str[i])
	{
		if (str[i] == '%')
		{
			rvalue += ft_percent(args, str[i + 1]);
			i = i + 2;
		}
		else
		{
			write(1, &str[i], 1);
			rvalue += 1;
			i++;
		}
	}
}