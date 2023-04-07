#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> prevPermOpt1(vector<int>& arr) {
        if (arr.size() == 1) return arr;
       /* if (arr.size() == 2) {
            if (arr[0] > arr[1]) {
                arr[0] += arr[1];
                arr[1] = arr[0] - arr[1];
                arr[0] = arr[0] - arr[1];
            }
            return arr;
        }*/

        int left = arr.size() - 2;
        int pre = arr.back();
        for (; left >= 0; left--) {
            if (arr[left] > pre) break;
            pre = arr[left];
        }

        if (left == -1) return arr;

        int right = left + 1;
        for (; right < arr.size(); right++) {
            if (arr[right] >= arr[left]) break;
        }

        arr[left] += arr[--right];
        arr[right] = arr[left] - arr[right];
        arr[left] = arr[left] - arr[right];
        return arr;
    }
};

int main() {
    Solution solution;
    vector<int> arr = { 1, 1, 5 };
    arr = solution.prevPermOpt1(arr);
    for (int val : arr) {
        cout << val << endl;
    }
}