#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include<stdlib.h>
// 双向循环链表(具有头结点)
using namespace std;
typedef int datatype;

typedef struct Node{
    datatype data;
    Node* next;
    Node* pre;
    int fre;
}Node;

Node* createnode(int x) {
    Node* newnode = new Node();
    newnode->next = NULL;
    newnode->pre = NULL;
    newnode->fre = 0;
    newnode->data = x;
    return newnode;
}

// 初始化
Node* ini_list() {
    Node* head = new Node();
    head->next = head;
    head->pre = head;
    return head;
}

// 头插法
void insert_head (Node* h, datatype x) {
    // 录入数据
    Node* newnode = createnode(x);
    // 插入结点,可以验证对初始情况同样适用
    Node* first = h->next; // 头结点后的第一个结点
    h->next = newnode;
    newnode->pre = h;
    newnode->next = first;
    first->pre = newnode;
}

// 头删结点
void del_head(Node* h) {
    Node* del = h->next;
    h->next = del->next;
    del->next->pre = del->pre;
    delete(del);
}


void show(Node* h) {
    Node* p = h->next;
    // 注意循环的条件控制
    while(p != h) {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<"\n";
    cout<<"频率如下："<<endl;
    p = h->next;
    // 注意循环的条件控制
    while(p != h) {
        cout<<p->fre<<" ";
        p = p->next;
    }
    cout<<"\n\n";
}



// 11.按照访问频率排序
void Locata(Node* h, int x) {
    Node* p = h->next;
    // 访问频率更新
    while (p != h) {
        if (p->data == x) {
            p->fre++;
        }
        p = p->next;
    }
    // 插入排序
    for (Node* i = h->next; i->next != h; i = i->next) {
        for (Node* j = i; j != h && j->next->fre > j->fre; j = j->pre) {
            int temp1 = j->next->data;
            int temp2 = j->next->fre;
            j->next->data = j->data;
            j->next->fre = j->fre;
            j->data = temp1;
            j->fre = temp2;
        }
    }
}



int main () {
    Node* h = ini_list();
    insert_head(h,1);
    insert_head(h,2);
    insert_head(h,3);
    insert_head(h,4);
    insert_head(h,5);
    insert_head(h,6);
    show(h);
    Locata(h,2);
    Locata(h,3);
    Locata(h,3);
    Locata(h,3);
    show(h);
    return 0;
}