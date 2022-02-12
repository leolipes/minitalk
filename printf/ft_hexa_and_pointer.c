/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_and_pointer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolipes <leolipes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:55:33 by leolipes          #+#    #+#             */
/*   Updated: 2021/09/13 15:55:50 by leolipes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexaux(size_t nb, char *base)
{
	int		quantchar;

	quantchar = 0;
	if (nb >= 16)
		quantchar += ft_hexaux(nb / 16, base);
	quantchar += ft_putchar((char)(base[nb % 16]));
	return (quantchar);
}

int	ft_puthexa(unsigned int nb, char *base)
{
	return (ft_hexaux(nb, base));
}

int	ft_pointer(void *ptr)
{
	int	quantchar;

	quantchar = 0;
	quantchar += write (1, "0x", 2);
	quantchar += ft_hexaux((size_t)ptr, "0123456789abcdef");
	return (quantchar);
}
