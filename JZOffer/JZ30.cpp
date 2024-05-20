#include<stack>

using namespace std;
class Solution {
//不会写所有操作全为O1的解法,看了看阿秀笔记上的解法
//大致思想就是维持两个栈，一个栈用来PUSH POP，另一个栈用来记录前一个栈每个状态下的最小值信息
private:
    stack<int> s;
    stack<int> m;

public:

    void push(int value) {
        s.push(value);
        if(!m.empty() && m.top()<value)
            m.push(m.top());
        else
            m.push(value);
    }
    void pop() {
        s.pop();
        m.pop();
    }
    int top() {
        return s.top();
    }
    int min() {
        return m.top();
    }
};