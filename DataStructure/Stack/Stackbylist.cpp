// ��ѭ������
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
    // ���캯�����ڳ�ʼ��ջ
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
        cout << "��ջ: " << value << endl;
    }

    bool pop (int& value) {
        if (isEmpty()) {
            cout << "ջΪ�գ��޷���ջ" << endl;
            return false;
        }
        Node* temp = top;            // �ݴ浱ǰջ���ڵ�
        value = top->data;           // ȡ��ջ��������
        top = top->next;             // ����ջ��Ϊ��һ���ڵ�
        delete temp;                 // �ͷ�ԭջ���ڵ�
        return true;
    }

    // ��ʾջ�е�Ԫ��
    void display() {
        if (isEmpty()) {
            cout << "ջΪ��" << endl;
            return;
        }
        Node* current = top;         // ��ջ����ʼ����
        while (current != nullptr) {
            cout << current->data << " ";  // �����ǰ�ڵ�����
            current = current->next;       // �ƶ�����һ���ڵ�
        }
        cout << endl;
    }
};

// ����ջ����������
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