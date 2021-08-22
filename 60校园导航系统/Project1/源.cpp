#include <iostream>
using namespace std;
#include <string>

typedef struct EdgeNode //边表结点
{
	int script;//顶点对应的下标
	int weight;//权值
	struct EdgeNode* next;//指向下一个邻接点
} EdgeNode;

typedef struct TopNode //顶点表结点
{
	char data[50];//顶点数据
	EdgeNode* edgefirst;//边表头指针
} TopNode, Box[100];

typedef struct //集合
{
	Box Box;
	int topnum, edgenum;//顶点数和边数
} MapBox;

class Map
{
	char mapname[100][100] = { "行政楼", "实验楼D", "教学楼A", "篮球场", "足球场",
	"A4", "实验楼C","教学楼B", "A2", "A6", "计算机系", "苏果超市","果曼优品",
	"实验楼A", "教学楼C", "图书馆", "一食堂", "D2", "D8", "C4", "中国联通",
	"羽毛球场","网球场", "B5", "B7", "D4", "D6", "C8","C6", "三食堂",
	"一鸣真鲜奶吧","B11"};//储存地点信息

	int distance[100][100] = { 0 };//存放两点之间的权值
	int shortdistance[100][100] = { 0 };//存放最短路径两点之间距离
	int shortpath[100][100] = { 0 };//储存最短路径信息
public:
	void InMap(MapBox* map);//初始化地图
	void CreateMap(MapBox* map);//创建地图
	void ShortWay(MapBox* map);//利用Floryd算法计算各个顶点之间最短路径
	void ShowShortWay(int begin, int end);//输出路径长度和具体路径
	void Add(MapBox* map); //添加一个景点
}; 

void Map::InMap(MapBox* map) //初始化地图基本数据
{
	map->topnum = 32;//输入顶点数和边数
	map->edgenum = 59;
	distance[0][2] = 60;

	distance[1][2] = 190;
	distance[1][7] = 210;
	distance[1][6] = 70;

	distance[2][7] = 80;
	distance[2][16] = 320;
	distance[2][3] = 120;

	distance[3][7] = 100;
	distance[3][14] = 170;
	distance[3][4] = 80;

	distance[4][11] = 180;
	distance[4][8] = 90;
	distance[4][5] = 140;

	distance[5][9] = 70;

	distance[6][7] = 220;
	distance[6][10] = 50;

	distance[7][10] = 210;
	distance[7][14] = 90;
	distance[7][16] = 260;

	distance[8][11] = 110;
	distance[8][9] = 60;

	distance[9][11] = 110;

	distance[10][17] = 190;
	distance[10][13] = 50;

	distance[11][16] = 80;
	distance[11][12] = 90;

	distance[12][16] = 100;

	distance[13][17] = 160;
	distance[13][18] = 170;
	distance[13][15] = 120;
	distance[13][14] = 190;

	distance[14][15] = 80;
	distance[14][16] = 210;

	distance[15][18] = 140;
	distance[15][20] = 200;
	distance[15][21] = 170;

	distance[16][21] = 200;
	distance[16][23] = 80;

	distance[17][25] = 60;
	distance[17][18] = 70;

	distance[18][26] = 70;
	distance[18][19] = 120;

	distance[19][20] = 60;

	distance[20][21] = 100;
	distance[20][22] = 110;
	distance[20][27] = 130;
	distance[20][28] = 120;

	distance[21][22] = 90;

	distance[22][29] = 120;
	distance[22][30] = 110;
	distance[22][24] = 110;

	distance[23][24] = 80;

	distance[24][30] = 40;

	distance[25][26] = 80;

	distance[26][27] = 80;

	distance[28][29] = 80;

	distance[29][31] = 180;
	distance[29][30] = 100;

	distance[30][31] = 100;
}

