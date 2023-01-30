/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:03:11 by gcamargo          #+#    #+#             */
/*   Updated: 2022/07/26 22:21:34 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

int	ft_printf(const char *str, ...);
int	ft_putstr(char *s);
int	ft_putchar(char c);
int	ft_printf_c(char c);
int	ft_printf_s(char *str);
int	ft_printf_d_and_i(int num);
int	ft_printf_u(unsigned int num);
int	ft_printf_lower_x(unsigned long int num);
int	ft_printf_upper_x(unsigned long int num);
int	ft_printf_p(unsigned long int num);

#endif