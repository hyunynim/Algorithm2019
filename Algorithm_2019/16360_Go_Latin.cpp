#include<iostream>
#include<string>

using namespace std;

int main() {
	int n;
	cin >> n;
	while (n--) {
		string str;
		cin >> str;
		if (str.back() == 'a' || str.back() == 'u')
			str += "s";
		else if (str.back() == 'i' || str.back() == 'y') {
			str.pop_back();
			str += "ios";
		}
		else if (str.size() > 1 && str.back() == 'e' && *(str.end() - 2) == 'n') {
			str.pop_back();
			str.pop_back();
			str += "anes";
		}
		else if (str.back() == 'n') {
			str.pop_back();
			str += "anes";
		}
		else if (str.back() == 'o')
			str.push_back('s');
		else if (str.back() == 'r' || str.back() == 'v' || str.back() == 'l')
			str += "es";
		else if (str.back() == 't' || str.back() == 'w')
			str += "as";
		else
			str += "us";
		cout << str << '\n';
	}
}