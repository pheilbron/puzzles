#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int	main(int ac, char **av)
{
	int		fds[10];
	char	bufs[10][1024];

	if (ac > 1)
	{
		for (int i = 1; i < ac; i++)
			if ((fds[i] = open(av[i], O_RDONLY)))
				read(fds[i], bufs[i], 1024);
		int size = strlen(bufs[1]);
		for (int i = 0; i < size; i++)
			for (int j = 1; j < ac; j++)
				printf("%c", bufs[j][i]);
	}
	return (0);
}
