/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 22:11:32 by ybouddou          #+#    #+#             */
/*   Updated: 2019/12/31 16:21:16 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_width(char *s, t_flag fl)
{
	int		n;
	int		len;

	len = ft_strlen(s);
	if (fl.w < 0)
		return (neg_width(s, len, fl));
	if (fl.w > fl.p)
	{
		n = fl.w - fl.p;
		if (fl.flag == 1)
			substr(s, 0, fl.p);
		while (n--)
			ft_putchar(' ');
		if (fl.flag == 0)
			substr(s, 0, fl.p);
		return (fl.w);
	}
	else
		substr(s, 0, fl.p);
	return (fl.p);
}

static int	ft_width_flag(char *s, t_flag fl)
{
	int		n;
	int		len;

	len = ft_strlen(s);
	if (fl.w < 0)
		return (neg_width(s, len, fl));
	if (fl.p >= len && fl.w > len)
		return (s_spaces(s, len, fl));
	else if (len > fl.p && fl.w > len)
	{
		n = fl.w - fl.p;
		if (fl.flag == 1)
		{
			if (fl.p < 0)
				n = fl.w - len;
			substr(s, 0, fl.p);
		}
		while (n--)
			ft_putchar(' ');
		if (fl.flag == 0)
			substr(s, 0, fl.p);
		return (fl.w);
	}
	ft_putstr(s);
	return (len);
}

static int	ft_zero_prec(char *s, int len, t_flag fl)
{
	int		n;

	if (fl.p < 0 || (fl.w > len && fl.p >= len))
	{
		n = fl.w - len;
		while (n--)
			ft_putchar('0');
		ft_putstr(s);
		return (fl.w);
	}
	else
		ft_putstr(s);
	return (len);
}

static int	ft_zero(char *s, t_flag fl)
{
	int		n;
	int		len;

	len = ft_strlen(s);
	if (fl.w < 0)
		return (neg_width(s, len, fl));
	if (fl.p >= fl.w && len > fl.p)
	{
		substr(s, 0, fl.p);
		return (fl.p);
	}
	else if (len > fl.p && fl.w > fl.p && fl.p >= 0)
	{
		n = fl.w - fl.p;
		while (n--)
			ft_putchar('0');
		substr(s, 0, fl.p);
	}
	else
		return (ft_zero_prec(s, len, fl));
	return (fl.w);
}

int			s_printf(char *s, t_flag fl)
{
	int		count;
	int		len;

	count = 0;
	if (!s)
		s = "(null)";
	len = ft_strlen(s);
	if ((len >= fl.w && fl.p < 0) || (fl.p < 0 && fl.w > len))
		return (ft_len(s, len, fl));
	if (fl.flag == 0 || fl.flag == 1)
	{
		if ((len >= fl.w) && (len >= fl.p))
			count += ft_width(s, fl);
		else
			count += ft_width_flag(s, fl);
	}
	else
		count += ft_zero(s, fl);
	return (count);
}
