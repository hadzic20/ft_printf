/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadzic <ahadzic@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:14:02 by ahadzic           #+#    #+#             */
/*   Updated: 2022/08/06 19:14:09 by ahadzic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>

int	ft_put_char(int c);
int	ft_put_string(const char *s);
int	ft_put_number(int nb);
int	ft_put_unsigned(unsigned int nb);
int	ft_put_hexadecimal(unsigned int nb, const char mode);
int	ft_put_pointer(unsigned long long nb);
int	ft_select(va_list args, const char mode);
int	ft_printf(const char *a, ...);

#endif
