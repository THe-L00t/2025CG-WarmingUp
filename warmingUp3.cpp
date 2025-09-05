#include <iostream>
#include <array>
#include <memory>
#include <cmath>
#include <print>
#include <algorithm>
#include <vector>

struct Point3D {
	Point3D() = default;
	Point3D(int i, int j, int k)
		:x{ i }, y{ j }, z{ k } {

	}
	bool operator<(const Point3D& other) {
		long long d{}, od{};
		d = x * x + y * y + z * z;
		od = other.x * other.x + other.y * other.y + other.z * other.z;
		return d < od;
	}
	bool operator>(const Point3D& other) {
		long long d{}, od{};
		d = x * x + y * y + z * z;
		od = other.x * other.x + other.y * other.y + other.z * other.z;
		return d > od;
	}

	int x;
	int y;
	int z;
};

class VQ {
public:


	void push_back(const Point3D& p) {
		data[b++] = std::make_unique<Point3D>(p);
	}
	void push_front(const Point3D& p) {
		b++;
		if (data[0] not_eq nullptr) {
			memcpy(&data[1], &data[0], sizeof(std::unique_ptr<Point3D>) * (b - f));
		}
		data[0] = std::make_unique<Point3D>(p);
	}
	void shift_down() {
		std::unique_ptr<Point3D> temp{};
		memcpy(&temp, &data[0], sizeof(std::unique_ptr<Point3D>));
		std::cout << "문제 없음1";
		memcpy(&data[0], &data[1], sizeof(std::unique_ptr<Point3D>) * 9);
		memcpy(&data[9], &temp, sizeof(std::unique_ptr<Point3D>));
	}
	void remove_back() {
		data[--b].release();
	}
	void remove_front() {
		data[f++].release();
	}
	void clear() {
		for (auto& p : data) {
			p.release();
		}
	}
	void sort() {
		std::vector<Point3D> temp{};
		for (size_t i = data.size() - 1; i + 1 > 0; --i)
		{
			if (data[i] not_eq nullptr) {
				temp.push_back(*data[i].get());
			}
		}
		std::sort(temp.begin(), temp.end());
		for (size_t i = 9; i+1 > 0; --i)
		{
			if (i < temp.size()) {
				std::println("{:<2}[{:^4} {:^4} {:^4}]", i, temp[i].x, temp[i].y, temp[i].z);
			}
			else {
				std::println("{:<2}[null null null]", i);
			}
		}
	}

	size_t size()const {
		return b-f;
	}
	void print() {
		for (size_t i = data.size()-1; i+1 > 0; --i)
		{
			if (data[i] not_eq nullptr) {
				std::println("{:<2}[{:^4} {:^4} {:^4}]", i, data[i].get()->x, data[i].get()->y, data[i].get()->z);
			}
			else {
				std::println("{:<2}[null null null]", i );
			}
		}
	}
private:
	std::array<std::unique_ptr<Point3D>, 10> data{};
	size_t f{}, b{};
};

int main()
{
	char method{};
	VQ vq;
	int tx{}, ty{}, tz{};

	vq.print();

	Point3D tP{};
	bool ftogle{ true };
	while (method not_eq 'q') {
		std::cout << "method : ";
		std::cin >> method;
		std::cin.clear();
		switch (method) {
		case '+':
			std::cout << "좌표를 입력하세요 : ";
			std::cin >> tP.x >> tP.y >> tP.z;
			std::cin.clear();
			vq.push_back(tP);
			system("cls");
			vq.print();
			break;
		case '-':
			vq.remove_back();
			system("cls");
			vq.print();
			break;
		case 'e':
			std::cout << "좌표를 입력하세요 : ";
			std::cin >> tP.x >> tP.y >> tP.z;
			std::cin.clear();
			vq.push_front(tP);
			system("cls");
			vq.print();
			break;
		case 'd':
			vq.remove_front();
			system("cls");
			vq.print();
			break;
		case 'a':
			std::cout << "저장된 점의 개수는 " << vq.size() << "입니다" << std::endl;
			break;
		case 'b':
			vq.shift_down();
			system("cls");
			vq.print();
			break;
		case 'c':
			vq.clear();
			system("cls");
			vq.print();
			break;
		case 'f':
			if (ftogle) {
				ftogle = false;
				system("cls");
				vq.sort();
			}
			else {
				ftogle = true;
				system("cls");
				vq.print();
			}
			
			break;
		}
	}
}