#include "./libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	ft_handler(int sig)
{
	static int	acc = 0;

	if (sig == SIGUSR1)
		++acc;
	else if (sig == SIGUSR2)
	{
		ft_putnbr_fd(acc, 1);
		ft_putchar_fd('\n', 1);
		exit(0);
	}
}

void	ft_send(int spid, char *str)
{
	int	i;
	int	len;

	len = ft_strlen(str) + 1;
	while (len--)
	{
		i = 128;
		while (i)
		{
			if (i & *str)
				kill(spid, SIGUSR1);
			else
				kill(spid, SIGUSR2);
			usleep(100);
			i /= 2;
		}
		str++;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	act;
	
	if (argc != 3)
		return (1);
	ft_putstr_fd("Sent to sever        : ", 1);
	ft_putnbr_fd(ft_strlen(argv[2]), 1);
	ft_putstr_fd("\nReceived from server : ", 1);
	act.sa_handler = ft_handler;
	act.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &act, 0);
	sigaction(SIGUSR2, &act, 0);
	ft_send(ft_atoi(argv[argc - 2]), argv[argc - 1]);
	while (1)
		pause();
	return (0);
}