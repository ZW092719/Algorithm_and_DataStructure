// 单循环链表
#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include<stdlib.h>

typedef int datatype;
using namespace std;
typedef struct Node {
    datatype data;
    Node* next;
}Node;

class Stack {
private:
    
public:
    Node* top;
    // 构造函数用于初始化栈
    Stack() {
        top = nullptr;
    }

    bool isEmpty () {
        return top == nullptr;
    }

    void push (int value) {
        Node* newnode = new Node();
        newnode->data = value;
        newnode->next = top;
        top = newnode;
        cout << "入栈: " << value << endl;
    }

    bool pop (int& value) {
        if (isEmpty()) {
            cout << "栈为空，无法出栈" << endl;
            return false;
        }
        Node* temp = top;            // 暂存当前栈顶节点
        value = top->data;           // 取出栈顶的数据
        top = top->next;             // 更新栈顶为下一个节点
        delete temp;                 // 释放原栈顶节点
        return true;
    }

    // 显示栈中的元素
    void display() {
        if (isEmpty()) {
            cout << "栈为空" << endl;
            return;
        }
        Node* current = top;         // 从栈顶开始遍历
        while (current != nullptr) {
            cout << current->data << " ";  // 输出当前节点数据
            current = current->next;       // 移动到下一个节点
        }
        cout << endl;
    }
};

// 利用栈将链表逆置
void inverseList (Node* h) {
    Stack s;
    Node* temp = h->next;
    while (temp) {
        s.push(temp->data);
        temp = temp->next;
    }
    temp = h->next;
    while (temp) {
        int num = 0;
        s.pop(num);
        temp->data = num;
        temp = temp->next;
    }
}


int main() {
    Stack st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.display();
    int x;
    st.pop(x);
    st.display();
    return 0;
}