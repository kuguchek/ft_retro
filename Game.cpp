/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asirenko <asirenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/07 15:40:55 by asirenko          #+#    #+#             */
/*   Updated: 2019/12/08 22:26:26 by asirenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "StarHorde.hpp"
#include "EnemyHorde.hpp"
#include "ProjHorde.hpp"
#include "Player.hpp"

Game::Game(void) : 
        _gameLoop(false),
        _difficulty(1),
        _timeStart(time(0)),
        _enemiesCount(100),
        _projsCount(50),
        _multiplayer(false),
        _starsCount(300),
        _stars(new Star[_starsCount]) {
 }

Game::Game(Game const &src) : _starsCount(src._starsCount){
    _gameLoop = src._gameLoop;
    _difficulty = src._difficulty;
    _timeStart = src._timeStart;
    _starsCount = src._starsCount;
    _enemiesCount = src._enemiesCount;
    _projsCount = src._projsCount;
    _multiplayer = src._multiplayer;
    _stars = new Star[src._starsCount];
    for (unsigned int i = 0; i < _starsCount; i++)
        _stars[i] = src._stars[i];
}

Game::~Game(void) {
    delete [] _stars;
}

Game    &Game::operator=(Game const &src) {
    if (this != &src) {
        Game tmp(src);
        swap(*this, tmp);
    }
	return *this;
}

void Game::swap(Game& r, Game& l) {
    std::swap(r._gameLoop, l._gameLoop);
    std::swap(r._difficulty, l._difficulty);
    std::swap(r._timeStart, l._timeStart);
    std::swap(r._starsCount, l._starsCount);
    std::swap(r._enemiesCount, l._enemiesCount);
    std::swap(r._projsCount, l._projsCount);
    std::swap(r._multiplayer, l._multiplayer);
    std::swap(r._stars, l._stars);
}
/*void	Game::StartGame(void) {
	this->_ResizeWindow();
	this->_NcursesInit();
	this->GameLoop = true;
}*/

/*void	Game::EndGame(void) {
    endwin();
    setGameLoop(false);
}*/

void	Game::setGameLoop(bool state) {
    _gameLoop = state;
}

/*void	Game::_NcursesInit(void) const {
	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	erase();
	curs_set(0);
}*/

//void	Game::_NcursesClose(void) const {
//	endwin();
//}

/*void	Game::_ResizeWindow(void) const {
	std::cout << "\e[8;" << std::to_string(H) << ";" << std::to_string(W) <<"t";
}*/

/*void	Game::Coloring(void) const {
    start_color();
    init_color(17, 800, 0, 0);
    init_color(18, 1000, 750, 790);
    init_pair(32, 18, COLOR_BLACK);
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, 17, COLOR_BLACK);
	init_pair(3, COLOR_CYAN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, 17, COLOR_BLACK);
	init_pair(6, COLOR_RED, COLOR_BLACK);
}*/

void		Game::moveStars(void) const {
    for (unsigned int i = 0; i < _starsCount; i++)
        _stars[i].move();
}

void		Game::printStars(void) const {
    for (unsigned int i = 0; i < _starsCount; i++)
        _stars[i].print();
}

void    Game::StatusBar(Player & p) const {
	int i = 0;
	attron(COLOR_PAIR(32) | A_BOLD);
	while(i < Game::W){
    	mvprintw(25, i, "_");
    	i++;
	}
    i = 0;
    p.setSeconds(difftime(time(0), this->_timeStart));
    std::string time = "    TIME     " + std::to_string(p.getSeconds()) + " ";
    std::string lives = "    LIVES:   " + std::to_string(p.getLives()) + " ";
    std::string score = "    SCORE    " + std::to_string(p.getScore()) + " ";
    mvprintw(26, 3, lives.c_str());
    mvprintw(27, 3, score.c_str());
    mvprintw(28, 3, time.c_str());
    mvprintw(26, 60, "    TO MOVE USE ARROWS ");
    mvprintw(27, 60, "    TO SHOOT [SPACE]   ");
    mvprintw(28, 60, "    TO EXIT [ESC]    ");
    attroff(COLOR_PAIR(32) | A_BOLD);
}

