/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <coder@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 18:44:50 by coder             #+#    #+#             */
/*   Updated: 2022/01/16 20:24:28 by coder            ###   ########.fr       */
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
	int count;

	count = 0;
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int		ft_is_min_integer(int nb)
{
	if (nb == -2147483648)
	{
		nb++;
		return (1);
	}
	else
		return (0);
}

void	ft_print_values(char values[], int index, int negative_control)
{
	if (index < 0)
		index = 0;
	while (index >= 0)
	{
		if (index == 0 && negative_control == 1)
			values[index] = values[index] + 1;
		write(1, &values[index], 1);
		index--;
	}
}

int	ft_putnbr(int nb)
{
	char	result[10];
	int		index;
	int		negative_control;

	index = -1;
	negative_control = ft_is_min_integer(nb);
	if (nb < 0)
	{
		write(1, "-", 1);
		if (negative_control == 1)
			nb++;
		nb *= -1;
	}
	if (nb == 0)
		result[0] = (nb % 10) + 48;
	else
	{
		while (nb > 0)
		{
			index++;
			result[index] = (nb % 10) + 48;
			nb /= 10;
		}
	}
	ft_print_values(result, index, negative_control);
	return (index++);
}
