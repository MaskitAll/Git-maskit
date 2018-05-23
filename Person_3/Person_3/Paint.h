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


	void setcur(int x, int y);															//Переводит курсор на позицию (х, у)
	void SetColor(int text, int background);											//Изменяет цвет экрана и текста

	bool isNumber(std::string str);														//Проверяет, является ли строка числом
	int Width_box(std::string str);														//Возвращает максимальную длину строки
	void print_text(std::string str, int x, int y);										//Выводит текст с отступом х,у
	void loading(int n, int delay, int x, int y);										//Визуальня картинка загрузки
	void fill_box(int x1, int y1, int x2, int y2);										//Очищает прямоугольник экрна {(x1, y1)(x2, y2)}
	void fill_box(std::string str, int x1, int y1, int x2, int y2);						//Заполняет прямоугольник экрана строками
	void fill_box(std::string str, int width, int x1, int y1, int x2, int y2);			//Рисует полый прямоугольник с шириной стороны widght * str.size()
	void print_Hline(int x, int y, int lenght);											//Рисует горизонтальную линию символами "-"
	void print_Hline(int x, int y, int background, int lenght);							//Рисует горизонтальную линию цветом background
	void print_Wline(int x, int y, int lenght);											//Рисует вертикальную линию символами "|"
	void print_Wline(int x, int y, int background, int lenght);							//Рисует вертикальную линию цветом background
	void print_box(int x1, int y1, int x2, int y2, int background);						//Рисует полый квадрат цветом background

};

