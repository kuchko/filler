#include "filler.h"

void	ft_solve_find(t_fill *map, t_fill *p)
{
	int	i;
	int	j;
	int kr;

	p->sx = 0;
	p->sy = 0;
	p->pl = 2147483647;
	j = -1;
	while (++j < map->N)
	{
		i = -1;
		while(++i < map->X)
		{
			if (ft_put_check(map, p, j, i))
			{
				kr = ft_manhetan(map, p, j, i);
				if (kr < p->pl)
				{
					p->sx = i;
					p->sy = j;
					p->pl = kr;
				}
			}
		}
	}
}

int	ft_put_check(t_fill *map, t_fill *p, int y, int x)
{
	int j;
	int i;
	int d;

	d = 0;
	j = -1;
	while (++j < p->N)
	{
		i = -1;
		while (++i < p->X)
		{
			if (p->c[j][i] == '*' && (y + j < map->N) && (x + i < map->X)
						 && ft_strchr(p->fr, map->c[y + j][x + i]))
				d++;
			if (p->c[j][i] == '*' && ((y + j >= map->N) || (x + i >= map->X)
						 || ft_strchr(p->en, map->c[y + j][x + i])))
				return (0);
			if (d > 1)
				return (0);
		}
	}
	return (d == 1 ? 1 : 0);
}

int	ft_manhetan(t_fill *map, t_fill *p, int y, int x)
{
	int j;
	int i;
	int d;

	d = 0;
	j = -1;
	while (++j < p->N)
	{
		i = -1;
		while (++i < p->X)
		{
			// if (p->c[j][i] == '*' && (y + j < map->N) && (x + i < map->X)
			// 			 && ft_strchr(p->fr, map->c[y + j][x + i]))
			// 	d++;
			// if (p->c[j][i] == '*' && ((y + j >= map->N) || (x + i >= map->X)
			// 			 || ft_strchr(p->en, map->c[y + j][x + i])))
			// 	return (0);
			// if (d > 1)
			// 	return (0);
		}
	}
	return (d == 1 ? 1 : 0);
}
