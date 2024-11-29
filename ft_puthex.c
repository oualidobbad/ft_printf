/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 17:42:51 by oobbad            #+#    #+#             */
/*   Updated: 2024/11/29 10:47:47 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	hex_low(unsigned long nb)
{
	char	*arr;
	char	q;
	int		count;

	arr = "0123456789abcdef";
	count = 0;
	if (nb >= 16)
	{
		count += hex_low(nb / 16);
	}
	q = arr[(nb % 16)];
	count += write(1, &q, 1);
	return (count);
}

static int	hex_up(unsigned long nb)
{
	char	*arr;
	char	q;
	int		count;

	arr = "0123456789ABCDEF";
	count = 0;
	if (nb >= 16)
	{
		count += hex_up(nb / 16);
	}
	q = arr[(nb % 16)];
	count += write(1, &q, 1);
	return (count);
}

int	ft_puthex(unsigned long n, char c)
{
	int	count;

	count = 0;
	if (c == 'X')
		count = hex_up(n);
	else if (c == 'p')
	{
		if (n == 0)
		{
			return (write(1, "(nil)", 5));
		}
		count = write(1, "0x", 2);
		count += hex_low(n);
	}
	else
		count = hex_low(n);
	return (count);
}

// int main()
// {
// 	int i = hex(255, 'x');
// 	printf("\n%d\n", i);
// 	// int j = printf("%x\n", 655);
// 	// printf("\n%d\n", 1);
// }