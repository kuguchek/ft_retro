
#ifndef STAR_HPP
# define STAR_HPP

# include "Enemy.hpp"
# include "Game.hpp"
#include "Elements.hpp"

class Star : public Elements
{
	public:
		Star(void);
		~Star(void);
		Star(Star const &src);

		Star	&operator=(Star const &src);
		
		void	print(void) const;
		void	move(void);
};

#endif
