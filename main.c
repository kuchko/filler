#include "filler.h"
#include <fcntl.h>
#include <stdio.h>

// ./filler_vm -p2 players/abanlin.filler -p1 ../okuchko.filler -v -f maps/map00

int main(void)
{
	t_fill	map;
	t_fill	p;
	char	*s;

	if (get_next_line(FD1, &s) > 0 && (ft_strncmp(s, "$$$ exec p", 10) == 0)
		&& (s[10] == '1' || s[10] == '2') && ((ft_atoi(s + 10) == 1) || (ft_atoi(s + 10) == 2)))
	{
		map.pl = ft_atoi(s + 10);
		free(s);
		p.fr = (map.pl == 1) ? "Oo" : "Xx";
		p.en = (map.pl == 1) ? "Xx" : "Oo";
		while (ft_game(&map, &p))
			;
	}
	else
		ft_printf("Bad player info\n");
	system("leaks okuchko.filler > testliks");
	return (0);
}

int ft_game(t_fill *map, t_fill *p)
{

	if (ft_map_read(map) == 0 || ft_piece_read(p) == 0)
	{
		system("leaks okuchko.filler > testliks");
		return (0);
	}
	ft_solve_find(map, p);
	ft_printf("%d %d\n", p->sy, p->sx);
	ft_doublefree(map->c);
	ft_doublefree(p->c);
	return (1);
}



/*
int main(void)
{
	t_fill	map;
	t_fill	p;
	char	*s;

//	ft_printf("%d\n", 2148);
	if (get_next_line(FD1, &s) > 0 && (ft_strncmp(s, "$$$ exec p", 10) == 0)
		&& (s[10] == '1' || s[10] == '2') && ((ft_atoi(s + 10) == 1) || (ft_atoi(s + 10) == 2)))
	{
		map.pl = ft_atoi(s + 10);
		free(s);
		p.fr = (map.pl == 1) ? "Oo" : "Xx";
		p.en = (map.pl == 1) ? "Xx" : "Oo";

		while (1)
		{
			if (ft_map_read(&map) == 0 || ft_piece_read(&p) == 0)
			{
				system("leaks okuchko.filler > testliks");
				return (0);
			}
			ft_solve_find(&map, &p);
			ft_printf("%d %d\n", p.sy, p.sx);
			ft_doublefree(map.c);
			ft_doublefree(p.c);
		}
	}
	else
		ft_printf("Bad player info\n");
	system("leaks okuchko.filler > testliks");
	return (0);
}
*/


void	ft_show(char **c)
{
	int i;

	i = -1;
	while(c[++i])
		ft_printf("%s\n", c[i]);
}

void	ft_doublefree(char **s)
{
	int		i;

	i = 0;
	while (s[i])
		free(s[i++]);
	free(s);
}
























/*	char	*s;
	int i;
	i = 1;
	int fd1;

	// i = 700;

	fd1 = open("text", O_CREAT | O_RDWR | O_APPEND); // O_TRUNC
	if (fd1 == -1)
	{
		ft_printf("%d\n", fd1);
	}

	while (i > 0)
	{
		i = get_next_line(1, &s);
		write(fd1, s, ft_strlen(s));
		write(fd1, "\n", 1);
	}

	s = "OPENED\n";
	write(fd1, s, ft_strlen(s));

	close(fd1);*/
