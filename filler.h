#ifndef FILLER_H
# define FILLER_H

# include "get_next_line.h"
# include "ft_printf.h"
# include "libft.h"

# define FD1 0

typedef struct		s_fill
{
	char		**c;
	int			X;
	int			N;
	int			pl;
	int			sx;
	int			sy;
	char		*en;
	char		*fr;
}					t_fill;

int main(void);
int ft_game(t_fill *map, t_fill *p);

int		ft_map_read(t_fill *mp);
int		ft_piece_read(t_fill *mp);
int		ft_get_dimensions(t_fill *mp, char *str, char *s, int n);
int		ft_creat_valid_mp(t_fill *mp, int n, char *valid);
//int		ft_creat_valid_map(t_fill *mp);

//int		ft_creat_valid_piece(t_fill *mp);



void	ft_show(char **g);
void	ft_doublefree(char **s);

void	ft_solve_find(t_fill *map, t_fill *p);
int	ft_put_check(t_fill *map, t_fill *p, int y, int x);
int	ft_kr_find(t_fill *map, t_fill *p, int y, int x);
int ft_manhetan(t_fill *map, t_fill *p, int y, int x);

#endif
