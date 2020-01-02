/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/19 20:43:26 by ybouddou          #+#    #+#             */
/*   Updated: 2020/01/03 00:39:13 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_precision(char *s, int len, t_flag fl)
{
	int		n;

	len = ((*s == '0') ? 0 : ft_strlen(s));
	if (len > fl.p)
	{
		ft_putstr(s);
		return (fl.p);
	}
	if (fl.p > len)
	{
		n = fl.p - len;
		while (n--)
			ft_putchar('0');
		if (fl.w < 0)
			return (neg_width_x(s, len, fl));
	}
	if (*s != '0')
		ft_putstr(s);
	return (fl.p);
}

static int	ft_width(char *s, int len, t_flag fl)
{
	int		n;

	n = 0;
	if (fl.p >= len)
	{
		n = fl.w - fl.p;
		while (n--)
			ft_putchar(' ');
		ft_precision(s, len, fl);
	}
	else if (len >= fl.p)
	{
		n = fl.w - len;
		while (n--)
			ft_putchar(' ');
		ft_precision(s, len, fl);
	}
	return (fl.w);
}

static int	ft_minus_x_width(char *s, int len, t_flag fl)
{
	int		n;

	if (fl.p >= len)
	{
		len = (*s == '0') ? 0 : ft_strlen(s);
		n = fl.p - len;
		while (n--)
			ft_putchar('0');
		if (*s != '0')
			ft_putstr(s);
		n = fl.w - fl.p;
		while (n--)
			ft_putchar(' ');
	}
	else if (len > fl.p)
	{
		n = fl.w - len;
		ft_putstr(s);
		while (n--)
			ft_putchar(' ');
	}
	return (fl.w);
}

static int	x_neg_prec(char *s, int len, t_flag fl)
{
	int		n;

	n = fl.w - len;
	while (n--)
		ft_putchar('0');
	ft_putstr(s);
	return (fl.w);
}

int			x_printf(char *s, t_flag fl)
{
	int		len;
	int		count;

	count = 0;
	len = ((*s == '0') ? 0 : ft_strlen(s));
	if (len >= fl.w && len >= fl.p)
		return (ft_len_x(s, len, fl));
	if (fl.p > fl.w && fl.p > len)
		count += ft_precision(s, len, fl);
	else if (fl.w > len)
	{
		len = (*s == '0' && fl.p == 0) ? 0 : ft_strlen(s);
		if (fl.flag == 2 && fl.p < 0)
			count += x_neg_prec(s, len, fl);
		else if (fl.flag == 2 || fl.flag == 0)
			count += ft_width(s, len, fl);
		else if (fl.flag == 1)
			count += ft_minus_x_width(s, len, fl);
	}
	return (count);
}
