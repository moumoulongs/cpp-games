#include<iostream>
#include<list>
#include<conio.h>
#include<windows.h>
#include<ctime>


struct snake_p { //蛇体每一节
    int x,y;
};
std::list<snake_p> snake = {{1,1},{1,2},{1,3}};//蛇体， 同时初始化；
// 空地：0，墙壁：1，蛇体：2，果子：3。
int map[25][25] = {0}; //地图
int dir = 1, live = 1; //蛇前进方向和存活状态

void inite_map() //初始化地图
{
    for(int i = 0; i < 25; i++)
        for(int j = 0; j < 25; j++)
        {
            if(i == 0 || i == 20 || j==0||j==20) map[i][j] = 1;
            else map[i][j] = 0;
        }
}

void push_snake() // 将蛇放入地图
{
    for(auto s : snake)
    {
        int x = s.x, y = s.y;
        map[x][y] = 2;
    }
}

void push_fruit() // 随机生成水果；
{
    
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
    snake.pop_back();
    snake.push_front({x,y});
}

void check() // 碰撞检测
{

}
void snake_dir() //蛇的转向
{
    if(kbhit())
    {
        int ch = getch();
        switch(ch)
        {
            case 'd':
                dir = 1;
                break;
            case 's':
                dir = 2;
                break;
            case 'a':
                dir = 3;
                break;
            case 'w':
                dir = 4;
        }
    }
}


int main()
{
    while(live)
    {
        system("cls");
        inite_map();
        snake_dir();
        snake_go();
        push_snake();
        for(int i = 0; i <= 21; i++)
        {
            for(int j = 0; j <= 21; j++)
            {
                if(map[i][j] == 0) printf(" ");
                else if(map[i][j] == 1) printf("#");
                else if(map[i][j] == 2) printf("@");
            }
            printf("\n");
        }
        Sleep(200);
    }
}


