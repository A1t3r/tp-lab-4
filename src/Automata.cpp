#include "Automata.h"
#include <stdio.h>
#include <string>
#include <iostream>
#include "windows.h"


using namespace std;

// 0 - off | 1 - wait | 2 - accept | 3 - check | 4 - cook //
Automata::Automata() {
	cash = 0;
	state = 1;
}//�����������

void Automata::on(){
	if (state == 1) {
		std::cout << "\n" << "Machine is already ON";
		return;
	}
	state = 1;
	printState();
} //- ��������� ��������;

void Automata::off() {
	std::cout << "\n" << "Have a nice day!";
	state = 0;
	printState();
	exit(1);
}// - ���������� ��������;

int Automata::coin(int _cash) {
	state = 2;
	printState();
	if (_cash == 0) {
		cancel();
	}
	this->cash += _cash;
	return this->cash;
} //- ��������� ����� �� ���� �������������;

void Automata::printMenu() {
	if (state != 0) {
		std::cout << "Drink" << "|   |" << "Price";
		for (int i = 0; i < 6; i++) {
			std::cout << "\n" << i + 1 << ".|" << this->menu[i] << " |" << " - " << "| " << this->prices[i] << " |";
		}
	}
} //- ����������� ���� � ��������� � ������ ��� ������������;

void Automata::printState() {
	if (state==0) {
		std::cout << "\n" << "OFF" << "\n";
	}

	if (state == 1) {
		std::cout << "\n" << "WAIT" << "\n";
	}

	if (state == 2) {
		std::cout << "\n" << "ACCEPT" << "\n";
	}

	if (state == 3) {
		std::cout << "\n" << "CHECK" << "\n";
	}

	if (state == 4) {
		std::cout << "\n" << "COOK" << "\n";
	}
}// - ����������� �������� ��������� ��� ������������;	

void Automata::choice() {
	int choice;
	int _cash;
	if (state == 0) {
		std::cout << "\n" << "The Machine is OFF";
		return;
	}
	state = 1;
	printState();
	printMenu();
	std::cout << "\n" << "Please, choose the number of drink you want ";
	std::cin >> choice;
	choice -= 1;
	if ((choice > 5) or (choice < 0)) {
		std::cout << "\n" << "You have inserted incorrect number";
		return;
	}
	std::cout << "\n" << "Now insert cash or cancel by pressing 0: ";
	std::cin >> _cash;
	coin(_cash);
	while (!(check(choice))) {
		std::cout << "\n" << "Please, Add money or cancel by pressing 0: ";
		std::cin >> _cash;
		coin(_cash);
	}
	//if (check(choice)) {
		cook();
		state = 1;
		finish();
	//}
} //- ����� ������� �������������;

bool Automata::check(int _i) {
	state = 3;
	printState();
	if (prices[_i]>cash) {
		std::cout << "\n" << "Not enough money";
		return false;
	}
	else {
		cash -= prices[_i];
		return true;
	}
}// - �������� ������� ����������� �����;

void Automata::cancel() {
	std::cout << "\n" << "Take your money - "<<cash;
	off();
}// - ������ ������ ������������ �������������;

void Automata::cook() {
	 state = 4;
	 printState();
	 std::cout << "\n" << "Your drink is preparing now";
	 std::cout << "\n" << ".";
	 Sleep(1000);
	 std::cout << "\n" << "..";
	 Sleep(2000);
	 std::cout << "\n" << "...";
	 Sleep(3000);
	 Beep(523, 350);
	 std::cout << "\n" << "Your drink is ready";
}// - �������� �������� ������������� �������;

void Automata::finish() {
	 std::cout << "\n" << "Take your money - " << cash;
	 off();
}// - ���������� ������������ ������������.