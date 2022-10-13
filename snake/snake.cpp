#include<iostream>
#include<list>
#include<conio.h>
#include<windows.h>
#include<ctime>


struct snake_p { //蛇体每一节.
    int x,y;
};
int fx,fy;
std::list<snake_p> snake = {{1,3},{1,2},{1,1}};//蛇体初始化
// 空地：0，墙壁：1，蛇体：2， 蛇头：3，果子：4。
int map[25][25] = {0}; //地图
int dir = 1, live = 1, fruit = 0; //蛇前进方向,存活状态,是否吃到果子

void inite_map() //初始化地图
{
    for(int i = 0; i < 25; i++)
        for(int j = 0; j < 25; j++)
        {
            if(i == 0 || i == 21 || j==0||j==21) map[i][j] = 1;
            else map[i][j] = 0;
        }
    map[fx][fy] = 4;
}

void push_snake() // 将蛇放入地图
{
    for(auto s : snake)
    {
        int x = s.x, y = s.y;
        map[x][y] = 2;
    }
    map[snake.front().x][snake.front().y] = 3;
}

void push_fruit() // 随机生成水果位置.
{
    int x, y;
    fx = rand()%17+1;
    fy = rand()%17+1;
    if(map[fx][fy] == 2 || map[fx][fy] == 3) push_fruit();
}

void snake_go() //蛇的移动
{
    int x = snake.front().x,y = snake.front().y;
    switch(dir)
    {
        case 1:
            y++;
            break;
        case 2:
            x++;
            break;
        case 3:
            y--;
            break;
        case 4:
            x--;
            break;
    }
    if(fruit == 0) snake.pop_back(); // 吃到果子
    snake.push_front({x,y});
    fruit = 0;
}

void check() // 碰撞检测
{
    int x = snake.front().x, y = snake.front().y;
    if(map[x][y] == 1 || map[x][y] == 2) live = 0;
    if(map[x][y] == 4) 
    {
        fruit = 1;
        push_fruit();
    }
}
void snake_dir() //蛇的前进方向
{
    if(kbhit())
    {
        int ch = getch();
        switch(ch)
        {
            case 'd':
                if(dir != 3) dir = 1;
                break;
            case 's':
                if(dir != 4) dir = 2;
                break;
            case 'a':
                if(dir != 1) dir = 3;
                break;
            case 'w':
                if(dir != 2) dir = 4;
        }
    }
}


int main()
{
    int speed;
    printf("请输入速度 1 - 10\n");
    std::cin >> speed;
    speed = (10-speed)*2;
    srand((unsigned)time(NULL));//随机种子
    push_fruit();
    while(live)
    {
        system("cls");
        snake_dir();
        inite_map();
        push_snake();
        snake_go();
        check();
        for(int i = 0; i <= 21; i++)
        {
            for(int j = 0; j <= 21; j++)
            {
                if(map[i][j] == 0) printf("□");
                else if(map[i][j] == 1) printf("■");
                else if(map[i][j] == 2 || map[i][j] == 3) printf("■");
                else if(map[i][j] == 4) printf("■");
            }
            printf("\n");
        }
        Sleep(speed);
    }
    printf("失败\n回车键退出...");
    getchar();
}


