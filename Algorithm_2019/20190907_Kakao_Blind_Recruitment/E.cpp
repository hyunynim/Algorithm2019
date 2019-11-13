#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;
	vector<vector<int>> a;
	vector<vector<int>> b;
	int board[1010][1010] = { 0 };
	for (int i = 0; i < build_frame.size(); ++i) {
		int y = build_frame[i][0];
		int x = build_frame[i][1];
		int w = build_frame[i][2];
		int ins = build_frame[i][3];
		if (w) {	//º¸
			if (ins) {
				if (board[x - 1][y] == 2 || board[x][y + 1] == 2
					|| (board[x][y - 1] == 1 && board[x][y + 1] == 1))
					board[x][y] = 1;
			}
			else 
				board[x][y] = 0;

		}
		else {		//±âµÕ
			if (ins) {
				if (x == 0 || board[x - 1][y]) {
					board[x][y] = 2;
				}
			}
			else
				board[x][y] = 0;
		}
	}
	return answer;
}