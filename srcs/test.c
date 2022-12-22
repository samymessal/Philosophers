/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smessal <smessal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 12:51:35 by smessal           #+#    #+#             */
/*   Updated: 2022/12/22 13:23:08 by smessal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void*   func_thread()
{
    printf("Coco\n");
    sleep(2);
    return (NULL);
}

int main(void)
{
    pthread_t   t1;
    pthread_t   t2;

    pthread_create(&t1, NULL, &func_thread, NULL);
    pthread_join(t1, NULL);
    pthread_create(&t2, NULL, &func_thread, NULL);
    pthread_join(t2, NULL);
}