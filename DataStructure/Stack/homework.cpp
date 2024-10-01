#include <iostream>
#include <string>
# define MAXSIZE 100

using namespace std;
typedef struct doubleStack {
    int top0, top1;
    int data[MAXSIZE];
}doubleStack;

doubleStack* ini_ds () {
    doubleStack* ds = new doubleStack();
    ds->top0 = -1; // 0号栈的栈顶
    ds->top1 = MAXSIZE; // 1号栈的栈顶
}

void push (doubleStack* ds, int i, int num) {
    if (i == 0) {
        if (ds->top0 + 1 == ds->top1) cout << "栈已满" << endl; return;
        ds->top0++;
        ds->data[ds->top0] = num;
    }else if (i == 1) {
        if (ds->top1 - 1 == ds->top0) cout << "栈已满" << endl; return;
        ds->top1--;
        ds->data[ds->top1] = num;
    }
}

bool isEmpty (doubleStack* ds, int i) {
    if (i == 0) {
        return ds->top0 == -1;
    }else if (i == 1) {
        return ds->top1 == MAXSIZE;
    }
}

void pop (doubleStack* ds, int i, int& num) {
    if (i == 0) {
        if (isEmpty(ds, 0)) cout << "栈0为空" << endl; return;
        num = ds->data[ds->top0];
        ds->top0--;
    }else if (i == 1) {
        if (isEmpty(ds, 1)) cout << "栈1为空" << endl; return;
        num = ds->data[ds->top1];
        ds->top1--;
    }
}




// 判断回文数
bool isHuiWen(string s) {
    int l = 0, r = s.size() - 2; // 以'@'结尾
    while (l < r) {
        if (s[l] == s[r]) {
            l++; r--;
        }else {
            return false;
        }
    }
    return true;
}




int main () {
    
}