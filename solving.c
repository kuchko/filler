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
				kr = ft_kr_find(map, p, j, i);
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

///////// kritery is sum of minimum manhetan_distances from each * to all enemies /////////////
int	ft_kr_find(t_fill *map, t_fill *p, int y, int x)
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
			if (p->c[j][i] == '*')
			{
				d += ft_manhetan(map, p, y + j, x + i);
			}
		}
	}
	return (d > -1 ? d : 0);
}

/////////////// find min of all manhet_distances from * <=> (x_y) to enemies /////////////////////
int ft_manhetan(t_fill *map, t_fill *p, int y, int x)
{
	int j;
	int i;
	int d;

	d = -1;
	j = -1;
	while (++j < map->N)
	{
		i = -1;
		while (++i < map->X)
		{
			if (ft_strchr(p->en, map->c[j][i]))
			{
				if (d == -1)
					d = 2147483647;
				d = d > ft_abs(y - j) + ft_abs(x - i) ? ft_abs(y - j) + ft_abs(x - i) : d; ///find min of all manhet_distances
			}//	d += ft_abs(y - j) + ft_abs(x - i); //count summ of all manhet_distances
		}
	}
	return (d > -1 ? d : 0);
}
