/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:33:07 by ybouddou          #+#    #+#             */
/*   Updated: 2019/12/31 16:22:33 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_width(unsigned int c, t_flag fl)
{
	int		n;

	n = fl.w - 1;
	if (fl.flag == 1)
	{
		ft_putchar(c);
		while (n--)
			ft_putchar(' ');
	}
	else if (fl.flag == 2)
	{
		while (n--)
			ft_putchar('0');
		ft_putchar(c);
	}
	else
	{
		while (n--)
			ft_putchar(' ');
		ft_putchar(c);
	}
}

int			c_printf(unsigned int i, t_flag fl)
{
	int		count;
	int		n;

	count = 0;
	if (fl.w > 1)
	{
		ft_width(i, fl);
		count += fl.w;
	}
	else if (fl.w < 0)
	{
		fl.w *= -1;
		n = fl.w - 1;
		ft_putchar(i);
		while (n--)
			ft_putchar(' ');
		return (fl.w);
	}
	else
	{
		ft_putchar(i);
		count++;
	}
	return (count);
}
