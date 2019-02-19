#include<iostream>
#include<string>

using namespace std;

int main() {
	string str;
	cin >> str;
	int l = 0, r = str.size() - 1;
	bool pal = 1;
	while (l < r) {
		if (str[l] != str[r]) {
			pal = 0; break;
		}
		++l; --r;
	}
	cout << pal;
}