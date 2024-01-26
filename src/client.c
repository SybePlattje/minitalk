/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   client.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: splattje <splattje@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 09:38:05 by splattje      #+#    #+#                 */
/*   Updated: 2024/01/22 15:01:16 by splattje      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

static int	g_ack_received = 0;

void	timeout_handler (int signum)
{
	ft_fprintf(2, "Error: Timeout. Client is shutting down\n");
	exit(EXIT_FAILURE);
}

void	args_check(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 3)
		handle_errors("Invalid number of arguments");
	while (argv[1][i])
		if (!ft_isdigit(argv[1][i++]))
			handle_errors("Invalid PID");
	if (*argv[2] == 0)
		handle_errors("Invalid message (empty)");
}

void	send_msg(pid_t sv_pid, char *msg)
{
	struct sigaction	sa_timeout;
	unsigned char		c;
	int					nbr_bits;
	int					index;

	sa_timeout.sa_handler &timeout_handler;
	sa_timeout.sa_flags = 0;
	sigaction(SIGALRM, &sa_timeout, NULL);
	index = 0;
	while (msg[index])
	{
		c = msg[index];
		nbr_bits = 8;
		while (nbr_bits--)
		{
			if (c & 0b10000000)
				kill(sv_pid, SIGUSR1);
			else
				kill(sv_pid, SIGUSR2);
			usleep(1000);
			c <<= 1;
		}
		index++;
		alarm(4);
		while (!g_ack_received)
			pause();
		g_ack_received = 0;
		alarm(0);
	}
	exit(EXIT_SUCCESS);
}

void	sig_handler(int signum)
{
	if (signum == SIGUSR2)
	{
		write(1, "Character has been sucessfully receieved!\n", 42);
		g_ack_received = 1;
	}
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_handler = &sig_handler;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSR2's behavior");
}

int	main(int argc, char **argv)
{
	pid_t	sv_pid;

	args_check(argc, argv);
	sv_pid = ft_atoi(argv[1]);
	config_signals();
	send_msg(sv_pid, argv[2]);
	while (1)
		pause();
	return (0);
}
