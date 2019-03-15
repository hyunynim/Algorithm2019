#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;

class BigBinary {
public:
	vector<int> dat;
	BigBinary() {
		dat.push_back(0);
	}
	BigBinary(const vector<int> seq) {
		for (int i = 0; i < seq.size(); ++i)
			dat.push_back(seq[i]);
	}

	void vecMul2(vector<int> & seq) {
		vector<int> tmp1, tmp2;
		for (auto i : seq) {
			tmp1.push_back(i);
			tmp2.push_back(i);
		}
		stack<int> ans;
		int num = 0;
		while (num != 0 || tmp1.size() || tmp2.size()) {
			if (tmp1.size()) {
				num += tmp1.back();
				tmp1.pop_back();
			}
			if (tmp2.size()) {
				num += tmp2.back();
				tmp2.pop_back();
			}
			ans.push(num % 10);
			num /= 10;
		}
		seq.clear();
		while (ans.size()) {
			seq.push_back(ans.top());
			ans.pop();
		}
	}
	vector<int> bin2dec() {
		vector<int> res;
		res.push_back(dat[0]);
		for (int i = 1; i < dat.size(); ++i) {
			vecMul2(res);
			*(res.rbegin()) += dat[i];
		}
		return res;
	}
	BigBinary & operator ++() {
		*(dat.rbegin()) += 1;
		if (dat.back() < 2) return *this;
		reverse(dat.begin(), dat.end());
		int carry = 0;
		for (int i = 0; i < dat.size(); ++i) {
			dat[i] += carry;
			carry = dat[i] / 2;
			dat[i] %= 2;
			if (carry == 0) {
				reverse(dat.begin(), dat.end());
				return *this;
			}
		}
		if (carry) dat.push_back(1);
		reverse(dat.begin(), dat.end());
		return *this;
	}
};

int main() {
	int n;
	scanf("%d", &n);

	vector<vector<vector<int>>> card(n);
	BigBinary b;
	for (; b.dat.size() <= n; ++b) {
		for (int i = 0; i < b.dat.size() && i < n; ++i)
			if (b.dat[i])
				card[i].push_back(b.bin2dec());
	}

	vector<int> bin;
	int has;
	for (int i = 0; i < n; ++i) {
		printf("%d: ", i);
		for (int j = 0; j < card[i].size(); ++j) {
			for (auto i : card[i][j])
				printf("%d", i);
			putchar(' ');
		}
		puts("");
		printf("이 그룹에 숫자가 포함되어 있습니까?(Y:1 N:0) ");
		scanf("%d", &has);
		bin.push_back(has);
	}
	reverse(bin.begin(), bin.end());
	vector<int> ans = BigBinary(bin).bin2dec();
	printf("당신이 고른 숫자는 이겁니다\n");
	for (auto i : ans)
		printf("%d", i);
}