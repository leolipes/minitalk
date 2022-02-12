/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leolipes <leolipes@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 11:55:50 by leolipes          #+#    #+#             */
/*   Updated: 2021/09/13 12:07:25 by leolipes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i])
		i++;
	write(1, s, i);
	return (i);
}

size_t	ft_strlen(const char *str)
{
	size_t	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	if (!c)
		return (0);
	while (s[i] && s[i] != (unsigned char)c)
		i++;
	if (s[i] == (unsigned char)c)
		return ((char *)&s[i]);
	return (NULL);
}

int	ft_putnbr(int nb)
{
	unsigned int	nbr;
	int				quantchar;

	quantchar = 0;
	if (nb < 0)
	{
		quantchar += ft_putchar('-');
		nbr = (unsigned int)(nb * -1);
	}
	else
		nbr = (unsigned int)nb;
	if (nbr >= 10)
		quantchar += ft_putnbr(nbr / 10);
	quantchar += ft_putchar((char)(nbr % 10 + '0'));
	return (quantchar);
}
