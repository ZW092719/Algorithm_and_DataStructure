#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include<stdlib.h>

using namespace std;
// 单向链表(具有头结点)
typedef int datatype;

typedef struct Node{
    datatype data;
    Node* next;
}Node;



// 初始化
Node* ini_Linked() {
    Node* h = new Node();
    h->next = NULL;
    return h;
}

// 头插法
void insertbyhead(Node* h, int x) {
    Node* newnode = new Node();
    newnode->data = x;
    newnode->next = h->next;
    h->next = newnode;
}

// 尾插法
void insertbytail(Node* h, int x) {
    Node* cur = h;
    Node* newnode = new Node();
    newnode->data = x;
    newnode->next = NULL;
    while (cur->next) {
        cur = cur->next;
    }
    cur->next = newnode;
}

// 求链表长度
int findlength(Node* h) {
    Node* cur = h->next;
    int cnt = 0;
    while (cur) {
        cnt++;
        cur = cur->next;
    }
    return cnt;
}

// 查找第i个结点
Node* findi_node(Node* h, int i) {
    int cnt = 0;
    Node* p = h;
    while (p->next && cnt < i) {
        p = p->next;
        cnt++;
    }
    if (cnt < i) {
        cout<<"该结点不存在!"<<endl;
        return NULL;
    }
    return p;
}

// 在i位置插入结点
void insertbyidx(Node* h, int i, int x) {
    Node* newnode = new Node;
    newnode->data = x;
    Node* pre = findi_node(h, i-1);
    if (pre == NULL) {
        cout<<"无法插入"<<endl;
        return;
    }
    newnode->next = pre->next;
    pre->next = newnode;
}

// 删除第i个结点
void deletebyidx(Node* h, int i) {
    Node* pre = findi_node(h, i-1);
    if (pre == NULL) {
        cout<<"无法删除"<<endl;
        return;
    }
    if (pre->next == NULL) {
        cout<<"要删除的结点不存在"<<endl;
        return;
    }
    Node* del = pre->next;
    pre->next = del->next;
    delete del; // 释放内存
}

// 单向链表的一些应用
// 1.逆序链表(有哨兵节点的情况)(与力扣的反转链表不太一样)
void reverse_list(Node* h) {
    Node* cur = h->next;
    Node* p;
    h->next = NULL;
    while (cur) {
        p = cur;
        cur = cur->next; // 注意他的位置!
        p->next = h->next;
        h->next = p;
    }
}
// 无头结点的操作
Node* reverseList(Node* head) {
    Node* pre = NULL;
    Node* cur = head;
    while (cur) {
        Node* next = cur->next;
        cur->next = pre;
        pre = cur;
        cur = next;
    }
    return pre;
}

// 2.删除重复结点
void delete_rep(Node* h) {
    Node* cur = h->next;
    while (cur->next) {
        Node* p = cur;
        while (p->next) {
            if (p->next->data == cur->data) {
                Node* rem = p->next;
                p->next = rem->next;
                delete(rem);
            }else {
                p = p->next;
            }
        }
        cur = cur->next;
    }
}

// 3.合并两个升序链表为降序链表
Node* merge_two_decrease(Node* A, Node* B) {
    Node* anext = A->next;
    Node* bnext = B->next;
    Node* cur;
    Node* C = new Node();
    // 头插法
    while (anext && bnext) {
        if (anext->data < bnext->data) {
            cur = anext;
            anext = anext->next;
        }else {
            cur = bnext;
            bnext = bnext->next;
        }
        cur->next = C->next;
        C->next = cur;
    }
    while (anext) {
        cur = anext;
        anext = anext->next;
        cur->next = C->next;
        C->next = cur;
    }
    while (bnext) {
        cur = bnext;
        bnext = bnext->next;
        cur->next = C->next;
        C->next = cur;
    }
    return C;
}

// 3.合并两个升序链表为升序链表
Node* merge_two_increase(Node* A, Node* B) {
    Node* anext = A->next;
    Node* bnext = B->next;
    Node* head = new Node();
    Node* tail = head;
    // 头插法
    while (anext && bnext) {
        if (anext->data < bnext->data) {
            tail->next = anext;
            anext = anext->next;
        }else {
            tail->next = bnext;
            bnext = bnext->next;
        }
        tail = tail->next;
    }
    if (anext) {
        tail->next = anext;
    } else if (bnext) {
        tail->next = bnext;
    }
    return head;
}


// 链表销毁
// 要对头结点进行操作需要使用2级指针
void destroy(Node** h) {
    Node* p = *h;
    while (p) {
        Node* nextnode = p->next;
        delete(p);
        p = nextnode;
    }
    *h = NULL; // 置为空
    cout<<"链表已销毁"<<endl;
}


void show(Node* h) {
    if (h == NULL) {
        cout<<"链表不存在"<<endl;
        return;
    }
    Node* p = h->next;
    while(p) {
        cout<<p->data<<" ";
        p = p->next;
    }
    cout<<"\n";
}


// 作业部分
//6.按顺序插入结点
void insert_order(Node* h, int x) {
    Node* newnode = new Node();
    newnode->data = x;
    Node* p = h->next;
    while (p->next && newnode->data > p->next->data) {
        p = p->next;
    }
    newnode->next = p->next;
    p->next = newnode;
}

// 7.两个递增链表和并为整体递增
Node* work_merge_two_increase(Node* A, Node* B) {
    Node* anext = A->next;
    Node* bnext = B->next;
    Node* C = new Node();
    Node* tail = C;
    while (anext && bnext) {
        if (anext->data < bnext->data) {
            tail->next = anext;
            anext = anext->next;
        }else {
            tail->next = bnext;
            bnext = bnext->next;
        }
        tail = tail->next;
    }
    if (anext) {
        tail->next = anext;
    } else if (bnext) {
        tail->next = bnext;
    }
    return C;
}

// 9.求出A和B的交集,并递增排列
// 对于A中每个结点在B中寻找，找到了就挂在C上，没找到A就来到下一个结点
Node* find_equal_and_merge(Node* A, Node* B) {
    Node* C = new Node();
    Node* tailc = C;
    Node* cura = A->next;
    while (cura) {
        Node* curb = B->next;
        while (curb) {
            if (curb->data == cura->data) {
                tailc->next = curb;
                tailc = curb;
                break;
            }
            curb = curb->next;
        }
        cura = cura->next;
    }
    tailc->next = NULL;
    return C; // 最后将B不匹配的剩余结点断开
}

// 10.找到链表中倒数第n个结点
// 滑动窗口(维持一个长度为n的滑窗,当right边界来到最后一个结点停止)
Node* find_backwords_nth(Node* h, int n) {
    Node* left = h->next;
    Node* right = h->next;
    // 生成窗口
    int cnt = 0;
    while (cnt < n - 1) {
        cnt++;
        right = right->next;
    }
    while (right->next) {
        right = right->next;
        left = left->next;
    }
    return left;
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
    Node* h1 = ini_Linked();
    insertbytail(h1,2);
    insertbytail(h1,3);
    insertbytail(h1,5);
    insertbytail(h1,9);
    insertbytail(h1,10);
    insertbytail(h1,11);
    Node* head = find_equal_and_merge(h,h1);
    Node* node = find_backwords_nth(h,5);
    cout<<node->data<<endl;
    show(head);
    return 0;
    
}
