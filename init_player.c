/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initPlayer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aidrissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/31 20:44:11 by aidrissi          #+#    #+#             */
/*   Updated: 2020/01/31 20:46:24 by aidrissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_player	init_player(t_player *p)
{
	p->erreur = 0;
	p->w = 0;
	p->h = 0;
	p->f_color = -2;
	p->c_color = -2;
	p->no = NULL;
	p->so = NULL;
	p->we = NULL;
	p->ea = NULL;
	p->s = NULL;
	p->world = NULL;
	p->world_map = NULL;
	p->sprite = NULL;
	p->spriteorder = NULL;
	p->spritedistance = NULL;
	p->nbr_sprite = 0;
	return (*p);
}
