#include <iostream>	
#include <fstream>
#include <string>
#include <vector>
#include <array>
#include <algorithm>
#include <Windows.h>

char beC{}, afC{};
int cnt{}, jE{};

int main() {
	std::ifstream in{ "data.txt" };
	std::vector<std::string> word{ std::istream_iterator<std::string>{in}, std::istream_iterator<std::string>{} };
	
	std::array<std::string, 10> sen;

	//전처리
	{
		for (size_t i = 0; i < 6; i++)
		{
			sen[0] += word[i] + " ";
		}
		for (size_t i = 6; i < 14; i++)
		{
			sen[1] += word[i] + " ";
		}
		for (size_t i = 14; i < 19; i++)
		{
			sen[2] += word[i] + " ";
		}
		for (size_t i = 19; i < 25; i++)
		{
			sen[3] += word[i] + " ";
		}
		for (size_t i = 25; i < 29; i++)
		{
			sen[4] += word[i] + " ";
		}
		for (size_t i = 29; i < 36; i++)
		{
			sen[5] += word[i] + " ";
		}
		for (size_t i = 36; i < 54; i++)
		{
			sen[6] += word[i] + " ";
		}
		for (size_t i = 54; i < 65; i++)
		{
			sen[7] += word[i] + " ";
		}
		for (size_t i = 65; i < 71; i++)
		{
			sen[8] += word[i] + " ";
		}
		for (size_t i = 71; i < 78; i++)
		{
			sen[9] += word[i] + " ";
		}
	}
	std::vector<std::string> tempS{ sen.begin(), sen.end() };

	char method{};

	bool atogle = true, btogle = true, ctogle = true;
	bool dtogle = true, etogle = true, ftogle = true;
	bool gtogle = true, htogle = true;
	int itogle{ 0 };

	std::string temp{};

	for (auto& s : sen) {
		std::cout << s << '\n';
	}
	while (method not_eq 'q') {
		std::cout << std::endl << "method : ";
		std::cin >> method;
		system("cls");
		switch (method)
		{
		case 'a':case 'A':
			if (atogle) {
				atogle = false;
				for (auto& a : sen) {
					for (auto& c : a) {
						std::cout << static_cast<char>(toupper(c));
					}
					std::cout << '\n';
				}
			}
			else {
				atogle = true;
				for (auto& s : sen) {
					std::cout << s <<'\n';
				}
			}
			break;
		case 'b':case'B':
			if (btogle) {
				btogle = false;
				for (size_t i = 0; i < 10; i++)
				{
					int cnt{};
					for (const auto& c : sen[i]) {
						if (c == ' ') cnt++;
					}
					std::cout << sen[i] << cnt << std::endl;
				}
			}
			else {
				btogle = true;
				for (auto& s : sen) {
					std::cout << s << '\n';
				}
			}
			break;
		case 'c':case 'C':
			if (ctogle) {
				ctogle = false;
				int cnt{}, Ent{};
				for (auto& w : word) {
					Ent++;
					if (isupper(w[0])) {
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
						std::cout << w << ' ';
						SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					}
					else {
						std::cout << w << ' ';
					}
					if (Ent == 6 || Ent == 14 || Ent == 19 || Ent == 25 || Ent == 29 || Ent == 36 || Ent == 54 || Ent == 65 || Ent == 71) std::cout << std::endl;
				}
				std::cout << std::endl;
			}
			else {
				ctogle = true;
				for (auto& s : sen) {
					std::cout << s << '\n';
				}
			}
			break;
		case'd':case'D':
			if (dtogle) {
				dtogle = false;
				for (auto& s : sen) {
					for (auto i = s.rbegin()+1; i != s.rend(); i++)
					{
						std::cout << *i;
					}
					std::cout << std::endl;
				}
			}
			else {
				dtogle = true;
				for (auto& s : sen) {
					std::cout << s << '\n';
				}
			}
			break;
		case 'e':case'E':
			if (etogle) {
				etogle = false;
				for (auto& s : tempS) {
					for (auto& c : s) {
						if (c == ' ') c = '/';
					}
				}
				for (auto& s : tempS) {
					std::cout << s << '\n';
				}
			}
			else {
				etogle = true;
				for (auto& s : tempS) {
					for (auto& c : s) {
						if (c == '/') c = ' ';
					}
				}
				for (auto& s : sen) {
					std::cout << s << '\n';
				}

			}
			break;
		case'f':case'F':
			if (ftogle) {
				ftogle = false;
				int Ent{};
				for (auto& c : word) {
					Ent++;
					for (auto i = c.rbegin(); i not_eq c.rend(); i++) {
						std::cout << *i;
					}
					if (not etogle) std::cout << '/';
					else std::cout << ' ';
					if (Ent == 6 || Ent == 14 || Ent == 19 || Ent == 25 || Ent == 29 || Ent == 36 || Ent == 54 || Ent == 65 || Ent == 71) std::cout << std::endl;
				}
			}
			else {
				ftogle = true;
				int Ent{};
				for (auto& c : word) {
					Ent++;
					std::cout << c;
					if (not etogle) std::cout << '/';
					else std::cout << ' ';
					if (Ent == 6 || Ent == 14 || Ent == 19 || Ent == 25 || Ent == 29 || Ent == 36 || Ent == 54 || Ent == 65 || Ent == 71) std::cout << std::endl;
				}
			}
			break;
		case'g':case'G':
			if (gtogle) {
				gtogle = false;
				for (auto& s : sen) {
					std::cout << s << '\n';
				}
				std::cout << std::endl << "바꿀 문자와 새로운 문자를 입력하세요 : ";
				
				std::cin >> beC >> afC;
				std::cin.clear();
				for (auto& s : tempS) {
					for (auto& c : s) {
						if (c == beC) c = afC;
					}
				}
				for (auto& s : tempS) {
					std::cout << s << std::endl;
				}
			}
			else {
				gtogle = true;
				std::copy(sen.begin(), sen.end(), tempS.begin());
				for (auto& s : sen) {
					std::cout << s << std::endl;
				}
			}
			break;
		case'h':case'H':
			if (htogle) {
				htogle = false;
				int Ent{};
				for (auto& s : word) {
					Ent++;
					for (auto& c : s) {
						std::cout << c;
						if (isalnum(c)) std::cout << std::endl;
					}
					std::cout << ' ';
					if (Ent == 6 || Ent == 14 || Ent == 19 || Ent == 25 || Ent == 29 || Ent == 36 || Ent == 54 || Ent == 65 || Ent == 71) std::cout << std::endl;
				}
			}
			else {
				htogle = true;
				for (auto& s : sen) {
					std::cout << s << std::endl;
				}
			}
			break;
		case'i':case'I':
			if (itogle == 0) {
				itogle = 1;
				for (auto& s : tempS) {
					sort(s.begin(), s.end(), [](const char& a, const char& b) {
						return a > b;
						});
					std::cout << s << std::endl;
				}
				
			}
			else if(itogle == 1){
				itogle = 2;
				for (auto& s : tempS) {
					sort(s.begin(), s.end(), [](const char& a, const char& b) {
						return a < b;
						});
					std::cout << s << std::endl;
				}
			}
			else if (itogle == 2) {
				itogle = 0;
				std::copy(sen.begin(), sen.end(), tempS.begin());
				for (auto& s : sen) {
					std::cout << s << std::endl;
				}
			}
			break;
		case'j':case'J':
			for (auto& s : sen) {
				std::cout << s << '\n';
			}
			std::cout << std::endl << "단어를 입력하세요 : ";
			std::cin >> temp;
			std::cin.clear();
			system("cls");
			for (auto& w : word) {
				jE++;
				std::string w1{}, w2{};
				for (char& c : w) {
					w1 += static_cast<char>(tolower(c));
				}
				for (char& c : temp) {
					w2 += static_cast<char>(tolower(c));
				}
				if (w1 == w2) {
					cnt++;
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
					std::cout << w << ' ';
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				}
				else {
					std::cout << w << ' ';
				}
				if (jE == 6 || jE == 14 || jE == 19 || jE == 25 || jE == 29 || jE == 36 || jE == 54 || jE == 65 || jE == 71) std::cout << std::endl;
			}
			std::cout << std::endl << "총 " << cnt << "개 있습니다." << std::endl;
			break;
		default:
			break;
		}
		std::cin.clear();
	}
}