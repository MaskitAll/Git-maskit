#pragma once
#include <Windows.h>
#include <string>
#include <iostream>

#include "Deck.h"
#include "Card.h"

class Paint
{
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

public:
	Paint();
	~Paint();


	void setcur(int x, int y);															//��������� ������ �� ������� (�, �)
	void SetColor(int text, int background);											//�������� ���� ������ � ������

	bool isNumber(std::string str);														//���������, �������� �� ������ ������
	int Width_box(std::string str);														//���������� ������������ ����� ������
	void print_text(std::string str, int x, int y);										//������� ����� � �������� �,�
	void loading(int n, int delay, int x, int y);										//��������� �������� ��������
	void fill_box(int x1, int y1, int x2, int y2);										//������� ������������� ����� {(x1, y1)(x2, y2)}
	void fill_box(std::string str, int x1, int y1, int x2, int y2);						//��������� ������������� ������ ��������
	void fill_box(std::string str, int width, int x1, int y1, int x2, int y2);			//������ ����� ������������� � ������� ������� widght * str.size()
	void print_Hline(int x, int y, int lenght);											//������ �������������� ����� ��������� "-"
	void print_Hline(int x, int y, int background, int lenght);							//������ �������������� ����� ������ background
	void print_Wline(int x, int y, int lenght);											//������ ������������ ����� ��������� "|"
	void print_Wline(int x, int y, int background, int lenght);							//������ ������������ ����� ������ background
	void print_box(int x1, int y1, int x2, int y2, int background);						//������ ����� ������� ������ background

};

