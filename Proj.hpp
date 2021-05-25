/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Proj.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:41:56 by asirenko          #+#    #+#             */
/*   Updated: 2019/12/08 22:29:07 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROJ_HPP
# define PROJ_HPP

# include "Game.hpp"
# include "Player.hpp"
#include "Elements.hpp"

class Proj : public Elements
{
	public:
		Proj(void);
		~Proj(void);
		Proj(Proj const &src);

		Proj 	&operator=(Proj const &src);

		void	move(Player p);
		void	spawn(Player p);
		void	print(void)		const;
		bool 	_isFired;
};

#endif
