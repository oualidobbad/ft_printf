/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:23:22 by oobbad            #+#    #+#             */
/*   Updated: 2024/11/29 10:45:52 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printss(char c, va_list list)
{
	int	count;

	count = 0;
	if (c == 's')
		count += ft_putstr(va_arg(list, char *));
	else if (c == 'c')
		count += ft_putchar(va_arg(list, int));
	else if (c == '%')
		count += ft_putchar('%');
	else if (c == 'd' || c == 'i')
		count += ft_putnbr(va_arg(list, int));
	else if (c == 'x' || c == 'X')
		count += ft_puthex(va_arg(list, unsigned int), c);
	else if (c == 'p')
		count += ft_puthex(va_arg(list, unsigned long), c);
	else if (c == 'u')
		count += ft_putnbr_uns(va_arg(list, unsigned long));
	return (count);
}

int	ft_printf(const char *last_fixed, ...)
{
	va_list	list;
	int		i;
	int		count;

	if (!last_fixed)
	{
		return (write(1, "", 1) - 2);
	}
	va_start(list, last_fixed);
	i = 0;
	count = 0;
	while (last_fixed[i])
	{
		if (last_fixed[i] == '%')
		{
			count += printss(last_fixed[i + 1], list);
			i++;
		}
		else
			count += ft_putchar(last_fixed[i]);
		i++;
	}
	va_end(list);
	return (count);
}
