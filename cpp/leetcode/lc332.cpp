#include <string>
#include <vector>

using namespace std;

class Solution {
private:
    vector<string> ans;
    vector<string> path;
    string station;

    bool lower(vector<string> s1, vector<string> s2) {
        int size = min(s1.size(), s2.size());
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < 3; j++) {
                if (s1[i][j] < s2[i][j]) return true;
                else if (s1[i][j] > s2[i][j]) return false;
            }
        }
        return false;
    }
    bool lower(string s1, string s2) {
        int size = min(s1.size(), s2.size());
        for (int i = 0; i < size; i++) {
            if (s1[i] > s2[i]) return false;
            else if (s1[i] < s2[i]) return true;
        }
        return false;
    }

    // { {"JFK","SFO"}, {"JFK","ATL"}, {"SFO","ATL"}, {"ATL","JFK"}, {"ATL","SFO"} };
    void search(vector<vector<string>>& tickets, vector<bool> used) {
        if (path.size() == tickets.size() + 1) {
            if (ans.size() == path.size() && lower(path, ans) || ans.size() == 1) ans = path;
            return;
        }
        string station_cur = "";
        if (ans.size() != 1) station_cur = ans[path.size()];
        for (int i = 0; i < tickets.size(); i++) {
            if (used[i] || tickets[i][0] != station) continue;
            if (!lower(tickets[i][1], station_cur)) continue;
            station = tickets[i][1];
            path.push_back(station);
            used[i] = true;
            search(tickets, used);
            path.pop_back();
            used[i] = false;
            station = tickets[i][0];
        }
    }

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        path = { "JFK" };
        ans = { "JFK" };
        station = "JFK";
        vector<bool> used(tickets.size(), false);
        search(tickets, used);
        return ans;
    }
};

// Î´½â¾ö
int main() {
    vector<vector<string>> tickets = { {"JFK","SFO"}, {"JFK","ATL"}, {"SFO","ATL"}, {"ATL","JFK"}, {"ATL","SFO"} };
    Solution solution;
    solution.findItinerary(tickets);
}