/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:59:56 by etornay-          #+#    #+#             */
/*   Updated: 2023/11/14 15:54:46 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include <signal.h>

void	server(int signal, siginfo_t *info, void *ucontext)
{
	static unsigned char	data;
	static int				counter;

	(void)ucontext;
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
	if (signal == SIGUSR1)
		kill(info->si_pid, SIGUSR1);
	else if (signal == SIGUSR2)
		kill(info->si_pid, SIGUSR2);
}

int	main(void)
{
	struct sigaction	action;

	action.sa_sigaction = &server;
	action.sa_flags = SA_SIGINFO;
	ft_printf("ID del servidor: %d\n", getpid());
	sigaction(SIGUSR1, &action, NULL);
	sigaction(SIGUSR2, &action, NULL);
	while (1)
		pause();
	return (0);
}