/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 20:30:32 by ybouddou          #+#    #+#             */
/*   Updated: 2019/12/31 16:38:23 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	digit(unsigned int i)
{
	int		n;

	n = 0;
	if (i == 0)
		return (0);
	while (i >= 10)
	{
		i = i / 10;
		n++;
	}
	return (n + 1);
}

static int	ft_precision(int i, int d, t_flag fl)
{
	int		n;

	if ((d == 0 && d > fl.p) || d > fl.p)
	{
		if (i != 0 || fl.p < 0)
			ft_itoa_unsigned(i);
		return (fl.p);
	}
	if ((d == 0 && fl.p >= d) || fl.p > d)
	{
		n = fl.p - d;
		while (n--)
			ft_putchar('0');
		return (u_digit(i, d, fl));
	}
	if (i != 0)
		ft_itoa_unsigned(i);
	return (fl.p);
}

static int	ft_width(int i, int d, t_flag fl)
{
	int		n;

	n = 0;
	if ((d == 0 && fl.p >= d) || fl.p > d)
	{
		n = fl.w - fl.p;
		while (n--)
			ft_putchar(' ');
		ft_precision(i, d, fl);
	}
	else if ((d == 0 && d > fl.p) || d >= fl.p)
	{
		d = (d == 0) ? 1 : d;
		n = fl.w - d;
		while (n--)
			ft_putchar(' ');
		ft_precision(i, d, fl);
	}
	return (fl.w);
}

static int	ft_minus_u_width(int i, int d, t_flag fl)
{
	int		n;

	if ((d == 0 && fl.p >= d) || fl.p > d)
	{
		n = fl.p - d;
		while (n--)
			ft_putchar('0');
		if (i != 0)
			ft_itoa_unsigned(i);
		n = fl.w - fl.p;
		while (n--)
			ft_putchar(' ');
	}
	else if ((d == 0 && d >= fl.p) || d >= fl.p)
	{
		d = (d == 0) ? 1 : d;
		n = fl.w - d;
		ft_itoa_unsigned(i);
		while (n--)
			ft_putchar(' ');
	}
	return (fl.w);
}

int			u_printf(unsigned int i, t_flag fl)
{
	int		d;
	int		count;

	count = 0;
	d = digit(i);
	if (d >= fl.w && d >= fl.p)
		return (u_digit(i, d, fl));
	if (fl.p > fl.w && fl.p > d)
		count += ft_precision(i, d, fl);
	else if (fl.w > d)
	{
		count = 0;
		if (fl.flag == 2 && fl.p < 0)
			count += neg_u_prec(i, d, fl);
		else if (fl.flag == 2 || fl.flag == 0)
			count += ft_width(i, d, fl);
		else if (fl.flag == 1)
			count += ft_minus_u_width(i, d, fl);
	}
	return (count);
}
