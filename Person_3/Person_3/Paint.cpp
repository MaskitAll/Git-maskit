#include "stdafx.h"
#include "Paint.h"

Paint::Paint()
{
}

Paint::~Paint()
{
}

void Paint::setcur(int x, int y)	//установка курсора на позицию  x y, Вызов: setcur(0, 0);
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};

void Paint::SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

bool Paint::isNumber(std::string str) {
	for (int i = 0; i < str.size(); ++i) {
		if (str[i] != ' ') {
			if (!isdigit(str[i])) {
				return false;
			}
		}
	}
	return true;
}

int Paint::Width_box(std::string str) {
	int max_widght = 0;
	for (int i = 0; i < str.size(); ++i) {
		if (max_widght < str.find("\n", i)) {
			max_widght = str.find("\n", i) - i;
			i = str.find("\n", i);
		}
	};
	return max_widght;
}

void Paint::print_text(std::string str, int x, int y) {
	if (x < 0 || y < 0) { return; }
	int y1 = 0;
	setcur(x, y + y1);
	for (int i = 0; i < str.size(); i++) {
		if (str[i] != '\n' && str[i] != '{') {
			std::cout << str[i];
		}
		else {
			if (str[i] == '\n') {
				y1++;
				setcur(x, y + y1);
				continue;
			}
			if (str[i] == '{') {
				++i;
				if (str[i] == 's') {
					int textground = 0;
					int background = 0;
					int pos = 0;
					int pos1 = 0;
					int pos2 = 0;
					pos = str.find("(", i) + 1;
					pos1 = str.find(",", pos);
					if (isNumber(str.substr(pos, pos1 - pos))) {
						textground = std::stoi(str.substr(pos, pos1 - pos));
					}
					else {
						i -= 1;
						std::cout << str[i];
						continue;
					}
					pos1++;
					pos2 = str.find(")", pos1);
					if (isNumber(str.substr(pos1, pos2 - pos1))) {
						background = std::stoi(str.substr(pos1, pos2 - pos1));
					}
					else {
						i -= 1;
						std::cout << str[i];
						continue;
					}
					i = pos2 + 1;
					SetColor(textground, background);
				}
				else {
					i -= 1;
					std::cout << str[i];
				}
			}
		}
	}
}

void Paint::loading(int n, int delay, int x, int y) {
	for (int j = 0; j < n; ++j) {
		Sleep(delay);
		system("cls");
		setcur(x, y);
		std::cout << "_...\\" << std::endl;
		Sleep(delay);
		system("cls");
		setcur(x, y);
		std::cout << "_../" << std::endl;
		Sleep(delay);
		system("cls");
		setcur(x, y);
		std::cout << "_..\\" << std::endl;
		Sleep(delay);
		system("cls");
		setcur(x, y);
		std::cout << "_./" << std::endl;
		Sleep(delay);
		system("cls");
		setcur(x, y);
		std::cout << "_.\\" << std::endl;
		Sleep(delay);
		system("cls");
		setcur(x, y);
		std::cout << "_/" << std::endl;
	}
}

void Paint::fill_box(int x1, int y1, int x2, int y2) {
	if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) { return; }
	if (x1 > x2) { std::swap(x1, x2); }
	if (y1 > y2) { std::swap(y1, y2); }
	for (int y = y1; y < y2; ++y) {
		setcur(x1, y);
		for (int x = x1; x < x2; ++x) {
			std::cout << " ";
		}
	}
}

void Paint::fill_box(std::string str, int x1, int y1, int x2, int y2) {
	if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0) { return; }
	if (x1 > x2) { std::swap(x1, x2); }
	if (y1 > y2) { std::swap(y1, y2); }
	for (int y = y1; y < y2; ++y) {
		setcur(x1, y);
		for (int x = x1; x < x2; ++x) {
			std::cout << str;
		}
	}
}

void Paint::fill_box(std::string str, int width, int x1, int y1, int x2, int y2) {
	if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 || width < 0) { return; }
	if (x1 > x2) { std::swap(x1, x2); }
	if (y1 > y2) { std::swap(y1, y2); }
	for (int y = y1; y < y2; ++y) {
		setcur(x1, y);
		for (int x = x1; x < x2; ++x) {
			if (x - x1 < width || y - y1 < width || x2 - x <= width || y2 - y <= width) {
				std::cout << str;
			}
			else {
				std::cout << " ";
			}
		}
	}
}

void Paint::print_Hline(int x, int y, int lenght) {
	setcur(x, y);
	for (int i = 0; i < lenght; ++i) { std::cout << "-"; }
}

void Paint::print_Hline(int x, int y, int background, int lenght) {
	SetColor(background, background);
	setcur(x, y);
	for (int i = 0; i < lenght; ++i) { std::cout << " "; }
	SetColor(15, 0);
}

void Paint::print_Wline(int x, int y, int lenght) {
	for (int i = 0; i < lenght; ++i) { setcur(x, y); std::cout << "|"; ++y; }
}

void Paint::print_Wline(int x, int y, int background, int lenght) {
	SetColor(background, background);
	for (int i = 0; i < lenght; ++i) { setcur(x, y); std::cout << " "; ++y; }
	SetColor(15, 0);
}

void Paint::print_box(int x1, int y1, int x2, int y2, int background) {
	print_Wline(x1, y1, background, (y2 - y1) + 1);
	print_Wline(x2, y1, background, (y2 - y1) + 1);
	print_Hline(x1, y1, background, (x2 - x1) + 1);
	print_Hline(x1, y2, background, (x2 - x1) + 1);
}

