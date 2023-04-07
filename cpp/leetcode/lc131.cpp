#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    vector<string> path;
    vector<vector<string>> ans;
    bool isPalindrome(string s) {
        int size = s.size();
        for (int i = 0; i < size / 2; i++) {
            if (s[i] != s[size - i - 1]) return false;
        }
        return true;
    }
    void search(string& s, int start) {
        int size = s.size();
        if (start == size) {
            ans.push_back(path);
            return;
        }
        for (int i = start + 1; i <= size; i++) {
            if (!isPalindrome(s.substr(start, i - start))) {
                continue;
            }
            path.push_back(s.substr(start, i - start));
            search(s, i);
            path.pop_back();

        }
    }
public:
    vector<vector<string>> partition(string s) {
        search(s, 0);
        return ans;
    }
};

int main() {
    string s = "aab";
    Solution solution;
    solution.partition(s);
}