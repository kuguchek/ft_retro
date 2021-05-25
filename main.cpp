#include "Game.hpp"

void resizeWindow(void) {
	std::cout << "\e[8;" << std::to_string(Game::H) << ";" << std::to_string(Game::W) << "t"; //resize the window
}

void ncursesColors(void) {
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
}

void ncursesInit(void) {
	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	nodelay(stdscr, TRUE);
	erase();
	curs_set(0);
}

int main(void) {
	Game g;
	
	resizeWindow();
	ncursesInit();
	ncursesColors();
	g.setGameLoop(true);
	//g.StartGame();
	g.StartingMenu();
	g.StartGameLoop();
	endwin();
	g.setGameLoop(false);
	return (0);
}
