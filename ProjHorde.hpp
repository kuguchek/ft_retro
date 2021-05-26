
#ifndef PROJHORDE_HPP
# define PROJHORDE_HPP

# include "Proj.hpp"

class ProjHorde
{
	public:
		ProjHorde(unsigned int n);
		ProjHorde(ProjHorde const &src);
		~ProjHorde(void);

		ProjHorde	&operator=(ProjHorde const &src);

		void		moveProjs(Player p);
		void		printProjs(void)			const;
		void		spawnProjs(Player p);
		void		fireProj(void);
		void		resetProj(Player p);
		void		spawnProj(int id, Player p);
		void		swap(ProjHorde& r, ProjHorde& l);
		Proj		& getProj(int id)				const;
	private:
		int		_currentProj;
		int		_projsCount;
		Proj*	_projs;
	
};

#endif
