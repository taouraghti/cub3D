/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:41:14 by aidrissi          #+#    #+#             */
/*   Updated: 2020/02/17 13:25:22 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	msg_erreur(t_player p)
{
	if (p.erreur < 0)
	{
		ft_putstr("Error\n");
		if (p.erreur == -1)
			ft_putstr("probleme en screen");
		if (p.erreur == -2)
			ft_putstr("probleme en texture");
		if (p.erreur == -3)
			ft_putstr("probleme en sol ou plafond");
		if (p.erreur == -4)
			ft_putstr("probleme en map");
		if (p.erreur == -5)
			ft_putstr("probleme en arguments");
		if (p.erreur == -6)
			ft_putstr("probleme d'ouverture du fichier");
		if (p.erreur == -7)
			ft_putstr("probleme en get_next_line");
		if (p.erreur == -100)
			ft_putstr("fichier invalide");
		if (p.erreur == -101)
			ft_putstr("probleme en allocation");
		p = free_game(p);
		exit(0);
	}
}

int		giveup(t_player *p)
{
	*p = free_game(*p);
	exit(0);
}

void	check_file_name(char *s)
{
	char	**t;
	int		i;
	int		j;

	j = 0;
	i = 0;
	if (!(t = ft_split(s, '.')))
	{
		ft_putstr("Error\n");
		exit(0);
	}
	if (!t[0] || !t[1] || ft_cmpr(t[1], "cub") != 0)
		j++;
	while (t && t[i])
	{
		free(t[i]);
		i++;
	}
	free(t);
	if (j == 1)
	{
		ft_putstr("Error\nfichier invalide");
		exit(0);
	}
}

int		main(int ac, char **av)
{
	t_player	p;
	int			fd;

	p = init_player(&p);
	if (ac < 2 || ac > 3 || (ac == 3 && ft_cmpr(av[2], "--save")))
		p.erreur = -5;
	msg_erreur(p);
	check_file_name(av[1]);
	if ((fd = open(av[1], O_RDONLY)) < 0)
		p.erreur = -6;
	else
	{
		p = read_from_file(fd, p);
		close(fd);
	}
	if (p.erreur >= 0)
		p.erreur = check_game(&p);
	msg_erreur(p);
	p = init_mlx(p, ac);
	p = draw(p, ac, av);
	mlx_hook(p.win.win_ptr, 17, 0, giveup, &p);
	mlx_hook(p.win.win_ptr, 2, 0, keys, &p);
	mlx_loop(p.win.mlx_ptr);
	return (0);
}
