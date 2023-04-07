#include <vector>
using namespace std;

//class Solution {
//private:
//	int count = 0;
//	void search(int n, int start) {
//		if (n == 1) {
//			count += 5 - start;
//			return;
//		}
//		if (n == 0) return;
//		
//		for (int i = start; i < 5; i++) {
//			search(n - 1, i);
//		}
//	}
//public:
//	int countVowelStrings(int n) {
//		count = 0;
//		search(n, 0);
//		return count;
//	}
//};

class Solution {
public:
	int countVowelStrings(int n) {
		vector<int> dp(5, 1);
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < 5; j++) {
				for (int k = 0; k < j; k++) {
					dp[j] += dp[k];
				}
			}
		}
		return dp[4];
	}
};