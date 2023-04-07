#include <vector>
#include <iostream>

using namespace std;

//vector<int> dpLeft(vector<int>& array) {
//	vector<int> dp(array.size(), 0);
//	for (int i = 1; i < array.size(); i++) {
//		for (int j = 0; j < i; j++) {
//			if (array[i] > array[j]) dp[i] = dp[i]++;
//		}
//	}
//	return dp;
//}
//
//vector<int> dpRight(vector<int>& array) {
//	vector<int> dp(array.size(), 0);
//	for (int i = array.size() - 2; i >= 0; i--) {
//		for (int j = array.size() - 1; j > i; j--) {
//			if (array[i] > array[j]) dp[i] = dp[i]++;
//		}
//	}
//	return dp;
//}

// ’“µΩ X^2 < Z^2 < Y^2
int main() {
	int N;
	cin >> N;
	vector<int> arr(N, 0);
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
		if (arr[i] < 0) arr[i] = -arr[i];
	}

	const int factor = 1e8 + 7;
	int ans = 0;

	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			if (arr[j] - 1 <= arr[i]) continue;
			for (int k = j + 1; k < N; k++) {
				if (arr[k] > arr[i] && arr[k] < arr[j]) {
					ans++;
					ans %= factor;
					//cout << arr[i] << " " << arr[j] << " " << arr[k] << endl;
				}
			}
		}
	}

	/*vector<int> left = dpLeft(arr);
	vector<int> right = dpRight(arr);
	for (int i = 0; i < arr.size(); i++) {
		ans += left[i] * right[i];
		ans %= factor;
	}*/

	cout << ans << endl;
}