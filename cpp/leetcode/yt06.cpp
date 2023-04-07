#include <iostream>
#include <vector>

using namespace std;

// index: chs��������chs[index]����������ַ���S�ĵ�index���ַ���
// prob: ���ʣ� N�� (layer, ��layer���ַ�) M�� (�����ַ��� "#")
// cur: ��ǰ�ݹ鵽���ַ�
// N���ַ�����
// ��һ���ַ�����Ϊ cur(��ǰ����)��chs[index](�¸��ַ�)��#(�ָ���������ΪM-1)
int search(vector<int>& chs, vector<vector<int>>& prob,int& N, int& M, int index, int cur, int layer) {
	int ans = 0;

	// ��ȡ��chs��ĩβ�ַ��� ����ֻ��Ϊ������# ������  // chsǰ���Ͽ죬�����S
	if (index == chs.size()) {
		if (layer == N) { return 1; }  // �ݹ����
		if (cur == M - 1 && prob[layer][M - 1] != 0) ans += prob[layer][M - 1] * search(chs, prob, N, M, index, M - 1, layer + 1);  // cur = M - 1����ʾĩβ����#������ȫ��ֻ����ȡ#
		else if (cur != M - 1 && prob[layer][cur] != 0) {
			ans += prob[layer][cur] * search(chs, prob, N, M, index, cur, layer + 1);  // ȡ����
			ans += prob[layer][M - 1] * search(chs, prob, N, M, index, M - 1, layer + 1);  // ȡ #
		}
		return ans;
	}

	// N - layer == chs.size() - index ʱ��ÿ���ַ���Ҫƥ��  // chsǰ����������ʣ�ַ�����
	if (N - layer == chs.size() - index) {
		if (cur != chs[index] && prob[layer][chs[index]] != 0) ans += prob[layer][chs[index]] * search(chs, prob, N, M, index + 1, chs[index], layer + 1);
		return ans;
	}

	//if (N - layer < chs.size() - index) return 0; // layer��ʣ���Ȳ���

	if (cur != M - 1 && prob[layer][cur] != 0) ans += prob[layer][cur] * search(chs, prob, N, M, index, cur, layer + 1);  // ȡ����
	if (prob[layer][M - 1] != 0) ans += prob[layer][M - 1] * search(chs, prob, N, M, index, M - 1, layer + 1);  // ȡ "#"

	if (chs[index] != cur && prob[layer][chs[index]] != 0) ans += prob[layer][chs[index]] * search(chs, prob, N, M, index + 1, chs[index], layer + 1);  // ȡ��һ���ַ������ܵ��ڵ�ǰ
	//else if (chs[index] != cur && prob[layer][chs[index]] != 0 && index + 1 == chs.size()) ans += prob[layer][chs[index]] * search(chs, prob, N, M, index + 1, chs[index], layer + 1);  // ��ȡ��ĩβ

	return ans % 1009;  // ȡģ
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

	int ans = search(chs, prob, N, M, 0, M - 1, 0); // cur = M - 1 ����ȡ '#'.
	cout << ans;
}