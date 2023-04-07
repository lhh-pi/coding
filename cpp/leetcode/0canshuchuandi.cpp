#include <iostream>

using namespace std;

void foo(int x, int y, int z) {
	cout << "x = " << x << "\ty = " << y << "\tz = " << z << endl;
}

void foo(int x = 0, int y = 0) {
	cout << "x = " << x << "\ty = " << y << endl;
}

// c++参数按位置传递，可以使用默认参数，该定义与(2)冲突，无法确定该调用哪一个，故出错！
//void foo(int x, int y, int z = 0) {
//	cout << "x = " << x << "\ty = " << y << "\tz = " << z << endl;
//}

int main() {
	foo(1);
	foo(1, 2, 3);
	foo(1, 2);
}