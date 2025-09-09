#include <windows.h>
#include <iostream>
#include <conio.h>
#include <array>
#include <algorithm>
#include <random>

std::random_device rd;
std::default_random_engine dre{ rd() };
std::uniform_int_distribution uid{4,20};

void gotoxy(int x, int y)
{
	COORD Cur;
	Cur.X = x;
	Cur.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Cur);
}

class Wu6 {
public:
	Wu6() {
		std::array<int, 900> temp{};
		int xNum{ uid(dre) };
		for (size_t i = 0; i < xNum; i++)
		{
			temp[i] = -1;
		}

		std::shuffle(temp.begin(), temp.end(), dre);
		int tIdx{};
		for (auto& a1 : board) {
			for (auto& i : a1) {
				i = temp[tIdx++];
			}
		}

	}

	void move(int tx, int ty) {
		if (board[py+ty][px+tx] not_eq -1) {
			board[py][px] += 1;
			px += tx;
			py += ty;
			
		}
		if (px < 0 || px >= 30 || py < 0 || py >= 30) {
			px -= tx;
			py -= ty;
			board[py][px] -= 1;
		}
		else {
			old = board[py][px];
		}
	}

	void postPrint() {
		board[py][px] = -2;
	}

	void print() const {
		
		for (const auto& a1 : board) {
			for (const auto& i : a1) {
				switch (i) {
				case -2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
					std::cout << " *";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					
					break;
				case -1:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					std::cout << " X";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					break;
				case 0:
					std::cout << " " << i;
					break;
				case 1:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
					std::cout << " " << i;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					break;
				case 2:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					std::cout << " " << i;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					break;
				case 3:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					std::cout << " "<<i;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					break;
				default:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					std::cout << " "<<i;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					break;
				}
			}
			std::cout << std::endl;
		}
	}

	void afterPrint() {
		board[py][px] = old;
	}

	void reset() {
		std::array<int, 900> temp{};
		int xNum{ uid(dre) };
		for (size_t i = 0; i < xNum; i++)
		{
			temp[i] = -1;
		}

		std::shuffle(temp.begin(), temp.end(), dre);
		int tIdx{};
		for (auto& a1 : board) {
			for (auto& i : a1) {
				i = temp[tIdx++];
			}
		}
		px = 0; py = 0;
	}
private:
	std::array<std::array<int, 30>, 30> board{};
	int px{ 0 }, py{ 0 };
	int old{};

};

int main() {
	char method{};
	Wu6 obj{};
	obj.postPrint();
	obj.print();
	obj.afterPrint();
	gotoxy(0, 0);
	while (method not_eq 'q') {
		if (_kbhit()) {
			method = _getch();
			switch (method) {
			case 'w':
				obj.move(0, -1);
				break;
			case 'a':
				obj.move(-1, 0);
				break;
			case 's':
				obj.move(0, 1);
				break;
			case 'd':
				obj.move(1, 0);
				break;
			case 'r':
				obj.reset();
				break;
			}
			obj.postPrint();
			obj.print();
			obj.afterPrint();
			gotoxy(0, 0);
		}
	}
}