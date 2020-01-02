/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_add_func.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 20:27:01 by ybouddou          #+#    #+#             */
/*   Updated: 2020/01/02 23:22:59 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_minus(int i, int d, int minus, t_flag fl)
{
	int		n;

	n = fl.w - d - minus;
	ft_itoa(i);
	while (n--)
		ft_putchar(' ');
}

static void	ft_spaces(int minus, t_flag fl)
{
	int		n;

	n = fl.w - fl.p - minus;
	while (n--)
		ft_putchar(' ');
}

int			ft_minus_width(int i, int d, t_flag fl)
{
	int		n;
	int		minus;

	minus = 0;
	if (i < 0 && i != -2147483648)
	{
		ft_putchar('-');
		i *= -1;
		minus = 1;
	}
	if ((d == 0 && fl.p >= d) || fl.p >= d)
	{
		n = fl.p - d;
		while (n--)
			ft_putchar('0');
		if (i != 0)
			ft_itoa(i);
		ft_spaces(minus, fl);
	}
	else if ((d == 0 && d >= fl.p) || d > fl.p)
	{
		d = (i == 0) ? 1 : d;
		ft_minus(i, d, minus, fl);
	}
	return (fl.w);
}

int			ft_digit(int i, int d, t_flag fl)
{
	int		n;
	int		minus;

	minus = (i < 0) ? 1 : 0;
	d = (i == 0) ? 1 : d;
	ft_itoa(i);
	if (fl.w < 0)
	{
		fl.w *= -1;
		n = fl.w - d - minus;
		n = (n < 0) ? 0 : n;
		while (n--)
			ft_putchar(' ');
		if (d >= fl.w && d >= fl.p)
			return (d + minus);
		return (fl.w);
	}
	return (d + minus);
}

int			ft_prec(int i, int d, int minus, t_flag fl)
{
	int		n;

	n = fl.p - d;
	while (n--)
		ft_putchar('0');
	if (i == -2147483648)
		ft_putstr("2147483648");
	else if (i != 0)
		ft_itoa(i);
	if (fl.w < 0)
	{
		fl.w *= -1;
		n = fl.w - fl.p - minus;
		n = (n < 0) ? 0 : n;
		if (fl.w < fl.p)
			n = 0;
		while (n--)
			ft_putchar(' ');
		if (fl.w <= fl.p)
			return (fl.p + minus);
		return (fl.w);
	}
	return (fl.p + minus);
}
