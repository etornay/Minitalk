/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:55:00 by etornay-          #+#    #+#             */
/*   Updated: 2023/11/14 16:53:54 by etornay-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Libft/libft.h"
#include <signal.h>

void	client(int pid, unsigned char octet)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if ((octet >> i & 1) == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(100);
		i--;
	}
}

void	server(int signal)
{
	if (signal == SIGUSR1)
		ft_printf("1");
	else if (signal == SIGUSR2)
		ft_printf("0");
}

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*s;

	signal(SIGUSR1, server);
	signal(SIGUSR2, server);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		s = argv[2];
		i = 0;
		while (s[i])
		{
			client (pid, (unsigned char)s[i]);
			i++;
		}
		client(pid, '\0');
		return (0);
	}
	else
	{
		ft_printf("Error de formato: %s <pid> <mensaje>\n", argv[0]);
		return (0);
	}
}
