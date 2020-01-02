/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_add_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 20:28:18 by ybouddou          #+#    #+#             */
/*   Updated: 2019/12/31 16:38:20 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			neg_u_prec(int i, int d, t_flag fl)
{
	int		n;

	d = (d == 0) ? 1 : d;
	n = fl.w - d;
	while (n--)
		ft_putchar('0');
	ft_itoa_unsigned(i);
	return (fl.w);
}

static int	neg_u_width(unsigned int i, int d, t_flag fl)
{
	int		n;

	fl.w *= -1;
	if (i != 0 || fl.p < 0)
		ft_itoa_unsigned(i);
	d = (i == 0) ? 1 : d;
	if ((fl.w > d && fl.p >= d) || (fl.p == 0 && i == 0))
		n = fl.w - fl.p;
	else if (fl.w > d && fl.p <= 0)
		n = fl.w - d;
	else
		n = 0;
	if (fl.p > 0 && fl.p < d && i != 0)
		n = fl.w - d;
	n = (n < 0) ? 0 : n;
	while (n--)
		ft_putchar(' ');
	if (fl.p > fl.w && fl.p > d)
		return (fl.p);
	if (d >= fl.p && d > fl.w)
		return (d);
	return (fl.w);
}

int			u_digit(unsigned int i, int d, t_flag fl)
{
	if (fl.w < 0)
		return (neg_u_width(i, d, fl));
	if (i != 0 || fl.p < 0)
		ft_itoa_unsigned(i);
	if (fl.w >= 0 && fl.p >= d)
		return (fl.p);
	d = (i == 0) ? 1 : d;
	return (d);
}
