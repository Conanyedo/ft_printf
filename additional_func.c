/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_func.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 20:05:06 by ybouddou          #+#    #+#             */
/*   Updated: 2019/12/30 20:25:57 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_intlen(int n, int sign)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (((len == 0) ? 1 : len) + sign);
}

static char		*ft_convert(int nlen, int sign, int n)
{
	char	*a;

	if (!(a = (char *)malloc((sizeof(char) * nlen + 1))))
		return (NULL);
	a[nlen] = '\0';
	while (--nlen >= sign)
	{
		a[nlen] = n % 10 + 48;
		n = n / 10;
	}
	if (nlen >= 0)
		a[nlen] = '-';
	return (a);
}

void			ft_itoa(int n)
{
	int		nlen;
	char	*a;
	int		sign;

	nlen = 0;
	sign = 0;
	if (n == -2147483648)
	{
		a = ft_strdup("-2147483648");
		ft_putstr(a);
		free(a);
		return ;
	}
	if (n < 0)
	{
		n = n * -1;
		sign = 1;
	}
	nlen = ft_intlen(n, sign);
	a = ft_convert(nlen, sign, n);
	ft_putstr(a);
	free(a);
}

static char		*ft_ispace(const char *s)
{
	while (((*s == ' ') || (*s == '\t') ||
				(*s == '\n') || (*s == '\v') ||
				(*s == '\f') || (*s == '\r')))
		s++;
	return ((char *)s);
}

int				ft_atoi(const char *s)
{
	int			sign;
	long int	n;
	long int	prev;

	n = 0;
	sign = 1;
	s = ft_ispace(s);
	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
		s++;
	while (*s >= '0' && *s <= '9')
	{
		prev = n;
		n = n * 10 + sign * (*s - '0');
		if (sign == 1 && prev > n)
			return (-1);
		else if (sign == -1 && prev < n)
			return (0);
		s++;
	}
	return (n);
}
