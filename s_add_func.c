/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_add_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 15:32:43 by ybouddou          #+#    #+#             */
/*   Updated: 2019/12/31 16:21:09 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_width_len(char *s, int len, t_flag fl)
{
	int		n;

	if (fl.flag == 2)
	{
		n = fl.w - len;
		while (n--)
			ft_putchar('0');
		ft_putstr(s);
		return (fl.w);
	}
	n = fl.w - len;
	if (fl.flag == 1)
		ft_putstr(s);
	while (n--)
		ft_putchar(' ');
	if (fl.flag == 0)
		ft_putstr(s);
	return (fl.w);
}

int		neg_width(char *s, int len, t_flag fl)
{
	int		n;

	fl.w *= -1;
	substr(s, 0, fl.p);
	n = (fl.p > len) ? (fl.w - len) : (fl.w - fl.p);
	if (fl.w < fl.p)
		n = 0;
	while (n--)
		ft_putchar(' ');
	if (len > fl.p && len > fl.w && fl.p > 0 && fl.w < fl.p)
		return (fl.p);
	if (fl.p >= len && fl.p > fl.w && len > fl.w)
		return (len);
	return (fl.w);
}

int		s_spaces(char *s, int len, t_flag fl)
{
	int		n;

	n = fl.w - len;
	if (fl.flag == 1)
		ft_putstr(s);
	while (n--)
		ft_putchar(' ');
	if (fl.flag == 0)
		ft_putstr(s);
	return (fl.w);
}

int		ft_len(char *s, int len, t_flag fl)
{
	int		n;

	if (fl.w > len)
		return (ft_width_len(s, len, fl));
	ft_putstr(s);
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
