#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

//class Solution {
//public:
//    string reverseStr(string s, int k) {
//        int left = 0, len = s.size();
//        while (left < len) {
//            int right = min(left + k, len) - 1;
//            while (left < right) {
//                swap(s[left], s[right]);
//            }
//            left += 2 * k;
//            cout << left << endl;
//        }
//        return s;
//    }
//};

//class Solution {
//public:
//    string reverseWords(string s) {
//        string res;
//        int left = s.size() - 1, right = s.size() - 1;
//        while (left >= 0) {
//            while (right >= 0 && s[right] == ' ') right--;
//            if (right < 0) break;
//            left = right;
//            while (left >= 0 && s[left] != ' ') left--;
//
//            if (res != "") res += ' ';
//            res += s.substr(left + 1, right - left);
//            right = left;
//        }
//        return res;
//    }
//};

class Solution {
public:
    void getNext(const string& s, int* next) {
        // int next[s.size()];
        int j = -1;
        next[0] = j;
        for (int i = 1; i < s.size(); i++) {
            while (j >= 0 && s[i] != s[j + 1]) {
                j = next[j];
            }
            if (s[j + 1] == s[i]) {
                j++;
            }
            // next[i] = j;
            if (s[j + 1] == s[i]) {
                next[i] = next[j + 1];
            }
            else {
                next[i] = j;
            }
        }
    }

    int strStr(string haystack, string needle) {
        if (haystack.size() < needle.size()) return -1;
        int* next = new int[needle.size()];
        getNext(needle, next);
        int j = -1;
        for (int i = 0; i < haystack.size(); i++) {
            while (j >= 0 && haystack[i] == needle[j + 1]) {
                j = next[j];
            }
            if (haystack[i] == needle[j + 1]) {
                j++;
            }
            if (j == needle.size() - 1) {
                return i - needle.size() + 1;
            }
        }
        return -1;
    }
};



int main() {
    string s1 = "sadbutsad";
    string s2 = "sad";

    Solution solution;
    int ans = solution.strStr(s1, s2);
    cout << ans << endl;
    return 0;

    //int n = 5;
    //int* arr = new int[n];
    //for (int i = 0; i < n; i++) {
    //    arr[i] = i;
    //}

    //for (int i = 0; i < n; i++) {
    //    cout << arr[i];
    //}
}
