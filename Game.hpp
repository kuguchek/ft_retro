
#ifndef GAME_HPP
# define GAME_HPP

# include <iostream>
# include <ncurses.h>
# include <unistd.h>
# include <time.h>
# include <string> 
# include "Player.hpp"

class EnemyHorde;
class ProjHorde;
class Star;

class Game
{
	public:
		Game(void);
		Game(Game const &src);
		~Game(void);

		Game			&operator=(Game const &src);

		//void			StartGame(void);
		//void			EndGame(void);
		void			StartGameLoop(void);
		void			GameLoopMultiplayer(Player& p, EnemyHorde& e, ProjHorde& ph);
		void			StartingMenu(void);
		//void			Coloring(void)	const;
		void			setGameLoop(bool state);
		void			printStars(void) const;
		void			moveStars(void) const;
		void			printBackground(void);
		void			secondStartScreen(void);
		void			swap(Game& r, Game& l);
		void			thirdStartScreen(void);
		void 			StatusBar(Player & p)	const;
		void 			StatusBarMultiplayer(Player & p, Player & s)	const;
		void			EndMenu(Player & p, EnemyHorde &e,ProjHorde & ph);
		void			EndMenuMultiplayer(Player & winner,Player & p2, EnemyHorde &e, ProjHorde & ph, ProjHorde & ph2);
		//void   		 	CheckDeath(Player & p, Player & p2, EnemyHorde &e, ProjHorde & ph, ProjHorde & ph2);
		void			resetData(Player & p, ProjHorde & ph);
		void    		Hooks(Player &p, ProjHorde & ph);
		void			hooksMultiplayer(Player& p, Player& p2, ProjHorde& ph, ProjHorde& ph2);
		void    		checkProjectileEnemyCollision(Player & p, EnemyHorde &e, ProjHorde & ph);
		static const int W = 140;
		static const int H = 30;
	private:
		bool			_gameLoop;
		unsigned int	_difficulty;
		time_t			_timeStart;
		unsigned int	_enemiesCount;
		unsigned int	_projsCount;
		bool			_multiplayer;
		unsigned int	_starsCount;
		Star*			_stars;
		
		//void			_ResizeWindow(void) const;
		//void			_NcursesInit(void) const;
		//void			_NcursesClose(void) const;
	
};

#endif
