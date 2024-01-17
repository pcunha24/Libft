/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedalexa <pedalexa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:17:21 by pedalexa          #+#    #+#             */
/*   Updated: 2023/10/15 18:25:55 by pedalexa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	ndigits;
	int	negative;

	negative = 0;
	ndigits = 1;
	if (n < 0)
	{
		negative = 1;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		ndigits++;
	}
	if (negative == 1)
		n = -n;
	return (ndigits);
}

static void	allocate_string(char *str, int n, int ndigits)
{
	ndigits--;
	str[ndigits + 1] = '\0';
	while (ndigits >= 0 && str[ndigits] != '-')
	{
		str[ndigits] = (n % 10) + 48;
		n = n / 10;
		ndigits--;
	}
}

static char	*if_min_int(void)
{
	char	*str;

	str = (char *)malloc(12 * sizeof(char));
	if (!str)
		return (NULL);
	str[0] = '-';
	str[1] = '2';
	str[2] = '1';
	str[3] = '4';
	str[4] = '7';
	str[5] = '4';
	str[6] = '8';
	str[7] = '3';
	str[8] = '6';
	str[9] = '4';
	str[10] = '8';
	str[11] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		ndigits;
	char	*str;

	if (n == 0)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (if_min_int());
	ndigits = count_digits(n);
	if (n < 0)
	{
		ndigits++;
		str = (char *)malloc((ndigits + 1) * sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '-';
		n = -n;
	}
	else
	{
		str = (char *)malloc((ndigits + 1) * sizeof(char));
		if (!str)
			return (NULL);
	}
	allocate_string(str, n, ndigits);
	return (str);
}
/*
int main ()
{
	int n = -11408335;

	printf("%s\n", ft_itoa(n));
	return (0);
}
*/