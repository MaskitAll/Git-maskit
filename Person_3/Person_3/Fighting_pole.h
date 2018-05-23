#pragma once
#include <vector>
#include "Card.h"
#include "Paint.h"

class Fighting_pole
{
	int current;
	std::vector <Card> fighting_deck;
	bool my_or_other;

public:
	Fighting_pole();
	~Fighting_pole();


};