void    Game::StatusBarMultiplayer(Player & p, Player & s) const {
    int i = 0;
    attron(COLOR_PAIR(32) | A_BOLD);
    while(i < Game::W){
        mvprintw(25, i, "_");
        i++;
    }
    i = 0;
    while(i < Game::W){ 
            mvprintw(12, i, "_");
            i++;
        }   
    p.setSeconds(difftime(time(0), this->_timeStart));
    std::string t = "TIME " + std::to_string(p.getSeconds()) + " ";
    std::string lives = "LIVES: " + std::to_string(p.getLives()) + " ";
    std::string score = "SCORE " + std::to_string(p.getScore()) + " ";
    mvprintw(26, 3, "PLAYER 1:");
    mvprintw(26, 14, lives.c_str());
    mvprintw(27, 14, score.c_str());
    mvprintw(28, 14, t.c_str());
    mvprintw(26, 60, "      TO MOVE USE ARROWS ");
    mvprintw(27, 60, "      TO SHOOT [SPACE]   ");
    mvprintw(28, 60, "      TO EXIT [ESC]    ");
    std::string l = "LIVES: " + std::to_string(s.getLives()) + " ";
    std::string sc = "SCORE " + std::to_string(s.getScore()) + " ";
    s.setSeconds(difftime(time(0), this->_timeStart));
    mvprintw(26, 27, "PLAYER 2:");
    mvprintw(26, 38, l.c_str());
    mvprintw(27, 38, sc.c_str());
    mvprintw(28, 38, t.c_str());
    mvprintw(26, 54, " PLAYER 1:");
    mvprintw(26, 91, "PLAYER 2:");
    mvprintw(26, 100, "  TO MOVE USE [A W D S] ");
    mvprintw(27, 100, "  TO SHOOT [F]   ");
    mvprintw(28, 100, "  TO EXIT [ESC]    ");
    attroff(COLOR_PAIR(32) | A_BOLD);
}

void Game::printBackground(void)
{
    int i;
    int j;
    i = 0;
    attron(COLOR_PAIR(17) | A_BOLD);
    while (i < Game::W - 1)
    {
        j = 0;
        while (j < Game::H) {
            mvprintw(j, i, "___|");
            if (i == Game::W) {
                j = 0;
            }
            j++;
        }
        i += 4;
    }
    attroff(COLOR_PAIR(17) | A_BOLD);
}

void Game::secondStartScreen(void) {
    char list2[2][16] = { "SINGLE PLAYER", "MULTIPLAYER" };
    int input;
    int i = 0;
    attron(COLOR_PAIR(32) | A_STANDOUT);
    mvprintw(9, 63, list2[0]);
    attroff(COLOR_PAIR(32) | A_STANDOUT);
    mvprintw(10, 63, list2[1]);
    while (1)
    {
        input = getch();
        mvprintw(i + 9, 63, list2[i]);
        switch (input) {
        case KEY_UP:
            i--;
            i = (i < 0) ? 1 : i;
            break;
        case KEY_DOWN:
            i++;
            i = (i > 1) ? 0 : i;
            break;
        }
        attron(COLOR_PAIR(32) | A_STANDOUT);
        mvprintw(i + 9, 63, list2[i]);
        attroff(COLOR_PAIR(32) | A_STANDOUT);
        if (input == 10 && i == 1) {
            this->_multiplayer = true;
            break;
        }
        if (input == 10 && i == 0)
            break;
        if (input == 27)
        {
            endwin();
            exit(1);
        }
    }
}

