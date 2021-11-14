#include "./libft/libft.h"
#include <unistd.h>
#include <signal.h>

void	ft_handler(int sig, siginfo_t *siginfo, void *ucontext)
{
	static unsigned char	c = 0;
	static int				i = 0;
	static	pid_t			cpid = 0;

	(void)ucontext;
	if (!cpid || cpid != siginfo->si_pid)
		cpid = siginfo->si_pid;
	c |= (sig == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (c == 0)
		{
			kill(cpid, SIGUSR2);
			return ;
		}
		kill(cpid, SIGUSR1);
		ft_putchar_fd(c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	struct sigaction	act;

	ft_putstr_fd("Server PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putchar_fd('\n', 1);
	act.sa_sigaction = ft_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	while (1)
		pause();
	return (0);
}