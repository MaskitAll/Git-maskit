//// Person_2.cpp: ���������� ����� ����� ��� ����������� ����������.
////
//
#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <conio.h>
#include "Card.h"
#include "Deck.h"
#include "fighting.h"	

void main_menu() {
	
	return;
}


int main()
{
	//Fighting fighting;
	//fighting.print_pole();
	system("pause");
	Deck deck;
	deck.pole();

    return 0;
}



/*����� ������ ����� ��� �������� ������� �������*/

//#include <iostream>
//#include <string>
//#include <ctime>
//#include <cstdlib>
//#include <map>
//
//static std::map<std::string, long> gCallingCount;
////#define FCALL_NUM(fn) (gCallingCount[ #fn ])
//#define FCALL_INC     (gCallingCount[ __func__ ] += 1) // ���� ������ ������� ���������� �� ���������� ������,
//// �� ������ ������ InterlockedIncrement()
//void foo() {
//	FCALL_INC;
//}
//
//void foo1() {
//	FCALL_INC;
//}
//
//void foo2() {
//	FCALL_INC;
//}
//// ...
//
//int main() {
//	srand((unsigned)time(NULL));
//	for (int i = 0; i < 100; ++i) {
//		if (rand() % 30 < 10) foo();
//		else if (rand() % 30 < 20 && rand() % 30 > 10) foo1();
//		else foo2();
//	}
//	for (auto & kv : gCallingCount)
//		std::cout << kv.first << " called " << kv.second << " time(s)" << std::endl;
//	system("pause");
//	return 0;
//}