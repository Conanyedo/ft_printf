/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 14:56:15 by ybouddou          #+#    #+#             */
/*   Updated: 2020/01/03 00:22:26 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_precision(char *s, int len, t_flag fl)
{
	int		n;

	ft_putstr("0x");
	len = (*s == '0') ? 0 : ft_strlen(s);
	if (fl.p >= len)
	{
		n = fl.p - len;
		while (n--)
			ft_putchar('0');
	}
	if (fl.p < 0 || *s != '0')
		ft_putstr(s);
	if (fl.w < 0)
	{
		fl.w *= -1;
		n = (fl.w > fl.p) ? (fl.w - fl.p - 2) : 0;
		n = (n < 0) ? 0 : n;
		while (n--)
			ft_putchar(' ');
		if (fl.p + 2 > fl.w)
			return (fl.p + 2);
		return (fl.w);
	}
	return (fl.p + 2);
}

static int	ft_width(char *s, int len, t_flag fl)
{
	int		n;

	if (fl.p >= len)
	{
		n = fl.w - fl.p - 2;
		n = (n < 0) ? 0 : n;
		while (n--)
			ft_putchar(' ');
		ft_precision(s, len, fl);
		if ((fl.p + 2) > fl.w)
			return (fl.p + 2);
	}
	else if (len > fl.p)
	{
		n = fl.w - len - 2;
		n = (n < 0) ? 0 : n;
		while (n--)
			ft_putchar(' ');
		ft_precision(s, len, fl);
		if ((*s == '0' && fl.p < 0 && len + 2 >= fl.w) || len + 2 >= fl.w)
			return (len + 2);
		if (fl.p + 2 > fl.w)
			return (fl.p + 2);
	}
	return (fl.w);
}

static int	ft_minus_p_width(char *s, int len, t_flag fl)
{
	int		n;

	ft_putstr("0x");
	if (fl.p >= len)
	{
		len = (*s == '0') ? 0 : ft_strlen(s);
		n = fl.p - len;
		while (n--)
			ft_putchar('0');
		if (fl.p < 0 || *s != '0')
			ft_putstr(s);
		n = fl.w - fl.p - 2;
		n = (n < 0) ? 0 : n;
		while (n--)
			ft_putchar(' ');
		if ((fl.p + 2) > fl.w)
			return (fl.p + 2);
	}
	else if (len > fl.p)
		return (ft_minus_p(s, len, fl));
	return (fl.w);
}

static int	p_neg_precision(char *s, int len, t_flag fl)
{
	int		n;

	ft_putstr("0x");
	n = fl.w - len - 2;
	n = (n < 0) ? 0 : n;
	while (n--)
		ft_putchar('0');
	ft_putstr(s);
	if (len + 2 > fl.w)
		return (len + 2);
	return (fl.w);
}

int			p_printf(char *s, t_flag fl)
{
	int		count;
	int		len;

	count = 0;
	len = (*s == '0') ? 0 : ft_strlen(s);
	if (len >= fl.w && len >= fl.p)
		return (ft_len_p(s, len, fl));
	if (fl.p > fl.w && fl.p > len)
		count += ft_precision(s, len, fl);
	else if (fl.w > len)
	{
		len = (*s == '0' && fl.p == 0) ? 0 : ft_strlen(s);
		if (fl.flag == 2 && fl.p <= -1)
			count += p_neg_precision(s, len, fl);
		else if (fl.flag == 2 || fl.flag == 0)
			count += ft_width(s, len, fl);
		else if (fl.flag == 1)
			count += ft_minus_p_width(s, len, fl);
	}
	return (count);
}
