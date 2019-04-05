#include<iostream>
#include<string>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int cnt = 1;
	while (1) {
		int a, b;
		string op;
		string ans = "";
		cin >> a >> op >> b;
		if (op == "!=") {
			if (a != b)
				ans = "true\n";
			else
				ans = "false\n";
		}
		else if (op == "==") {
			if (a == b)
				ans = "true\n";
			else
				ans = "false\n";
		}
		else if (op == ">") {
			if (a > b)
				ans = "true\n";
			else
				ans = "false\n";
		}
		else if (op == ">=") {
			if (a >= b)
				ans = "true\n";
			else
				ans = "false\n";
		}
		else if (op == "<") {
			if (a < b)
				ans = "true\n";
			else
				ans = "false\n";
		}
		else if (op == "<=") {
			if (a <= b)
				ans = "true\n";
			else
				ans = "false\n";
		}
		else if (op == "E")
			return 0;
		cout << "Case " << cnt++ << ": " << ans;
	}
}