#include<iostream>
#include<string>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	string s1 = "", s2 = "", str;
	for (int i = 0; i < n; ++i) {
		cin >> str;
		for (int j = 0; j < m; ++j) {
			s1 += str[j];
			s1 += str[j];
		}
	}
	for (int i = 0; i < n; ++i) {
		cin >> str;
		s2 += str;
	}
	if (s1 == s2)
		printf("Eyfa");
	else
		printf("Not Eyfa");
}