#include <iostream>
#include <string>
using namespace std;

//int main() {
//    int a, b;
//    while (cin >> a >> b) { // 注意 while 处理多个 case
//        cout << a + b << endl;
//    }
//}
//int main() {
//    int n;
//    cin >> n;
//    string str = to_string(n);
//    int size = str.size();
//    int used[10] = { 0 };
//    string ans;
//    while (--size >= 0) {
//        char ch = str[size];
//        if (used[ch - '0'] == 0) {
//            ans += ch;
//            used[ch - '0'] = 1;
//        }
//    }
//
//    cout << stoi(ans) << endl;
//}

//int main() {
//    string str;
//    int cnt[128] = {};
//    int ans = 0;
//    getline(cin, str);
//    for (char ch : str) {
//        if (cnt[(int)ch] == 0) {
//            cnt[(int)ch] = 1;
//            ans++;
//        }
//    }
//    return ans;
//}
//int main() {
//	string str;
//	getline(cin, str);
//	cout << str.size() << endl;
//	cout << str << endl;
//}

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool isVaild(string si, string sr) {
    return si.find(sr) != string::npos;
}

int main() {
    vector<string> I, R;
    int n;
    string num;
    cin >> n;
    while (n--) {
        cin >> num;
        I.push_back(num);
    }

}
// 64 位输出请用 printf("%lld")