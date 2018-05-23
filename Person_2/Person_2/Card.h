	#pragma once
	#include "iostream"
	#include <string>
	#include <Windows.h>



	class Card
	{
	private:
		enum Elements
		{
			air,
			fire,
			ground,
			water,
			light,
			dark
		};

		enum Race
		{
			human,
			elf,
			orс,
			goblin,
			angel,
			gnoll,
			inferno,
			undead
		};

		enum ConsoleColor
		{
			Black = 0,
			Blue = 1,
			Green = 2,
			Cyan = 3,
			Red = 4,
			Magenta = 5,
			Brown = 6,
			LightGray = 7,
			DarkGray = 8,
			LightBlue = 9,
			LightGreen = 10,
			LightCyan = 11,
			LightRed = 12,
			LightMagenta = 13,
			Yellow = 14,
			White = 15
		};

		struct Character {
			const int general;						//изначальная характеристика
			int local;								//с возможными изменениями
			Character& operator=(Character character);
		};

			std::string Name;						//Имя
			const int ID;							//ID карты

			Character lvl;							//уровень
			Character Rhand;						//урон правой рукой
			Character Lhand;						//урон левой рукой
			Character HP;							//количество жизни
			Character Armor;						//броня
			Character Speed;						//скорость

			Race race;								//раса
			Elements elements;						//стихия
			std::string Description;				//описание


	public:


/*+*/		std::string race_to_string(Race race);						//перевод рассы в стринг
/*+*/		std::string elements_to_string(Elements elements);			//перевод елемента в стринг
/*+*/		Card::Character *Card::int_to_Character(int n);

		void setcur(int x, int y);
		void SetColor(int text, int background);
/*+*/		std::string getName();
/*+*/		void setID(int id);
/*+*/		int getID();

/*+*/		Character setCharacter(Character character);
/*+*/		void reCharacter(Character &current, int count);			//переопределить характеристику
/*+*/		void _reCharacter(Character &current, int count);		//изменить значение характеристики local

/*+*/		bool Card::isEmptyCharacter(Character &current);
/*+*/		bool Card::isEmptyCard();



/*+*/		Card& operator=(Card card);
/*+*/		bool& operator==(Card card);
/*+*/		bool& operator<(Card card);
/*+*/		bool& operator>(Card card);

/*+*/		Card();
/*+*/		Card(std::string Name, const int ID, Character lvl, Character Rhand, Character Lhand, Character HP, Character Armor, Character Speed, Race race, Elements elements, std::string Description);
/*+*/		Card(int ID);
/*+*/		~Card();
	
/*+*/		void recard();												//переопределить карту
/*+*/		void _recard(std::string ch);

/*+*/		void character_up(Character &current, int up);

/*+*/		int h_to_12(std::string str, bool h);
/*+*/		void print_Character(Character &current);
/*+*/		void print_Card();
/*+*/		void print_Card(int x, int y);

/*+*/		std::string write_card();

		void pole();

	};

