/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   server.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: splattje <splattje@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/12/06 09:24:34 by splattje      #+#    #+#                 */
/*   Updated: 2024/01/17 09:09:25 by splattje      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void	handle_sigusr(int signum, siginfo_t *info, void *ucontent)
{
	static int				bit_itr = -1;
	static unsigned char	c;

	(void)ucontent;
	if (bit_itr < 0)
		bit_itr = 7;
	if (signum == SIGUSR1)
		c |= (1 << bit_itr);
	bit_itr--;
	if (bit_itr < 0 && c)
	{
		ft_putchar_fd(c, 1);
		if (kill(info->si_pid, SIGUSR2) == -1)
			handle_errors("Server failed to send SIGUSR2");
		c = 0;
		return ;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		handle_errors("Failed to send SIGUSR1");
}

void	config_signals(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handle_sigusr;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSER1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		handle_errors("Failed to change SIGUSER2's behavior");
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("SERVER PID = %d\n\n", pid);
	config_signals();
	while (1)
		pause();
	return (EXIT_SUCCESS);
}
