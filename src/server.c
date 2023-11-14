/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:51:09 by etornay-          #+#    #+#             */
/*   Updated: 2023/11/14 15:00:11 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include <signal.h>

void	server(int signal)
{
	static unsigned char	data;
	static int				counter;

	if (counter < 8)
	{
		if (signal == SIGUSR1)
			data |= (1 << (7 - counter));
		counter++;
	}
	if (counter == 8)
	{
		if (data != '\0')
			ft_printf("%c", data);
		else
			ft_printf("\n");
		data = 0;
		counter = 0;
	}
}

int	main(void)
{
	ft_printf("Id del servidor: %d\n", getpid());
	signal(SIGUSR2, server);
	signal(SIGUSR1, server);
	while (1)
		pause();
	return (0);
}
