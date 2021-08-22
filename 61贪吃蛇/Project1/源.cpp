/************************贪吃蛇***********************/
/*                     by:yinggcy                   */
/**********************2017/10/07********************/

#include <iostream>
#include <deque>
#include <windows.h>                //包含 隐藏光标
#include <conio.h>                  //包含 _getch() 和 _kbhit()
#include <ctime>
using namespace std;
#define N 30
#define Up 1                        //方向键对应的的ASCII为 72
#define Down 2                      //的ASCII为   80
#define Left 3                      //的ASCII为   75
#define Right 4                     //的ASCII为   77

class Map {
private:
	class snake {                   //蛇坐标类
	public:
		int x;
		int y;
	};
	class Food {                    //食物坐标类
	public:
		int x;
		int y;
	};
	Food food;
	snake head, tail;               //蛇头 蛇尾
	deque<int> direction;           //保存每次前进的方向,最近一次前进添加到最前面
	int mod;                        //游戏模式 普通模式 == 0, 冒险模式 == 1;
	int score;
	int grade;
	int autoSpeed;                  //更新游戏自动更新速度
	char map[N][N];                 //保存输出      //如 xx[Up] = 80 Down的ASCII码为80
	int opposite_direction[5] = { 0, 80, 72, 77, 75 };//保存各方向的反方向的ASCII码(接上面)
	int speed[9] = { 0, 800, 600, 500, 420, 250, 100, 40, 5 };//保存自动前进速度,单位ms
public:
	Map() : head({ N / 2, N / 2 }), tail({ N / 2, N / 2 - 2 }),     //构造函数
		mod(0), score(0), grade(1), autoSpeed(speed[grade]) { }
	void Hello();                   //欢迎界面
	void Print_Hello(int);          //打印欢迎界面
	void Start_Game();
	void Initialize_Map();
	int Update_Map();
	void Show_Map();
	void Rand_Food();
	void Reset();                   //复位
};

void Map::Hello()
{
	while (true) {
		system("cls");                  //清屏
		Print_Hello(mod);

		if (_getch() != 13) {                //判断是否为回车键,确定选择的模式
			switch (_getch()) {              //判断上下移动
			case 80: mod = 1; break;
			case 72: mod = 0; break;
			}
			continue;
		}
		//Enter 的ASCII码为 13, 按了回车确定模式
		if (mod == 0) {                              //普通模式
			do {
				system("cls");
				cout << "\n\n\n\n\t\t\t 请输入你需要的游戏级别: (1~8)   ";
				cin >> grade;
			} while (grade > 8 || grade < 1);   //判断等级输入是否正确
			autoSpeed = speed[grade];           //更新自动快进速度
			break;
		}
		else                                    //冒险模式
			break;
	}
	Start_Game();               //开始游戏
}

void Map::Print_Hello(int mod)
{
	srand((unsigned)time(nullptr));     //用时间产生随机种子,百度一下,你便知道
	cout << "\n\n\n\t\t\t\t 贪吃蛇 \n\n\n\n";
	cout << "\t\t\t     请选择你的模式:";
	cout << "\n\n\t\t\t     普通模式:";
	if (mod == 0) cout << "   *";       //让玩家知道未按回车确定前选择的模式
	cout << "\n\n\t\t\t     冒险模式:";
	if (mod == 1) cout << "   *";
	cout << "\n\n\n\n\n\n\n\n 版本:V1.0        \t\t\t\t\t 作者: yinggcy";
}

void Map::Start_Game()
{
	char choose;
	Initialize_Map();           //初始化地图
	Rand_Food();                //产生第一个食物
	do {
		Show_Map();
	} while (Update_Map());

	cout << "\t\t Game Over!!!     你先继续吗? (Y/Others)";
	cin >> choose;
	if (choose == 'Y' || choose == 'y') {
		Reset();
		Hello();
	}
}

void Map::Initialize_Map()
{
	for (int i = 0; i < N; i++)                     //左右边框
		map[0][i] = map[N - 1][i] = '*';
	for (int i = 1; i < N; i++)                     //上下边框
		map[i][0] = map[i][N - 1] = '*';
	for (int i = 1; i < N - 1; i++)                 //中间空白
		for (int j = 1; j < N - 1; j++)
			map[i][j] = ' ';

	map[N / 2][N / 2] = '@';                                //初始蛇头
	map[N / 2][N / 2 - 1] = map[N / 2][N / 2 - 2] = 'O';    //初始蛇身
	direction.push_front(Right);        //初始化 direction
	direction.push_front(Right);        //因为初始为 OO@ 尾部要进行两个向右才能到蛇头位置
}

