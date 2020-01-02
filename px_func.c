/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_func.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 00:45:42 by ybouddou          #+#    #+#             */
/*   Updated: 2019/12/31 17:55:19 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*ft_rev(char *hex)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(hex) - 1;
	while (i < len)
	{
		tmp = hex[i];
		hex[i++] = hex[len];
		hex[len--] = tmp;
	}
	return (hex);
}

char		*converter(unsigned int n, char x)
{
	int		i;
	int		temp;
	char	*hex;

	i = 0;
	hex = (char *)malloc(sizeof(char) * 20);
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			hex[i++] = 48 + temp;
		else
			hex[i++] = (x - 33) + temp;
		n /= 16;
	}
	hex[i] = '\0';
	hex = ft_rev(hex);
	return (hex);
}

static void	*ft_rev_p(char *hex)
{
	int		i;
	int		len;
	char	tmp;

	i = 0;
	len = ft_strlen(hex) - 1;
	while (i < len)
	{
		tmp = hex[i];
		hex[i++] = hex[len];
		hex[len--] = tmp;
	}
	return (hex);
}

char		*p_converter(unsigned long int n)
{
	int		i;
	int		temp;
	char	*hex;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	hex = (char *)malloc(sizeof(char) * 20);
	while (n != 0)
	{
		temp = n % 16;
		if (temp < 10)
			hex[i++] = 48 + temp;
		else
			hex[i++] = 87 + temp;
		n /= 16;
	}
	hex[i] = '\0';
	hex = ft_rev_p(hex);
	return (hex);
}
