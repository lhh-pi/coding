#include <iostream>
#include <sstream>
#include <string>
#include <math.h>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    string input;
    vector<double> res;
    while (getline(cin, input)) {
        if (input.size() == 0) break;
        stringstream strin(input);
        double n = 0.;
        int m = 0;
        double ans = 0.;
        strin >> n;
        strin >> m;
        while (m--) {
            ans += n;
            n = sqrt(n);
        }
        res.push_back(ans);
    }
    for (double v : res) {
        cout << fixed << std::setprecision(2) << v << endl;
    }
}