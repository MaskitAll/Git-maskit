#include "stdafx.h"
#include "Deck.h"


//Deck::Deck() :deck({Card(deck.size())})
//{
//}

Deck::Deck() : deck({ })
{
}

Deck::~Deck()
{
}

void Deck::new_card() {
	deck.push_back(Card(deck.size()));
	deck[deck.size() - 1].recard();
}

void Deck::delete_card(int current) {
	deck.erase(deck.begin() + current);
	std::vector<Card>(deck).swap(deck);
}

void Deck::shuffle() {
	//for (int j = 0; j < deck.size() - 1; ++j)
	//{
		//std::swap(deck[j], deck[std::rand() % deck.size()]);
		std::random_shuffle(deck.begin(), deck.end());
		//Card empty = deck[j];
		//int i = std::rand() % (deck.size() - j) + j;
		//deck[j] = deck[i];
		//deck[i] = empty;
	//}
}

void Deck::restore_order() {
	//std::sort(deck.begin(), deck.end());
	for (int j = 0; j < deck.size(); ++j)
	{
		for (int i = j; i < deck.size(); ++i)
		{
			if (deck[j].getID() > deck[i].getID()) {
			Card empty = deck[j];
			deck[j] = deck[i];
			deck[i] = empty;
			}
		}
	}
}

void Deck::print_Deck() {
	int x = 0, y = 0;
	char vvod = ' ';
	while (vvod != 'q' && vvod != 'Q') {
		system("cls");
		std::cout << "To continue enter 'Q'\n";
		for (int i = 0; i < deck.size(); ++i) {
			x = (i % 4) * 15;
			y = ((i / 4) + 1) * 13;
			deck[i].print_Card(x, y);
			std::cout << "\n***************\n";
		}

		vvod = _getche();
	}
}

void Deck::_print_Deck(int current, int x, int y) {

	if (current == -1) return;

	if (current - 2 >= 0) {
		deck[current - 2].print_Card(x + 1, y);
	}
	if (current - 1 >= 0) {
		deck[current - 1].print_Card(x + 2, y);
	}
	if (current + 2 <= deck.size() - 1) {
		deck[current + 2].print_Card(x + 5, y);
	}
	if (current + 1 <= deck.size() - 1) {
		deck[current + 1].print_Card(x + 4, y);
	}
	deck[current].print_Card(x + 3, y);
}

void Deck::read_file(std::string filename) {
	std::string file_str;
	std::ifstream fin(filename);
	if (!fin.is_open()) { // если файл не открыт
		std::cout << "Файл не может быть открыт!\n"; // сообщить об этом
		return;
	}
	else
	{
		while (!fin.eof()) {
			char ch[120];
			fin.getline(ch, 120);
			file_str = ch;
			//std::cout << file_str;
			deck.push_back(Card(deck.size()));
			deck[deck.size() - 1]._recard(file_str);
		}
	}
	fin.close();
	//system("pause");
	return;
}


void Deck::write_file(std::string filename) {
	std::ofstream fout(filename);
	fout.clear();
	int i = 0;
	while (i < deck.size() - 1) {
		fout << deck[i].write_card();
		fout << "\n";
		++i;
	}
	fout << deck[i].write_card();
	fout.close();
}

void Deck::pole() {
	int current = -1;

	char vvod;
	do {
		system("cls");
		std::cout << "Enter \t1) - to add new card\n\t2) - to shuffle deck\n\t3) - to restore order deck\n\t4) - to wath all cards\n\t5) - to up character\n\ta) - to left card\n\td) - to right card\n\n";
		_print_Deck(current, 1, 10);
		vvod = _getche();

		if (vvod == '1') { new_card(); current = deck.size() - 1; }
		if (vvod == '2') { shuffle();  current = deck.size() - 1; }
		if (vvod == '3') { restore_order(); current = deck.size() - 1; }
		if (vvod == '4') { print_Deck(); current = deck.size() - 1; }
		if (vvod == '5') { read_file("Deck.txt"); current = deck.size() - 1;}
		if (vvod == '6') { write_file("Deck.txt"); current = deck.size() - 1; }
		if (vvod == '7') { 
		int n; 
		std::cout << "Enter char(1 - 6): ";
		std::cin >> n; 	
		while (n > 6 || n < 1) {
			std::cout << "\nEnter char(1 - 6): ";
			std::cin >> n;
		}
		int up;
		std::cout << "Enter up: ";
		std::cin >> up;
		deck[current].character_up(*deck[current].int_to_Character(n), up);
		}
		if (vvod == 'a' || vvod == 'A') { if (current > 0) { current--; } }
		if (vvod == 'd' || vvod == 'D') { if (current < deck.size() - 1) { current++; } }
		if (vvod == 'q' || vvod == 'Q') { break; }
	} while (vvod != 'q' && vvod != 'Q');
}