void Game::thirdStartScreen(void) {
    char list3[3][8] = { "EASY", "MEDIUM", "HARD" };
    int input;
    int i = 0;

    attron(COLOR_PAIR(32) | A_BOLD);
    mvprintw(9, 55, "|                           |");
    mvprintw(10, 55, "|                           |");
    mvprintw(11, 55, "|                           |");
    attroff(COLOR_PAIR(32) | A_BOLD);
    attron(COLOR_PAIR(32) | A_STANDOUT);
    mvprintw(9, 66, list3[0]);
    attroff(COLOR_PAIR(32) | A_STANDOUT);
    mvprintw(10, 66, list3[1]);
    mvprintw(11, 66, list3[2]);
    i = 0;
    while (1)
    {
        input = getch();
        mvprintw(i + 9, 66, list3[i]);
        switch (input) {
        case KEY_UP:
            i--;
            i = (i < 0) ? 2 : i;
            break;
        case KEY_DOWN:
            i++;
            i = (i > 2) ? 0 : i;
            break;
        }
        attron(COLOR_PAIR(32) | A_STANDOUT);
        mvprintw(i + 9, 66, list3[i]);
        attroff(COLOR_PAIR(32) | A_STANDOUT);
        if (input == 10 && i == 0) {
            this->_difficulty = 1;
            break;
        }
        if (input == 10 && i == 1)
        {
            this->_difficulty = 2;
            break;
        }
        if (input == 10 && i == 2)
        {
            this->_difficulty = 3;
            break;
        }
        if (input == 27)
        {
            endwin();
            exit(1);
        }
    }
}

void    Game::StartingMenu(void) {
    char list[2][5] = {"PLAY", "EXIT"};
    int i;
    int input;
    printBackground();
    attron(COLOR_PAIR(32) | A_BOLD);
    mvprintw(6, 56, "___________________________");
    mvprintw(7, 55, "|    WELLCOME TO FT_RETRO   |");
    mvprintw(8, 55, "|___________________________|");
    mvprintw(9, 55, "|                           |");
    mvprintw(10, 55, "|                           |");
    mvprintw(11, 55, "|                           |");
    mvprintw(12, 55, "|___________________________|");
    attroff(COLOR_PAIR(32) | A_BOLD);
    attron(COLOR_PAIR(32) | A_STANDOUT);
    mvprintw(9, 67, list[0]);
    attroff(COLOR_PAIR(32) | A_STANDOUT);
    mvprintw(10, 67, list[1]);
    i = 0;
    while(1)
    {
        input = getch();
        if (input == 27)
        {
            endwin();
            exit(1);
        }
        mvprintw(i + 9, 67, list[i]);
        switch(input) {
            case KEY_UP:
              i--;
              i = (i < 0) ? 1 : i;
              break ;
            case KEY_DOWN:
               i++;
               i = (i > 1) ? 0 : i;
               break ;
            }
            attron(COLOR_PAIR(32) | A_STANDOUT);
            mvprintw(i + 9, 67, list[i]);
            attroff(COLOR_PAIR(32) | A_STANDOUT);
            if (input == 10 && i == 1)
            {
                    endwin();
                    exit(1);
            }
            if (input == 10 && i == 0) //second screen started 
            {
                secondStartScreen();
                thirdStartScreen();
                //third screen started
                break ;
            }
    }
    erase();
    refresh();
}

void    Game::EndMenuMultiplayer(Player & winner, Player & p2,
                                EnemyHorde &e, ProjHorde & ph, ProjHorde & ph2) {
    //this->Coloring();
    printBackground();
    /*attron(COLOR_PAIR(17) | A_BOLD);
    int i = 0;
    int j;
    while(i < Game::W - 1)
    {
        j = 0;
        while(j < Game::H) {
            mvprintw(j, i, "___|");
            if (i == Game::W){
                j = 0;
            }
            j++;
        }
        i += 4;
    }
    attroff(COLOR_PAIR(17) | A_BOLD);*/
    std::string t = "    TIME     " + std::to_string(winner.getSeconds()) + " ";
    std::string score = "    SCORE    " + std::to_string(winner.getScore()) + " ";
    attron(COLOR_PAIR(32) | A_BOLD);
    mvprintw(6, 56, "___________________________");
    std::string id = " PLAYER " + std::to_string(winner.getId()) + " IS THE WINNER";
    mvprintw(7, 55, "|                           |");
    mvprintw(8, 55, "|___________________________|");
    mvprintw(9, 55, "|                           |");
    mvprintw(10, 55, "|                           |");
    mvprintw(11, 55, "|___________________________|");
    mvprintw(12, 55, "|         * RETRY *         |");
    mvprintw(13, 55, "|       Press [ENTER]       |");
    mvprintw(14, 55, "|___________________________|");
    mvprintw(15, 55, "|         * EXIT *          |");
    mvprintw(16, 55, "|        Press [ESC]        |");
    mvprintw(17, 55, "|___________________________|");
    attroff(COLOR_PAIR(32) | A_BOLD);
    attron(COLOR_PAIR(32));
    mvprintw(7, 58, id.c_str());
    mvprintw(9, 60, score.c_str());
    mvprintw(10, 60, t.c_str());
    attroff(COLOR_PAIR(32));
    refresh();
    int input;
    while (1) {
        input = getch();
        if (input == 27) {
            endwin();
            exit(1);
        }
        if (input == 10)
        {
            _timeStart = time(0);
            e.spawnEnemies();
            resetData(winner, ph);
            resetData(p2, ph2);
            break ;
        }
        else if (input != 27) {}
    }
    erase();
    refresh();
}

