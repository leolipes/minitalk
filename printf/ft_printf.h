/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 12:07:42 by leolipes          #+#    #+#             */
/*   Updated: 2022/02/09 16:41:50 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int		ft_printf(const char *input, ...);
int		ft_check_flags(char c, va_list args);
int		ft_flag_u(unsigned int nbr);
int		ft_hexaux(size_t nb, char *base);
int		ft_puthexa(unsigned int nb, char *base);
int		ft_pointer(void *ptr);
int		ft_putnbr(int nb);
int		ft_putchar(char c);
int		ft_putstr(char *s);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlen(const char *str);

#endif