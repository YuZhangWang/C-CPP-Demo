#include <string>
#include <iostream>
using namespace std;

class CGobang //������
{
private:
	char chSort; //���ӵ����
	int nWin; //Ӯ��Ĵ���
	int nLose; //����Ĵ���
	static int nDraw; //ƽ�ִ���
	static char achBoard[4][4]; //����
	static int nSize; //���̵ĳߴ� nSize X nSize
public:
	CGobang(char chsort) //���캯��������һ�����ӵ����
	{
		chSort=chsort;
		nWin=nLose=nDraw=0;
	}
	
	void PlayTurn(); //��1����
	int Judge(); //�ж��Ƿ�����һ�ߣ����򷵻�1�����򷵻�0
	void Win(); //Ӯ��
	void Lose(); //����
	static void Draw(); //ƽ��
	void PrintInfo(); //����������
	static void PrintBoard(); //�������
	static int GetFull(); //�ж������Ƿ��Ѳ�������
	static void InitialBoard(); //��ʼ������
};

char CGobang::achBoard[4][4] = {' '};
int CGobang::nSize = 4;
int CGobang::nDraw = 0;

void CGobang::Draw()
{
	cout << "\n\n\t\tƽ��!\n\n";
	nDraw++;
}

void CGobang::InitialBoard() //��ʼ������
{
	for(int i=0;i<nSize;i++)
		for(int j=0;j<nSize;j++)
			achBoard[i][j]=' ';
}

void CGobang::PrintBoard() //�������
{
	cout << endl;
	cout << "  1   2   3   4" << endl;
	cout << "1 " << achBoard[0][0] << " | " << achBoard[0][1] << " | " << achBoard[0][2] << " | " << achBoard[0][3] << endl;
	cout << " ---|---|---|---" << endl;
	cout << "2 " << achBoard[1][0] << " | " << achBoard[1][1] << " | " << achBoard[1][2] << " | " << achBoard[1][3] << endl;
	cout << " ---|---|---|---" << endl;
	cout << "3 " << achBoard[2][0] << " | " << achBoard[2][1] << " | " << achBoard[2][2] << " | " << achBoard[2][3] << endl;
	cout << " ---|---|---|---" << endl;
	cout << "4 " << achBoard[3][0] << " | " << achBoard[3][1] << " | " << achBoard[3][2] << " | " << achBoard[3][3] << endl;
	cout << endl;
	cout << endl;
}

int CGobang::GetFull() //�ж������Ƿ������ӣ����Ƿ���1
{
	int flag=1;
	for(int i=0;i<nSize;i++)
	{
		for(int j=0;j<nSize;j++)
		{
			if(achBoard[i][j] == ' ' )
			{
                flag=0;
				break;
			}
		}
		if(flag == 0)
			break;
	}
	return flag;
}

void CGobang::Win() //Ӯ��
{
	cout << "\n\n\t\t"<<chSort<<"����ʤ!\n\n";
	nWin++;
}

void CGobang::Lose() //����
{
	nLose++;
}

void CGobang::PlayTurn(void) //��1����
{
	int nRow,nCol;
	cout <<"���ڸ� "<<chSort<<" �����壬�������������꣨x��y����";
	do
	{
		cin >> nRow >> nCol; //��������
		if(nRow>nSize || nCol>nSize) //�ж�����Խ��
		{
			cout <<"���������Խ�磬x��y�ķ�ΧӦС�ڵ���"<<nSize<<",����������\n";
		}
		else if(achBoard[nRow-1][nCol-1]!=' ') //�ж��������
		{
			cout <<"����("<<nRow <<" ��"<<nCol <<")���������ӣ�����������\n";
		}
		else
		{
			achBoard[nRow-1][nCol-1]=chSort; //�����괦��������
			break; //�˳�ѭ��
		}
	}while(1);
}

int CGobang::Judge() //�ж��Ƿ���������һ�ߣ����Ƿ���1
{//�����Ǹ��ֿ�������һ�ߵ����
	int flag=0;
	if(achBoard[0][0]==chSort && achBoard[1][1]==chSort && achBoard[2][2]==chSort && achBoard[3][3]==chSort)
		flag=1;
	else if(achBoard[3][0]==chSort && achBoard[2][1]==chSort && achBoard[1][2]==chSort && achBoard[0][3]==chSort)
		flag=1;
	for(int i=0;i<nSize;i++)
	{
        if(achBoard[i][0]==chSort && achBoard[i][1]==chSort && achBoard[i][2]==chSort && achBoard[i][3]==chSort)
			flag=1;
		else if(achBoard[0][i]==chSort && achBoard[1][i]==chSort && achBoard[2][i]==chSort && achBoard[3][i]==chSort)
			flag=1;
	}
	return flag; //û������һ���򷵻�0
}

void CGobang::PrintInfo(void) //��ӡ�������
{
	cout <<chSort<<"������Ӯ "<<nWin<<" �֣��� "<<nLose<<" �֣�ƽ "<<nDraw<<" �֡�"<<endl;
}

void PrintRule(void) //��ӡ����
{
	cout << "\t\t��ӭʹ������������Ϸ!" << endl << endl;
	cout << "\t��Ϸ����:" << endl;
	cout << "\t1.ÿ1������Ҫ����ĸ��ӵ�x��y���꣬��Enter��\n";
	cout << "\t2.��1������4����������һ�߼��л�ʤ\n";
	cout << "\t3.�����Ӳ������̵����޻�ʤ����Ϊƽ��\n";
	cout << "\t4.X������\n";
	cout << "\n\n\t\t��س�����ʼ����!\n\n";
}

int JudgePlay(CGobang &SideX,CGobang &SideO) //ÿ��1��Ҫ������Ӯ���жϣ��н���򷵻�1
{
	if(SideX.Judge()) //X����ʤ
	{
		SideX.Win();
		SideO.Lose();
		return 1;
	}
	else if(SideO.Judge()) //O����ʤ
	{
		SideO.Win();
		SideX.Lose();
		return 1;
	}
	else
		return 0;
}

void Play(CGobang &SideX,CGobang &SideO) //��ʼһ����Ϸ
{
	while(1)
	{
		CGobang::PrintBoard(); //�������
		
		SideX.PlayTurn(); //X������
		
		if(JudgePlay(SideX,SideO)) //�ж���Ӯ
			break;
		
		if(CGobang::GetFull()) //�ж��Ƿ�ƽ��
		{
			CGobang::Draw();
			break;
		}
		
		CGobang::PrintBoard(); //�������
		
		SideO.PlayTurn(); //O������
		
		if(JudgePlay(SideX,SideO)) //�ж���Ӯ
			break;
		
		if(CGobang::GetFull()) //�ж��Ƿ�ƽ��
		{
			CGobang::Draw();
			break;
		}
	}
}

int main()
{
	CGobang SideX('X'),SideO('O'); //����������������󣬷ֱ����X����O��
	PrintRule();
	cin.get();
	string strChoice;

	do
	{
		CGobang::InitialBoard(); //��ʼ������
		Play(SideX,SideO); //��ʼ��һ��
		cout << "�Ƿ������Y/N����";
		cin >> strChoice;
	}while(strChoice == "Y" || strChoice == "y");
	
	SideX.PrintInfo();
	SideO.PrintInfo();
	cout << "\n\n\t��ӭ�ٴ�ʹ������������Ϸ!" << endl << endl;
	return 0;
}