
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
