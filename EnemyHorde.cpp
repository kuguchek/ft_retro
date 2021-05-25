/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EnemyHorde.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 17:57:19 by asirenko          #+#    #+#             */
/*   Updated: 2019/12/08 22:22:51 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EnemyHorde.hpp"
#include <cstdlib>

EnemyHorde::EnemyHorde(unsigned int n) :
					_enemies(new Enemy[n]),
					_enemiesCount(n) {

}

EnemyHorde::EnemyHorde(EnemyHorde const &src) {
	_enemiesCount = src._enemiesCount;
	for (int i = 0; i < _enemiesCount; i++) {
		_enemies[i] = src._enemies[i];
	}
}

EnemyHorde& EnemyHorde::operator=(EnemyHorde const& src) {
	if (this != &src) {
		EnemyHorde tmp(src);
		swap(*this, tmp);
	}
	return *this;
}

void		EnemyHorde::swap(EnemyHorde& r, EnemyHorde& l) {
	std::swap(r._enemiesCount, l._enemiesCount);
	std::swap(r._enemies, l._enemies);
}

EnemyHorde::~EnemyHorde(void) {
	delete [] _enemies;
}


void		EnemyHorde::moveEnemies(void) const {
	for (int i = 0; i < _enemiesCount; i++)
		_enemies[i].move();
}

void		EnemyHorde::printEnemies(void) const {
	for (int i = 0; i < _enemiesCount; i++)
		_enemies[i].print();
}

void		EnemyHorde::spawnEnemies(void) const {
	for (int i = 0; i < _enemiesCount; i++)
		_enemies[i].spawn();
}

/*int			EnemyHorde::getEnemiesCount(void) const {
	return this->_enemiesCount;
}*/

Enemy		& EnemyHorde::getEnemy(int id) const {
	return _enemies[id];
}

void		EnemyHorde::spawnEnemy(int id) const {
		_enemies[id].spawn();
}

void		EnemyHorde::collisionEnemy(Player & p) const {
	int py = p.getPosY();
	int px = p.getPosX();
	for (int i = 0; i < _enemiesCount; i++) {
		if ((_enemies[i].getPosX() - px == 0 ||
			_enemies[i].getPosX() - px == 1) &&
			abs(_enemies[i].getPosY() - py) <= 1) {
			_enemies[i].spawn();
			p.setLives(p.getLives() - 1);
		}
	}
}
