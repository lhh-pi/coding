#include <iostream>

using namespace std;

void foo(int x, int y, int z) {
	cout << "x = " << x << "\ty = " << y << "\tz = " << z << endl;
}

void foo(int x = 0, int y = 0) {
	cout << "x = " << x << "\ty = " << y << endl;
}

// c++������λ�ô��ݣ�����ʹ��Ĭ�ϲ������ö�����(2)��ͻ���޷�ȷ���õ�����һ�����ʳ���
//void foo(int x, int y, int z = 0) {
//	cout << "x = " << x << "\ty = " << y << "\tz = " << z << endl;
//}

int main() {
	foo(1);
	foo(1, 2, 3);
	foo(1, 2);
}