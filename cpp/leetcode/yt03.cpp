#include <iostream>

using namespace std;

bool isVaild(int val) {
	if (val % 7 == 0) return false;
	do {
		if (val % 10 == 7) return false;
	} while (val /= 10);
	return true;
}

void fun(int n) {
	for (int i = 1; i <= n / 3; i++) {
		if (!isVaild(i)) continue;
		for (int j = i; j <= (n - i) / 2; j++) {
			if (!isVaild(j)) continue;
			int k = n - i - j;
			if (isVaild(k)) {
				cout << i << " " << j << " " << k << endl;
				return;
			}
		}
	}
	cout << "No Solution!" << endl;
}

int main() {
	int n;
	cin >> n;
	fun(n);
}