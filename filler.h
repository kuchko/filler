#ifndef FILLER_H
# define FILLER_H

# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

typedef struct		s_piece
{
	int			*x;
	int			*y;
	int			x_size;
	int			y_size;
}					t_piece;

typedef struct		s_map
{
	char		**m;
	int			X;
	int			N;
	int			pl;
}					t_map;

int main(void);

int		ft_map_read(t_map *map);
int		ft_map_valid(t_map *map);
char	**ft_creatmass(int k);
void	ft_show(char **g);
void	ft_doublefree(char **s);
#endif
