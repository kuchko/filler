#include "filler.h"
#include <fcntl.h>

//./filler_vm -p1 user1 -p2 user2 -v -f samples/w1.flr
// ./filler_vm -p1 players/abanlin.filler -p2 players/okuchko.filler -v -f maps/map00

int main(void)
{
	char	*s;
	int i;
	i = 1;
	int fd1;

	// i = 700;

	fd1 = open("text", O_WRONLY | O_CREAT | O_APPEND);
	//ft_printf("$$$ exec p2 : [players/okuchko.filler]\n");
	while (i > 0)
	{
		i = get_next_line(1, &s);
		write(fd1, s, ft_strlen(s));
		write(fd1, "\n", 1);
	}
	// while (i > 0)
	// {
	// 	i = get_next_line(1, &s);
	// 	i++;
	// }

	//ft_printf("%s\n", s);
	close(fd1);
	return (0);
}
