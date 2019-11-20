#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	main(int ac, char **av)
{
	int		fds[10];
	char	bufs[10][1024];

	if (ac == 7)
	{
		for (int i = 2; i < ac; i++)
			if (!(fds[i] = open(av[i], O_CREAT | O_RDWR)))
				return (printf("ERROR"));
		int fd = open(av[1], O_RDONLY);
		read(fd, bufs[1], 1024);
		int size = strlen(bufs[1]);
		for (int i = 0; i < 5; i++)
			bufs[1][size + i] = '\n';
		size += 5;
		for (int i = 0; i < size; i++)
			write(fds[(i % 5) + 2], bufs[1] + i, 1);
	}
	return (0);
}
