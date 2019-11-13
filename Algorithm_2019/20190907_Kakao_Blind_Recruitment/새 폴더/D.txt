#include<bits/stdc++.h>
using namespace std;
struct Trie {
	struct Node {
		int children[26];
		int ans[26];
		bool valid;
		Node() {
			for (int i = 0; i < 26; i++) {
				children[i] = -1;
				ans[i] = -1;
			}
			valid = false;
		}
	};
	vector<Node> trie;
	int root;
	int init() {
		Node x;
		trie.push_back(x);
		return (int)trie.size() - 1;
	}
	Trie() {
		root = init();
	}
	void add(int node, string& s, int index) {
		if (index == s.size()) {
			trie[node].valid = true;
			return;
		}
		int c = s[index] - 'a';
		if (trie[node].children[c] == -1) {
			int next = init();
			trie[node].children[c] = next;
		}
		int child = trie[node].children[c];
		add(child, s, index + 1);
	}
	void add(string& s) {
		add(root, s, 0);
	}
	int search(int node, string& s, int index) {
		if (node == -1) return false;
		if (index == s.length()) return trie[node].valid;
		if (s[index] == '?') {
			int sum = 0;
			for (int i = 0; i < 26; ++i) {
				if (trie[node].ans[i] == -1)
					sum += trie[node].ans[i] = search(trie[node].children[i], s, index + 1);
				else
					sum += trie[node].ans[i];
			}
			return sum;
		}
		int c = s[index] - 'a';
		int child = trie[node].children[c];
		return search(child, s, index + 1);
	}
	int search(string& s) {
		return search(root, s, 0);
	}
};
vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	Trie t[2];
	for (int i = 0; i < words.size(); ++i) {
		t[0].add(words[i]);
		reverse(words[i].begin(), words[i].end());
		t[1].add(words[i]);
	}
	for (int i = 0; i < queries.size(); ++i) {
		if (queries[i].back() == '?') 
			answer.push_back(t[0].search(queries[i]));
		
		else {
			reverse(queries[i].begin(), queries[i].end());
			answer.push_back(t[1].search(queries[i]));
		}
	}
	return answer;
}
int main() {
	vector<string> a[2];
	int p, q; cin >> p >> q;
	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < (i ? q : p); ++j) {
			string str;
			cin >> str;
			a[i].push_back(str);
		}
	}
	vector<int> ans = solution(a[0], a[1]);
	for (auto i : ans)
		cout << i << ' ';
}