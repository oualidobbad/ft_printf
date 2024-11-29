/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:23:17 by oobbad            #+#    #+#             */
/*   Updated: 2024/11/29 10:40:46 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
		return (write(1, "(null)", 6));
	i = 0;
	while (str[i])
	{
		i += ft_putchar(str[i]);
	}
	return (i);
}
// int main ()
// {
//     int i = ft_putstr("walid\n");
//     printf("%d", i);
// }