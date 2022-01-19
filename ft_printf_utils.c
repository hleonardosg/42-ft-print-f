/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:44:50 by coder             #+#    #+#             */
/*   Updated: 2022/01/19 05:59:26 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	ft_is_min_integer(int nb)
{
	if (nb == -2147483648)
	{
		nb++;
		return (1);
	}
	else
		return (0);
}

int	ft_print_values(char values[], int index, int size)
{
	if (index < 0)
		index = 0;
	while (index >= 0)
	{
		write(1, &values[index], 1);
		index--;
		size++;
	}
	return (size);
}

int	ft_putnbr(int nb)
{
	char	result[10];
	int		index;
	int		size;

	index = -1;
	size = 0;
	if (nb < 0)
	{
		if (nb == -2147483648)
			return (write(1, "-2147483648", 11));
		write(1, "-", 1);
		size += 1;
		nb *= -1;
	}
	if (nb == 0)
		result[0] = (nb % 10) + 48;
	else
	{
		while (nb > 0)
		{
			result[++index] = (nb % 10) + 48;
			nb /= 10;
		}
	}
	return (ft_print_values(result, index, size));
}
