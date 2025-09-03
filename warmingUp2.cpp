#include <iostream>	
#include <fstream>
#include <string>
#include <vector>

int main() {
	std::ifstream in{ "data.txt" };
	std::vector<std::string> v{ std::istream_iterator<std::string>{in}, std::istream_iterator<std::string>{} };

	char method{};

	bool atogle = true;
	while (method not_eq 'q') {
		std::cin >> method;
		switch (method)
		{
		case 'a':case 'A':
			if (atogle) {
				atogle = false;
				for (auto& a : v) {
					for (auto& c : a) {
						std::cout << static_cast<char>(toupper(c));
					}
					std::cout << ' ';
				}
			}
			else {
				atogle = true;
				for (auto& s : v) {
					std::cout << s;
				}
			}
			break;
		case 'b':case'B':
			break;
		case 'c':case 'C':
			break;
		case'd':case'D':
			break;
		case 'e':case'E':
			break;
		case'f':case'F':
			break;
		case'g':case'G':
			break;
		case'h':case'H':
			break;
		case'i':case'I':
			break;
		case'j':case'J':
			break;
		default:
			break;
		}
		std::cin.clear();
	}
}