void Map::CreateMap(MapBox* map) //创建地图
{
	EdgeNode *e;

	for (int i = 0; i < map->topnum; i++)//读入顶点信息，建立顶点表
	{
		strcpy(map->Box[i].data, mapname[i]);//读入顶点信息
		map->Box[i].edgefirst = NULL;//将边表置为空表
	}

	for (int i = 0; i < map->topnum; i++)//建立边表（头插法）
	{
		for (int j = 0; j < i; j++)
		{
			int temp;
			if (distance[i][j] != 0 || distance[j][i] != 0)
			{
				if (distance[i][j] != 0)
				{
					temp = distance[i][j];
					distance[j][i] = distance[i][j];
				}
				else
				{
					temp = distance[j][i];
					distance[i][j] = distance[j][i];
				}

				e = new EdgeNode;
				e->script = j;
				e->next = map->Box[i].edgefirst;
				e->weight = temp;
				map->Box[i].edgefirst = e;

				e = new EdgeNode;

				e->script = i;
				e->next = map->Box[j].edgefirst;
				e->weight = temp;
				map->Box[j].edgefirst = e;
			}
		}
	}
}

void Map::ShortWay(MapBox* map)
{
	for (int i = 0; i < map->topnum; ++i)
	{
		for (int j = 0; j < map->topnum; ++j)
		{
			if ( distance[i][j] == 0  && i != j)
			{
				distance[i][j] = 10000;
			}
			shortdistance[i][j] = distance[i][j];
			shortpath[i][j] = j;
		}
	}

	for (int k = 0; k < map->topnum; ++k)
	{
		for (int i = 0; i < map->topnum; ++i)
		{
			for (int j = 0; j < map->topnum; ++j)
			{
				if (shortdistance[i][j] > shortdistance[i][k] + shortdistance[k][j])
				{
					shortdistance[i][j] = shortdistance[i][k] + shortdistance[k][j];
					shortpath[i][j] = shortpath[i][k];
				}
			}
		}
	}
}

void Map::ShowShortWay(int begin, int end)
{
	int temp;
	cout << "起点:" << mapname[begin] << endl
		<< "终点:" << mapname[end] << endl;
	cout << "最短距离:" << shortdistance[begin][end] << endl;
	temp = shortpath[begin][end];
	cout << "具体路径:" << mapname[begin] << "—>";

	while (temp != end)
	{
		cout << mapname[temp] << "—>";
		temp = shortpath[temp][end];
	}
	cout << mapname[end] << endl << endl;
}

void Map::Add(MapBox* map)
{
	int a, b;
	cout << "请输入需要添加的景点:";
	cin >> mapname[map->topnum];
	map->topnum = map->topnum + 1;
	while (1)
	{
		char c;
	    cout << "请输入与该景点相邻的景点下标以及两景点之间的距离:";
		cin >> a >> b;
		distance[map->topnum-1][a] = b;
		map->edgenum = map->edgenum + 1;
		cout << "是否继续添加? 输入y或n判断:";
		cin >> c;
		if (c == 'N' || c == 'n')
		{
			return;
		}
    }
}

int main()
{
	Map guide;
	int begin, end;
	MapBox* map = new MapBox;
	guide.InMap(map);
	guide.CreateMap(map);
	guide.ShortWay(map);
	//guide.ShowMap(map);

	cout << "------------------------------------" << endl;
	cout << "--      欢迎使用校园导航系统      --" << endl;
	cout << "------------------------------------" << endl;
	int a;
	while (1)
	{
		cout << "  " << "--------------------------------" << endl;
		cout << "  " << "|  1.显示地图                  |" << endl;
		cout << "  " << "|  2.添加一个景点              |" << endl;
		cout << "  " << "|  3.查询两景点之间的最短路径  |" << endl;
		cout << "  " << "--------------------------------" << endl;
		cin >> a;
		switch (a)
		{
		case 1:
			system("mspaint SchoolMap.png");
			break;
		case 2:
			guide.Add(map);
			guide.CreateMap(map);
			guide.ShortWay(map);
			break;
		default:
			cout << "请输入起点和终点:";
			cin >> begin >> end;
			guide.ShowShortWay(begin, end);
			break;
		}
	}
	return 0;
}