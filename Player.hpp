/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 16:07:30 by asirenko          #+#    #+#             */
/*   Updated: 2019/12/08 22:28:22 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

class Player
{
	public:
		Player(void);
		Player(Player const &src);
		~Player(void);

		Player &operator=(Player const &src);

		void	movePlayerUp(void);
		void	movePlayerDown(void);
		void	movePlayerLeft(void);
		void	movePlayerRight(void);
		void	spawnPlayer(void);
		void	printPlayer(void);
		void	setScore(int score);
		void	setLives(int lives);
		void	setSeconds(int seconds);
		void	setId(int id);
		int		getPosX(void)		const;
		int		getPosY(void)		const;
		int		getLives(void)		const;
		int		getScore(void)		const;
		int		getSeconds(void)	const;
		int		getId(void)			const;
	private:
		int const	_startPositionX;
		int const	_startPositionY;
		int 		_posX;
		int 		_posY;
		int 		_lives;
		int 		_score;
		int		_secondsStart;
		int			_id;
};

#endif
