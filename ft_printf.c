/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdagciog <fdagciog@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 13:09:29 by icelebi           #+#    #+#             */
/*   Updated: 2022/12/22 19:35:17 by fdagciog         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		i = 0;
		while (s[i])
		{
			ft_putchar(s[i]);
			i++;
		}
	}
	else
	{
		return (ft_putstr("(null)"));
	}
	return (i);
}

static int	ft_nbr_printer(unsigned long long int nbr, char	*base_c,
	int base, int p)
{
	int		nbr_backwards[100];
	int		i;
	int		res;

	i = 0;
	res = 0;
	if (p == 1)
		res += ft_putstr("0x");
	if (nbr == 0)
		res += ft_putstr("0");
	if (p == 2 && (int)nbr < 0)
	{
		nbr = nbr * -1;
		res += ft_putstr("-");
	}
	while (nbr)
	{
		nbr_backwards[i] = nbr % base;
		nbr = nbr / base;
		i++;
	}
	while (--i >= 0)
		res += ft_putchar (base_c[nbr_backwards[i]]);
	return (res);
}

static int	ft_sort(const char *s, va_list arg)
{
	if (*s == 'd' || *s == 'i')
		return (ft_nbr_printer(va_arg(arg, int)
				, "0123456789", 10, 2));
	if (*s == 'u')
		return (ft_nbr_printer(va_arg(arg, unsigned int)
				, "0123456789", 10, 0));
	if (*s == 'x' )
		return (ft_nbr_printer(va_arg(arg, unsigned int)
				, "0123456789abcdef", 16, 0));
	if (*s == 'X')
		return (ft_nbr_printer(va_arg(arg, unsigned int)
				, "0123456789ABCDEF", 16, 0));
	if (*s == 'p')
		return (ft_nbr_printer(va_arg(arg, unsigned long long int)
				, "0123456789abcdef", 16, 1));
	if (*s == 's')
		return (ft_putstr(va_arg(arg, char *)));
	if (*s == 'c')
		return (ft_putchar(va_arg(arg, int)));
	if (*s == '%')
		return (ft_putstr("%"));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list		args;
	int			res;

	res = 0;
	va_start(args, s);
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			res += ft_sort(s, args);
		}
		else
		res += write(1, &*s, 1);
		if (*s != '\0')
			s++;
	}
	va_end(args);
	return (res);
}
