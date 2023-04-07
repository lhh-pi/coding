#include <iostream>
#include <vector>

using namespace std;

// index: chs的索引，chs[index]代表带查找字符串S的第index个字符；
// prob: 概率， N行 (layer, 第layer个字符) M列 (各个字符及 "#")
// cur: 当前递归到的字符
// N：字符总数
// 下一个字符可能为 cur(当前自身)、chs[index](下个字符)、#(分隔符，索引为M-1)
int search(vector<int>& chs, vector<vector<int>>& prob,int& N, int& M, int index, int cur, int layer) {
	int ans = 0;

	// 已取到chs的末尾字符， 后续只能为连续的# 和自身  // chs前进较快，先组成S
	if (index == chs.size()) {
		if (layer == N) { return 1; }  // 递归完成
		if (cur == M - 1 && prob[layer][M - 1] != 0) ans += prob[layer][M - 1] * search(chs, prob, N, M, index, M - 1, layer + 1);  // cur = M - 1，表示末尾已是#，后续全部只可以取#
		else if (cur != M - 1 && prob[layer][cur] != 0) {
			ans += prob[layer][cur] * search(chs, prob, N, M, index, cur, layer + 1);  // 取自身
			ans += prob[layer][M - 1] * search(chs, prob, N, M, index, M - 1, layer + 1);  // 取 #
		}
		return ans;
	}

	// N - layer == chs.size() - index 时，每个字符都要匹配  // chs前进较慢，所剩字符不足
	if (N - layer == chs.size() - index) {
		if (cur != chs[index] && prob[layer][chs[index]] != 0) ans += prob[layer][chs[index]] * search(chs, prob, N, M, index + 1, chs[index], layer + 1);
		return ans;
	}

	//if (N - layer < chs.size() - index) return 0; // layer所剩长度不足

	if (cur != M - 1 && prob[layer][cur] != 0) ans += prob[layer][cur] * search(chs, prob, N, M, index, cur, layer + 1);  // 取本身
	if (prob[layer][M - 1] != 0) ans += prob[layer][M - 1] * search(chs, prob, N, M, index, M - 1, layer + 1);  // 取 "#"

	if (chs[index] != cur && prob[layer][chs[index]] != 0) ans += prob[layer][chs[index]] * search(chs, prob, N, M, index + 1, chs[index], layer + 1);  // 取下一个字符，不能等于当前
	//else if (chs[index] != cur && prob[layer][chs[index]] != 0 && index + 1 == chs.size()) ans += prob[layer][chs[index]] * search(chs, prob, N, M, index + 1, chs[index], layer + 1);  // 已取到末尾

	return ans % 1009;  // 取模
	//return ans;
}

int main() {
	int N = 0, M = 0, K = 0;
	cin >> N >> M >> K;
	vector<int> chs(K, 0);
	for (int i = 0; i < K; i++) {
		cin >> chs[i];
		chs[i]--;  // 0 -- (M - 2)
	}
	vector<vector<int>> prob(N, vector<int>(M, 0));  // prob[i][k]

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) cin >> prob[i][j];
	}

	int ans = search(chs, prob, N, M, 0, M - 1, 0); // cur = M - 1 代表取 '#'.
	cout << ans;
}