/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyHorde.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:57:44 by asirenko          #+#    #+#             */
/*   Updated: 2019/12/08 22:23:55 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMYHORDE_HPP
# define ENEMYHORDE_HPP

# include "Enemy.hpp"
# include "Elements.hpp"


class EnemyHorde
{
	public:
		//EnemyHorde(void);
		EnemyHorde(unsigned int n);
		EnemyHorde(EnemyHorde const &src);
		~EnemyHorde(void);

		EnemyHorde	&operator=(EnemyHorde const &src);

		void		moveEnemies(void)			const;
		void		swap(EnemyHorde& r, EnemyHorde& l);
		void		printEnemies(void)			const;
		void		spawnEnemies(void)			const;
		//int			getEnemiesCount(void)		const;
		Enemy		& getEnemy(int id)			const;
		void		spawnEnemy(int id)			const;
		void		collisionEnemy(Player & p)	const;
	private:
		Enemy	*_enemies;
		int		_enemiesCount;
	
};

#endif
