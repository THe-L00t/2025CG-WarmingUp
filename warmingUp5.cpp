#include <array> 
#include <Windows.h>
#include <iostream>
#include <memory>

enum status {
	Null,
	FirR,
	SecR,
	Mul,
	Nov
};

struct Point {
	size_t x{};
	size_t y{};
};

struct Rect {
	Rect() = default;
	Rect(int x1, int y1, int x2, int y2) {
		s.x = x1;s.y = y1;
		w = x2 - x1; h = y2 - y1;
	}
	~Rect() = default;
	Point s{};
	size_t w{}, h{};
};

class map {
public:
	map() {
		for (auto& a1 : m) {
			for (auto& a2 : a1) {
				a2 = Nov;
			}
		}
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				m[i][j] = Null;
			}
		}
	}

	void setRect() {
		std::cout << "input coord value1 : ";
		int a, b, c, d;
		std::cin >> a >> b >> c >> d;
		std::cin.clear();
		ra = std::make_unique<Rect>(a,b,c,d);
		std::cout << "input coord value2 : ";
		std::cin >> a >> b >> c >> d;
		std::cin.clear();
		rb = std::make_unique<Rect>(a, b, c, d);
	}

	void postPrint() {
		for (size_t i = ra.get()->s.y; i < ra.get()->h; i++)
		{
			for (size_t j = 0; j < ra.get()->w; j++)
			{
				m[i][j] = FirR;
			}
		}
		for (size_t i = rb.get()->s.y; i < rb.get()->h; i++)
		{
			for (size_t j = 0; j < rb.get()->w; j++)
			{
				if (m[i][j] == FirR) {
					m[i][j] = Mul;
				}
				else {
					m[i][j] = SecR;
				}
			}
		}
	}

	void setSize(const char& c, int tx,int ty) {
		if (c == 'a') {
			ra.get()->w += tx;
			ra.get()->h += ty;
		}
		else if (c == 'b') {
			rb.get()->w += tx;
			rb.get()->h += ty;
		}
	}
	void move(const char& c, int tx, int ty) {
		if (c == 'a') {
			ra.get()->s.x += tx;
			ra.get()->s.y += ty;
		}
		else if (c == 'b') {
			rb.get()->s.x += tx;
			rb.get()->s.y += ty;
		}
	}

	void 넓이(const char& c)const{
		if (c == 'a') {
			std::cout << "a사각형의 넓이는 " << ra.get()->w * ra.get()->h << "입니다." << std::endl;
		}
		else if (c == 'b') {
			std::cout << "b사각형의 넓이는 " << rb.get()->w * rb.get()->h << "입니다." << std::endl;
		}
	}

	void reset() {
		for (auto& a1 : m) {
			for (auto& a2 : a1) {
				a2 = Nov;
			}
		}
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				m[i][j] = Null;
			}
		}
		ra.release();
		rb.release();
	}

	void plus() {
		w++;h++;
		for (auto& a1 : m) {
			for (auto& a2 : a1) {
				a2 = Nov;
			}
		}
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				m[i][j] = Null;
			}
		}
	}

	void minus() {
		w--;h--;
		for (auto& a1 : m) {
			for (auto& a2 : a1) {
				a2 = Nov;
			}
		}
		for (size_t i = 0; i < h; i++)
		{
			for (size_t j = 0; j < w; j++)
			{
				m[i][j] = Null;
			}
		}
	}
	void print() const{
		system("cls");

		for (auto& a1 : m) {
			for (auto& a2 : a1) {
				switch (a2) {
				case Null:
					std::cout << " +";
					break;
				case FirR:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
					std::cout << " 0";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					break;
				case SecR:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
					std::cout << " @";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					break;
				case Mul:
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
					std::cout << " #";
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
					break;
				default:
					break;
				}
			}
		}
	}
private:
	std::array<std::array<status, 40>, 40> m{};
	size_t w{ 30 }, h{ 30 };
	std::unique_ptr<Rect> ra, rb;
};

int main() {
	char method{};
	map mm{};
	mm.setRect();
	bool togle{ true }, selA{true};
	while (method not_eq 'q') {
		std::cout << "명령어를 입력하세요 : ";
		std::cin >> method;
		switch (method) {
		case'u':
			if (togle) {
				togle = false;	// 크기조정 모드
			}
			else {
				togle = true;
			}
			break;
		case 'i':
			if (selA) {
				selA = false;
			}
			else {
				selA = true;
			}
		case'w':
			if (togle) {
				if (selA) mm.move('a', 0, -1);
				else mm.move('b', 0, -1);
			}
			else {
				if (selA) mm.setSize('a', 0, 1);
				else mm.setSize('b', 0, 1);
			}
			break;
		case 'a':
			if (togle) {
				if (selA) mm.move('a', -1, 0);
				else mm.move('b', -1, 0);
			}
			else {
				if (selA) mm.setSize('a', -1, 0);
				else mm.setSize('b', -1, 0);
			}
			break;
		case's':
			if (togle) {
				if (selA) mm.move('a', 0, 1);
				else mm.move('b', 0, 1);
			}
			else {
				if (selA) mm.setSize('a', 0, -1);
				else mm.setSize('b', 0, -1);
			}
			break;
		case 'd':
			if (togle) {
				if (selA) mm.move('a', 1, 0);
				else mm.move('b', 1, 0);
			}
			else {
				if (selA) mm.setSize('a', 1, 0);
				else mm.setSize('b', 1, 0);
			}
			break;
		case 'c':
			if (selA) {
				mm.넓이('a');
			}
			else {
				mm.넓이('b');
			}
			break;
		case',':	//보드 사이즈 감소
			break;
		case'.':
			break;
		case 'r':
			mm.reset();
			break;

		}
	}
}