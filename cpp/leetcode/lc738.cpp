#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int monotoneIncreasingDigits(int n) {
		string s = to_string(n);
		int index = s.size();
		for (int i = s.size() - 2; i >= 0; i--) {
			if (s[i] > s[i + 1]) {
				s[i]--;
				index = i + 1;
			}
		}
		for (; index < s.size(); index++) s[index] = '9';
		return stoi(s);
	}
};
