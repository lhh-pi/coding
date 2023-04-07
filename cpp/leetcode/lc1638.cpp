#include <string>

using namespace std;

class Solution {
private:
    bool isValid(string s1, string s2) {
        //if (s1.size() != s2.size()) return false;
        int diff = 0;
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) {
                if (diff++ == 1) return false;
            }            
        }
        return diff == 1 ? true : false;
    }
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        for (int start = 0; start < s.size(); start++) {
            for (int last = start + 1; last <= s.size(); last++) {
                int lenth = last - start;
                for (int t1 = 0; t1 + lenth <= t.size(); t1++) {
                    if (isValid(s.substr(start, last), t.substr(t1, t1 + lenth))) ans++;
                }
            }
        }
        return ans;
    }
};