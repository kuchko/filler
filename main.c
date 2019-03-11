#include "filler.h"
#include <fcntl.h>
#include <stdio.h>

// ./filler_vm -p2 players/abanlin.filler -p1 ../okuchko.filler -v -f maps/map00
//$$$ exec p
int main(void)
{
	t_map	map;
	char	*s;

	if (get_next_line(1, &s) > 0 && (ft_strncmp(s, "$$$ exec p", 10) == 0)
		&& (s[10] == '1' || s[10] == '2') && ((ft_atoi(s + 10) == 1) || (ft_atoi(s + 10) == 2)))
	{
		map.pl = ft_atoi(s + 10);
		free(s);
		ft_map_read(&map);
		// if (ft_map_read(&map) == 0)
		// 	return(0);
		// if (ft_piece_read(s) == 0)
		// 	return(0);
	}
	else
		ft_printf("Bad player info\n");
	ft_show(map.m);
	ft_doublefree(map.m);
	system("leaks okuchko.filler");
	return (0);
}

int	ft_map_read(t_map *map)
{
	char	**spl;
	int		i;
	char	*s;

	i = 0;
	if (get_next_line(1, &s) > 0 && (spl = ft_strsplit(s, ' ')) && (ft_strcmp("Plateau", spl[0]) == 0))
	{////////read map params/////////////
		map->N = ft_atoi(spl[1]);
		map->X = ft_atoi(spl[2]);
		while (i < 3)
			free(spl[i++]);
		free(spl);
		free(s);
		////////////create map with reading//////
		if (map->N > 0 && map->X > 0 && get_next_line(1, &s) > 0)
		{
			free(s);
			if ((map->m = ft_creatmass(map->N)) == NULL) //|| ft_map_valid(map) == NULL)
				return (0);
			//ft_show(map->m);
			return(1);
		}
	}
	return (0);
}

int	ft_map_valid(t_map *map)
{
	int i;

	i = -1;
	while (++i < )

}


char	**ft_creatmass(int k)
{
	char	**mas;
	int		i;
	char	*s;

	if (!(mas = (char**)malloc(sizeof(char*) * (k + 1))))
		return (NULL);
	i = -1;
	while (++i <= k)
		mas[i] = NULL;
	i = -1;
	while((++i < k) && (get_next_line(1, &s) > 0))
	{
		if (!(mas[i] = ft_strdup(s + 4)))
			return(NULL);
		free(s);
	}
	if (i != k)
		return(NULL);
	return(mas);
}

void	ft_show(char **g)
{
	int i;

	i = -1;
	while(g[++i])
		ft_printf("%s\n", g[i]);
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