void    Game::EndMenu(Player & p, EnemyHorde &e,
                        ProjHorde & ph) {
    //this->Coloring();
    /*attron(COLOR_PAIR(17) | A_BOLD);
    int i = 0;
    int j;
    while(i < Game::W - 1)
    {
        j = 0;
        while(j < Game::H) {
            mvprintw(j, i, "___|");
            if (i == Game::W){
                j = 0;
            }
            j++;
        }
        i += 4;
    }
    attroff(COLOR_PAIR(17) | A_BOLD);*/
    printBackground();
    std::string t = "    TIME     " + std::to_string(p.getSeconds()) + " ";
    std::string score = "    SCORE    " + std::to_string(p.getScore()) + " ";
    attron(COLOR_PAIR(32) | A_BOLD);
    mvprintw(6, 56, "___________________________");
    mvprintw(7, 55, "|     SORRY, YOU ARE DEAD   |");
    mvprintw(8, 55, "|___________________________|");
    mvprintw(9, 55, "|                           |");
    mvprintw(10, 55, "|                           |");
    mvprintw(11, 55, "|___________________________|");
    mvprintw(12, 55, "|         * RETRY *         |");
    mvprintw(13, 55, "|       Press [ENTER]       |");
    mvprintw(14, 55, "|___________________________|");
    mvprintw(15, 55, "|         * EXIT *          |");
    mvprintw(16, 55, "|        Press [ESC]        |");
    mvprintw(17, 55, "|___________________________|");
    attroff(COLOR_PAIR(32) | A_BOLD);
    attron(COLOR_PAIR(32));
    mvprintw(9, 60, score.c_str());
    mvprintw(10, 60, t.c_str());
    attroff(COLOR_PAIR(32));
    refresh();
    int input;
    while (1) {
        input = getch();
        if (input == 27) {
            endwin();
            exit(1);
        }
        if (input == 10)
        {
            _timeStart = time(0);
            e.spawnEnemies();
            resetData(p, ph);
            erase();
            refresh();
            //return ;
            break ;
        }
        else if (input != 27) {}
    }
    erase();
    refresh();
}

//need for multiplayer

void    Game::resetData(Player & p,
                        ProjHorde & ph) {
    p.spawnPlayer();
    ph.resetProj(p);
    p.setLives(3);
    p.setScore(0); 
}

/*void    Game::CheckDeath(Player & p, Player & p2, EnemyHorde &e,
                            ProjHorde & ph, ProjHorde & ph2) {
    if (this->_multiplayer == false)
    {
        if (p.getLives() <= 0)
            this->EndMenu(p, e, ph);
    }
    else
    {
        if (p.getLives() <= 0)
            this->EndMenuMultiplayer(p2, p, p2, e, ph, ph2);
        else if (p2.getLives() <= 0)
            this->EndMenuMultiplayer(p, p, p2, e, ph, ph2);
    }
}*/

void    Game::hooksMultiplayer(Player &p, Player& p2, ProjHorde& ph, ProjHorde& ph2) {

    int input = getch();
    if (input == 119)
        p2.movePlayerUp();
    if (input == 115)
        p2.movePlayerDown();
    if (input == 97)
        p2.movePlayerLeft();
    if (input == 100)
        p2.movePlayerRight();
    if (input == 102)
        ph2.fireProj();
    if (input == KEY_DOWN)
        p.movePlayerDown();
    if (input == KEY_UP)
        p.movePlayerUp();
    if (input == KEY_RIGHT)
        p.movePlayerRight();
    if (input == KEY_LEFT)
        p.movePlayerLeft();
    if (input == 32)
        ph.fireProj();
    if (input == 27) {
        endwin();
        setGameLoop(false);
    }
}

