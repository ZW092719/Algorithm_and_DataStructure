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
    int top; // ջ��������

public:
    // ���캯������ʼ��ջ
    Stack() {
        top = -1;
    }

    // �ж�ջ�Ƿ�Ϊ��
    bool isEmpty() {
        return top == -1;
    }

    // ��ջ
    bool push(int x) {
        if (top == MAXSIZE - 1) {
            cout << "ջ����" << endl;
            return false;
        }
        stack[++top] = x;
        return true;
    }

    // ��ջ
    // ���ǰ����ô���,������ֱ���޸��βε�ֵ,�����ββ����ǿ���,���Ǵ�����ʲô�����ͶԲ�������ʲô����
    bool pop(int &x) {
        if (isEmpty()) {
            cout << "��ǰջû��Ԫ��" << endl;
            return false;
        }
        x = stack[top--];
        return true;
    }

    // ��ʾջ����
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
        cout << "����Ԫ��: " << x << endl;
    }
}
