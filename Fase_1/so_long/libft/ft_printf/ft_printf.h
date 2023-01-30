/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamargo <gcamargo@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 19:37:36 by gcamargo          #+#    #+#             */
/*   Updated: 2023/01/06 19:37:38 by gcamargo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

char	*__getstr(char spec, va_list ap);
int		__sharp(const char **fmt, va_list ap);
int		__plus(const char **fmt, va_list ap);
int		__minus(const char **fmt, va_list ap);
int		__dot(const char **fmt, va_list ap);
int		__space(const char **fmt, va_list ap);
int		__zero(int n, const char **fmt, va_list ap);
int		__dot_dispatch(char spec, char *buff, va_list ap);
int		__minus_dispatch(char spec, char *buff, va_list ap);
int		__space_dispatch(char spec, char *buff, va_list ap);
int		__zero_dispatch(char spec, char *buff, va_list ap);
int		__spec_dispatch(char spec, va_list ap);
int		ft_printf(const char *fmt, ...);

#endif
