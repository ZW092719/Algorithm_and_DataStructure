// 单循环链表
#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include<stdlib.h>

typedef int datatype;
using namespace std;
#define MAXSIZE 100

typedef struct Stack{
    datatype stack[MAXSIZE];
    int top; // 栈顶的索引
}Stack;

Stack* ini_stack () {
    Stack* st = new Stack();
    st->top = -1;
    return st;
}

// 判断栈是否为空
bool isEmpty(Stack* st) {
    return st->top == -1;
}

// 入栈
bool push (Stack* st, int x) {
    if (st->top == MAXSIZE - 1) {
        cout<<"栈已满"<<endl;
        return false;
    }
    st->top++;
    st->stack[st->top] = x;
    return true;
}

// 出栈
bool pop (Stack* st, int& x) {
    if (isEmpty(st)) {
        cout<<"当前栈没有元素"<<endl;
        return false;
    }
    x = st->stack[st->top];
    st->top--;
    //cout<<"弹出元素："<<x<<endl;
    return true;
}


void showstack(Stack* st) {
    for (int i = st->top; i >= 0; i--) {
        cout<<st->stack[i]<<endl;
    }
}



// 栈的应用
// 打印N的r进制
void printBinary(int n, int r) {
    Stack* st = ini_stack();
    while (n) {
        push(st, n % r);
        n /= r;
    }
    while (!isEmpty(st)) {
        int x;
        pop(st, x);
        cout<<x;
    }
}

// 判断圆括号是否正确配对
bool isPair (string s) {
    Stack* st = ini_stack();
    int n = s.size(), num = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') push(st, s[i]);
        if (s[i] == ')') {
            if (!isEmpty(st)) {
                pop(st, num);
            }else {
                return false;
            }
        }
    }
    return isEmpty(st);
}

// 检查相邻数字是否连续
bool isContinue (Stack* s) {
    int num;
    queue<int>q;
    // 首先借助队列对栈进行逆序
    while (!isEmpty(s)) {
        pop(s,num);
        q.push(num);
    }
    while (!q.empty()) {
        push(s, q.front());
        q.pop();
    }
    while (!isEmpty(s)) {
        int a; pop(s, a);
        if (!isEmpty(s)) {
            int b; pop(s, b);
            if (abs(a - b) != 1) return false;
        }
    }
}




int main () {
    
    string s = "(2+34+5)-6)";
    cout << isPair(s) << endl;
}

