/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etornay- <etornay-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 12:25:33 by etornay-          #+#    #+#             */
/*   Updated: 2023/11/14 15:12:36 by etornay-         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	int		pid;
	int		i;
	char	*s;

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
