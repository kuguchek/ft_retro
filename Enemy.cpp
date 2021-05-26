
#include "Enemy.hpp"

Enemy::Enemy(void) {
	_posX = Game::W + rand() % 500;
	_posY = rand() % (Game::H - 5);
}

Enemy::Enemy(Enemy const &src) : Elements(src) {
}

Enemy::~Enemy(void) {

}

Enemy	&Enemy::operator=(Enemy const &src) {
	if (this != &src) {
		_posX = src._posX;
		_posY = src._posY;
	}
	return *this;
}

void	Enemy::spawn(void) {
	_posX = Game::W + rand() % 500;
	_posY = rand() % (Game::H - 5);
}

void	Enemy::move(void) {
	_posX--;
	if (_posX < 0)
		spawn();
}

void	Enemy::print(void) const {
	if (getPosX() >= 0 && getPosX() < Game::W - 1
		&& getPosY() >= 0 && getPosY() < Game::H - 1) {
		mvaddch(getPosY(), getPosX(), '*');
	}
}
