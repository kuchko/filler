#include "filler.h"

int	ft_map_read(t_fill *mp)
{
	char	**spl;
	int		i;
	char	*s;

	i = 0;
	if (get_next_line(1, &s) > 0 && (spl = ft_strsplit(s, ' ')) && (ft_strcmp("Plateau", spl[0]) == 0))
	{
		mp->N = ft_atoi(spl[1]);
		mp->X = ft_atoi(spl[2]);
		while (i < 3)
			free(spl[i++]);
		free(spl);
		free(s);
		if (mp->N > 0 && mp->X > 0 && get_next_line(1, &s) > 0)
		{
			free(s);
			if (ft_creat_valid_map(mp))
				return(1);
		}
	}
	return (0);
}

int		ft_creat_valid_map(t_fill *mp)
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
	while ((++i < mp->N) && (get_next_line(1, &s) > 0))
	{
		if (!(mp->c[i] = ft_strdup(s + 4)))
			return (0);
		free(s);
		j = 0;
		while (mp->c[i][j] && ft_strchr("xXoO.", mp->c[i][j]))
			j++;
		if (j != mp->X || mp->c[i][j] != '\0')
			return (0);
	}
	if (i != mp->N)
		return (0);
	return (1);
}

int	ft_piece_read(t_fill *mp)
{
	char	**spl;
	int		i;
	char	*s;

	i = 0;
	if (get_next_line(1, &s) > 0 && (spl = ft_strsplit(s, ' ')) && (ft_strcmp("Piece", spl[0]) == 0))
	{
		mp->N = ft_atoi(spl[1]);
		mp->X = ft_atoi(spl[2]);
		while (i < 3)
			free(spl[i++]);
		free(spl);
		free(s);
		if (mp->N > 0 && mp->X > 0)
		{
			if (ft_creat_valid_piece(mp))
				return(1);
		}
	}
	return (0);
}

int		ft_creat_valid_piece(t_fill *mp)
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
	while ((++i < mp->N) && (get_next_line(1, &s) > 0))
	{
		if (!(mp->c[i] = ft_strdup(s)))
			return (0);
		free(s);
		j = 0;
		while (mp->c[i][j] && ft_strchr("*.", mp->c[i][j]))
			j++;
		if (j != mp->X || mp->c[i][j] != '\0')
			return (0);
	}
	if (i != mp->N)
		return (0);
	return (1);
}
