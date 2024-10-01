// 中缀表达式转后缀,并打印计算过程
#include<bits/stdc++.h>
using namespace std;
vector<char>change_ans; // 转换为后缀表达式
stack<char>op, op2;
stack<int>data1, data2;
// 定义优先级
int check(char c)
{
	switch(c)
	{
		case '+':return 1;
		case '-':return 1;
		case '*':return 2;
		case '/':return 2;
		case '^':return 3;
		case '(':return 0;
		case ')':return 0;
		default:return -1;
	}
}

int js(int x,int y,char t)
{
	switch(t)
	{
		case '+':return x+y;
		case '-':return x-y;
		case '*':return x*y;
		case '/':return x/y;
		case '^':return pow(x,y);
		default:return -0x3f3f3f3f;//程序不会执行到这里，同样为了保险
	}
}

// 转换为后缀表达式
void change (string s) {
    int n = s.size();
	for (int i = 0; i < n; i++) {
		if (isdigit(s[i])) change_ans.push_back(s[i]);
		else if (s[i] == '(') op.push(s[i]);
		else if (check(s[i]) >= 1 && check(s[i]) <= 3) {
			// 这里有一个条件需要注意,对应测试2^2^3
			while (!op.empty() && check(s[i]) <= check(op.top()) && check(s[i]) != 3) {
				change_ans.push_back(op.top());
				op.pop();
			}
			op.push(s[i]); 
		}
		else if (s[i] == ')') {
			char c = op.top();
			while (!op.empty() && c != '(') {
				change_ans.push_back(c);
				op.pop();
				c = op.top();
			}
			op.pop(); // 最后把'('也弹出
		}
	}
	// 最后将剩余的出栈
	while (!op.empty()) {
		change_ans.push_back(op.top());
		op.pop();
	}
	for (char& cc : change_ans) {
		cout << cc << " ";
	}
	cout << endl;
}

// 后缀表达式求值并打印过程
// 就是一个倒过来再倒回去并打印的操作，需要注意的是两个栈一个为char，另一个为int
void In_solve() {
	int n = change_ans.size();
	for (int i = n - 1; i >= 0; i--) {
		op.push(change_ans[i]);
	}
	while (!op.empty()) {
		char t = op.top();
		op.pop();
		if (isdigit(t)) {
			data1.push(t - '0');
		}else {
			int b = data1.top(); data1.pop();
			int a = data1.top(); data1.pop();
			data1.push(js(a, b, t));
			int x;
			while (!data1.empty()) {
				x = data1.top();
				data1.pop();
				data2.push(x);
			}
			while (!data2.empty()) {
				x = data2.top();
				data2.pop();
				data1.push(x);
				cout << x << " ";
			}
			while (!op.empty()) {
				t = op.top();
				op.pop();
				op2.push(t);
				cout << t << " ";
			}
			while (!op2.empty()) {
				t = op2.top();
				op2.pop();
				op.push(t);
			}
			cout << endl;
		}
	}
}

int main () {
	string s; // 3*2^(4+2*2-1*3)-5
	cin >> s;
	change(s);
	In_solve();
}