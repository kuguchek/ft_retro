/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Proj.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:42:27 by asirenko          #+#    #+#             */
/*   Updated: 2019/12/08 22:28:50 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Proj.hpp"

Proj::Proj(void) : Elements() {
	_isFired = false;
}

Proj::Proj(Proj const &src) : Elements(src) {
	_isFired = src._isFired;
}

Proj::~Proj(void) {

}

Proj	&Proj::operator=(Proj const &src) {
	if (this != &src) {
		_posX = src._posX;
		_posY = src._posY;
	}
	return *this;
}

void	Proj::spawn(Player p) {
	_posY = p.getPosY();
	_posX = p.getPosX();
}

void	Proj::move(Player p) {
	if (_isFired)
		_posX++;
	if (_posX > Game::W - 1)
	{
		_isFired = false;
		spawn(p);
	}
}

/*int		Proj::getPosX(void) const {
	return this->_posX;
}

int		Proj::getPosY(void) const {
	return this->_posY;
}*/

void	Proj::print(void) const {
	if (_isFired && getPosX() >= 0 &&
		getPosX() < Game::W - 1 && getPosY() >= 0
		&& getPosY() < Game::H - 1) {
			attron(COLOR_PAIR(6));
			mvaddch(getPosY(), getPosX(), '-');
			attroff(COLOR_PAIR(6));
		}
}
