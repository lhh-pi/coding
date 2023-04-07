#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> ans;
    vector<string> ip;
    bool legal(string s) {
        if (s.size() > 3 || s.size() > 1 && s[0] == '0') return false;
        if (stoi(s) > 255) return false;
        return true;
    }

    void search(string &s, int start) {
        int size = s.size();
        if (ip.size() == 3) {
            string s1 = s.substr(start, size - start);
            if (legal(s1)) {
                string ips;
                for (string ss : ip) ips += ss + '.';
                ips += s1;
                ans.push_back(ips);
            }
            return;
        }

        for (int i = start + 1; i < min(4 + start, size); i++) {
            if (!legal(s.substr(start, i - start))) continue;
            ip.push_back(s.substr(start, i - start));
            search(s, i);
            ip.pop_back();
        }
    }

public:
    vector<string> restoreIpAddresses(string s) {
        ans.clear();
        ip.clear();
        if (s.size() > 12 || s.size() < 4) return ans;
        search(s, 0);
        return ans;
    }
};

int main() {
    string s = "25525511135";
    Solution solution;
    solution.restoreIpAddresses(s);
}