void Map::Show_Map()                            //输出游戏画面
{
	system("cls");
	for (int i = 0; i < N; i++) {
		cout << "\t";
		for (int j = 0; j < N; j++)
			cout << map[i][j] << ' ';
		if (i == N / 4)
			cout << "\t Score: " << score;
		if (i == N / 4 + 4)
			cout << "\t grade: " << grade;
		if (i == N / 4 + 8)
			cout << " 按空格键暂停/继续";
		cout << endl;
	}
}

int Map::Update_Map()                           //更新游戏(最主要的)
{
	int tmp_direction, tmp_others, sign = 0;    //sign == 1(读入了方向键)         
	double start_time = (double)clock() / CLOCKS_PER_SEC;//读入执行这段代码时的时间

	do {
		if (_kbhit()) {          //_kbhit()判断是否有按键输入,但不读入.
			tmp_others = _getch();              //代码前有介绍
			if (tmp_others == 32)               //为空格键 暂停游戏
				while (_getch() != 32);         //当读入空格键退出循环
			else if (tmp_others == 224) { //224为方向键的第一个字节的ASCII码
				tmp_direction = _getch();
				if (opposite_direction[direction.front()] == tmp_direction)
					//是否为上一次方向的反向,在这个设定下长度<=4不会吃到自己(下接)
					continue;   //假设当前蛇为: OO@ 如果输入左转向 判断为无效按钮,继续循环  
				switch (tmp_direction) {                                 //判断方向
				case 72: direction.push_front(Up); sign = 1; break;
				case 80: direction.push_front(Down); sign = 1; break;
				case 75: direction.push_front(Left); sign = 1; break;
				case 77: direction.push_front(Right); sign = 1; break;
				}
				if (sign) break;                //读入了方向键,推出循环 判断情况
			}
		}
		//未读入方向键或空格,判断是否超过自动前进时间
		if ((double)clock() / CLOCKS_PER_SEC - start_time > autoSpeed / 1000.0) {//用法,代码前有介绍
			direction.push_front(direction.front());    //自动前进,和前一次前进方向一样
			break;
		}
	} while (true);

	map[head.x][head.y] = 'O';          //更新地图把蛇头原蛇头位置置为蛇身
	switch (direction.front()) {         //更新蛇头坐标
	case Up: head.x -= 1; break;
	case Down: head.x += 1; break;
	case Left: head.y -= 1; break;
	case Right: head.y += 1; break;
	}

	if (head.x == food.x && head.y == food.y) {  //是否吃到食物
		map[head.x][head.y] = '@';
		score += 10;
		if (mod == 1) {          //更新冒险模式的游戏等级和速度,每吃6个增加一级,最高5级
			if (score / 60 >= grade) {
				if (grade < 5)
					grade++;
				autoSpeed = speed[grade];
			}
		}
		Rand_Food();                    //更新食物
	}
	else if (map[head.x][head.y] != ' ' && !(head.x == tail.x && head.y == tail.y))
		return 0;   //if(更新的头位置是否不为地图中的空白 && 是否不为蛇尾) (接下)
		//前面已经判断没吃到食物,所以蛇尾会前进,因为只更新了蛇头没有更新蛇尾,所以排除蛇尾情况
	else {                              //没有吃到食物    
		map[tail.x][tail.y] = ' ';      //更新地图蛇尾
		map[head.x][head.y] = '@';      //更新地图蛇头
		switch (direction.back()) {      //更新蛇尾坐标
		case Up: tail.x -= 1; break;
		case Down: tail.x += 1; break;
		case Left: tail.y -= 1; break;
		case Right: tail.y += 1; break;
		}
		direction.pop_back();           //弹出 前 蛇尾坐标
	}
	return 1;                           //未撞墙或吃到自己
}

void Map::Rand_Food()
{
	do {
		food.x = rand() % (N - 2) + 1;
		food.y = rand() % (N - 2) + 1;
	} while (map[food.x][food.y] != ' ');
	map[food.x][food.y] = '%';
}

void Map::Reset()
{
	Initialize_Map();
	head = { N / 2, N / 2 };
	tail = { N / 2, N / 2 - 2 };
	mod = 0;
	score = 0;
	grade = 1;
	autoSpeed = 800;
	direction.clear();
}

int main()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);                    //  百度
	CONSOLE_CURSOR_INFO CursorInfo;                                     //  搜的
	GetConsoleCursorInfo(handle, &CursorInfo);      //获取控制台光标信息 //  隐藏
	CursorInfo.bVisible = false;                    //隐藏控制台光标       //  光标
	SetConsoleCursorInfo(handle, &CursorInfo);      //设置控制台光标状态 //  方法

	Map m;
	m.Hello();

	return 0;
}