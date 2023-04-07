#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
	int maxWidthOfVerticalArea(vector<vector<int>>& point) {
		int ans = 0;
		sort(point.begin(), point.end(), [](vector<int> x, vector<int> y) {return x[0] == y[0] ? x[1] < y[1] : x[0] < y[0]; });
		for (int i = 1; i < point.size(); i++) {
			ans = max(ans, point[i][0] - point[i - 1][0]);
		}
		return ans;
	}
};