
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
