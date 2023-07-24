/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kseniakaremina <kseniakaremina@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 14:30:27 by kseniakarem       #+#    #+#             */
/*   Updated: 2023/07/21 16:14:14 by kseniakarem      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>

void	ft_atobyte(int pid, char c)
{
	int	denom;
	int	bit;

	denom = 128;
	bit = 0;
	while (denom > 0)
	{
		if (c / denom == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c = c % denom;
		denom = denom / 2;
		usleep(42000);
	}
}

int	main(int argc, char *argv[])
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_atobyte(pid, argv[2][i]);
			i++;
		}
	}
	else
	{
		ft_printf("Error\n");
		return (1);
	}
	return (0);
}
