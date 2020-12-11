/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 13:54:04 by aidrissi          #+#    #+#             */
/*   Updated: 2020/02/11 16:19:11 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		ft_screen(t_player *p, char **tab)
{
	if (ft_atoi(tab[1]) > 0 && ft_atoi(tab[2]) > 0 && check_atoi_er(tab, 1))
	{
		if (ft_atoi(tab[1]) > 2560)
			p->w = 2560;
		else
			p->w = ft_atoi(tab[1]);
		if (ft_atoi(tab[2]) > 1400)
			p->h = 1400;
		else
			p->h = ft_atoi(tab[2]);
		return (0);
	}
	return (-1);
}

int		ft_texture(t_player *p, char **tab)
{
	if (!p->no && !ft_cmpr(tab[0], "NO"))
	{
		if (!(p->no = ft_strdup(tab[1])))
			return (-101);
	}
	else if (!p->so && !ft_cmpr(tab[0], "SO"))
	{
		if (!(p->so = ft_strdup(tab[1])))
			return (-101);
	}
	else if (!p->we && !ft_cmpr(tab[0], "WE"))
	{
		if (!(p->we = ft_strdup(tab[1])))
			return (-101);
	}
	else if (!p->ea && !ft_cmpr(tab[0], "EA"))
	{
		if (!(p->ea = ft_strdup(tab[1])))
			return (-101);
	}
	else
		return (-2);
	return (0);
}

int		ft_sol_plafond(t_player *p, char **tab)
{
	char	**tmp;
	int		i;

	if (!(tmp = ft_split(tab[1], ',')) || !check_atoi_er(tmp, 0))
		return (-3);
	if (p->f_color == -2 && nbr_ch(tmp) == 3 && !ft_cmpr(tab[0], "F"))
		p->f_color = rgb(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	else if (p->c_color == -2 && nbr_ch(tmp) == 3 && !ft_cmpr(tab[0], "C"))
		p->c_color = rgb(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
	else
		p->f_color = -1;
	i = 0;
	while (tmp[i])
	{
		free(tmp[i]);
		i++;
	}
	free(tmp);
	if (nbr_ch(tmp) != 3 || p->f_color == -1 || p->c_color == -1)
		return (-3);
	return (0);
}

int		ft_world_map(t_player *p, char *line)
{
	char *tmp;

	if (!(p->world))
	{
		if (!(p->world = ft_strdup("")))
			return (-101);
	}
	tmp = p->world;
	if (!(p->world = ft_strjoin(p->world, line)))
	{
		free(tmp);
		return (-101);
	}
	free(tmp);
	tmp = p->world;
	if (!(p->world = ft_strjoin(p->world, "\n")))
		return (-101);
	free(tmp);
	tmp = NULL;
	return (0);
}
