/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahadzic <ahadzic@42.tr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 19:12:30 by ahadzic           #+#    #+#             */
/*   Updated: 2022/08/06 19:13:00 by ahadzic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_number(int nb)
{
	int		i;
	int		length;
	char	a[11];

	length = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	if (nb == -2147483648)
		return (write(1, "-2147483648", 11));
	if (nb < 0)
	{
		length += write(1, "-", 1);
		nb *= -1;
	}
	i = 0;
	while (nb > 0)
	{
		a[i] = nb % 10;
		nb /= 10;
		i++;
	}
	length += i;
	while (i >= 1)
		ft_put_char(a[i-- - 1] + 48);
	return (length);
}

int	ft_put_unsigned(unsigned int nb)
{
	int		i;
	int		length;
	char	a[11];

	i = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	while (nb > 0)
	{
		a[i] = nb % 10;
		nb /= 10;
		i++;
	}
	length = i;
	while (i >= 1)
		ft_put_char(a[i-- - 1] + 48);
	return (length);
}

int	ft_put_hexadecimal(unsigned int nb, const char mode)
{
	int		i;
	int		length;
	char	a[11];

	i = 0;
	if (nb == 0)
		return (write(1, "0", 1));
	while (nb > 0)
	{
		a[i] = nb % 16;
		nb /= 16;
		i++;
	}
	length = i;
	while (i >= 1)
	{
		i--;
		if (a[i] <= 9 && a[i] >= 0)
			ft_put_char(a[i] + '0');
		else if (a[i] < 16 && a[i] >= 10 && mode == 'X')
			ft_put_char(a[i] + 'A' - 10);
		else if (a[i] < 16 && a[i] >= 10 && mode == 'x')
			ft_put_char(a[i] + 'a' - 10);
	}
	return (length);
}

int	ft_put_pointer(unsigned long long nb)
{
	int		i;
	int		length;
	char	a[20];

	i = 0;
	write(1, "0x", 2);
	if (nb == 0)
		return (ft_put_char('0') + 2);
	while (nb > 0)
	{
		a[i] = nb % 16;
		nb /= 16;
		i++;
	}
	length = i + 2;
	while (i >= 1)
	{
		i--;
		if (a[i] <= 9 && a[i] >= 0)
			ft_put_char(a[i] + '0');
		else if (a[i] < 16 && a[i] >= 10)
			ft_put_char(a[i] + 'a' - 10);
	}
	return (length);
}
