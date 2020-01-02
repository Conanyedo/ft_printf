/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_add_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 02:40:28 by ybouddou          #+#    #+#             */
/*   Updated: 2020/01/03 00:39:15 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_x(char *s, int len, t_flag fl)
{
	int		n;

	if (fl.p < 0 || *s != '0')
	{
		len = (*s == '0') ? 1 : len;
		ft_putstr(s);
	}
	if (fl.w < 0)
	{
		fl.w *= -1;
		n = (fl.w < len) ? 0 : (fl.w - len);
		while (n--)
			ft_putchar(' ');
		if (fl.w > len)
			return (fl.w);
	}
	return (len);
}

int		neg_width_x(char *s, int len, t_flag fl)
{
	int		n;

	len = 0;
	if (fl.w < 0)
	{
		fl.w *= -1;
		n = (fl.w > fl.p) ? (fl.w - fl.p) : 0;
		if (*s != '0')
			ft_putstr(s);
		while (n--)
			ft_putchar(' ');
		if (fl.p > fl.w)
			return (fl.p);
		return (fl.w);
	}
	return (fl.p);
}

int		ft_len_p(char *s, int len, t_flag fl)
{
	int		n;

	ft_putstr("0x");
	len = (*s == '0' && fl.p == 0) ? 0 : ft_strlen(s);
	if (fl.p < 0 || *s != '0')
		ft_putstr(s);
	if (fl.w < 0)
	{
		fl.w *= -1;
		n = (fl.w < len) ? 0 : (fl.w - len - 2);
		n = (n < 0) ? 0 : n;
		while (n--)
			ft_putchar(' ');
		if (fl.w >= len + 2)
			return (fl.w);
		else if (len + 2 > fl.w)
			return (len + 2);
	}
	return (len + 2);
}

int		ft_minus_p(char *s, int len, t_flag fl)
{
	int		n;

	n = fl.w - len - 2;
	n = (n < 0) ? 0 : n;
	ft_putstr(s);
	while (n--)
		ft_putchar(' ');
	if ((*s == '0' && fl.p < 0 && len + 2 >= fl.w) || len + 2 >= fl.w)
		return (len + 2);
	if (fl.p + 2 > fl.w)
		return (fl.p + 2);
	return (fl.w);
}
