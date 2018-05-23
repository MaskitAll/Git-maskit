#pragma once

#include <vector>
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include <algorithm>
#include "Deck.h"
#include "Card.h"

class Deck
{
private:
	std::vector <Card> deck;
public:

	Deck();
	Deck(std::string filename);
	~Deck();

	void new_card();						//добавить новую карту
	void delete_card(int current);			//удалить карту
	void shuffle();							//перемешать карты
	void restore_order();					//восстановить порядок



};


