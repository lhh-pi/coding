#include <iostream> 
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main() {
	int n = 0;
	std::cin >> n;
	vector<int> arr;
	
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		arr.push_back(num);
	}

	std::sort(arr.begin(), arr.end());

	n = arr.size() - 1;
	long long int ans = arr.back();

	while (arr[n] && n--) {
		if (arr[n] >= arr[n + 1]) {
			arr[n] = arr[n + 1] - 1;
		}
		ans += arr[n];
	}
	cout << ans << endl;
}