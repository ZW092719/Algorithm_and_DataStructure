// 顺序表
#include<iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include<stdlib.h>
#define MAXSIZE 100
typedef char ElemType;
using namespace std;
typedef struct {
    ElemType data[MAXSIZE];
    int length; // 当前顺序表的长度
}Seqlist;

// 顺序表初始化
Seqlist* ini_sqlist() {
    Seqlist* l = new Seqlist();
    l->length = 0;
    return l;
}
// 插入操作
bool insert(Seqlist* L, int posi, ElemType x) { // 插入位置1<=posi<=n+1, a1,a2...an
    if (L->length == MAXSIZE) {
        cout<<"当前顺序表已满"<<endl;
        return false;
    }else if (posi < 1 || posi > L->length + 1) {
        cout<<"插入位置出错"<<endl;
        return false;
    }
    int idx = posi - 1; // 要插入的索引位置
    int n = L->length;
    for (int i = n; i > idx; i--) {
        L->data[i] = L->data[i-1];
    }
    L->data[idx] = x;
    L->length++;
    return true;
}

// 删除操作
bool del(Seqlist* L, int posi) {
    int n = L->length;
    if (n == 0) {
        cout<<"当前顺序表没有元素"<<endl;
        return false;
    }else if (posi < 1 || posi > n) {
        cout<<"删除错误"<<endl;
    }
    int idx = posi - 1; // 要删除位置的索引
    for (int i = idx; i < n - 1; i++) {
        L->data[i] = L->data[i+1]; 
    }
    L->length--;
    return true;
}
// 查找值x是否在顺序表中
bool search(Seqlist* l, int x) {
    int n = l->length;
    for (int i = 0; i < n; i++) {
        if (l->data[i] == x) {
            return true;
        }
    }
    return false;
}

// 顺序表的应用
// 1.以第一个元素为界限重新划分顺序表
void part(Seqlist*l) {
    int n = l ->length;
    int x = l->data[0];
    for (int i = 1; i < n; i++) {
        if (l->data[i] < x) {
            int temp = l->data[i];
            for (int j = i - 1; j >=0; j--) {
                l->data[j+1] = l->data[j];
            }
            l->data[0] = temp;
        }
    }
}
// 2. 合并两个有序数组到c
void merge(Seqlist*l1, Seqlist* l2, Seqlist*c) {
    int n1 = l1->length, n2 = l2->length;
    int i = 0, j = 0, idx = 0;
    while (i < n1 && j < n2) {
        c->data[idx++] = l1->data[i] < l2->data[j] ? l1->data[i++] : l2->data[j]++; 
    }
    while (i < n1) {
        c->data[idx++] = l1->data[i++];
    }
    while (j < n2) {
        c->data[idx++] = l2->data[j++];
    }
}

// 3.比较顺序表大小
// 返回1代表l1 > l2,相等返回0, 小于返回-1
int compare(Seqlist*l1, Seqlist*l2) {
    // 顺序表最短长度
    int n = l1->length < l2->length ? l1->length : l2->length;
    // 先提取公共前缀
    int i = 0;
    while (i < n && l1->data[i] == l2->data[i]) {
        i++;
    }
    // l1、l2剩余长度
    int left_l1 = l1->length - i;
    int left_l2 = l2->length - i;
    // 两者一样
    if (left_l1 == left_l2 && left_l1 == 0) {
        return 0;
    }else if (left_l1 > 0 && left_l2 == 0 || left_l1 > 0 && left_l2 > 0 && l1->data[i] > l2->data[i]) {
        return 1;
    }else {
        return -1;
    }
}


// 顺序表作业
// 1.在有序的顺序表中插入数字
void insertbyorder(Seqlist* l, int x) {
    int n = l->length;
    for (int i = 1; i < n ; i++) {
        if (x <= l->data[i] && x >= l->data[i-1]) {
            for (int j = n; j > i; j--) {
                l->data[j] = l->data[j - 1];  
            }
            l->data[i] = x;
            l->length++;
            return;
        }
    }
    // 如果 x 比所有元素都大，则在末尾插入
    l->data[n] = x;
    l->length++;
}

// 2.删除顺序表中的重复数字
void deleterep(Seqlist*l) {
    int n = l->length;
    for (int i = 1; i < l->length; i++) {
        if (l->data[i] == l->data[i-1]) {
            int j = i;
            while (l->data[i-1] == l->data[j]) {
                j++;
            }
            int del_num = j - i + 1; // 删除元素的个数
            for (int begin = j; begin < n; begin++) {
                l->data[begin - del_num] = l->data[begin];
            }
            l->length -= del_num;
        }
    }
}

// 3.删除x~y所有元素
void delete_area(Seqlist*l, int x, int y) {
    sort(l->data, l->data + l->length); // 先对顺序表排序小到大
    int n = l->length;
    for (int i = 0; i < l->length; i++) {
        if (l->data[i] >= x) {
            int begin = i, stop = begin;
            // 找到这个范围的坐标
            while (l->data[stop] <= y) {
                stop++;
            }
            int del_num = stop - begin;
            for (int idx = stop; idx < n; idx++) {
                l->data[idx - del_num] = l->data[idx];
            }
            l->length -= del_num;
        }
    }
}

// 4.按字母、数字其他字符的顺序排序
bool isch(char c) {
    if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') {
        return true;
    }
    return false;
}
bool isnum(char c) {
    if (c >= '0' && c <= '9') {
        return true;
    }
    return false;
}
void resort(Seqlist* l) {
    int n = l->length;
    int left = 0, right = n - 1;
    // 字母放在前
    while (left < right) {
        while (left < right && isch(l->data[left])) left++;
        while (left < right && !isch(l->data[right])) right--;
        if (left < right) {
            char temp = l->data[left];
            l->data[left] = l->data[right];
            l->data[right] = temp;
        }
    }
    // 接着调整数字在前
    left++; right = n - 1;
    while (left < right) {
        while (left < right && isnum(l->data[left])) left++;
        while (left < right && !isnum(l->data[right])) right--;
        if (left < right) {
            char temp = l->data[left];
            l->data[left] = l->data[right];
            l->data[right] = temp;
        }
    }
}

// 5.前m个后n个整体互换
// 反转函数
void reverse(Seqlist* l, int left, int right) {
    while (left < right) {
        int temp = l->data[left];
        l->data[left] = l->data[right];
        l->data[right] = temp;
        left++;
        right--;
    }
}
void exchange(Seqlist* l, int m, int n) {
    // 先部分反转
    reverse(l, 0, m - 1);
    reverse(l, m, m + n - 1);
    // 整体反转
    reverse(l, 0, m + n - 1);
}








void show(Seqlist* L) {
    for (int i = 0; i < L->length; i++) {
        cout<<L->data[i]<<" ";
    }
    cout<<"\n";
}






int main() {
    Seqlist* L = ini_sqlist();
    insert(L,1,'1');
    insert(L,2,'2');
    insert(L,3,'a');
    insert(L,4,'f');
    insert(L,5,'t');
    insert(L,6,'+');
    insert(L,7,'-');
    insert(L,8,'6');
    show(L);
    exchange(L,3, 5);
    show(L);
    cout<<L->length<<endl;
    return 0;
}