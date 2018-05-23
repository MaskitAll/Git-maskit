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
	~Deck();

	void new_card();						//�������� ����� �����
	void delete_card(int current);			//������� �����
	void shuffle();							//���������� �����
	void restore_order();					//������������ �������
	void print_Deck();
	void _print_Deck(int current, int x, int y);
	void read_file(std::string filename);
	void write_file(std::string filename);

	void pole();
};