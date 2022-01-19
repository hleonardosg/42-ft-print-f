/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:35:40 by coder             #+#    #+#             */
/*   Updated: 2022/01/16 18:35:40 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print_hexa_p(unsigned long int nb)
{
	char	*base;
	char	temp[30];
	int		size;
	int		index;

	base = "0123456789abcdef";
	size = 0;
	index = 0;
	if (nb == 0)
		return (ft_putstr("(nil)"));
	while (nb > 0)
	{
		temp[index++] = base[nb % 16];
		nb /= 16;
		size++;
	}
	size += ft_putstr("0x");
	while (index-- > 0)
		ft_putchar(temp[index]);
	return (size);
}

static int	ft_print_decimal(unsigned long int nb)
{
	char	*base;
	char	temp[30];
	int		size;
	int		index;

	base = "0123456789";
	size = 0;
	index = 0;
	while (nb > 0)
	{
		temp[index++] = base[nb % 10];
		nb /= 10;
		size++;
	}
	while (index-- > 0)
		ft_putchar(temp[index]);
	return (size);
}

static int	ft_print_hexa(unsigned long int nb, const char format)
{
	char	*base;
	char	temp[30];
	int		size;
	int		index;

	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	size = 0;
	index = 0;
	if (nb == 0)
		return (ft_putstr("(nil)"));
	while (nb > 0)
	{
		temp[index++] = base[nb % 16];
		nb /= 16;
		size++;
	}
	while (index-- > 0)
		ft_putchar(temp[index]);
	return (size);
}

static int	ft_printf_args(const char *format, va_list args, int size)
{
	while (*format)
	{
		if (*format == '%')
		{
			if (*++format == 'c')
				size += ft_putchar(va_arg(args, int));
			else if (*format == 's')
				size += ft_putstr(va_arg(args, char *));
			else if (*format == 'd' || *format == 'i')
				size += ft_putnbr(va_arg(args, int));
			else if (*format == 'u')
				size += ft_print_decimal(va_arg(args, unsigned int));
			else if (*format == 'x' || *format == 'X')
				size += ft_print_hexa(va_arg(args, unsigned int), *format);
			else if (*format == 'p')
				size += ft_print_hexa_p(va_arg(args, unsigned int));
			else
				size += ft_putchar(*format);
			format++;
		}
		else
			size += ft_putchar(*format++);
	}
	return (size);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;

	va_start(args, format);
	size = 0;
	size = ft_printf_args(format, args, size);
	va_end(args);
	return (size);
}
