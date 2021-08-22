#include <iostream>
using namespace std;
#include <string>

typedef struct EdgeNode //�߱���
{
	int script;//�����Ӧ���±�
	int weight;//Ȩֵ
	struct EdgeNode* next;//ָ����һ���ڽӵ�
} EdgeNode;

typedef struct TopNode //�������
{
	char data[50];//��������
	EdgeNode* edgefirst;//�߱�ͷָ��
} TopNode, Box[100];

typedef struct //����
{
	Box Box;
	int topnum, edgenum;//�������ͱ���
} MapBox;

class Map
{
	char mapname[100][100] = { "����¥", "ʵ��¥D", "��ѧ¥A", "����", "����",
	"A4", "ʵ��¥C","��ѧ¥B", "A2", "A6", "�����ϵ", "�չ�����","������Ʒ",
	"ʵ��¥A", "��ѧ¥C", "ͼ���", "һʳ��", "D2", "D8", "C4", "�й���ͨ",
	"��ë��","����", "B5", "B7", "D4", "D6", "C8","C6", "��ʳ��",
	"һ�������̰�","B11"};//����ص���Ϣ

	int distance[100][100] = { 0 };//�������֮���Ȩֵ
	int shortdistance[100][100] = { 0 };//������·������֮�����
	int shortpath[100][100] = { 0 };//�������·����Ϣ
public:
	void InMap(MapBox* map);//��ʼ����ͼ
	void CreateMap(MapBox* map);//������ͼ
	void ShortWay(MapBox* map);//����Floryd�㷨�����������֮�����·��
	void ShowShortWay(int begin, int end);//���·�����Ⱥ;���·��
	void Add(MapBox* map); //���һ������
}; 

void Map::InMap(MapBox* map) //��ʼ����ͼ��������
{
	map->topnum = 32;//���붥�����ͱ���
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

void Map::CreateMap(MapBox* map) //������ͼ
{
	EdgeNode *e;

	for (int i = 0; i < map->topnum; i++)//���붥����Ϣ�����������
	{
		strcpy(map->Box[i].data, mapname[i]);//���붥����Ϣ
		map->Box[i].edgefirst = NULL;//���߱���Ϊ�ձ�
	}

	for (int i = 0; i < map->topnum; i++)//�����߱�ͷ�巨��
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
	cout << "���:" << mapname[begin] << endl
		<< "�յ�:" << mapname[end] << endl;
	cout << "��̾���:" << shortdistance[begin][end] << endl;
	temp = shortpath[begin][end];
	cout << "����·��:" << mapname[begin] << "��>";

	while (temp != end)
	{
		cout << mapname[temp] << "��>";
		temp = shortpath[temp][end];
	}
	cout << mapname[end] << endl << endl;
}

void Map::Add(MapBox* map)
{
	int a, b;
	cout << "��������Ҫ��ӵľ���:";
	cin >> mapname[map->topnum];
	map->topnum = map->topnum + 1;
	while (1)
	{
		char c;
	    cout << "��������þ������ڵľ����±��Լ�������֮��ľ���:";
		cin >> a >> b;
		distance[map->topnum-1][a] = b;
		map->edgenum = map->edgenum + 1;
		cout << "�Ƿ�������? ����y��n�ж�:";
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
	cout << "--      ��ӭʹ��У԰����ϵͳ      --" << endl;
	cout << "------------------------------------" << endl;
	int a;
	while (1)
	{
		cout << "  " << "--------------------------------" << endl;
		cout << "  " << "|  1.��ʾ��ͼ                  |" << endl;
		cout << "  " << "|  2.���һ������              |" << endl;
		cout << "  " << "|  3.��ѯ������֮������·��  |" << endl;
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
			cout << "�����������յ�:";
			cin >> begin >> end;
			guide.ShowShortWay(begin, end);
			break;
		}
	}
	return 0;
}