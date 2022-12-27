/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 02:44:24 by smessal           #+#    #+#             */
/*   Updated: 2022/12/27 03:56:13 by smessal          ###   ########.fr       */
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
