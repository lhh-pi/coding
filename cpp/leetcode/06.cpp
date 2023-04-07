#include <stack>

using namespace std;

class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
    }

    void push(int x) {
        st1.push(x);
    }

    int pop() {
        if (st2.empty()) {
            while (!st1.empty()) {
                st2.push(st1.top());
                st1.pop();
            }
        }
        int ans = st2.top();
        st2.pop();
        return ans;
    }

    int peek() {
        int p = this->pop();
        this->push(p);
        return p;
    }

    bool empty() {
        return st1.empty() && st2.empty();
    }
};

int main() {
    MyQueue q = MyQueue();
    q.push(1);
    q.push(2);
    q.peek();
    q.pop();
    q.empty();
}