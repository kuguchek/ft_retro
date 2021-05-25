/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:52:12 by asirenko          #+#    #+#             */
/*   Updated: 2019/12/08 22:23:38 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Game.hpp"
# include "Elements.hpp"

class Enemy : public Elements
{
	public:
		Enemy(void);
		~Enemy(void);
		Enemy(Enemy const &src);

		Enemy	&operator=(Enemy const &src);

		void	move(void);
		void	spawn(void);
		void	print(void)		const;
};

#endif
