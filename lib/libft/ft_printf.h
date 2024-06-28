/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 16:50:23 by daspring          #+#    #+#             */
/*   Updated: 2024/04/01 21:59:14 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>

int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(char *s);
int		ft_putnbr(int n);
int		ft_putuint(unsigned int n);
int		ft_puthexa(unsigned int n);
int		ft_puthexa_upper_case(unsigned int n);
int		ft_putpointer(unsigned long n);
size_t	ft_strlen(const char *s);
int		put_to_screen(char *c, int *counter);
int		power_of_ten(int pow);

#endif
