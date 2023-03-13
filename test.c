/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:45:55 by smessal           #+#    #+#             */
/*   Updated: 2023/03/13 17:06:44 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    struct timeval lol;
	int				result;
    gettimeofday(&lol, NULL);
    int i = lol.tv_usec;
    printf("time: %d\n", i);
    usleep(900 * 1000);
    gettimeofday(&lol, NULL);
    int j = lol.tv_usec;
    printf("time: %d\n", j);
	if (j < i)
	{
		result = i - j;
		result = 1000000 - result;
	}
	else
		result = j - i;
	// printf("result = %d\n", result);
    return (0);
}