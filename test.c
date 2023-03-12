/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/12 15:45:55 by smessal           #+#    #+#             */
/*   Updated: 2023/03/12 16:07:59 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int ac, char **av)
{
    struct timeval lol;
    gettimeofday(&lol, NULL);
    printf("time: %ld\n", lol.tv_sec);
    usleep(1000000);
    gettimeofday(&lol, NULL);
    printf("time: %ld\n", lol.tv_sec);
    return (0);
}