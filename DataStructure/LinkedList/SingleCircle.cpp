// ��ѭ������
#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include<stdlib.h>

using namespace std;
// ��������(����ͷ���)
typedef int datatype;

typedef struct Node{
    datatype data;
    Node* next;
}Node;

Node* ini_Linked() {
    Node* h = new Node();
    h->next = h;
    return h;
}

void insertbyhead(Node* h, int x) {
    Node* newnode = new Node();
    newnode->data = x;
    newnode->next = h->next;
    h->next = newnode;
}

void insertbytail(Node* h, int x) {
    Node* cur = h->next;
    Node* newnode = new Node();
    newnode->data = x;
    newnode->next = h;
    while (cur->next != h) {
        cur = cur->next;
    }
    cur->next = newnode;
}

void show(Node* h) {
    Node* p = h->next;
    // ע��ѭ������������
    while(p != h) {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<"\n";
}


// 8.ɾ��ǰ�����
void delete_before(Node* p) {
    Node* cur = p; // curΪp��ǰ��,��Ҫɾ���Ľ��
    Node* last;  // cur��ǰ�����
    while (cur->next != p) {
        last = cur;
        cur = cur->next;
    }
    last->next = p;
    delete(cur);
}


int main() {
    Node* h = ini_Linked();
    insertbytail(h,1);
    insertbytail(h,2);
    insertbytail(h,5);
    insertbytail(h,7);
    insertbytail(h,8);
    insertbytail(h,9);
    show(h);
    delete_before(h->next->next->next);
    show(h);
    return 0;
}