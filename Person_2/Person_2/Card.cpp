#include "stdafx.h"
#include "Card.h"

std::string Card::race_to_string(Race race) {
	switch (race)
	{
	case human:
		return "human";
	case elf:
		return "elf";
	case orс:
		return "orc";
	case goblin:
		return "goblin";
	case angel:
		return "angel";
	case gnoll:
		return "gnoll";
	case inferno:
		return "inferno";
	case undead:
		return "undead";
	default:
		break;
	}
	return NULL;
}

std::string Card::elements_to_string(Elements elements) {
	switch (elements)
	{
	case air:
		return "air";
	case fire:
		return "fire";
	case ground:
		return "ground";
	case dark:
		return "dark";
	case light:
		return "light";
	case water:
		return "water";
	default:
		break;
	}
	return NULL;
}

Card::Character *Card::int_to_Character(int n) {
	switch (n)
	{
	case 1:
		return &lvl;
	case 2:
		return &Rhand;
	case 3:
		return &Lhand;
	case 4:
		return &HP;
	case 5:
		return &Armor;
	case 6:
		return &Speed;
	default:
		break;
	}
}

std::string Card::getName() {
	return Name;
}

int Card::getID() {
	return ID;
}

void Card::setID(int id) {
	*(const_cast<int *>(&ID)) = id;
}

void Card::setcur(int x, int y)//установка курсора на позицию  x y, Вызов: setcur(0, 0);
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
};

