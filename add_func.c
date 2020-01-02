/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouddou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/30 20:00:25 by ybouddou          #+#    #+#             */
/*   Updated: 2019/12/30 20:24:07 by ybouddou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_intlen(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (((len == 0) ? 1 : len));
}

static char		*ft_convert(int nlen, unsigned int n)
{
	char	*a;

	if (!(a = (char *)malloc((sizeof(char) * nlen + 1))))
		return (NULL);
	a[nlen] = '\0';
	while (--nlen >= 0)
	{
		a[nlen] = n % 10 + 48;
		n = n / 10;
	}
	return (a);
}

void			ft_itoa_unsigned(unsigned int n)
{
	int		nlen;
	char	*a;

	nlen = ft_intlen(n);
	a = ft_convert(nlen, n);
	ft_putstr(a);
	free(a);
}

static char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	j;
	char			*sub;

	if (!s)
		return (NULL);
	if (!*s || start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	j = 0;
	if (!(sub = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	while (s[i])
	{
		if (i == start)
		{
			while (s[i] && j < len)
				sub[j++] = s[i++];
			sub[j] = '\0';
			return (sub);
		}
		i++;
	}
	return (NULL);
}

void			substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;

	sub = ft_substr(s, start, len);
	ft_putstr(sub);
	free(sub);
}
