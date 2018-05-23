#pragma once
#include "Deck.h"
#include "Card.h"


class Fighting
{
	Card myCard;
	int posx;
	int posy;
	bool my_or_other;
public:

	Fighting();
	~Fighting();

	void set_pos(int x, int y);

	void print_empty_sqare(int x, int y);
	void print_employed_sqare(int x, int y, Card card);

	void print_person();
	void print_pole();

};

