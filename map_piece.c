#include "filler.h"


int	ft_map_read(t_fill *mp)
{
	int		i;
	char	*s;

	i = 0;
	get_next_line(FD1, &s);
	if (ft_get_dimensions(mp, "Plateau", s, 7))
		i = 1;
	free(s);
	if (i && mp->N > 0 && mp->X > 0 && get_next_line(FD1, &s) > 0)
	{
		free(s);
		if (ft_creat_valid_mp(mp, 4, "xXoO."))
			return(1);
	}
	return (0);
}

int	ft_piece_read(t_fill *mp)
{
	int		i;
	char	*s;

	i = 0;
	if (get_next_line(FD1, &s) > 0)
	{
		if (ft_get_dimensions(mp, "Piece", s, 5))
			i = 1;
		free(s);
		if (i && mp->N > 0 && mp->X > 0)
			if (ft_creat_valid_mp(mp, 0, "*."))
				return(1);
	}
	return (0);
}

int ft_get_dimensions(t_fill *mp, char *str, char *s, int n)
{
	int		i;
	char	**spl;

	if (ft_strncmp(str, s, n) == 0)
	{
		spl = ft_strsplit(s, ' ');
		mp->N = ft_atoi(spl[1]);
		mp->X = ft_atoi(spl[2]);
		i = 0;
		while (i < 3)
			free(spl[i++]);
		free(spl);
		return (1);
	}
	return (0);
}

int		ft_creat_valid_mp(t_fill *mp, int n, char *valid)
{
	int		i;
	int		j;
	char	*s;

	if (!(mp->c = (char**)malloc(sizeof(char*) * (mp->N + 1))))
		return (0);
	i = -1;
	while (++i <= mp->N)
		mp->c[i] = NULL;
	i = -1;
	while ((++i < mp->N) && (get_next_line(FD1, &s) > 0))
	{
		if (!(mp->c[i] = ft_strdup(s + n)))
			return (0);
		free(s);
		j = 0;
		while (mp->c[i][j] && ft_strchr(valid, mp->c[i][j]))
			j++;
		if (j != mp->X || mp->c[i][j] != '\0')
			return (0);
	}
	if (i != mp->N)
		return (0);
	return (1);
}
