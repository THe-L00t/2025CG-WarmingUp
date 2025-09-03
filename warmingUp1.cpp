#include <iostream>	
#include <array>
#include <random>
#include <print>

std::random_device rd;
std::default_random_engine dre{ rd() };
std::uniform_int_distribution<int> uid(1,9);


class Matrix {
public:
	Matrix() {
		for (auto& a : data) {
			for (int& a2 : a) {
				a2 = uid(dre);
			}
		}
	}

	void print() const {
		for (const auto& a : data) {
			std::println("[{:^4}{:^4}{:^4}{:^4}]", a[0], a[1], a[2], a[3]);
		}
	}

	const Matrix& mul(const Matrix& other) {
		Matrix temp{};
		int cnt{ 0 };
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				temp.data[i][j] = 0;
				for (size_t k = 0; k < 4; k++)
				{
					temp.data[i][j] += data[i][k] * other.data[k][j];
				}
			}
		}
		return temp;
	}

	const Matrix& add(const Matrix& other) {
		return Matrix(data[0][0] + other.data[0][0], data[0][1] + other.data[0][1], data[0][2] + other.data[0][2], data[0][3] + other.data[0][3],
			data[1][0] + other.data[1][0], data[1][1] + other.data[1][1], data[1][2] + other.data[1][2], data[1][3] + other.data[1][3],
			data[2][0] + other.data[2][0], data[2][1] + other.data[2][1], data[2][2] + other.data[2][2], data[2][3] + other.data[2][3],
			data[3][0] + other.data[3][0], data[3][1] + other.data[3][1], data[3][2] + other.data[3][2], data[3][3] + other.data[3][3]);
	}

	const Matrix& sub(const Matrix& other) {
		return Matrix(data[0][0] - other.data[0][0], data[0][1] - other.data[0][1], data[0][2] - other.data[0][2], data[0][3] - other.data[0][3],
			data[1][0] - other.data[1][0], data[1][1] - other.data[1][1], data[1][2] - other.data[1][2], data[1][3] - other.data[1][3],
			data[2][0] - other.data[2][0], data[2][1] - other.data[2][1], data[2][2] - other.data[2][2], data[2][3] - other.data[2][3],
			data[3][0] - other.data[3][0], data[3][1] - other.data[3][1], data[3][2] - other.data[3][2], data[3][3] - other.data[3][3]);
	}

	int det() const {
		return determinant4x4(data);
	}

	const Matrix& trans() {
		return Matrix(data[0][0], data[1][0], data[2][0], data[3][0],
			data[0][1], data[1][1], data[2][1], data[3][1],
			data[0][2], data[1][2], data[2][2], data[3][2],
			data[0][3], data[1][3], data[2][3], data[3][3]);
	}

	const Matrix& commandE() {
		int min{10};
		for (const auto& a : data) {
			for (const int& a1 : a) {
				if (a1 < min) {
					min = a1;
				}
			}
		}
		return Matrix(data[0][0] - min, data[0][1] - min, data[0][2] - min, data[0][3] - min,
			data[1][0] - min, data[1][1] - min, data[1][2] - min, data[1][3] - min,
			data[2][0] - min, data[2][1] - min, data[2][2] - min, data[2][3] - min,
			data[3][0] - min, data[3][1] - min, data[3][2] - min, data[3][3] - min);
	}

	const Matrix& commandF() {
		int max{ 0 };
		for (const auto& a : data) {
			for (const int& a1 : a) {
				if (a1 > max) {
					max = a1;
				}
			}
		}
		return Matrix(data[0][0] - max, data[0][1] - max, data[0][2] - max, data[0][3] - max,
			data[1][0] - max, data[1][1] - max, data[1][2] - max, data[1][3] - max,
			data[2][0] - max, data[2][1] - max, data[2][2] - max, data[2][3] - max,
			data[3][0] - max, data[3][1] - max, data[3][2] - max, data[3][3] - max);
	}

	void reset() {
		for (auto& a : data) {
			for (int& a2 : a) {
				a2 = uid(dre);
			}
		}
	}

	void commandNum(int& num) {
		Matrix temp{};
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				if (data[i][j] == num)temp.data[i][j] = data[i][j];
				else temp.data[i][j] = 0;
			}
		}
		temp.print();
	}

	void copy(const Matrix& other) {
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				data[i][j] = other.data[i][j];

			}
		}
	}
