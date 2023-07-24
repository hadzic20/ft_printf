/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadzic <ahadzic@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:19:46 by ahadzic           #+#    #+#             */
/*   Updated: 2022/08/06 20:19:48 by ahadzic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_char(int c)
{
	return (write(1, &c, 1));
}

int	ft_put_string(const char *s)
{
	int	i;

	i = 0;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
		i++;
	write(1, s, i);
	return (i);
}

int	ft_select(va_list args, const char mode)
{
	int	length;

	length = 0;
	if (mode == 'c')
		length = ft_put_char(va_arg(args, int));
	else if (mode == 's')
		length = ft_put_string(va_arg(args, const char *));
	else if (mode == 'p')
		length = ft_put_pointer(va_arg(args, unsigned long long));
	else if (mode == 'd' || mode == 'i')
		length = ft_put_number(va_arg(args, int));
	else if (mode == 'u')
		length = ft_put_unsigned(va_arg(args, unsigned int));
	else if (mode == 'x' || mode == 'X')
		length = ft_put_hexadecimal(va_arg(args, int), mode);
	else if (mode == '%')
		length = ft_put_char('%');
	return (length);
}

int	ft_printf(const char *a, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	va_start(args, a);
	while (a[i] != '\0')
	{
		if (a[i] != '%')
			length += ft_put_char(a[i++]);
		else
		{
			length += ft_select(args, a[++i]);
			i++;
		}
	}
	va_end(args);
	return (length);
}
