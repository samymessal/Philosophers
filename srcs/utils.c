/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:44:24 by smessal           #+#    #+#             */
/*   Updated: 2023/03/16 17:07:32 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	neg;
	int	result;

	i = 0;
	neg = 1;
	result = 0;
	while (nptr[i] && (nptr[i] == ' ' || (nptr[i] >= 7 && nptr[i] <= 13)))
		i++;
	if (nptr[i] && (nptr[i] == '+' || nptr[i] == '-'))
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
		result = result * 10 + (nptr[i++] - '0');
	return (result * neg);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

static int	ft_numlen(int n)
{
	int				i;
	long long int	num;

	i = 0;
	if (n == 0)
		return (1);
	num = n;
	if (num < 0)
	{
		num *= -1;
		i = 1;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char			*num;
	int				len;
	long long int	long_n;

	len = ft_numlen(n);
	num = malloc(sizeof(char) * (len + 1));
	if (!num)
		return (NULL);
	long_n = n;
	if (long_n < 0)
	{
		long_n *= -1;
		num[0] = '-';
	}
	num[len] = '\0';
	while (long_n > 9)
	{
		num[len - 1] = (long_n % 10) + '0';
		long_n /= 10;
		len--;
	}
	num[len - 1] = long_n + '0';
	return (num);
}

time_t	timer(void)
{
	struct timeval	time;
	time_t			current;

	gettimeofday(&time, NULL);
	current = time.tv_sec * 1000 + time.tv_usec / 1000;
	return (current);
}

/*
int	main(void)
{
	printf("%s", ft_itoa(-7));
}
*/
