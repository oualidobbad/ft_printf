/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oobbad <oobbad@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 10:41:50 by oobbad            #+#    #+#             */
/*   Updated: 2024/11/29 10:54:58 by oobbad           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *last_fixed, ...);
int	ft_putstr(char *str);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_puthex(unsigned long n, char c);
int	ft_putnbr_uns(unsigned int n);
#endif