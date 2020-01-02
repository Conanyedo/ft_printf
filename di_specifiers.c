/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 20:27:36 by ybouddou          #+#    #+#             */
/*   Updated: 2020/01/02 23:27:26 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit(int i)
{
	int		n;

	n = 0;
	if (i == 0)
		return (0);
	if (i == -2147483648)
		return (10);
	if (i < 0)
		i *= -1;
	while (i >= 10)
	{
		i = i / 10;
		n++;
	}
	return (n + 1);
}

static int	ft_precision(int i, int d, t_flag fl)
{
	int		minus;

	minus = 0;
	if ((d == 0 && d > fl.p) || d > fl.p)
	{
		if (i != 0 || fl.p < 0)
			ft_itoa(i);
		return (fl.p);
	}
	if (i < 0)
	{
		ft_putchar('-');
		i *= -1;
		minus = 1;
	}
	if ((d == 0 && fl.p >= d) || fl.p >= d)
		return (ft_prec(i, d, minus, fl));
	if (i != 0)
		ft_itoa(i);
	return (fl.p);
}

static int	ft_width(int i, int d, t_flag fl)
{
	int		n;
	int		minus;

	minus = 0;
	if (i < 0)
		minus = 1;
	if ((d == 0 && fl.p >= d) || fl.p >= d)
	{
		n = fl.w - fl.p - minus;
		while (n--)
			ft_putchar(' ');
		ft_precision(i, d, fl);
	}
	else if ((d == 0 && d > fl.p) || d > fl.p)
	{
		n = fl.w - d - minus;
		if (fl.p < 0 && d == 0)
			n = fl.w - 1;
		while (n--)
			ft_putchar(' ');
		ft_precision(i, d, fl);
	}
	return (fl.w);
}

static int	zero_neg_prec(int i, int d, t_flag fl)
{
	int		n;
	int		minus;

	minus = 0;
	if (i < 0)
	{
		minus = 1;
		if (i != -2147483648)
			i *= -1;
		ft_putchar('-');
	}
	d = (i == 0) ? 1 : d;
	n = fl.w - d - minus;
	while (n--)
		ft_putchar('0');
	if (i != -2147483648)
		ft_itoa(i);
	else
		ft_putstr("2147483648");
	return (fl.w);
}

int			di_printf(int i, t_flag fl)
{
	int		d;
	int		count;

	count = 0;
	d = digit(i);
	if (fl.p >= fl.w && fl.p >= d)
		count += ft_precision(i, d, fl);
	else if (fl.w > d && fl.w > fl.p)
	{
		if (fl.flag == 2 && fl.p < 0)
			count += zero_neg_prec(i, d, fl);
		else if (fl.flag == 2 || fl.flag == 0)
			count += ft_width(i, d, fl);
		else if (fl.flag == 1)
			count += ft_minus_width(i, d, fl);
	}
	else if (d >= fl.w && d >= fl.p)
		count = ft_digit(i, d, fl);
	return (count);
}
