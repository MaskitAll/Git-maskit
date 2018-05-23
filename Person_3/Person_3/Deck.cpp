#include "stdafx.h"
#include "Deck.h"

Deck::Deck() : deck({})
{
}

Deck::Deck(std::string filename)
{
	std::ifstream fin(filename);
	if (!fin.is_open()) {								// если файл не открыт
		std::cout << "File not founded!\n";	// сообщить об этом
		return;
	}
	else
	{
		while (!fin.eof()) {
			char ch[120];
			fin.getline(ch, 120);
			filename = ch;
			deck.push_back(Card(deck.size()));
			deck[deck.size() - 1].filestring_to_Card(filename);
		}
	}
	fin.close();
}

Deck::~Deck()
{
}

void Deck::new_card() {
	deck.push_back(Card(deck.size()));
}

void Deck::delete_card(int current) {
	deck.erase(deck.begin() + current);
	std::vector<Card>(deck).swap(deck);
}

void Deck::shuffle() {
	std::random_shuffle(deck.begin(), deck.end());
}

void Deck::restore_order() {
	std::sort(deck.begin(), deck.end());
}

