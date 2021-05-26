
#include "Star.hpp"

Star::Star(void) : Elements() {
	_posX = rand() % Game::W - 2;
	_posY = rand() % Game::H;
}

Star::Star(Star const &src) : Elements(src) {
}

Star::~Star(void) {

}

Star	&Star::operator=(Star const &src) {
	if (this != &src) {
		_posX = src._posX;
		_posY = src._posY;
	}
	return *this;
}

void	Star::print(void) const {
	int i = rand() % 6 + 1;
	if (getPosX() >= 0 && getPosX() < Game::W - 1 &&
		getPosY() >= 0 && getPosY() < Game::H - 1) {
			attron(COLOR_PAIR(i));
			mvaddch(getPosY(), getPosX(), '.');
			attroff(COLOR_PAIR(i));
		}
}

void	Star::move(void) {
	_posX -= 2;
	if (_posX < 0)
	{
		_posY = rand() % Game::H;
		_posX = rand() % Game::W - 2;
	}
}
