/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:44:24 by smessal           #+#    #+#             */
/*   Updated: 2023/03/17 14:09:52 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	ft_atol(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	sign = 1;
	res = 0;
	while ((str[i] > 9 && str[i] < 13) || (str[i] == ' '))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		if (res * sign < -2147483648 || res * sign > 2147483647)
			return (-1);
		i++;
	}
	return (res * sign);
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
