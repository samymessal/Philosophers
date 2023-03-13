/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:45:55 by smessal           #+#    #+#             */
/*   Updated: 2023/03/13 10:36:39 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    struct timeval lol;
    gettimeofday(&lol, NULL);
    int i = lol.tv_usec;
    printf("time: %d\n", i);
    usleep(200 * 1000);
    gettimeofday(&lol, NULL);
    int j = lol.tv_usec;
    printf("time: %d\n", j);
    if (j < 99999)
        j *= 10;
    if (j < 9999)
        j *= 10;
    if (i < 99999)
        i *= 10;
    if (i < 9999)
        i *= 10;
    if (j > i)
        printf("result = %d\n", j - i);
    else
        printf("result = %d\n", 1000000 - i + j);
    return (0);
}