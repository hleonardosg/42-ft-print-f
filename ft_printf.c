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
#include <stdio.h>

static int ft_printf_args(const char *format, va_list args)
{
	int	size;

	size = 0;
	while(*format)
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
				size += ft_putnbr(va_arg(args, unsigned int));
			else
				size += ft_putchar(*format);
			*format++;
		}
		else
			size += ft_putchar(*format++);
	}
}

int ft_printf(const char *format, ...)
{
	va_list	args;
	int		size;

	va_start(args, format);
	size = 0;
	size = ft_printf_args(format, args);
	va_end(args);
	return (size);
}

int	main(void)
{
	ft_printf("Teste %u\n\n\n\n",-100);
	printf("Decimal:\t%u\n", 100);
	return (0);
}