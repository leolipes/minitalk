/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolipes <leolipes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:59:30 by leolipes          #+#    #+#             */
/*   Updated: 2021/09/13 15:59:18 by leolipes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_flag_u(unsigned int nbr)
{
	int	quantchar;

	quantchar = 0;
	if (nbr >= 10)
		quantchar += ft_putnbr(nbr / 10);
	quantchar += ft_putchar((char)(nbr % 10 + '0'));
	return (quantchar);
}

int	ft_check_flags(char c, va_list args)
{
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_flag_u(va_arg(args, int)));
	if (c == '%')
		return (ft_putchar(c));
	if (c == 'x')
		return (ft_puthexa(va_arg(args, int), "0123456789abcdef"));
	if (c == 'X')
		return (ft_puthexa(va_arg(args, int), "0123456789ABCDEF"));
	if (c == 'p')
		return (ft_pointer(va_arg(args, void *)));
	return (0);
}

int	ft_printf(const char *input, ...)
{
	va_list	args;
	size_t	count;
	int		quantchar;

	count = 0;
	quantchar = 0;
	va_start(args, input);
	while (input[count])
	{
		if (input[count] == '%' && ft_strchr("cspdiuxX%", input[count + 1]))
		{
			quantchar += ft_check_flags(input[++count], args);
			count++;
		}
		else
		{
			quantchar += ft_putchar(input[count]);
			count++;
		}
	}
	va_end (args);
	return (quantchar);
}
