
#ifndef ENEMYHORDE_HPP
# define ENEMYHORDE_HPP

# include "Enemy.hpp"
# include "Elements.hpp"


class EnemyHorde
{
	public:
		EnemyHorde(unsigned int n);
		EnemyHorde(EnemyHorde const &src);
		~EnemyHorde(void);
		EnemyHorde	&operator=(EnemyHorde const &src);

		void		moveEnemies(void)			const;
		void		swap(EnemyHorde& r, EnemyHorde& l);
		void		printEnemies(void)			const;
		void		spawnEnemies(void)			const;
		Enemy		& getEnemy(int id)			const;
		void		spawnEnemy(int id)			const;
		void		collisionEnemy(Player & p)	const;
	private:
		Enemy	*_enemies;
		int		_enemiesCount;
	
};

#endif