private:
	std::array<std::array<int, 4>, 4> data{};

	Matrix(int a1, int a2, int a3, int a4,
		int b1, int b2, int b3, int b4,
		int c1, int c2, int c3, int c4,
		int d1, int d2, int d3, int d4) {
		data[0][0] = a1; data[0][1] = a2;data[0][2] = a3;data[0][3] = a4;
		data[1][0] = b1; data[1][1] = b2;data[1][2] = b3;data[1][3] = b4;
		data[2][0] = c1; data[2][1] = c2;data[2][2] = c3;data[2][3] = c4;
		data[3][0] = d1; data[3][1] = d2;data[3][2] = d3;data[3][3] = d4;
	}

	static int determinant3x3(const std::array<std::array<int, 3>, 3>& mat) {
		return mat[0][0] * (mat[1][1] * mat[2][2] - mat[1][2] * mat[2][1])
			- mat[0][1] * (mat[1][0] * mat[2][2] - mat[1][2] * mat[2][0])
			+ mat[0][2] * (mat[1][0] * mat[2][1] - mat[1][1] * mat[2][0]);
	}

	static std::array<std::array<int, 3>, 3> getMinor(const std::array<std::array<int, 4>, 4>& mat, int row, int col) {
		std::array<std::array<int, 3>, 3> minor{};
		int m_row = 0, m_col = 0;
		for (int i = 0; i < 4; ++i) {
			if (i == row) continue;
			m_col = 0;
			for (int j = 0; j < 4; ++j) {
				if (j == col) continue;
				minor[m_row][m_col++] = mat[i][j];
			}
			++m_row;
		}
		return minor;
	}

	static int determinant4x4(const std::array<std::array<int, 4>, 4>& mat) {
		int det = 0;
		for (int col = 0; col < 4; ++col) {
			auto minor = getMinor(mat, 0, col);
			int cofactor = ((col % 2 == 0) ? 1 : -1) * mat[0][col] * determinant3x3(minor);
			det += cofactor;
		}
		return det;
	}

};

int main() {
	Matrix a, b;
	Matrix atemp, btemp;
	Matrix temp;
	atemp.copy(a);
	btemp.copy(b);
	std::cout << "a 행렬" << std::endl;
	a.print();
	std::cout << "b 행렬" << std::endl;
	b.print();
	char method{};

	bool etogle = true, ftogle = true;
	while (method not_eq 'q') {
		std::cin >> method;
		switch (method) {
		case 'm':case'M':	//곱
			a.mul(b).print();
			break;
		case 'a':case'A':	//덧
			a.add(b).print();
			break;
		case 'd':case'D':	//뺄
			a.sub(b).print();
			break;
		case 'r':case'R':	//행렬식
			std::cout << "a 행렬의 행렬식 : " << a.det()<< std::endl;
			std::cout << "b 행렬의 행렬식 : " << b.det() << std::endl;
			break;
		case 't':case'T':	//전치
			a.trans().print();
			std::cout << "a 전치행렬의 행렬식 : " << a.trans().det() << std::endl;
			b.trans().print();
			std::cout << "b 전치행렬의 행렬식 : " << b.trans().det() << std::endl;
			break;
		case'e':case'E':	//최소 빼기
			if (etogle) {
				etogle = false;
				std::cout << "a 행렬" << std::endl;
				a.commandE().print();
				temp.copy(a.commandE());
				a.copy(temp);
				std::cout << "b 행렬" << std::endl;
				b.commandE().print();
				temp.copy(b.commandE());
				b.copy(temp);
			}
			else {
				etogle = true;
				a.copy(atemp);
				b.copy(btemp);
				a.print();
				b.print();
			}
			break;
		case'f':case'F':	//최대빼기
			if (ftogle) {
				ftogle = false;
				std::cout << "a 행렬" << std::endl;
				a.commandF().print();
				temp.copy(a.commandF());
				a.copy(temp);
				std::cout << "b 행렬" << std::endl;
				b.commandF().print();
				temp.copy(b.commandF());
				b.copy(temp);
			}
			else {
				ftogle = true;
				a.copy(atemp);
				b.copy(btemp);
				a.print();
				b.print();
			}
			break;
		case's':	//re random
			a.reset();
			b.reset();
			atemp.copy(a);
			btemp.copy(b);
			system("cls");
			std::cout << "a 행렬" << std::endl;
			a.print();
			std::cout << "b 행렬" << std::endl;
			b.print();
			break;
		default:	//배수만
			if (method >= '1' && method <= '9') {
				int n = method - '0';
				a.commandNum(n);
				b.commandNum(n);
			}
			break;
		}
		std::cin.clear();
	}
}
