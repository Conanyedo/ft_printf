/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers_func.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/21 21:32:14 by ybouddou          #+#    #+#             */
/*   Updated: 2019/12/26 16:08:40 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		print(const char **s)
{
	int		count;

	count = 0;
	while (**s && **s != '%')
	{
		ft_putchar(**s);
		(*s)++;
		count++;
	}
	return (count);
}

int		cs_checker(const char **str, va_list arg, t_flag flags)
{
	char			*s;
	unsigned int	i;
	int				count;

	count = 0;
	if (**str == 's')
	{
		s = va_arg(arg, char *);
		count += s_printf(s, flags);
		(*str)++;
	}
	else if (**str == 'c' || **str == '%')
	{
		if (**str == '%')
			count += c_printf('%', flags);
		else
		{
			i = va_arg(arg, int);
			count += c_printf(i, flags);
		}
		(*str)++;
	}
	return (count);
}

int		dui_checker(const char **str, va_list arg, t_flag flags)
{
	unsigned int	i;
	int				count;

	count = 0;
	if (**str == 'd' | **str == 'i')
	{
		i = va_arg(arg, int);
		count += di_printf(i, flags);
		(*str)++;
	}
	else if (**str == 'u')
	{
		i = va_arg(arg, unsigned int);
		count += u_printf(i, flags);
		(*str)++;
	}
	return (count);
}

int		px_checker(const char **str, va_list arg, t_flag flags)
{
	unsigned long int	i;
	char				*s;
	int					count;

	count = 0;
	if (**str == 'x' || **str == 'X')
	{
		i = va_arg(arg, unsigned int);
		s = converter(i, **str);
		if (i == 0)
			*s = '0';
		count += x_printf(s, flags);
		free(s);
		(*str)++;
	}
	else if (**str == 'p')
	{
		i = va_arg(arg, unsigned long int);
		s = p_converter(i);
		count += p_printf(s, flags);
		free(s);
		(*str)++;
	}
	return (count);
}
