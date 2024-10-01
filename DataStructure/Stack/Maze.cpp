#include<iostream>
#include<cstdlib>
#include <ctime>
using namespace std;

// 迷宫实际大小m行,n列
#define m 6
#define n 8
// 栈中元素
typedef struct elem {
    int i, j, d;
}item;

typedef struct Stack {
    elem stack[65];
    int top;
}Stack;

Stack* ini_Stack() {
    Stack* s = new Stack();
    s->top = -1;
    return s;
}

void push(Stack* s, elem num) {
    s->top++;
    s->stack[s->top] = num;
}

void pop(Stack* s, elem& num) {
    num = s->stack[s->top];
    s->top--;
}

bool emptystack(Stack* s) {
    return s->top == -1;
}



// 定义试探方向
typedef struct direct{
    int x,y;
}direct;




// 迷宫创建
void ini_Maze(int maze[m+2][n+2]) {
    // 制作围墙
    for (int j = 0; j < n + 2; j++) maze[0][j] = 1;
    for (int j = 0; j < n + 2; j++) maze[7][j] = 1;
    for (int i = 0; i < m + 2; i++) maze[i][0] = 1;
    for (int i = 0; i < m + 2; i++) maze[i][9] = 1;
    // 迷宫
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            maze[i][j] = rand() % 2; // 随机生成0或1
        }
    }
}

// 用于标记到过的地方
void ini_Mark(int maze[m+2][n+2]) {
    // 迷宫
    for (int i = 0; i < m + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            maze[i][j] = 0; // 随机生成0或1
        }
    }
}

void make_direct (direct move[8]) {
    // 正东移动
    move[0].x = 0;
    move[0].y = 1;
    // 东南移动
    move[1].x = 1;
    move[1].y = 1;
    move[2].x = 1;
    move[2].y = 0;
    move[3].x = 1;
    move[3].y = -1;
    move[4].x = 0;
    move[4].y = -1;
    move[5].x = -1;
    move[5].y = -1;
    move[6].x = -1;
    move[6].y = 0;
    move[7].x = -1;
    move[7].y = 1;

}

// 核心求解算法
bool solve_Maze (int maze[m + 2][n + 2], direct move[8]) {
    Stack* maze_s = ini_Stack();
    elem idx; // 包括x，y坐标以及下一个移动方向d
    int d = 0; // 控制移动方向
    // 初始位置
    idx.i = 1;
    idx.j = 1;
    idx.d = -1;
    push(maze_s, idx);
    while (!emptystack(maze_s)) {
        pop(maze_s, idx);
        // 上一个位置的坐标
        int last_x = idx.i;
        int last_y = idx.j;
        int d = idx.d + 1; // 尝试下一个方向
        while (d < 8) {
            int new_x = last_x + move[d].x;
            int new_y = last_y + move[d].y;
            if (maze[new_x][new_y] == 0) {
                idx = {last_x, last_y, d};
                push(maze_s, idx);
                // 更新坐标
                last_x = new_x;
                last_y = new_y;
                maze[last_x][last_y] = -1;
                if (last_x == m && last_y == n) {
                    return true; // 找到出口
                }else {
                    d = 0;
                }
            }else {
                d++;
            }
        }
    }
    return false;
}




void show(int maze[m+2][n+2]) {
    for (int i = 0; i < m + 2; i++) {
        for (int j = 0; j < n + 2; j++) {
            cout<<maze[i][j]<<" ";
        }
        cout<<endl;
    }
}


int main () {
    srand(static_cast<unsigned int>(std::time(0))); // 需要设置随机种子不然结果固定?
    int maze[m + 2][n + 2];
    direct move[8];
    make_direct(move);
    ini_Maze(maze);
    show(maze);
    cout << solve_Maze(maze, move) << endl;
    while (!solve_Maze(maze,move)) {
        ini_Maze(maze);
        show(maze);
        cout << endl;
    }
}