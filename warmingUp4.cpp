#include <array>
#include <iostream>
#include <random>
#include <algorithm>
#include <print>
#include <Windows.h>

std::random_device rd;
std::default_random_engine dre{ rd() };

int cNum{ 9 };

struct cSet {
	char c;
	int status{ 0 };
	int color{};
};

void autoP(const cSet& cs) {
	if (cs.status == 0) {
		std::cout << " * ";
	}
	else if (cs.status == 1) {
		std::cout << " " << cs.c << " ";
	}
	else if (cs.status == 2) {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cs.color);
		std::cout<< " " << static_cast<char>(toupper(cs.c)) << " ";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	}
}

class board {
public:
	board() {
		std::array<char, 25> temp{};
		char tc = 'a';
		for (size_t i = 0; i < 12; i++)
		{
			temp[i] = tc;
			temp[i + 12] = tc++;
		}
		temp[24] = '@';
		size_t idx{};
		std::shuffle(temp.begin(), temp.end(), dre);
		for (auto& a : b) {
			for (auto& c : a) {
				c.c = temp[idx++];
			}
		}
	}

	void play() {
		std::string fir{};
		std::string sec{};
		std::cout << "카드를 입력하세요 : ";
		std::cin >> fir >> sec;
		cnt--;
		if (fir[0] == 'r') {
			reset();
			cnt++;
			return;
		}
		if (fir[0] == 'h') {
			std::cout << "잠시 보여줍니다. " << std::endl;
			hint();
			cnt++;
			return;
		}
		if (not(fir[0] >= 'a' && fir[0] <= 'e') || not(sec[0] >= 'a' && sec[0] <= 'e')) {
			std::cout << "가로 범위를 벗어나는 입력이 있습니다. " << std::endl;
			Sleep(500);
			return;
		}
		if (not(fir[1] >= '1' && fir[1] <= '5') || not(sec[1] >= '1' && sec[1] <= '5')) {
			std::cout << "세로 범위를 벗어나는 입력이 있습니다. " << std::endl;
			Sleep(500);
			return;
		}
		int df1{}, df2{}, ds1{}, ds2{};
		df1 = fir[0] - 'a';
		df2 = fir[1] - '0'-1;
		ds1 = sec[0] - 'a';
		ds2 = sec[1] - '0'-1;
		if (b[df2][df1].status == 2 || b[ds2][ds1].status == 2) {
			std::cout << "이미 맞춘 카드가 있습니다. " << std::endl;
			Sleep(500);
			return;
		}


		if (b[df2][df1].c == b[ds2][ds1].c) {
			b[df2][df1].status = 2;
			b[ds2][ds1].status = 2;
			b[df2][df1].color = cNum;
			b[ds2][ds1].color = cNum++;
			score += 100;
		}
		else if (b[df2][df1].c == '@') {
			b[df2][df1].status = 2;
			b[ds2][ds1].status = 2;
			b[df2][df1].color = cNum;
			b[ds2][ds1].color = cNum;
			score += 150;
			for (auto& a1 : b) {
				for (auto& s : a1) {
					if (s.c == b[ds2][ds1].c) {
						s.status = 2;
						s.color = cNum;
					}
				}
			}
			cNum++;
		}
		else if (b[ds2][ds1].c == '@') {
			b[df2][df1].status = 2;
			b[ds2][ds1].status = 2;
			b[df2][df1].color = cNum;
			b[ds2][ds1].color = cNum;
			score += 150;
			for (auto& a1 : b) {
				for (auto& s : a1) {
					if (s.c == b[ds2][ds1].c) {
						s.status = 2;
						s.color = cNum;
					}
				}
			}
			cNum++;
		}
		else {
			b[df2][df1].status = 1;
			b[ds2][ds1].status = 1;
			print();
			Sleep(700);
			b[df2][df1].status = 0;
			b[ds2][ds1].status = 0;
		}

	}

	void print() const{
		system("cls");
		std::cout << "    a  b  c  d  e" << std::endl;
		int col{ 1 };
		for (auto& a1 : b) {
			std::cout << " " << col++ << " ";
			for (auto& c : a1) {
				autoP(c);
			}
			std::cout << std::endl;
		}
		std::cout << std::endl << "score : " << score << '\t' << "남은 기회 : "<<cnt <<std::endl;
	}

	bool siZero() const {
		return cnt == 0;
	}

	void hint() {
		for (auto& a1 : b) {
			for (auto& s : a1) {
				if (s.status == 0) {
					s.status = 1;
				}
			}
		}
		print();
		Sleep(1000);
		for (auto& a1 : b) {
			for (auto& s : a1) {
				if (s.status == 1) {
					s.status = 0;
				}
			}
		}
	}

	void reset() {
		cNum = 9;
		std::array<char, 25> temp{};
		char tc = 'a';
		for (size_t i = 0; i < 12; i++)
		{
			temp[i] = tc;
			temp[i + 12] = tc++;
		}
		temp[24] = '@';
		size_t idx{};
		std::shuffle(temp.begin(), temp.end(), dre);
		for (auto& a : b) {
			for (auto& c : a) {
				c.c = temp[idx++];
				c.status = 0;
				c.color = 15;
			}
		}
	}
private:
	std::array<std::array<cSet, 5>, 5> b;
	size_t score{};
	size_t cnt{ 5 };
};

int main() {
	board game{};
	game.print();
	while (true) {
		game.print();
		game.play();
		if (game.siZero()) {
			std::cout << "게임이 종료되었습니다. " << std::endl;
			break;
		}
	}
}