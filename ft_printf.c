/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 16:24:51 by ybouddou          #+#    #+#             */
/*   Updated: 2020/01/02 22:59:50 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_flags(const char **s, t_flag *fl)
{
	fl->flag = 0;
	if (**s == '-')
	{
		(*s)++;
		while (**s == '-' || **s == '0')
			(*s)++;
		fl->flag = 1;
	}
	else if (**s == '0')
	{
		(*s)++;
		fl->flag = 2;
		while (**s == '0')
			(*s)++;
		if (**s == '-')
		{
			(*s)++;
			fl->flag = 1;
		}
		while (**s == '-' || **s == '0')
			(*s)++;
	}
}

static void	ft_width(const char **s, t_flag *fl, int arg)
{
	fl->w = 0;
	if (**s >= '0' && **s <= '9')
	{
		fl->w = ft_atoi(*s);
		while (**s >= '0' && **s <= '9')
			(*s)++;
	}
	else if (**s == '*')
	{
		fl->w = arg;
		(*s)++;
	}
}

static void	ft_precision(const char **s, t_flag *fl, int arg)
{
	fl->p = -1;
	if (**s == '.')
	{
		(*s)++;
		if (**s == '*')
		{
			fl->p = arg;
			(*s)++;
		}
		else if (**s >= '0' && **s <= '9')
		{
			fl->p = ft_atoi(*s);
			while (**s >= '0' && **s <= '9')
				(*s)++;
		}
		else
			fl->p = 0;
	}
}

static void	ft_checker(const char **str, t_flag *flags, va_list arg)
{
	ft_flags(str, flags);
	if (**str == '*')
		ft_width(str, flags, va_arg(arg, int));
	else
		ft_width(str, flags, 1);
	if (**str == '.' && *(*str + 1) == '*')
		ft_precision(str, flags, va_arg(arg, int));
	else
		ft_precision(str, flags, 1);
}

int			ft_printf(const char *str, ...)
{
	va_list			arg;
	int				count;
	t_flag			flags;

	count = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_checker(&str, &flags, arg);
			if (flags.w == INT32_MAX || flags.p == INT32_MAX)
				return (-1);
			if (*str == 's' | *str == 'c' | *str == '%')
				count += cs_checker(&str, arg, flags);
			else if (*str == 'd' | *str == 'u' | *str == 'i')
				count += dui_checker(&str, arg, flags);
			else if (*str == 'x' | *str == 'X' | *str == 'p')
				count += px_checker(&str, arg, flags);
		}
		count += print(&str);
	}
	va_end(arg);
	return (count);
}
