// 后缀表达式求值
// 这道题需要注意输入的数字不一定是0-9，还可能是12，13.....
#include<bits/stdc++.h>
using namespace std;
int main () {
    stack<int>s; // 声明一个栈
    int a = 0, b = 0, num = 0; // b为栈顶，a为栈顶的下一个元素，运算a在前b在后
    char ch;
    while ((ch = getchar()) != '@') {
        switch(ch)
        {
            case '.': s.push(num); num = 0;break;
            case '+': b = s.top(); s.pop(); a = s.top(); s.pop(); s.push(a + b);break;
            case '-': b = s.top(); s.pop(); a = s.top(); s.pop(); s.push(a - b);break;
            case '*': b = s.top(); s.pop(); a = s.top(); s.pop(); s.push(a * b);break;
            case '/': b = s.top(); s.pop(); a = s.top(); s.pop(); s.push(a / b);break;
            default : num = num * 10 + ch - '0';break;
        }
    }
    printf("%d\n", s.top());
}