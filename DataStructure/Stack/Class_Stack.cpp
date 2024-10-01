#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include<stdlib.h>

typedef int datatype;
using namespace std;
#define MAXSIZE 100

class Stack {
private:
    datatype stack[MAXSIZE];
    int top; // 栈顶的索引

public:
    // 构造函数，初始化栈
    Stack() {
        top = -1;
    }

    // 判断栈是否为空
    bool isEmpty() {
        return top == -1;
    }

    // 入栈
    bool push(int x) {
        if (top == MAXSIZE - 1) {
            cout << "栈已满" << endl;
            return false;
        }
        stack[++top] = x;
        return true;
    }

    // 出栈
    // 这是按引用传递,他可以直接修改形参的值,他的形参不再是拷贝,而是传进来什么参数就对参数进行什么操作
    bool pop(int &x) {
        if (isEmpty()) {
            cout << "当前栈没有元素" << endl;
            return false;
        }
        x = stack[top--];
        return true;
    }

    // 显示栈内容
    void showStack() {
        for (int i = top; i >= 0; i--) {
            cout << stack[i] << endl;
        }
    }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.showStack();

    int x;
    if (st.pop(x)) {
        cout << "弹出元素: " << x << endl;
    }
}