void Card::SetColor(int text, int background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void Card::print_Character(Character &current) {
	if (current.general < current.local) { SetColor(1, 0); }				//вывод синим цветом
	if (current.general > current.local) { SetColor(4, 0); }				//вывод красным цветом
	std::cout << current.local;
	SetColor(13, 0);
}

void Card::reCharacter(Character &current, int count) {
	*(const_cast<int *>(&current.general)) = count;
	current.local = count;
}

void Card::_reCharacter(Character &current, int count) {
	current.local = count;
}

bool Card::isEmptyCharacter(Character &current) {
	return (current.general != NULL) && (current.local != NULL);
}

bool Card::isEmptyCard() {
	return (Name != "") && (ID != NULL) && (isEmptyCharacter(lvl)) && (isEmptyCharacter(Rhand)) && (isEmptyCharacter(Lhand)) && (isEmptyCharacter(HP)) && (isEmptyCharacter(Armor)) && (isEmptyCharacter(Speed));
}

Card::Character Card::setCharacter(Character character) {
	return character;
}

Card::Character& Card::Character::operator=(Character character) {												//??? 2 варианта ???
																												/*1*/
	Character subcharacter = { 0 ,0 };
	*(const_cast<int *>(&subcharacter.general)) = character.general;
	subcharacter.local = character.local;
	return subcharacter;
	/*2*/
	//return {character.general, character.local};
}

Card& Card::operator=(Card card) {
	setID(card.getID());
	Name = card.Name;

	*(const_cast<int *>(&lvl.general)) = card.lvl.general;
	lvl.local = card.lvl.local;

	race = card.race;

	*(const_cast<int *>(&Rhand.general)) = card.Rhand.general;
	Rhand.local = card.Rhand.local;

	*(const_cast<int *>(&Lhand.general)) = card.Lhand.general;
	Lhand.local = card.Lhand.local;

	*(const_cast<int *>(&HP.general)) = card.HP.general;
	HP.local = card.HP.local;

	*(const_cast<int *>(&Armor.general)) = card.Armor.general;
	Armor.local = card.Armor.local;

	*(const_cast<int *>(&Speed.general)) = card.Speed.general;
	Speed.local = card.Speed.local;

	elements = card.elements;

	Description = card.Description;

	return *this;
}

bool& Card::operator==(Card card) {
	bool a = (Name == card.Name) && (getID() == card.getID());
	return a;
}

bool& Card::operator<(Card card) {
	bool a = getID() < getID();
	return a;
}

bool& Card::operator>(Card card) {
	bool a = getID() > getID();
	return a;
}


Card::Card() : Name(""), ID(NULL), lvl({ NULL, NULL }), Rhand({ NULL, NULL }), Lhand({ NULL, NULL }), HP({ NULL, NULL }), Armor({ NULL, NULL }), Speed({ NULL, NULL }), race(human), elements(air), Description("") {}

Card::Card(int ID) : Name(""), ID(ID), lvl({ 0,0 }), Rhand({ 0,0 }), Lhand({ 0,0 }), HP({ 0,0 }), Armor({ 0,0 }), Speed({ 0,0 }), race(human), elements(air), Description("") {}

Card::Card(std::string Name, const int ID, Character lvl, Character Rhand, Character Lhand, Character HP, Character Armor, Character Speed, Race race, Elements elements, std::string Description)
	: Name(Name), ID(ID), lvl(lvl), Rhand(Rhand), Lhand(Lhand), HP(HP), Armor(Armor), Speed(Speed), race(race), elements(elements), Description(Description) {}

Card::~Card()
{
}

void Card::recard() {
	int n = 0;
	std::cout << "\nEnter new cardName(1-12 symbols): ";
	//getline(std::cin, Name);
	std::cin >> Name;
	while (Name.size() > 12) {
		std::cout << "\nEnter new cardName(1-12 symbols): ";
		std::cin >> Name;
	}

	std::cout << "\nEnter new Rhand damage: ";
	std::cin >> n;
	while (n < 0) {
		std::cout << "\nEnter new Rhand damage: ";
		std::cin >> n;
	}
	reCharacter(Rhand, n);

	std::cout << "\nEnter new Lhand damage: ";
	std::cin >> n;
	while (n < 0) {
		std::cout << "\nEnter new Lhand damage: ";
		std::cin >> n;
	}
	reCharacter(Lhand, n);

	std::cout << "\nEnter new race(0 - 7): ";
	std::cin >> n;
	while (n < 0 || n > 7)
	{
		std::cout << "\nEnter new race(0 - 7): ";
		std::cin >> n;
	}
	race = Race(n);

	std::cout << "\nEnter new maxHP: ";
	std::cin >> n;
	while (n < 0) {
		std::cout << "\nEnter new maxHP: ";
		std::cin >> n;
	}
	reCharacter(HP, n);


	std::cout << "\nEnter new armor: ";
	std::cin >> n;
	while (n < 0) {
		std::cout << "\nEnter new armor: ";
		std::cin >> n;
	}
	reCharacter(Armor, n);

	std::cout << "\nEnter new speed: ";
	std::cin >> n;
	while (n < 0) {
		std::cout << "\nEnter new speed: ";
		std::cin >> n;
	}
	reCharacter(Speed, n);

	std::cout << "\nEnter new card's elements(0 - 5): ";
	std::cin >> n;
	while (n < 0 || n > 7)
	{
		std::cout << "\nEnter new card's elements(0 - 5): ";
		std::cin >> n;
	}
	elements = Elements(n);
}

void Card::_recard(std::string ch)
{
	size_t begin = 0;
	size_t end = 0;
	/*Name*/
	end = ch.find("|");
	Name = ch.substr(begin, end);
	begin = end + 2;
	/*lvl*/
	end = ch.substr(begin).find("|");
	reCharacter(lvl, stoi(ch.substr(begin, end)));
	begin += (end + 2);
	/*race*/
	end = ch.substr(begin).find("|");
	race = Race(stoi(ch.substr(begin, end)));
	begin += (end + 2);
	/*Rhand*/
	end = ch.substr(begin).find("|");
	reCharacter(Rhand, stoi(ch.substr(begin, end)));
	begin += end + 2;
	/*Lhand*/
	end = ch.substr(begin).find("|");
	reCharacter(Lhand, stoi(ch.substr(begin, end)));
	begin += end + 2;
	/*HP*/
	end = ch.substr(begin).find("|");
	reCharacter(HP, stoi(ch.substr(begin, end)));
	begin += end + 2;
	/*Armor*/
	end = ch.substr(begin).find("|");
	reCharacter(Armor, stoi(ch.substr(begin, end)));
	begin += end + 2;
	/*Speed*/
	end = ch.substr(begin).find("|");
	reCharacter(Speed, stoi(ch.substr(begin, end)));
	begin += end + 2;
	/*Elements*/
	end = ch.substr(begin).find("|");
	elements = Elements(stoi(ch.substr(begin, end)));
	begin += end + 2;
	/*Description*/
	Description = ch.substr(begin);
}

void Card::character_up(Character &current, int up) {
	current.local += up;
}

int Card::h_to_12(std::string str, bool h) {		//(h = true) если стоит первым
	if (str.size() > 12) return 0;
	if (!h) {
		if (str.size() % 2 != 0) {
			return ((12 - str.size()) / 2 + 1);
		}
	}
	return ((12 - str.size()) / 2);
}

void Card::print_Card(int x, int y) {	// рисует карту на опр. позиции
										/*1 ---*/
	setcur(x, y);
	SetColor(10, 0);
	std::cout << " ";
	for (int i = 0; i < 12; ++i) { std::cout << "_"; }
	std::cout << " \n";
	SetColor(15, 0);
	/*2 - Name*/
	setcur(x, y + 1);
	SetColor(10, 0);
	std::cout << "/";
	for (int i = 0; i < h_to_12(Name, 1); ++i) { std::cout << " "; }
	std::cout << Name;
	SetColor(10, 0);
	for (int i = 0; i < h_to_12(Name, 0); ++i) { std::cout << " "; }
	std::cout << "\\";
	std::cout << "\n";
	SetColor(15, 0);	
	/*3 - lvl*/
	setcur(x, y + 2);
	SetColor(10, 0);
	std::cout << "|";
	for (int i = 0; i < h_to_12(std::to_string(lvl.local), 1); ++i) { std::cout << " "; }
	print_Character(lvl);
	SetColor(10, 0);
	for (int i = 0; i < h_to_12(std::to_string(lvl.local), 0); ++i) { std::cout << " "; }
	std::cout << "|";
	std::cout << "\n";
	SetColor(15, 0);
	/*4 - race*/
	setcur(x, y + 3);
	SetColor(10, 0);
	std::cout << "|";
	for (int i = 0; i < h_to_12(race_to_string(race), 1); ++i) { std::cout << " "; }
	std::cout << race_to_string(race);
	for (int i = 0; i < h_to_12(race_to_string(race), 0); ++i) { std::cout << " "; }
	std::cout << "|";
	std::cout << "\n";
	SetColor(15, 0);
	/*5 - Hand's*/
	setcur(x, y + 4);
	SetColor(10, 0);
	std::cout << "|";
	for (int i = 0; i < h_to_12(std::to_string(Rhand.local) + " \\ / " + std::to_string(Lhand.local), 1) + 1; ++i) { std::cout << " "; }
	print_Character(Rhand);
	SetColor(10, 0);
	std::cout << " \\/ ";
	print_Character(Lhand);
	SetColor(10, 0);
	for (int i = 0; i < h_to_12(std::to_string(Rhand.local) + " \\ / " + std::to_string(Lhand.local), 0); ++i) { std::cout << " "; }
	std::cout << "|";
	std::cout << "\n";
	SetColor(15, 0);
	/*6 - HP*/
	setcur(x, y + 5);
	SetColor(10, 0);
	std::cout << "|";
	for (int i = 0; i < h_to_12(std::to_string(HP.local), 1); ++i) { std::cout << " "; }
	print_Character(HP);
	SetColor(10, 0);
	for (int i = 0; i < h_to_12(std::to_string(HP.local), 0); ++i) { std::cout << " "; }
	std::cout << "|";
	std::cout << "\n";
	SetColor(15, 0);
	/*7 - Armor*/
	setcur(x, y + 6);
	SetColor(10, 0);
	std::cout << "|";
	for (int i = 0; i < h_to_12(std::to_string(Armor.local), 1); ++i) { std::cout << " "; }
	print_Character(Armor);
	SetColor(10, 0);
	for (int i = 0; i < h_to_12(std::to_string(Armor.local), 0); ++i) { std::cout << " "; }
	std::cout << "|";
	std::cout << "\n";
	SetColor(15, 0);
	/*8 ---*/
	setcur(x, y + 7);
	SetColor(10, 0);
	std::cout << "|";
	for (int i = 0; i < 12; ++i) { std::cout << "-"; }
	std::cout << "|";
	std::cout << "\n";
	SetColor(15, 0);
	/*9 - Speed*/
	setcur(x, y + 8);
	SetColor(10, 0);
	std::cout << "|  /";
	for (int i = 0; i < h_to_12(std::to_string(Speed.local), 1) - 3; ++i) { std::cout << " "; }
	print_Character(Speed);
	SetColor(10, 0);
	for (int i = 0; i < h_to_12(std::to_string(Speed.local), 0) - 3; ++i) { std::cout << " "; }
	std::cout << "\\  |";
	std::cout << "\n";
	SetColor(15, 0);
	/*10 ---*/
	setcur(x, y + 9);
	SetColor(10, 0);
	std::cout << "|";
	for (int i = 0; i < 12; ++i) { std::cout << "-"; }
	std::cout << "|";
	std::cout << "\n";
	SetColor(15, 0);
	/*11 - element*/
	setcur(x, y + 10);
	SetColor(10, 0);
	std::cout << "|";
	for (int i = 0; i < h_to_12(elements_to_string(elements), 1); ++i) { std::cout << " "; }
	std::cout << elements_to_string(elements);
	for (int i = 0; i < h_to_12(elements_to_string(elements), 0); ++i) { std::cout << " "; }
	std::cout << "|";
	std::cout << "\n";
	SetColor(15, 0);
	/*12 ---*/
	setcur(x, y + 11);
	SetColor(10, 0);
	std::cout << "|";
	for (int i = 0; i < 12; ++i) { std::cout << "_"; }
	std::cout << "|";
	std::cout << "\n";
	SetColor(15, 0);
}

std::string Card::write_card() {
	std::string str;
	str = Name;
	for (int i = Name.size(); i < 12; ++i) { str += " "; }
	str = str + "| " + std::to_string(lvl.general);
	for (int i = std::to_string(lvl.general).size(); i < 4; ++i) { str += " "; }
	str = str + "| " + std::to_string(race);
	for (int i = std::to_string(race).size(); i < 4; ++i) { str += " "; }
	str = str + "| " + std::to_string(Rhand.general);
	for (int i = std::to_string(Rhand.general).size(); i < 4; ++i) { str += " "; }
	str = str + "| " + std::to_string(Lhand.general);
	for (int i = std::to_string(Lhand.general).size(); i < 4; ++i) { str += " "; }
	str = str + "| " + std::to_string(HP.general);
	for (int i = std::to_string(HP.general).size(); i < 4; ++i) { str += " "; }
	str = str + "| " + std::to_string(Armor.general);
	for (int i = std::to_string(Armor.general).size(); i < 4; ++i) { str += " "; }
	str = str + "| " + std::to_string(Speed.general);
	for (int i = std::to_string(Speed.general).size(); i < 4; ++i) { str += " "; }
	str = str + "| " + std::to_string(elements);
	for (int i = std::to_string(elements).size(); i < 4; ++i) { str += " "; }
	str = str + "| " + Description;
	for (int i = Description.size(); i < 4; ++i) { str += " "; }
	return str;
}

void Card::pole() {

}