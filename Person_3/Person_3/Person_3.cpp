// Person_3.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#include <string>

#include "Paint.h"
#include "Card.h"
#include "Deck.h"


#include <Windows.h>
#include <iostream>




int main()
{
	Paint Mypaint;
	//Mypaint.fill_box("=", 3, 50, 15, 20, 30);
	//Mypaint.print_text("-----------------\n|               |\n|{s(10, 0)} hello\tWorld {s(15, 0)}|\n|               |\n-----------------\n", 30, 20);
	//std::cout << "\n" << Mypaint.Width_box("----------------------------\n|               |\n\n|{s(10, 0)} hello\tWorld {s(15, 0)}|\n|               |\n-----------------\n") << "\n";
	//Mypaint.print_Hline(5, 5, 15, 20);
	//Mypaint.print_Wline(5, 6, 15, 10);
	//Mypaint.print_box(10, 10, 30, 20, 12);
	//Mypaint.setcur(50, 50);
	//Mypaint.loading(10, 1000, 20, 20);

	Card myCard(5);
	//std::cout << myCard.Card_to_filestring();
	std::cout << "\n\n";
	myCard.recard((std::string)"Maskit", 5, 5, 5555, 34, 12, 3, 3,(std::string)"deadas");
	std::cout << "\n\n";
	std::cout << myCard.Card_to_printstring();
	std::cout << "\n\n";
	myCard.character_up(*myCard.int_to_Character(4), 10);
	myCard.character_up(*myCard.int_to_Character(3), -10);
	Mypaint.print_text(myCard.Card_to_printstring(), 35, 0);


	//std::cout << myCard.Card_to_filestring();
	//std::cout << "\n\n";
	//std::cout << "5   | Maskit        | 1   | 1   | 1   | 1155| 23  | 11  | human   | water   | deadas    |";
	//std::cout << "\n\n";

	//myCard.filestring_to_Card("5   | Maskit        | 1   | 1   | 1   | 1155| 23  | 11  | human   | water   | deadas    |");
	//std::cout << "\n\n";	
	//std::cout << myCard.Card_to_filestring();
	//std::cout << "\n\n";

	Deck mydeck;
	mydeck.new_card();
	
	system("pause");
	return 0;
}

