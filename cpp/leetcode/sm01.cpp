#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

int main() {
    vector<vector<int>> ans;
    string input;
    while (getline(cin, input)) {
        if (input.size() == 0) break;
        stringstream strin(input);
        int num;
        vector<int> row;
        while (strin >> num) {
            row.push_back(num);
        }
        ans.push_back(row);
    }

    for (int c = 0; c < ans[0].size(); c++) {
        for (int r = 0; r < ans.size(); r++) {
            cout << ans[r][c] << " ";
        }
        cout << endl;
    }



}