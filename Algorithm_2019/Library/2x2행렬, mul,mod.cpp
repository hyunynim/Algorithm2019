#include<cstdio>
typedef long long ll;

class Matrix {
private:
	ll data[2][2];
public:
	Matrix() {
		data[0][0] = 1;
		data[1][1] = 1;
		data[1][0] = 0;
		data[0][1] = 0;
	}
	Matrix(int E) {
		data[0][0] = E;
		data[1][1] = E;
		data[1][0] = 0;
		data[0][1] = 0;
	}
	Matrix(int a, int b, int c, int d) {
		data[0][0] = a;
		data[1][1] = d;
		data[1][0] = c;
		data[0][1] = b;
	}
	void SetMatrix(int data, int i, int j) {
		this->data[i][j] = data;
	}
	Matrix operator*(Matrix &mat2) {
		Matrix res;
		res.data[0][0] = this->data[0][0] * mat2.data[0][0] + this->data[0][1] * mat2.data[1][0];
		res.data[0][1] = this->data[0][0] * mat2.data[0][1] + this->data[0][1] * mat2.data[1][1];
		res.data[1][0] = this->data[1][0] * mat2.data[0][0] + this->data[1][1] * mat2.data[1][0];
		res.data[1][1] = this->data[1][0] * mat2.data[0][1] + this->data[1][1] * mat2.data[1][1];
		return res;
	}

	Matrix operator%(ll mod) {
		Matrix res;
		res.data[0][0] = this->data[0][0] % mod;
		res.data[0][1] = this->data[0][1] % mod;
		res.data[1][0] = this->data[1][0] % mod;
		res.data[1][1] = this->data[1][1] % mod;
		return res;
	}

	void operator=(Matrix &mat2) {
		this->data[0][0] = mat2.data[0][0];
		this->data[1][0] = mat2.data[1][0];
		this->data[0][1] = mat2.data[0][1];
		this->data[1][1] = mat2.data[1][1];
	}

	void Print() {
		for (int i = 0; i < 2; ++i) {
			for (int j = 0; j < 2; ++j)
				printf("%d ", data[i][j]);
			printf("\n");
		}
	}
	ll GetData(int i, int j) {
		return data[i][j];
	}
};

Matrix mat1(0, 1, 0, 1);

ll pow(ll n, ll m) {
	Matrix res;
	while (n > 0) {
		if (n % 2 != 0) {
			res = mat1 * res;
			res = res % m;
		}
		mat1 = mat1 * mat1;
		mat1 = mat1 % m;
		n /= 2;
	}
	return res.GetData(0, 1)%m;
}