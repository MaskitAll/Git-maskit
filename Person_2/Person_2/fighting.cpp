#include "stdafx.h"
#include "fighting.h"


Fighting::Fighting(): myCard(), posx(NULL), posy(NULL), my_or_other(NULL)
{
}


Fighting::~Fighting()
{
}

void Fighting::set_pos(int x, int y) {
	posx = x;
	posy = y;

}

void setcur(int x, int y)//установка курсора на позицию  x y, Вызов: setcur(0, 0);
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};

void Fighting::print_empty_sqare(int x, int y) {
	setcur(x, y);
	for (int i = 0; i < 8; ++i) {
		std::cout << "-";
	}
	/*2*/
	setcur(x, y + 1);
	std::cout << "|";
	for (int i = 0; i < 6; ++i) {
		std::cout << " ";
	}
	std::cout << "|";
	/*3*/
	setcur(x, y + 2);
	std::cout << "|";
	for (int i = 0; i < 6; ++i) {
		std::cout << " ";
	}
	std::cout << "|";
	/*4*/
	setcur(x, y + 3);
	std::cout << "|";
	for (int i = 0; i < 6; ++i) {
		std::cout << " ";
	}
	std::cout << "|";
	/*5*/
	setcur(x, y + 4);
	for (int i = 0; i < 8; ++i) {
		std::cout << "-";
	}

}

void Fighting::print_employed_sqare(int x, int y, Card card) {
	/*1*/
	setcur(x, y);
	for (int i = 0; i < 8; ++i) {
		std::cout << "-";
	}
	/*2*/
	setcur(x, y + 1);
	std::cout << "|";
	std::cout << card.getName();
	std::cout << "|";
	/*3*/
	setcur(x, y + 2);
	std::cout << "|";
	card.print_Character(*card.int_to_Character(4));
	std::cout << "|";
	/*4*/
	setcur(x, y + 3);
	std::cout << "|";
	card.print_Character(*card.int_to_Character(2));
	std::cout << " \/ ";
	card.print_Character(*card.int_to_Character(3));
	std::cout << "|";
	/*5*/
	setcur(x, y + 4);
	for (int i = 0; i < 8; ++i) {
		std::cout << "-";
	}

}

void Fighting::print_person() {
	if (my_or_other == false) {
		if (myCard.isEmptyCard()) {
			print_employed_sqare(posx * 10, posy * 5, myCard);
		}
		else {
			print_empty_sqare(posx * 10, posy * 5);
		}
	}
	else {
		if (myCard.isEmptyCard()) {
			print_employed_sqare(posx * 10, posy * 5 + 17, myCard);
		}
		else {
			print_empty_sqare(posx * 10, posy * 5 + 17);
		}
	}
}

void Fighting::print_pole() {
	myCard.recard();
	system("cls");
	for (int x = 0; x < 6; ++x) {
		for (int y = 0; y < 3; ++y) {
			my_or_other = false;
			set_pos(x, y);
			print_person();
		}
	}

	setcur(0, 15);
	for (int i = 0; i < 58; ++i) {
		std::cout << "-";
	}
	setcur(0, 16);
	for (int i = 0; i < 58; ++i) {
		std::cout << "-";
	}
	for (int x = 0; x < 6; ++x) {
		for (int y = 0; y < 3; ++y) {
			my_or_other = true;
			set_pos(x, y);
			print_person();
		}
	}
}