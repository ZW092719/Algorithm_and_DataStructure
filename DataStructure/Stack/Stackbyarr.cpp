// ��ѭ������
#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include<stdlib.h>

typedef int datatype;
using namespace std;
#define MAXSIZE 100

typedef struct Stack{
    datatype stack[MAXSIZE];
    int top; // ջ��������
}Stack;

Stack* ini_stack () {
    Stack* st = new Stack();
    st->top = -1;
    return st;
}

// �ж�ջ�Ƿ�Ϊ��
bool isEmpty(Stack* st) {
    return st->top == -1;
}

// ��ջ
bool push (Stack* st, int x) {
    if (st->top == MAXSIZE - 1) {
        cout<<"ջ����"<<endl;
        return false;
    }
    st->top++;
    st->stack[st->top] = x;
    return true;
}

// ��ջ
bool pop (Stack* st, int& x) {
    if (isEmpty(st)) {
        cout<<"��ǰջû��Ԫ��"<<endl;
        return false;
    }
    x = st->stack[st->top];
    st->top--;
    //cout<<"����Ԫ�أ�"<<x<<endl;
    return true;
}


void showstack(Stack* st) {
    for (int i = st->top; i >= 0; i--) {
        cout<<st->stack[i]<<endl;
    }
}



// ջ��Ӧ��
// ��ӡN��r����
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

// �ж�Բ�����Ƿ���ȷ���
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

// ������������Ƿ�����
bool isContinue (Stack* s) {
    int num;
    queue<int>q;
    // ���Ƚ������ж�ջ��������
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

