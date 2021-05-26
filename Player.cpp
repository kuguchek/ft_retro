
#include "Player.hpp"
#include "Game.hpp"

Player::Player(void) :
				_startPositionX(3),
				_startPositionY(Game::H / 2),
				_posX(_startPositionX),
				_posY(_startPositionY),
				_lives(3),
				_score(0),
				_secondsStart(0),
				_id(0) {

}

Player::Player(Player const &src) : _startPositionX(3), _startPositionY(Game::H / 2) {
		_posX = src._posX;
		_posY = src._posY;
		_lives = src._lives;
		_score = src._score;
		_secondsStart = src._secondsStart;
		_id = src._id;
}

Player::~Player(void) {

}

Player &Player::operator=(Player const &src) {
	if (this != &src) {
		_posX = src._posX;
		_posY = src._posY;
		_lives = src._lives;
		_score = src._score;
		_secondsStart = src._secondsStart;
		_id = src._id;
	}
	return *this;
}

int		Player::getPosX(void) const {
	return _posX;
}

int		Player::getPosY(void) const {
	return _posY;
}

void	Player::movePlayerUp(void) {
	if ((_id == 0 || _id == 1) && _posY > 1)
		_posY--;
	if (_id == 2 && _posY > (Game::H - 2) / 2)
		_posY--;
}

void	Player::movePlayerDown(void) {
	if ((_id == 2 || _id == 0) && _posY < Game::H - 7)
		_posY++;
	if (_id == 1 && _posY < (Game::H - 9) / 2)
		_posY++;
}

void	Player::movePlayerLeft(void) {
	if (_posX > 1)
		_posX--;
}

void	Player::movePlayerRight(void) {
	if (_posX < Game::W / 3)
		_posX++;
}

void	Player::spawnPlayer(void) {
	_posX = _startPositionX;
	_posY = _startPositionY;
	if (_id == 1)
	{
		_posX = 3;
		_posY = 6;
	}
	if (_id == 2)
	{
		_posX = 3;
		_posY = 18;
	}
}

int		Player::getLives(void) const {
	return _lives;
}

void	Player::setLives(int lives) {
	_lives = lives;
}

int		Player::getScore(void) const {
	return _score;
}

void	Player::setScore(int score) {
	_score = score;
}

int		Player::getSeconds(void) const {
	return _secondsStart;
}

void	Player::setSeconds(int seconds) {
	_secondsStart = seconds;
}

int		Player::getId(void) const {
	return _id;
}

void	Player::setId(int id) {
	_id = id;
}

void	Player::printPlayer(void) {
	attron(COLOR_PAIR(32) | A_BOLD);
	mvaddch(_posY, _posX, '>');
	mvaddch(_posY, _posX + 1, '-');
	attroff(COLOR_PAIR(32) | A_BOLD);
	attron(COLOR_PAIR(2) | A_BOLD);
	mvaddch(_posY - 1, _posX - 1, '\\');
	mvaddch(_posY + 1, _posX - 1, '/');
	attroff(COLOR_PAIR(2) | A_BOLD);
}
