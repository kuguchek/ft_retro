/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ProjHorde.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 19:52:34 by asirenko          #+#    #+#             */
/*   Updated: 2019/12/08 22:30:06 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ProjHorde.hpp"

//int ProjHorde::_currentProj = 0;

ProjHorde::ProjHorde(unsigned int n) :
					_currentProj(0),
					_projsCount(n),
					_projs(new Proj[n]) {
}

ProjHorde::ProjHorde(ProjHorde const &src) {
	_projsCount = src._projsCount;
	_projs = new Proj[_projsCount];
	_currentProj = src._currentProj;
	for (int i = 0; i < _projsCount; i++) {
		_projs[i] = src._projs[i];
	}
}

ProjHorde::~ProjHorde(void) {
	delete [] _projs;
}

ProjHorde	&ProjHorde::operator=(ProjHorde const &src) {
	if (this != &src) {
		ProjHorde tmp(src);
		swap(*this, tmp);
	}
	return *this;
}

void		ProjHorde::swap(ProjHorde& r, ProjHorde& l) {
	std::swap(r._projsCount, l._projsCount);
	std::swap(r._projs, l._projs);
}

void		ProjHorde::moveProjs(Player p) {
	for (int i = 0; i < _projsCount; i++)
		_projs[i].move(p);
}

void		ProjHorde::printProjs(void) const {
	for (int i = 0; i < _projsCount; i++)
			_projs[i].print();
}

void		ProjHorde::spawnProjs(Player p) {
	for (int i = 0; i < _projsCount; i++)
		if (_projs[i]._isFired == false)
			_projs[i].spawn(p);
}

void		ProjHorde::resetProj(Player p) {
	for (int i = 0; i < _projsCount; i++)
	{
		_projs[i]._isFired = false;
		_projs[i].spawn(p);
	}
}

void		ProjHorde::fireProj(void) {
	//static int currentProj = 0;
	if (_currentProj >= _projsCount)
		_currentProj = 0;
	if (_projs[_currentProj]._isFired == false)
	{
		_projs[_currentProj]._isFired = true;
		_currentProj++;
	}
}

//int			ProjHorde::getProjsCount(void) const {
//	return this->_projsCount;
//}


Proj &	ProjHorde::getProj(int id) const {
	return _projs[id];
}

void		ProjHorde::spawnProj(int id, Player p) {
		_projs[id]._isFired = false;
		_projs[id].spawn(p);
}