void    Game::Hooks(Player &p, ProjHorde & ph)
{
    int input = getch();
    if (input == KEY_DOWN)
        p.movePlayerDown();
    if (input == KEY_UP)
        p.movePlayerUp();
    if (input == KEY_RIGHT)
        p.movePlayerRight();
    if (input == KEY_LEFT)
        p.movePlayerLeft();
    if (input == 32)
        ph.fireProj();
    if (input == 27) {
        endwin();
        setGameLoop(false);
    }
}

void    Game::checkProjectileEnemyCollision(Player & p,
                                            EnemyHorde &e, ProjHorde & ph)
{
    for (unsigned int i = 0; i < this->_projsCount; i++)
    {
        for (unsigned int j = 0; j < this->_enemiesCount; j++)
            if (abs(ph.getProj(i).getPosX() - e.getEnemy(j).getPosX()) <= 1
                && ph.getProj(i).getPosY() == e.getEnemy(j).getPosY()) {
                ph.spawnProj(i, p);
                p.setScore(p.getScore() + 10 * _difficulty);
                e.spawnEnemy(j);
            }
    }
}

void Game::GameLoopMultiplayer(Player & p, EnemyHorde & e, ProjHorde & ph) {
    Player p2;
    ProjHorde ph2(_projsCount);

    p.setId(1);
    p2.setId(2);
    p.spawnPlayer();
    p2.spawnPlayer();
    while (_gameLoop) {
        ph.spawnProjs(p);
        ph2.spawnProjs(p2);
        hooksMultiplayer(p, p2, ph, ph2);
        e.collisionEnemy(p);
        e.collisionEnemy(p2);
        checkProjectileEnemyCollision(p, e, ph);
        checkProjectileEnemyCollision(p2, e, ph2);
        ph.moveProjs(p);
        ph2.moveProjs(p2);
        e.moveEnemies();
        moveStars(); //stars
        erase();
        ph.printProjs();
        ph2.printProjs();
        printStars(); //stars
        p.printPlayer();
        p2.printPlayer();
        e.printEnemies();
        StatusBarMultiplayer(p, p2);
        if (p.getLives() <= 0)
            this->EndMenuMultiplayer(p2, p, e, ph2, ph);
        else if (p2.getLives() <= 0)
            this->EndMenuMultiplayer(p, p2, e, ph, ph2);
        usleep(32000);
    }
}

void	Game::StartGameLoop(void) {
    _enemiesCount *= _difficulty;
    _projsCount /= _difficulty;
	Player p;
    //Player p2;
    //ProjHorde ph2(_projsCount);
	EnemyHorde e(_enemiesCount);
	//StarHorde s(_starsCount);
	ProjHorde ph(_projsCount);
	
    if (_multiplayer == true)
        GameLoopMultiplayer(p, e, ph);
    else
    {
        while (_gameLoop) {
            ph.spawnProjs(p);
            //if (this->_multiplayer)
            //    ph2.spawnProjs(p2);
            Hooks(p, ph); //for single player
            e.collisionEnemy(p);
            //if (this->_multiplayer)
            //e.collisionEnemy(p2);
            checkProjectileEnemyCollision(p, e, ph); //for single player
            ph.moveProjs(p);
            //if (this->_multiplayer)
            //    ph2.moveProjs(p2);
            e.moveEnemies();
            moveStars(); //stars
            erase();
            ph.printProjs();
            //if (this->_multiplayer)
            //    ph2.printProjs();
            printStars(); //stars
            p.printPlayer();
            // if (this->_multiplayer)
             //    p2.printPlayer();
            e.printEnemies();
            StatusBar(p);
            //if (this->_multiplayer)
            //    StatusBarMultiplayer(p, p2);
            if (p.getLives() <= 0)
                EndMenu(p, e, ph); //for single player
            usleep(32000);
        }
	}
}
