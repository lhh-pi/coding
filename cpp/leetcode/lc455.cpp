#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
	int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());
		int i = 0, j = 0, ans = 0;
		while (i < g.size() && j < s.size()) {
			if (s[j] >= g[i]) {
				ans++;
				i++;
			}
			j++;
		}
		return ans;
	}
};

int main() {
	vector<int> g{ 1, 2, 3 };
	vector<int> s{ 1,1 };
	Solution solution;
	int ans = solution.findContentChildren(g, s);
	cout << ans << endl;
}