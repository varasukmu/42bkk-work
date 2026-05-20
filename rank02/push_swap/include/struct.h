/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasukmua <wrp.sukmuang@gmail.com>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/21 03:30:41 by vasukmua          #+#    #+#             */
/*   Updated: 2026/05/21 05:05:45 by vasukmua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef struct s_list
{
	int				nbr;
	int				index;
	struct s_list	*next;
}	t_list;

#endif
