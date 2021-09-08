/***********************************
 * @author: YuZhangWang
 * @date: 2021/9/3 16:42
 * @link: https://www.yuzhang.wang/
***********************************/

#include <iostream>
#include <string>

using namespace std;

class CGobang //棋子类
{
private:
    char chSort; //棋子的类别
    int nWin; //赢棋的次数
    int nLose; //输棋的次数
    static int nDraw; //平局次数
    static char achBoard[4][4]; //棋盘
    static int nSize; //棋盘的尺寸 nSize X nSize
public:
    CGobang(char chsort) //构造函数，决定一方棋子的类别
    {
        chSort = chsort;
        nWin = nLose = nDraw = 0;
    }

    void PlayTurn(); //走1步棋
    int Judge(); //判断是否连成一线，是则返回1，否则返回0
    void Win(); //赢棋
    void Lose(); //输棋
    static void Draw(); //平局
    void PrintInfo(); //输出总体情况
    static void PrintBoard(); //输出棋盘
    static int GetFull(); //判断棋盘是否已布满棋子
    static void InitialBoard(); //初始化棋盘
};

char CGobang::achBoard[4][4] = {' '};
int CGobang::nSize = 4;
int CGobang::nDraw = 0;

void CGobang::Draw() {
    cout << "\n\n\t\t平局!\n\n";
    nDraw++;
}

void CGobang::InitialBoard() //初始化棋盘
{
    for (int i = 0; i < nSize; i++)
        for (int j = 0; j < nSize; j++)
            achBoard[i][j] = ' ';
}

void CGobang::PrintBoard() //输出棋盘
{
    cout << endl;
    cout << "  1   2   3   4" << endl;
    cout << "1 " << achBoard[0][0] << " | " << achBoard[0][1] << " | " << achBoard[0][2] << " | " << achBoard[0][3]
         << endl;
    cout << " ---|---|---|---" << endl;
    cout << "2 " << achBoard[1][0] << " | " << achBoard[1][1] << " | " << achBoard[1][2] << " | " << achBoard[1][3]
         << endl;
    cout << " ---|---|---|---" << endl;
    cout << "3 " << achBoard[2][0] << " | " << achBoard[2][1] << " | " << achBoard[2][2] << " | " << achBoard[2][3]
         << endl;
    cout << " ---|---|---|---" << endl;
    cout << "4 " << achBoard[3][0] << " | " << achBoard[3][1] << " | " << achBoard[3][2] << " | " << achBoard[3][3]
         << endl;
    cout << endl;
    cout << endl;
}

int CGobang::GetFull() //判断棋盘是否布满棋子，若是返回1
{
    int flag = 1;
    for (int i = 0; i < nSize; i++) {
        for (int j = 0; j < nSize; j++) {
            if (achBoard[i][j] == ' ') {
                flag = 0;
                break;
            }
        }
        if (flag == 0)
            break;
    }
    return flag;
}

void CGobang::Win() //赢棋
{
    cout << "\n\n\t\t" << chSort << "方获胜!\n\n";
    nWin++;
}

void CGobang::Lose() //输棋
{
    nLose++;
}

void CGobang::PlayTurn(void) //走1步棋
{
    int nRow, nCol;
    cout << "现在该 " << chSort << " 方下棋，请输入棋盘坐标（x，y）：";
    do {
        cin >> nRow >> nCol; //输入坐标
        if (nRow > nSize || nCol > nSize) //判断坐标越界
        {
            cout << "输入的坐标越界，x与y的范围应小于等于" << nSize << ",请重新输入\n";
        } else if (achBoard[nRow - 1][nCol - 1] != ' ') //判断坐标合理
        {
            cout << "棋盘(" << nRow << " ，" << nCol << ")处已有棋子，请重新输入\n";
        } else {
            achBoard[nRow - 1][nCol - 1] = chSort; //在坐标处放上棋子
            break; //退出循环
        }
    } while (1);
}

int CGobang::Judge() //判断是否棋子连成一线，若是返回1
{//以下是各种可能连成一线的情况
    int flag = 0;
    if (achBoard[0][0] == chSort && achBoard[1][1] == chSort && achBoard[2][2] == chSort && achBoard[3][3] == chSort)
        flag = 1;
    else if (achBoard[3][0] == chSort && achBoard[2][1] == chSort && achBoard[1][2] == chSort &&
             achBoard[0][3] == chSort)
        flag = 1;
    for (int i = 0; i < nSize; i++) {
        if (achBoard[i][0] == chSort && achBoard[i][1] == chSort && achBoard[i][2] == chSort &&
            achBoard[i][3] == chSort)
            flag = 1;
        else if (achBoard[0][i] == chSort && achBoard[1][i] == chSort && achBoard[2][i] == chSort &&
                 achBoard[3][i] == chSort)
            flag = 1;
    }
    return flag; //没有连成一线则返回0
}

void CGobang::PrintInfo(void) //打印总体情况
{
    cout << chSort << "方共计赢 " << nWin << " 局，输 " << nLose << " 局，平 " << nDraw << " 局。" << endl;
}

void PrintRule(void) //打印规则
{
    cout << "\t\t欢迎使用三子连珠游戏!" << endl << endl;
    cout << "\t游戏规则:" << endl;
    cout << "\t1.每1步输入要下棋的格子的x，y坐标，按Enter键\n";
    cout << "\t2.有1方首先4个棋子连成一线即判获胜\n";
    cout << "\t3.当棋子布满棋盘但仍无获胜方即为平局\n";
    cout << "\t4.X方先行\n";
    cout << "\n\n\t\t请回车键开始下棋!\n\n";
}

int JudgePlay(CGobang &SideX, CGobang &SideO) //每下1步要进行输赢的判断，有结果则返回1
{
    if (SideX.Judge()) //X方获胜
    {
        SideX.Win();
        SideO.Lose();
        return 1;
    } else if (SideO.Judge()) //O方获胜
    {
        SideO.Win();
        SideX.Lose();
        return 1;
    } else
        return 0;
}

void Play(CGobang &SideX, CGobang &SideO) //开始一局游戏
{
    while (1) {
        CGobang::PrintBoard(); //输出棋盘

        SideX.PlayTurn(); //X方下棋

        if (JudgePlay(SideX, SideO)) //判断输赢
            break;

        if (CGobang::GetFull()) //判断是否平局
        {
            CGobang::Draw();
            break;
        }

        CGobang::PrintBoard(); //输出棋盘

        SideO.PlayTurn(); //O方下棋

        if (JudgePlay(SideX, SideO)) //判断输赢
            break;

        if (CGobang::GetFull()) //判断是否平局
        {
            CGobang::Draw();
            break;
        }
    }
}

int main() {
    CGobang SideX('X'), SideO('O'); //定义两个棋子类对象，分别代表X方与O方
    PrintRule();
    cin.get();
    string strChoice;

    do {
        CGobang::InitialBoard(); //初始化棋盘
        Play(SideX, SideO); //开始下一局
        cout << "是否继续（Y/N）？";
        cin >> strChoice;
    } while (strChoice == "Y" || strChoice == "y");

    SideX.PrintInfo();
    SideO.PrintInfo();
    cout << "\n\n\t欢迎再次使用三子连珠游戏!" << endl << endl;
    return 0;
}