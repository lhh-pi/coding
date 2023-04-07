#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;


class Solution {
private:
    unordered_map<int, string> strs = { {2, "abc"}, {3, "def"}, {4, "ghi"},
                                    {5, "jkl"}, {6, "mno"}, {7, "pqrs"},
                                    {8, "tuv"}, {9, "wxyz"} };
    vector<string> ans;
    string path;

public:
    void search(string digits) {
        if (digits.size() == 0) return;

        for (char ch : strs[(digits[0] - '0')]) {
            path += ch;
            if (digits.size() == 1) ans.push_back(path);
            search(digits.substr(1, digits.size()));
            path = path.substr(0, path.size() - 1);
        }
    }

    vector<string> letterCombinations(string digits) {
        search(digits);
        return ans;
    }
};

int main() {
    string digits = "23";
    Solution solution;
    solution.letterCombinations(digits);
}