#include <vector>
#include <iostream>

using namespace std;

class que {
private:
    vector<long long> q;
public:
    int front() {
        return q[0];
    }
    void pop() {
        if (q.empty()) return;
        q.erase(q.begin());
    }
    void push(long long val) {
        if (q.empty() || val > q.back()) {
            q.push_back(val);
            return;
        }
        if (find(q.begin(), q.end(), val) != q.end()) return;
        int left = 0, right = q.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (q[mid] > val) right = mid - 1;
            else if (q[mid] < val) left = mid + 1;
            else return;
        }
        // if (q[right] == val) return;
        if (q[right] < val) right++;
        q.insert(q.begin() + right, val);
    }
};

class Solution {
public:
    int GetUglyNumber_Solution(int index) {
        if (index == 1) return 1;
        que q;
        q.push(1);
        long long ans;
        while (index--) {
            ans = q.front();
            q.push(ans * 2);
            q.push(ans * 3);
            q.push(ans * 5);
            q.pop();
            //cout << 1500 - index << ": " << ans << endl;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    int ans = solution.GetUglyNumber_Solution(1500);
    cout << ans << endl;
    //cout << LLONG_MAX << " - " << INT_MAX << endl;
}